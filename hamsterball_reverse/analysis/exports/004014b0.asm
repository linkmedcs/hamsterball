004014b0	SUB ESP,0x14
004014b3	MOV ECX,dword ptr [ESP + 0x18]
004014b7	FLD float ptr [ESP + 0x18]
004014bb	MOV dword ptr [EAX + 0xc64],ECX
004014c1	FMUL float ptr [EAX + 0xc94]
004014c7	ADD EAX,0xc98
004014cc	LEA EDX,[ESP + 0x8]
004014d0	CMP EAX,EDX
004014d2	FSTP float ptr [ESP + 0x4]
004014d6	FLD float ptr [ESP + 0x18]
004014da	FMUL float ptr [EAX + -0x8]
004014dd	FSTP float ptr [ESP]
004014e1	FLD float ptr [ESP + 0x18]
004014e5	FMUL float ptr [EAX + -0xc]
004014e8	FSTP float ptr [ESP + 0x8]
004014ec	JZ 0x00401502
004014ee	MOV ECX,dword ptr [ESP + 0x8]
004014f2	MOV EDX,dword ptr [ESP]
004014f6	MOV dword ptr [EAX],ECX
004014f8	MOV ECX,dword ptr [ESP + 0x4]
004014fc	MOV dword ptr [EAX + 0x4],EDX
004014ff	MOV dword ptr [EAX + 0x8],ECX
00401502	ADD ESP,0x14
00401505	RET 0x4
