#!/usr/bin/env python3
"""Execute allowlisted original x86 functions in a memory-only Unicorn sandbox.

No PE entry point, Windows APIs, network, disk imports, or game installation.
Dependencies: unicorn==2.1.4, capstone==5.0.9 (installed separately).
"""
from pathlib import Path
import json
import math
import random
import struct
import sys
from analyze_exe import PE
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UcError
from unicorn.x86_const import *

ROOT=Path(__file__).resolve().parent
PEFILE=ROOT.parent/'original/hamsterball/hamsterball.exe'
STACK=0x1000000
HEAP=0x2000000
STOP=0x3000000


class Sandbox:
    def __init__(self):
        self.pe=PE(PEFILE)
        self.uc=Uc(UC_ARCH_X86,UC_MODE_32)
        self.uc.mem_map(self.pe.base,(self.pe.image_size+4095)&~4095)
        for section in self.pe.sections:
            self.uc.mem_write(self.pe.base+section['rva'],self.pe.data[section['offset']:section['offset']+section['size']])
        self.uc.mem_map(STACK,0x100000)
        self.uc.mem_map(HEAP,0x100000)
        self.uc.mem_map(STOP,4096)
        self.uc.mem_write(STOP,b'\xf4')
        self.uc.reg_write(UC_X86_REG_FPCW,0x037f)
        self.visited=set()
        self.instruction_count=0
        self.imports={int(f['iat'],16):f['name'] for dll in self.pe.imports() for f in dll['functions']}
        self.uc.hook_add(UC_HOOK_CODE,self.on_code)

    def on_code(self,uc,address,size,_):
        self.instruction_count+=1
        self.visited.add(address)
        if address==STOP:return
        if not 0x401000<=address<0x4de000:
            raise RuntimeError(f'Execution outside original code: {address:#x}')

    def write_floats(self,address,values):self.uc.mem_write(address,struct.pack('<'+'f'*len(values),*values))
    def read_floats(self,address,n):return list(struct.unpack('<'+'f'*n,self.uc.mem_read(address,n*4)))

    def call(self,address,registers=None,args=()):
        for reg in [UC_X86_REG_EAX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_EDX,
                    UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EBP]:self.uc.reg_write(reg,0)
        stack=STACK+0x80000
        self.uc.mem_write(stack,struct.pack('<'+'I'*(len(args)+1),STOP,*args))
        self.uc.reg_write(UC_X86_REG_ESP,stack)
        self.uc.reg_write(UC_X86_REG_EFLAGS,0x202)
        for reg,value in (registers or {}).items():self.uc.reg_write(reg,value)
        self.uc.emu_start(address,STOP,count=200000)
        if self.uc.reg_read(UC_X86_REG_EIP)!=STOP:
            raise RuntimeError('Instruction budget exhausted')


def run():
    box=Sandbox()
    obj=HEAP+0x1000
    box.call(0x4627d0,{UC_X86_REG_ESI:obj,UC_X86_REG_EAX:HEAP+0x5000})
    initial=dict(
        iteration_limit=struct.unpack('<I',box.uc.mem_read(obj+0xc60,4))[0],
        coefficient_at_c68=box.read_floats(obj+0xc68,1)[0],
        coefficient_at_c6c=box.read_floats(obj+0xc6c,1)[0],
        limit_at_c70=box.read_floats(obj+0xc70,1)[0],
        radius_candidate=box.read_floats(obj+0xc78,1)[0],
        direction=box.read_floats(obj+0xc8c,3),
        scaled_direction=box.read_floats(obj+0xc98,3))
    assert initial['iteration_limit']==3
    assert initial['radius_candidate']==25
    assert initial['direction']==[0,-1,0]
    ctor_instructions=box.instruction_count
    # Scalar/direction setter recovered directly from 0x4014b0.
    rng=random.Random(20261108)
    setter_cases=[]
    for _ in range(100):
        vector=[rng.uniform(-3,3) for _ in range(3)]
        scale=rng.uniform(-2000,2000)
        vector=list(struct.unpack('<3f',struct.pack('<3f',*vector)))
        scale=struct.unpack('<f',struct.pack('<f',scale))[0]
        box.write_floats(obj+0xc8c,vector)
        box.call(0x4014b0,{UC_X86_REG_EAX:obj},[struct.unpack('<I',struct.pack('<f',scale))[0]])
        actual=box.read_floats(obj+0xc98,3)
        expected=list(struct.unpack('<3f',struct.pack('<3f',*(v*scale for v in vector))))
        assert actual==expected,(vector,scale,actual,expected)
        assert box.read_floats(obj+0xc64,1)==[scale]
        setter_cases.append(dict(direction=vector,scalar=scale,actual=actual,expected=expected))
    # Empty-world branch of the original ellipsoid movement solver, no collision callbacks.
    # Output pointer, position pointer, displacement pointer, radii pointer, context, hit flag.
    movement_cases=[]
    for displacement in [(0,0,0),(10,0,0),(0,-12,0),(4,-6,8)]:
        output,pos,velocity,radii,hit=[HEAP+0x8000+i*0x100 for i in range(5)]
        position=[100.,150.,200.]
        box.write_floats(pos,position);box.write_floats(velocity,displacement)
        box.write_floats(radii,[25,25,25]);box.write_floats(output,[999]*3)
        box.uc.mem_write(hit,b'\x00')
        box.call(0x463200,{UC_X86_REG_ECX:obj},[output,pos,velocity,radii,0,hit])
        actual=box.read_floats(output,3)
        expected=[p+v for p,v in zip(position,displacement)]
        assert all(abs(a-b)<1e-4 for a,b in zip(actual,expected)),(actual,expected)
        movement_cases.append(dict(position=position,displacement=displacement,result=actual))
    result=dict(exe_sha256=__import__('hashlib').sha256(box.pe.data).hexdigest(),
                constructor='0x4627d0',constructor_instruction_count=ctor_instructions,
                reset='0x4630e0',initial_state=initial,
                direction_setter='0x4014b0',setter_cases_passed=len(setter_cases),
                empty_world_solver='0x463200',empty_world_cases=movement_cases,
                original_instructions_executed=box.instruction_count,
                unique_original_instruction_addresses=len(box.visited),
                windows_api_calls=0,notes=[
                    'Original bytes executed without patches; constructor/reset, direction-scalar helper and empty-world solver branch.',
                    'No Windows loader or whole game execution.',
                    'These probes do not validate complete movement or collision behavior.',
                    'Field names except direction are provisional; gameplay semantics require call-site analysis.'],
                setter_cases=setter_cases)
    (ROOT/'original-probe-results.json').write_text(json.dumps(result,indent=2))
    print(json.dumps({k:v for k,v in result.items() if k!='setter_cases'},indent=2))


if __name__=='__main__':run()
