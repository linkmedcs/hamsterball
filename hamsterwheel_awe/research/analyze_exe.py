#!/usr/bin/env python3
"""Reproducible, read-only PE inventory and disassembly anchors (stdlib only)."""
from pathlib import Path
import bisect
import collections
import hashlib
import json
import math
import re
import struct
import subprocess

ROOT = Path(__file__).resolve().parent
EXE = ROOT.parent/'original/hamsterball/hamsterball.exe'


class PE:
    def __init__(self, path):
        self.data = path.read_bytes()
        pe, = struct.unpack_from('<I', self.data, 60)
        self.machine, n, self.timestamp = struct.unpack_from('<HHI', self.data, pe+4)
        optional_size, = struct.unpack_from('<H', self.data, pe+20)
        opt = pe+24
        self.entry_rva, self.base = struct.unpack_from('<I8xI', self.data, opt+16)
        self.image_size, = struct.unpack_from('<I', self.data, opt+56)
        self.directories = [struct.unpack_from('<II', self.data, opt+96+8*i) for i in range(16)]
        self.sections = []
        for i in range(n):
            name, vs, va, size, offset = struct.unpack_from('<8sIIII', self.data, opt+optional_size+40*i)
            code = self.data[offset:offset+size]
            entropy = -sum((v/len(code))*math.log2(v/len(code)) for v in collections.Counter(code).values())
            self.sections.append(dict(name=name.rstrip(b'\0').decode(), rva=va, virtual_size=vs,
                                      size=size, offset=offset, entropy=round(entropy,4)))

    def offset(self, va):
        rva = va-self.base
        for s in self.sections:
            if s['rva'] <= rva < s['rva']+s['size']:
                return s['offset']+rva-s['rva']
        raise ValueError(hex(va))

    def address(self, offset):
        for s in self.sections:
            if s['offset'] <= offset < s['offset']+s['size']:
                return self.base+s['rva']+offset-s['offset']
        raise ValueError(offset)

    def u32(self, address):
        return struct.unpack_from('<I', self.data, self.offset(address))[0]

    def string(self, address):
        start=self.offset(address)
        return self.data[start:self.data.index(b'\0',start)].decode('cp1252')

    def imports(self):
        result=[]
        rva,size=self.directories[1]
        cursor=self.offset(self.base+rva)
        while True:
            lookup,_,_,name,iat=struct.unpack_from('<5I',self.data,cursor)
            if not any((lookup,name,iat)):break
            functions=[];lookup=lookup or iat
            for i in range(10000):
                value=self.u32(self.base+lookup+4*i)
                if value==0:break
                functions.append(dict(name=f'ordinal:{value & 0xffff}' if value & 0x80000000
                                      else self.string(self.base+value+2),iat=hex(self.base+iat+4*i)))
            result.append(dict(dll=self.string(self.base+name),functions=functions))
            cursor+=20
        return result


def instructions(path):
    for line in path.read_text().splitlines():
        match=re.match(r'\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*([^\t]+)\t?(.*)',line)
        if match:
            yield int(match[1],16),match[2].strip(),match[3].strip(),line


def main():
    pe=PE(EXE)
    assembly=ROOT/'hamsterball-4.2.asm'
    with assembly.open('w') as out:
        subprocess.run(['objdump','-d','--x86-asm-syntax=intel',str(EXE)],stdout=out,check=True)
    ins=list(instructions(assembly));by_address={a:(m,op,line) for a,m,op,line in ins}
    calls=collections.Counter()
    for address,mnemonic,operands,line in ins:
        match=re.match(r'0x([0-9a-f]+)',operands)
        if mnemonic=='call' and match:calls[int(match[1],16)]+=1
    # Runs of code pointers in .rdata are candidates, not confirmed C++ class boundaries.
    tables=[]
    rdata=next(s for s in pe.sections if s['name']=='.rdata')
    run=[]
    for offset in range(rdata['offset'],rdata['offset']+rdata['size']-3,4):
        value=struct.unpack_from('<I',pe.data,offset)[0]
        valid=value in by_address and 0x401000<=value<0x4de000
        if valid:run.append((offset,value))
        else:
            if len(run)>=4:tables.append(dict(address=hex(pe.address(run[0][0])),targets=[hex(v) for _,v in run]))
            run=[]
    starts=sorted(set(calls)|{int(v,16) for t in tables for v in t['targets']})
    strings={pe.address(m.start()):m.group().decode() for m in re.finditer(rb'[ -~]{5,}',pe.data)
             if m.start()>=0x1000}
    interesting=re.compile(r'Board \(|CAMERALOCUS|CAMERALOOKAT|START1-1|SAFESPOT|E:GRAVITY|E:SHRINK|N:GOAL|N:WAVY|N:SQUAREWOBBLY|Physics|Gravity|Friction|MouseSensitivity|Pause',re.I)
    anchors=[]
    for address,mnemonic,operands,line in ins:
        for token in re.findall(r'0x([0-9a-f]+)',operands):
            value=int(token,16);string=strings.get(value)
            if string and interesting.search(string):
                ix=bisect.bisect_right(starts,address)-1
                anchors.append(dict(instruction=hex(address),string_address=hex(value),string=string,
                                    nearby_entry_candidate=hex(starts[ix]) if ix>=0 else None,assembly=line.strip()))
    counts=collections.Counter(m for _,m,_,_ in ins)
    result=dict(sha256=hashlib.sha256(pe.data).hexdigest(),bytes=len(pe.data),machine=hex(pe.machine),
                base=hex(pe.base),entry=hex(pe.base+pe.entry_rva),image_size=pe.image_size,
                sections=pe.sections,debug_directory=pe.directories[6],clr_directory=pe.directories[14],
                imports=pe.imports(),direct_call_target_count=len(calls),
                code_pointer_run_count=len(tables),code_pointer_runs=tables,
                instruction_mnemonics=counts,anchors=anchors)
    (ROOT/'static-inventory.json').write_text(json.dumps(result,indent=2))
    (ROOT/'anchors.tsv').write_text('instruction\tentry_candidate\tstring_va\tstring\n'+'\n'.join(
        '\t'.join([a['instruction'],a['nearby_entry_candidate'] or '',a['string_address'],a['string']]) for a in anchors))
    # Constructor-initialized vptrs provide useful class anchors even without RTTI names.
    vptr_writes=[]
    for address,mnemonic,operands,line in ins:
        match=re.search(r'dword ptr \[(?:esi|edi|ebp|eax|ebx|ecx)\], 0x(4f[0-9a-f]+)$',operands)
        if mnemonic=='mov' and match:
            value=int(match[1],16)
            if 0x401000<=pe.u32(value)<0x4de000:vptr_writes.append((address,value))
    boundaries=sorted(set(v for _,v in vptr_writes))
    boards=[]
    for address,mnemonic,operands,line in ins:
        if mnemonic!='mov' or not re.search(r'\+ 0x868\], 0x',operands):continue
        value=int(operands.split('0x')[-1],16)
        try:name=pe.string(value)
        except ValueError:continue
        if not(name.startswith('Board') or name.startswith('RumbleBoard')):continue
        direct_starts=sorted(calls)
        start=direct_starts[bisect.bisect_right(direct_starts,address)-1]
        possible=[v for a,v in vptr_writes if start<=a<=address]
        table=possible[-1] if possible else None
        methods=[]
        if table:
            following=[v for v in boundaries if v>table]
            end=min(following[0] if following else table+240,table+240)
            for cursor in range(table,end,4):
                target=pe.u32(cursor)
                if not 0x401000<=target<0x4de000:break
                methods.append(hex(target))
        boards.append(dict(name=name,constructor_candidate=hex(start),name_assignment=hex(address),
                           vtable=hex(table) if table else None,method_candidates=methods))
    (ROOT/'board-map.json').write_text(json.dumps(boards,indent=2))
    print(json.dumps({k:result[k] for k in ['sha256','bytes','machine','entry','direct_call_target_count','code_pointer_run_count']}))
    print('Anchors:',len(anchors),'DLLs:',len(result['imports']))


if __name__=='__main__':main()
