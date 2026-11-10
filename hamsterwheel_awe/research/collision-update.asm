
source/hxgame4.2/hamsterball.exe:	file format coff-i386

Disassembly of section .text:

00401000 <.text>:
  462c00: 8b 45 00                     	mov	eax, dword ptr [ebp]
  462c03: 8b 4d 04                     	mov	ecx, dword ptr [ebp + 0x4]
  462c06: 8b 55 08                     	mov	edx, dword ptr [ebp + 0x8]
  462c09: 89 44 24 20                  	mov	dword ptr [esp + 0x20], eax
  462c0d: 89 4c 24 24                  	mov	dword ptr [esp + 0x24], ecx
  462c11: 89 54 24 28                  	mov	dword ptr [esp + 0x28], edx
  462c15: d9 44 24 28                  	fld	dword ptr [esp + 0x28]
  462c19: d8 4c 24 28                  	fmul	dword ptr [esp + 0x28]
  462c1d: d9 44 24 24                  	fld	dword ptr [esp + 0x24]
  462c21: d8 4c 24 24                  	fmul	dword ptr [esp + 0x24]
  462c25: de c1                        	faddp	st(1), st
  462c27: d9 44 24 20                  	fld	dword ptr [esp + 0x20]
  462c2b: d8 4c 24 20                  	fmul	dword ptr [esp + 0x20]
  462c2f: de c1                        	faddp	st(1), st
  462c31: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462c35: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462c39: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462c3f: df e0                        	fnstsw	ax
  462c41: f6 c4 41                     	test	ah, 0x41
  462c44: 7a 06                        	jp	0x462c4c <.text+0x61c4c>
  462c46: 89 5c 24 50                  	mov	dword ptr [esp + 0x50], ebx
  462c4a: eb 35                        	jmp	0x462c81 <.text+0x61c81>
  462c4c: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462c50: 83 ec 08                     	sub	esp, 0x8
  462c53: dd 1c 24                     	fstp	qword ptr [esp]
  462c56: e8 c9 7e 06 00               	call	0x4cab24 <.text+0xc9b24>
  462c5b: d9 5c 24 58                  	fstp	dword ptr [esp + 0x58]
  462c5f: 83 c4 08                     	add	esp, 0x8
  462c62: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462c66: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462c6c: df e0                        	fnstsw	ax
  462c6e: f6 c4 41                     	test	ah, 0x41
  462c71: 75 0e                        	jne	0x462c81 <.text+0x61c81>
  462c73: d9 05 a0 91 4f 00            	fld	dword ptr [0x4f91a0]
  462c79: d8 74 24 50                  	fdiv	dword ptr [esp + 0x50]
  462c7d: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462c81: d9 44 24 20                  	fld	dword ptr [esp + 0x20]
  462c85: 8d be a4 0c 00 00            	lea	edi, [esi + 0xca4]
  462c8b: d8 4c 24 50                  	fmul	dword ptr [esp + 0x50]
  462c8f: d9 5c 24 20                  	fstp	dword ptr [esp + 0x20]
  462c93: d9 44 24 24                  	fld	dword ptr [esp + 0x24]
  462c97: d8 4c 24 50                  	fmul	dword ptr [esp + 0x50]
  462c9b: d9 5c 24 24                  	fstp	dword ptr [esp + 0x24]
  462c9f: d9 44 24 28                  	fld	dword ptr [esp + 0x28]
  462ca3: d8 4c 24 50                  	fmul	dword ptr [esp + 0x50]
  462ca7: d9 5c 24 28                  	fstp	dword ptr [esp + 0x28]
  462cab: d9 44 24 28                  	fld	dword ptr [esp + 0x28]
  462caf: d8 4f 08                     	fmul	dword ptr [edi + 0x8]
  462cb2: d9 5c 24 14                  	fstp	dword ptr [esp + 0x14]
  462cb6: d9 44 24 24                  	fld	dword ptr [esp + 0x24]
  462cba: d8 4f 04                     	fmul	dword ptr [edi + 0x4]
  462cbd: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462cc1: d9 44 24 20                  	fld	dword ptr [esp + 0x20]
  462cc5: d8 0f                        	fmul	dword ptr [edi]
  462cc7: d9 5c 24 2c                  	fstp	dword ptr [esp + 0x2c]
  462ccb: d9 44 24 2c                  	fld	dword ptr [esp + 0x2c]
  462ccf: d8 4c 24 2c                  	fmul	dword ptr [esp + 0x2c]
  462cd3: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462cd7: d8 4c 24 50                  	fmul	dword ptr [esp + 0x50]
  462cdb: de c1                        	faddp	st(1), st
  462cdd: d9 44 24 14                  	fld	dword ptr [esp + 0x14]
  462ce1: d8 4c 24 14                  	fmul	dword ptr [esp + 0x14]
  462ce5: de c1                        	faddp	st(1), st
  462ce7: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462ceb: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462cef: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462cf5: df e0                        	fnstsw	ax
  462cf7: f6 c4 41                     	test	ah, 0x41
  462cfa: 7b 14                        	jnp	0x462d10 <.text+0x61d10>
  462cfc: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462d00: 83 ec 08                     	sub	esp, 0x8
  462d03: dd 1c 24                     	fstp	qword ptr [esp]
  462d06: e8 19 7e 06 00               	call	0x4cab24 <.text+0xc9b24>
  462d0b: dd d8                        	fstp	st(0)
  462d0d: 83 c4 08                     	add	esp, 0x8
  462d10: 8b 17                        	mov	edx, dword ptr [edi]
  462d12: 8b 4f 04                     	mov	ecx, dword ptr [edi + 0x4]
  462d15: 8b 47 08                     	mov	eax, dword ptr [edi + 0x8]
  462d18: 89 54 24 50                  	mov	dword ptr [esp + 0x50], edx
  462d1c: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462d20: 89 4c 24 14                  	mov	dword ptr [esp + 0x14], ecx
  462d24: d8 4c 24 50                  	fmul	dword ptr [esp + 0x50]
  462d28: 89 44 24 18                  	mov	dword ptr [esp + 0x18], eax
  462d2c: d9 44 24 14                  	fld	dword ptr [esp + 0x14]
  462d30: d8 4c 24 14                  	fmul	dword ptr [esp + 0x14]
  462d34: de c1                        	faddp	st(1), st
  462d36: d9 44 24 18                  	fld	dword ptr [esp + 0x18]
  462d3a: d8 4c 24 18                  	fmul	dword ptr [esp + 0x18]
  462d3e: de c1                        	faddp	st(1), st
  462d40: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462d44: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462d48: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462d4e: df e0                        	fnstsw	ax
  462d50: f6 c4 41                     	test	ah, 0x41
  462d53: 7a 06                        	jp	0x462d5b <.text+0x61d5b>
  462d55: 89 5c 24 14                  	mov	dword ptr [esp + 0x14], ebx
  462d59: eb 16                        	jmp	0x462d71 <.text+0x61d71>
  462d5b: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462d5f: 83 ec 08                     	sub	esp, 0x8
  462d62: dd 1c 24                     	fstp	qword ptr [esp]
  462d65: e8 ba 7d 06 00               	call	0x4cab24 <.text+0xc9b24>
  462d6a: d9 5c 24 1c                  	fstp	dword ptr [esp + 0x1c]
  462d6e: 83 c4 08                     	add	esp, 0x8
  462d71: d9 07                        	fld	dword ptr [edi]
  462d73: d8 45 00                     	fadd	dword ptr [ebp]
  462d76: d9 1f                        	fstp	dword ptr [edi]
  462d78: d9 45 04                     	fld	dword ptr [ebp + 0x4]
  462d7b: d8 47 04                     	fadd	dword ptr [edi + 0x4]
  462d7e: d9 5f 04                     	fstp	dword ptr [edi + 0x4]
  462d81: d9 45 08                     	fld	dword ptr [ebp + 0x8]
  462d84: d8 47 08                     	fadd	dword ptr [edi + 0x8]
  462d87: d9 5f 08                     	fstp	dword ptr [edi + 0x8]
  462d8a: 8b 17                        	mov	edx, dword ptr [edi]
  462d8c: 8b 4f 04                     	mov	ecx, dword ptr [edi + 0x4]
  462d8f: 8b 47 08                     	mov	eax, dword ptr [edi + 0x8]
  462d92: 89 54 24 50                  	mov	dword ptr [esp + 0x50], edx
  462d96: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462d9a: 89 4c 24 18                  	mov	dword ptr [esp + 0x18], ecx
  462d9e: d8 4c 24 50                  	fmul	dword ptr [esp + 0x50]
  462da2: 89 44 24 1c                  	mov	dword ptr [esp + 0x1c], eax
  462da6: d9 44 24 18                  	fld	dword ptr [esp + 0x18]
  462daa: d8 4c 24 18                  	fmul	dword ptr [esp + 0x18]
  462dae: de c1                        	faddp	st(1), st
  462db0: d9 44 24 1c                  	fld	dword ptr [esp + 0x1c]
  462db4: d8 4c 24 1c                  	fmul	dword ptr [esp + 0x1c]
  462db8: de c1                        	faddp	st(1), st
  462dba: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462dbe: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462dc2: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462dc8: df e0                        	fnstsw	ax
  462dca: f6 c4 41                     	test	ah, 0x41
  462dcd: 7a 06                        	jp	0x462dd5 <.text+0x61dd5>
  462dcf: 89 5c 24 50                  	mov	dword ptr [esp + 0x50], ebx
  462dd3: eb 16                        	jmp	0x462deb <.text+0x61deb>
  462dd5: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462dd9: 83 ec 08                     	sub	esp, 0x8
  462ddc: dd 1c 24                     	fstp	qword ptr [esp]
  462ddf: e8 40 7d 06 00               	call	0x4cab24 <.text+0xc9b24>
  462de4: d9 5c 24 58                  	fstp	dword ptr [esp + 0x58]
  462de8: 83 c4 08                     	add	esp, 0x8
  462deb: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462def: d8 9e 70 0c 00 00            	fcomp	dword ptr [esi + 0xc70]
  462df5: df e0                        	fnstsw	ax
  462df7: f6 c4 41                     	test	ah, 0x41
  462dfa: 0f 85 81 00 00 00            	jne	0x462e81 <.text+0x61e81>
  462e00: d9 44 24 14                  	fld	dword ptr [esp + 0x14]
  462e04: d8 9e 70 0c 00 00            	fcomp	dword ptr [esi + 0xc70]
  462e0a: df e0                        	fnstsw	ax
  462e0c: f6 c4 05                     	test	ah, 0x5
  462e0f: 7a 2c                        	jp	0x462e3d <.text+0x61e3d>
  462e11: 8b 86 70 0c 00 00            	mov	eax, dword ptr [esi + 0xc70]
  462e17: 89 44 24 1c                  	mov	dword ptr [esp + 0x1c], eax
  462e1b: 8b c7                        	mov	eax, edi
  462e1d: e8 ce 92 fa ff               	call	0x40c0f0 <.text+0xb0f0>
  462e22: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462e26: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462e2a: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462e30: df e0                        	fnstsw	ax
  462e32: f6 c4 41                     	test	ah, 0x41
  462e35: 75 2e                        	jne	0x462e65 <.text+0x61e65>
  462e37: d9 44 24 1c                  	fld	dword ptr [esp + 0x1c]
  462e3b: eb 20                        	jmp	0x462e5d <.text+0x61e5d>
  462e3d: 8b c7                        	mov	eax, edi
  462e3f: e8 ac 92 fa ff               	call	0x40c0f0 <.text+0xb0f0>
  462e44: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462e48: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462e4c: d8 1d b0 91 4f 00            	fcomp	dword ptr [0x4f91b0]
  462e52: df e0                        	fnstsw	ax
  462e54: f6 c4 41                     	test	ah, 0x41
  462e57: 75 0c                        	jne	0x462e65 <.text+0x61e65>
  462e59: d9 44 24 14                  	fld	dword ptr [esp + 0x14]
  462e5d: d8 74 24 50                  	fdiv	dword ptr [esp + 0x50]
  462e61: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462e65: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462e69: d8 0f                        	fmul	dword ptr [edi]
  462e6b: d9 1f                        	fstp	dword ptr [edi]
  462e6d: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462e71: d8 4f 04                     	fmul	dword ptr [edi + 0x4]
  462e74: d9 5f 04                     	fstp	dword ptr [edi + 0x4]
  462e77: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462e7b: d8 4f 08                     	fmul	dword ptr [edi + 0x8]
  462e7e: d9 5f 08                     	fstp	dword ptr [edi + 0x8]
  462e81: d9 05 a0 91 4f 00            	fld	dword ptr [0x4f91a0]
  462e87: 8d be a4 0c 00 00            	lea	edi, [esi + 0xca4]
  462e8d: d8 a6 68 0c 00 00            	fsub	dword ptr [esi + 0xc68]
  462e93: 88 5c 24 13                  	mov	byte ptr [esp + 0x13], bl
  462e97: d8 4c 24 58                  	fmul	dword ptr [esp + 0x58]
  462e9b: d9 05 a0 91 4f 00            	fld	dword ptr [0x4f91a0]
  462ea1: d8 64 24 58                  	fsub	dword ptr [esp + 0x58]
  462ea5: de c1                        	faddp	st(1), st
  462ea7: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462eab: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462eaf: d8 0f                        	fmul	dword ptr [edi]
  462eb1: d9 1f                        	fstp	dword ptr [edi]
  462eb3: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462eb7: d8 4f 04                     	fmul	dword ptr [edi + 0x4]
  462eba: d9 5f 04                     	fstp	dword ptr [edi + 0x4]
  462ebd: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462ec1: d8 4f 08                     	fmul	dword ptr [edi + 0x8]
  462ec4: d9 5f 08                     	fstp	dword ptr [edi + 0x8]
  462ec7: 8a 86 7c 0c 00 00            	mov	al, byte ptr [esi + 0xc7c]
  462ecd: 3a c3                        	cmp	al, bl
  462ecf: 75 32                        	jne	0x462f03 <.text+0x61f03>
  462ed1: 8b 44 24 4c                  	mov	eax, dword ptr [esp + 0x4c]
  462ed5: d9 47 08                     	fld	dword ptr [edi + 0x8]
  462ed8: d8 40 08                     	fadd	dword ptr [eax + 0x8]
  462edb: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462edf: d9 47 04                     	fld	dword ptr [edi + 0x4]
  462ee2: 8b 54 24 50                  	mov	edx, dword ptr [esp + 0x50]
  462ee6: d8 40 04                     	fadd	dword ptr [eax + 0x4]
  462ee9: 89 54 24 34                  	mov	dword ptr [esp + 0x34], edx
  462eed: d9 5c 24 4c                  	fstp	dword ptr [esp + 0x4c]
  462ef1: d9 00                        	fld	dword ptr [eax]
  462ef3: 8b 4c 24 4c                  	mov	ecx, dword ptr [esp + 0x4c]
  462ef7: d8 07                        	fadd	dword ptr [edi]
  462ef9: 89 4c 24 30                  	mov	dword ptr [esp + 0x30], ecx
  462efd: d9 5c 24 2c                  	fstp	dword ptr [esp + 0x2c]
  462f01: eb 3d                        	jmp	0x462f40 <.text+0x61f40>
  462f03: 8b 54 24 58                  	mov	edx, dword ptr [esp + 0x58]
  462f07: 8b 06                        	mov	eax, dword ptr [esi]
  462f09: 8d 4c 24 13                  	lea	ecx, [esp + 0x13]
  462f0d: 51                           	push	ecx
  462f0e: 8b 4c 24 58                  	mov	ecx, dword ptr [esp + 0x58]
  462f12: 52                           	push	edx
  462f13: 8b 54 24 54                  	mov	edx, dword ptr [esp + 0x54]
  462f17: 51                           	push	ecx
  462f18: 57                           	push	edi
  462f19: 52                           	push	edx
  462f1a: 8d 4c 24 4c                  	lea	ecx, [esp + 0x4c]
  462f1e: 51                           	push	ecx
  462f1f: 8b ce                        	mov	ecx, esi
  462f21: ff 50 1c                     	call	dword ptr [eax + 0x1c]
  462f24: 8d 54 24 2c                  	lea	edx, [esp + 0x2c]
  462f28: 3b d0                        	cmp	edx, eax
  462f2a: 74 14                        	je	0x462f40 <.text+0x61f40>
  462f2c: 8b 08                        	mov	ecx, dword ptr [eax]
  462f2e: 8b 50 04                     	mov	edx, dword ptr [eax + 0x4]
  462f31: 8b 40 08                     	mov	eax, dword ptr [eax + 0x8]
  462f34: 89 4c 24 2c                  	mov	dword ptr [esp + 0x2c], ecx
  462f38: 89 54 24 30                  	mov	dword ptr [esp + 0x30], edx
  462f3c: 89 44 24 34                  	mov	dword ptr [esp + 0x34], eax
  462f40: d9 44 24 58                  	fld	dword ptr [esp + 0x58]
  462f44: d8 8e 64 0c 00 00            	fmul	dword ptr [esi + 0xc64]
  462f4a: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462f4e: 8b 4c 24 50                  	mov	ecx, dword ptr [esp + 0x50]
  462f52: 89 4c 24 4c                  	mov	dword ptr [esp + 0x4c], ecx
  462f56: d9 44 24 4c                  	fld	dword ptr [esp + 0x4c]
  462f5a: d8 8e 94 0c 00 00            	fmul	dword ptr [esi + 0xc94]
  462f60: d9 5c 24 1c                  	fstp	dword ptr [esp + 0x1c]
  462f64: d9 44 24 4c                  	fld	dword ptr [esp + 0x4c]
  462f68: 8b 4c 24 1c                  	mov	ecx, dword ptr [esp + 0x1c]
  462f6c: d8 8e 90 0c 00 00            	fmul	dword ptr [esi + 0xc90]
  462f72: 89 4c 24 28                  	mov	dword ptr [esp + 0x28], ecx
  462f76: d9 5c 24 54                  	fstp	dword ptr [esp + 0x54]
  462f7a: d9 44 24 4c                  	fld	dword ptr [esp + 0x4c]
  462f7e: 8b 44 24 54                  	mov	eax, dword ptr [esp + 0x54]
  462f82: d8 8e 8c 0c 00 00            	fmul	dword ptr [esi + 0xc8c]
  462f88: 89 44 24 24                  	mov	dword ptr [esp + 0x24], eax
  462f8c: 38 5c 24 13                  	cmp	byte ptr [esp + 0x13], bl
  462f90: d9 5c 24 20                  	fstp	dword ptr [esp + 0x20]
  462f94: 8b 54 24 20                  	mov	edx, dword ptr [esp + 0x20]
  462f98: d9 44 24 50                  	fld	dword ptr [esp + 0x50]
  462f9c: 89 54 24 20                  	mov	dword ptr [esp + 0x20], edx
  462fa0: d8 0d f4 91 4f 00            	fmul	dword ptr [0x4f91f4]
  462fa6: d9 5c 24 4c                  	fstp	dword ptr [esp + 0x4c]
  462faa: d9 44 24 4c                  	fld	dword ptr [esp + 0x4c]
  462fae: d8 8e 94 0c 00 00            	fmul	dword ptr [esi + 0xc94]
  462fb4: d9 5c 24 54                  	fstp	dword ptr [esp + 0x54]
  462fb8: d9 44 24 4c                  	fld	dword ptr [esp + 0x4c]
  462fbc: d8 8e 90 0c 00 00            	fmul	dword ptr [esi + 0xc90]
  462fc2: d9 5c 24 50                  	fstp	dword ptr [esp + 0x50]
  462fc6: d9 44 24 4c                  	fld	dword ptr [esp + 0x4c]
  462fca: d8 8e 8c 0c 00 00            	fmul	dword ptr [esi + 0xc8c]
  462fd0: d9 5c 24 38                  	fstp	dword ptr [esp + 0x38]
  462fd4: d9 44 24 38                  	fld	dword ptr [esp + 0x38]
  462fd8: d8 44 24 20                  	fadd	dword ptr [esp + 0x20]
  462fdc: d9 5c 24 20                  	fstp	dword ptr [esp + 0x20]
  462fe0: d9 44 24 24                  	fld	dword ptr [esp + 0x24]
  462fe4: d8 44 24 50                  	fadd	dword ptr [esp + 0x50]
  462fe8: d9 5c 24 24                  	fstp	dword ptr [esp + 0x24]
  462fec: d9 44 24 28                  	fld	dword ptr [esp + 0x28]
  462ff0: d8 44 24 54                  	fadd	dword ptr [esp + 0x54]
  462ff4: d9 5c 24 28                  	fstp	dword ptr [esp + 0x28]
  462ff8: d9 44 24 20                  	fld	dword ptr [esp + 0x20]
  462ffc: d8 07                        	fadd	dword ptr [edi]
  462ffe: d9 1f                        	fstp	dword ptr [edi]
  463000: d9 44 24 24                  	fld	dword ptr [esp + 0x24]
  463004: d8 47 04                     	fadd	dword ptr [edi + 0x4]
  463007: d9 5f 04                     	fstp	dword ptr [edi + 0x4]
  46300a: d9 44 24 28                  	fld	dword ptr [esp + 0x28]
  46300e: d8 47 08                     	fadd	dword ptr [edi + 0x8]
  463011: d9 5f 08                     	fstp	dword ptr [edi + 0x8]
  463014: 75 5e                        	jne	0x463074 <.text+0x62074>
  463016: d9 44 24 58                  	fld	dword ptr [esp + 0x58]
  46301a: 8a 46 14                     	mov	al, byte ptr [esi + 0x14]
  46301d: 3a c3                        	cmp	al, bl
  46301f: d8 86 74 0c 00 00            	fadd	dword ptr [esi + 0xc74]
  463025: d9 9e 74 0c 00 00            	fstp	dword ptr [esi + 0xc74]
  46302b: 74 4d                        	je	0x46307a <.text+0x6207a>
  46302d: 6a 68                        	push	0x68
  46302f: e8 8e 78 06 00               	call	0x4ca8c2 <.text+0xc98c2>
  463034: 8b e8                        	mov	ebp, eax
  463036: 83 c4 04                     	add	esp, 0x4
  463039: 3b eb                        	cmp	ebp, ebx
  46303b: 74 07                        	je	0x463044 <.text+0x62044>
  46303d: e8 ee f6 ff ff               	call	0x462730 <.text+0x61730>
  463042: 8b dd                        	mov	ebx, ebp
  463044: 8d 43 48                     	lea	eax, [ebx + 0x48]
  463047: 3b c7                        	cmp	eax, edi
  463049: c7 03 05 00 00 00            	mov	dword ptr [ebx], 0x5
  46304f: 74 10                        	je	0x463061 <.text+0x62061>
  463051: 8b 17                        	mov	edx, dword ptr [edi]
  463053: 89 10                        	mov	dword ptr [eax], edx
  463055: 8b 4f 04                     	mov	ecx, dword ptr [edi + 0x4]
  463058: 89 48 04                     	mov	dword ptr [eax + 0x4], ecx
  46305b: 8b 57 08                     	mov	edx, dword ptr [edi + 0x8]
  46305e: 89 50 08                     	mov	dword ptr [eax + 0x8], edx
  463061: 8b 86 74 0c 00 00            	mov	eax, dword ptr [esi + 0xc74]
  463067: 83 c6 18                     	add	esi, 0x18
  46306a: 89 43 54                     	mov	dword ptr [ebx + 0x54], eax
  46306d: e8 0e cb ff ff               	call	0x45fb80 <.text+0x5eb80>
  463072: eb 06                        	jmp	0x46307a <.text+0x6207a>
  463074: 89 9e 74 0c 00 00            	mov	dword ptr [esi + 0xc74], ebx
  46307a: 8b 44 24 48                  	mov	eax, dword ptr [esp + 0x48]
  46307e: 5f                           	pop	edi
  46307f: 5e                           	pop	esi
  463080: 8d 4c 24 24                  	lea	ecx, [esp + 0x24]
  463084: 3b c1                        	cmp	eax, ecx
  463086: 5d                           	pop	ebp
  463087: 5b                           	pop	ebx
  463088: 74 14                        	je	0x46309e <.text+0x6209e>
  46308a: 8b 54 24 1c                  	mov	edx, dword ptr [esp + 0x1c]
  46308e: 8b 4c 24 20                  	mov	ecx, dword ptr [esp + 0x20]
  463092: 89 10                        	mov	dword ptr [eax], edx
  463094: 8b 54 24 24                  	mov	edx, dword ptr [esp + 0x24]
  463098: 89 48 04                     	mov	dword ptr [eax + 0x4], ecx
  46309b: 89 50 08                     	mov	dword ptr [eax + 0x8], edx
  46309e: 83 c4 34                     	add	esp, 0x34
  4630a1: c2 14 00                     	ret	0x14
  4630a4: 90                           	nop
  4630a5: 90                           	nop
  4630a6: 90                           	nop
  4630a7: 90                           	nop
  4630a8: 90                           	nop
  4630a9: 90                           	nop
  4630aa: 90                           	nop
  4630ab: 90                           	nop
  4630ac: 90                           	nop
  4630ad: 90                           	nop
  4630ae: 90                           	nop
  4630af: 90                           	nop
