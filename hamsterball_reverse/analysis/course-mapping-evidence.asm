
; Evidence range 0x414240..0x4142da
  414240: 64 a1 00 00 00 00            	mov	eax, dword ptr fs:[0x0]
  414246: 6a ff                        	push	-0x1
  414248: 68 48 ca 4d 00               	push	0x4dca48
  41424d: 50                           	push	eax
  41424e: 8b 44 24 14                  	mov	eax, dword ptr [esp + 0x14]
  414252: 64 89 25 00 00 00 00         	mov	dword ptr fs:[0x0], esp
  414259: 56                           	push	esi
  41425a: 8b 74 24 14                  	mov	esi, dword ptr [esp + 0x14]
  41425e: 50                           	push	eax
  41425f: 56                           	push	esi
  414260: e8 ab 8a ff ff               	call	0x40cd10 <.text+0xbd10>
  414265: 8b 56 14                     	mov	edx, dword ptr [esi + 0x14]
  414268: c7 06 d8 82 4f 00            	mov	dword ptr [esi], 0x4f82d8
  41426e: c7 86 68 08 00 00 2c d6 50 00	mov	dword ptr [esi + 0x868], 0x50d62c
  414278: c7 86 b0 29 00 00 3c d6 50 00	mov	dword ptr [esi + 0x29b0], 0x50d63c
  414282: 8b 82 dc 01 00 00            	mov	eax, dword ptr [edx + 0x1dc]
  414288: 89 86 70 08 00 00            	mov	dword ptr [esi + 0x870], eax
  41428e: b8 00 00 80 3f               	mov	eax, 0x3f800000
  414293: 33 c9                        	xor	ecx, ecx
  414295: 68 4c d6 50 00               	push	0x50d64c
  41429a: 56                           	push	esi
  41429b: 89 4c 24 14                  	mov	dword ptr [esp + 0x14], ecx
  41429f: 89 86 08 15 00 00            	mov	dword ptr [esi + 0x1508], eax
  4142a5: 89 8e 0c 15 00 00            	mov	dword ptr [esi + 0x150c], ecx
  4142ab: 89 86 10 15 00 00            	mov	dword ptr [esi + 0x1510], eax
  4142b1: 89 86 14 15 00 00            	mov	dword ptr [esi + 0x1514], eax
  4142b7: e8 c4 fa ff ff               	call	0x413d80 <.text+0x12d80>
  4142bc: 8b 4c 24 04                  	mov	ecx, dword ptr [esp + 0x4]
  4142c0: c7 86 38 43 00 00 5c d6 50 00	mov	dword ptr [esi + 0x4338], 0x50d65c
  4142ca: 8b c6                        	mov	eax, esi
  4142cc: 64 89 0d 00 00 00 00         	mov	dword ptr fs:[0x0], ecx
  4142d3: 5e                           	pop	esi
  4142d4: 83 c4 0c                     	add	esp, 0xc
  4142d7: c2 08 00                     	ret	0x8

; Evidence range 0x414310..0x4143ce
  414310: 6a ff                        	push	-0x1
  414312: 68 56 c2 4d 00               	push	0x4dc256
  414317: 64 a1 00 00 00 00            	mov	eax, dword ptr fs:[0x0]
  41431d: 50                           	push	eax
  41431e: 64 89 25 00 00 00 00         	mov	dword ptr fs:[0x0], esp
  414325: 51                           	push	ecx
  414326: 56                           	push	esi
  414327: 68 d0 10 00 00               	push	0x10d0
  41432c: 8b f1                        	mov	esi, ecx
  41432e: e8 8f 65 0b 00               	call	0x4ca8c2 <.text+0xc98c2>
  414333: 83 c4 04                     	add	esp, 0x4
  414336: 89 44 24 04                  	mov	dword ptr [esp + 0x4], eax
  41433a: 85 c0                        	test	eax, eax
  41433c: c7 44 24 10 00 00 00 00      	mov	dword ptr [esp + 0x10], 0x0
  414344: 74 1a                        	je	0x414360 <.text+0x13360>
  414346: 8b 8e 78 08 00 00            	mov	ecx, dword ptr [esi + 0x878]
  41434c: 8b 91 74 01 00 00            	mov	edx, dword ptr [ecx + 0x174]
  414352: 68 6c d6 50 00               	push	0x50d66c
  414357: 52                           	push	edx
  414358: 50                           	push	eax
  414359: e8 62 85 05 00               	call	0x46c8c0 <.text+0x6b8c0>
  41435e: eb 02                        	jmp	0x414362 <.text+0x13362>
  414360: 33 c0                        	xor	eax, eax
  414362: 68 d0 10 00 00               	push	0x10d0
  414367: c7 44 24 14 ff ff ff ff      	mov	dword ptr [esp + 0x14], 0xffffffff
  41436f: 89 86 ac 08 00 00            	mov	dword ptr [esi + 0x8ac], eax
  414375: e8 48 65 0b 00               	call	0x4ca8c2 <.text+0xc98c2>
  41437a: 83 c4 04                     	add	esp, 0x4
  41437d: 89 44 24 04                  	mov	dword ptr [esp + 0x4], eax
  414381: 85 c0                        	test	eax, eax
  414383: c7 44 24 10 01 00 00 00      	mov	dword ptr [esp + 0x10], 0x1
  41438b: 74 10                        	je	0x41439d <.text+0x1339d>
  41438d: 57                           	push	edi
  41438e: 8b be ac 08 00 00            	mov	edi, dword ptr [esi + 0x8ac]
  414394: 50                           	push	eax
  414395: e8 66 13 05 00               	call	0x465700 <.text+0x64700>
  41439a: 5f                           	pop	edi
  41439b: eb 02                        	jmp	0x41439f <.text+0x1339f>
  41439d: 33 c0                        	xor	eax, eax
  41439f: 8b ce                        	mov	ecx, esi
  4143a1: c7 44 24 10 ff ff ff ff      	mov	dword ptr [esp + 0x10], 0xffffffff
  4143a9: 89 86 b0 08 00 00            	mov	dword ptr [esi + 0x8b0], eax
  4143af: e8 ec 97 ff ff               	call	0x40dba0 <.text+0xcba0>
  4143b4: 8b 06                        	mov	eax, dword ptr [esi]
  4143b6: 8b ce                        	mov	ecx, esi
  4143b8: ff 90 80 00 00 00            	call	dword ptr [eax + 0x80]
  4143be: 8b 4c 24 08                  	mov	ecx, dword ptr [esp + 0x8]
  4143c2: 5e                           	pop	esi
  4143c3: 64 89 0d 00 00 00 00         	mov	dword ptr fs:[0x0], ecx
  4143ca: 83 c4 10                     	add	esp, 0x10
  4143cd: c3                           	ret

; Evidence range 0x41dab0..0x41db80
  41dab0: 64 a1 00 00 00 00            	mov	eax, dword ptr fs:[0x0]
  41dab6: 6a ff                        	push	-0x1
  41dab8: 68 f3 c5 4d 00               	push	0x4dc5f3
  41dabd: 50                           	push	eax
  41dabe: 8b 44 24 14                  	mov	eax, dword ptr [esp + 0x14]
  41dac2: 64 89 25 00 00 00 00         	mov	dword ptr fs:[0x0], esp
  41dac9: 56                           	push	esi
  41daca: 8b 74 24 14                  	mov	esi, dword ptr [esp + 0x14]
  41dace: 50                           	push	eax
  41dacf: 56                           	push	esi
  41dad0: e8 3b f2 fe ff               	call	0x40cd10 <.text+0xbd10>
  41dad5: 68 50 fb 45 00               	push	0x45fb50
  41dada: 68 10 b4 41 00               	push	0x41b410
  41dadf: 6a 08                        	push	0x8
  41dae1: 68 18 04 00 00               	push	0x418
  41dae6: 8d 8e 60 43 00 00            	lea	ecx, [esi + 0x4360]
  41daec: 51                           	push	ecx
  41daed: c7 44 24 20 00 00 00 00      	mov	dword ptr [esp + 0x20], 0x0
  41daf5: c7 06 d8 89 4f 00            	mov	dword ptr [esi], 0x4f89d8
  41dafb: e8 eb d2 0a 00               	call	0x4cadeb <.text+0xc9deb>
  41db00: 8b 56 14                     	mov	edx, dword ptr [esi + 0x14]
  41db03: c7 86 68 08 00 00 a8 e2 50 00	mov	dword ptr [esi + 0x868], 0x50e2a8
  41db0d: c7 86 b0 29 00 00 bc e2 50 00	mov	dword ptr [esi + 0x29b0], 0x50e2bc
  41db17: 8b 82 dc 01 00 00            	mov	eax, dword ptr [edx + 0x1dc]
  41db1d: 89 86 70 08 00 00            	mov	dword ptr [esi + 0x870], eax
  41db23: b8 00 00 80 3f               	mov	eax, 0x3f800000
  41db28: 68 cc e2 50 00               	push	0x50e2cc
  41db2d: 56                           	push	esi
  41db2e: c6 44 24 14 01               	mov	byte ptr [esp + 0x14], 0x1
  41db33: 89 86 08 15 00 00            	mov	dword ptr [esi + 0x1508], eax
  41db39: c7 86 0c 15 00 00 00 00 40 3f	mov	dword ptr [esi + 0x150c], 0x3f400000
  41db43: c7 86 10 15 00 00 00 00 80 3e	mov	dword ptr [esi + 0x1510], 0x3e800000
  41db4d: 89 86 14 15 00 00            	mov	dword ptr [esi + 0x1514], eax
  41db53: e8 28 62 ff ff               	call	0x413d80 <.text+0x12d80>
  41db58: 8b 4c 24 04                  	mov	ecx, dword ptr [esp + 0x4]
  41db5c: c7 86 38 43 00 00 d8 e2 50 00	mov	dword ptr [esi + 0x4338], 0x50e2d8
  41db66: 8b c6                        	mov	eax, esi
  41db68: 64 89 0d 00 00 00 00         	mov	dword ptr fs:[0x0], ecx
  41db6f: 5e                           	pop	esi
  41db70: 83 c4 0c                     	add	esp, 0xc
  41db73: c2 08 00                     	ret	0x8
  41db76: 90                           	nop
  41db77: 90                           	nop
  41db78: 90                           	nop
  41db79: 90                           	nop
  41db7a: 90                           	nop
  41db7b: 90                           	nop
  41db7c: 90                           	nop
  41db7d: 90                           	nop
  41db7e: 90                           	nop
  41db7f: 90                           	nop

; Evidence range 0x41dc10..0x41dd30
  41dc10: 6a ff                        	push	-0x1
  41dc12: 68 56 c2 4d 00               	push	0x4dc256
  41dc17: 64 a1 00 00 00 00            	mov	eax, dword ptr fs:[0x0]
  41dc1d: 50                           	push	eax
  41dc1e: 64 89 25 00 00 00 00         	mov	dword ptr fs:[0x0], esp
  41dc25: 51                           	push	ecx
  41dc26: 53                           	push	ebx
  41dc27: 55                           	push	ebp
  41dc28: 56                           	push	esi
  41dc29: 57                           	push	edi
  41dc2a: 68 d0 10 00 00               	push	0x10d0
  41dc2f: 8b d9                        	mov	ebx, ecx
  41dc31: e8 8c cc 0a 00               	call	0x4ca8c2 <.text+0xc98c2>
  41dc36: 83 c4 04                     	add	esp, 0x4
  41dc39: 89 44 24 10                  	mov	dword ptr [esp + 0x10], eax
  41dc3d: 85 c0                        	test	eax, eax
  41dc3f: c7 44 24 1c 00 00 00 00      	mov	dword ptr [esp + 0x1c], 0x0
  41dc47: 74 1a                        	je	0x41dc63 <.text+0x1cc63>
  41dc49: 8b 8b 78 08 00 00            	mov	ecx, dword ptr [ebx + 0x878]
  41dc4f: 8b 91 74 01 00 00            	mov	edx, dword ptr [ecx + 0x174]
  41dc55: 68 e8 e2 50 00               	push	0x50e2e8
  41dc5a: 52                           	push	edx
  41dc5b: 50                           	push	eax
  41dc5c: e8 5f ec 04 00               	call	0x46c8c0 <.text+0x6b8c0>
  41dc61: eb 02                        	jmp	0x41dc65 <.text+0x1cc65>
  41dc63: 33 c0                        	xor	eax, eax
  41dc65: 83 ce ff                     	or	esi, -0x1
  41dc68: 68 d0 10 00 00               	push	0x10d0
  41dc6d: 89 74 24 20                  	mov	dword ptr [esp + 0x20], esi
  41dc71: 89 83 ac 08 00 00            	mov	dword ptr [ebx + 0x8ac], eax
  41dc77: e8 46 cc 0a 00               	call	0x4ca8c2 <.text+0xc98c2>
  41dc7c: 83 c4 04                     	add	esp, 0x4
  41dc7f: 89 44 24 10                  	mov	dword ptr [esp + 0x10], eax
  41dc83: 85 c0                        	test	eax, eax
  41dc85: c7 44 24 1c 01 00 00 00      	mov	dword ptr [esp + 0x1c], 0x1
  41dc8d: 74 0e                        	je	0x41dc9d <.text+0x1cc9d>
  41dc8f: 8b bb ac 08 00 00            	mov	edi, dword ptr [ebx + 0x8ac]
  41dc95: 50                           	push	eax
  41dc96: e8 65 7a 04 00               	call	0x465700 <.text+0x64700>
  41dc9b: eb 02                        	jmp	0x41dc9f <.text+0x1cc9f>
  41dc9d: 33 c0                        	xor	eax, eax
  41dc9f: 8b cb                        	mov	ecx, ebx
  41dca1: 89 74 24 1c                  	mov	dword ptr [esp + 0x1c], esi
  41dca5: 89 83 b0 08 00 00            	mov	dword ptr [ebx + 0x8b0], eax
  41dcab: e8 f0 fe fe ff               	call	0x40dba0 <.text+0xcba0>
  41dcb0: 8b 03                        	mov	eax, dword ptr [ebx]
  41dcb2: 8b cb                        	mov	ecx, ebx
  41dcb4: ff 90 80 00 00 00            	call	dword ptr [eax + 0x80]
  41dcba: 8d 8b 60 43 00 00            	lea	ecx, [ebx + 0x4360]
  41dcc0: 33 c0                        	xor	eax, eax
  41dcc2: 8d ab 20 64 00 00            	lea	ebp, [ebx + 0x6420]
  41dcc8: 89 4c 24 10                  	mov	dword ptr [esp + 0x10], ecx
  41dccc: 8d 64 24 00                  	lea	esp, [esp]
  41dcd0: 8b 54 24 10                  	mov	edx, dword ptr [esp + 0x10]
  41dcd4: 52                           	push	edx
  41dcd5: 8d 78 01                     	lea	edi, [eax + 0x1]
  41dcd8: 57                           	push	edi
  41dcd9: 68 fc e2 50 00               	push	0x50e2fc
  41dcde: be b8 f1 50 00               	mov	esi, 0x50f1b8
  41dce3: e8 c8 dc 04 00               	call	0x46b9b0 <.text+0x6a9b0>
  41dce8: 8b 8b ac 08 00 00            	mov	ecx, dword ptr [ebx + 0x8ac]
  41dcee: 83 c4 08                     	add	esp, 0x8
  41dcf1: 50                           	push	eax
  41dcf2: e8 79 36 05 00               	call	0x471370 <.text+0x70370>
  41dcf7: 8b 54 24 10                  	mov	edx, dword ptr [esp + 0x10]
  41dcfb: c7 45 00 00 00 00 00         	mov	dword ptr [ebp], 0x0
  41dd02: 8b c7                        	mov	eax, edi
  41dd04: 81 c2 18 04 00 00            	add	edx, 0x418
  41dd0a: 83 c5 04                     	add	ebp, 0x4
  41dd0d: 83 f8 08                     	cmp	eax, 0x8
  41dd10: 89 54 24 10                  	mov	dword ptr [esp + 0x10], edx
  41dd14: 7c ba                        	jl	0x41dcd0 <.text+0x1ccd0>
  41dd16: 8b 4c 24 14                  	mov	ecx, dword ptr [esp + 0x14]
  41dd1a: 5f                           	pop	edi
  41dd1b: 5e                           	pop	esi
  41dd1c: 5d                           	pop	ebp
  41dd1d: 5b                           	pop	ebx
  41dd1e: 64 89 0d 00 00 00 00         	mov	dword ptr fs:[0x0], ecx
  41dd25: 83 c4 10                     	add	esp, 0x10
  41dd28: c3                           	ret
  41dd29: 90                           	nop
  41dd2a: 90                           	nop
  41dd2b: 90                           	nop
  41dd2c: 90                           	nop
  41dd2d: 90                           	nop
  41dd2e: 90                           	nop
  41dd2f: 90                           	nop
