0041dec0	PUSH EBP
0041dec1	MOV EBP,ESP
0041dec3	AND ESP,0xfffffff8
0041dec6	SUB ESP,0x14
0041dec9	PUSH ESI
0041deca	MOV ESI,ECX
0041decc	CALL 0x0040fbc0
0041ded1	FLD float ptr [ESI + 0x6420]
0041ded7	FSUB double ptr [0x004f9238]
0041dedd	XOR ECX,ECX
0041dedf	FSTP double ptr [ESP + 0x10]
0041dee3	FLD double ptr [ESP + 0x10]
0041dee7	FCOMP double ptr [0x004f9190]
0041deed	FNSTSW AX
0041deef	TEST AH,0x41
0041def2	JNZ 0x0041df06
0041def4	MOV EAX,dword ptr [ESP + 0x10]
0041def8	MOV EDX,dword ptr [ESP + 0x14]
0041defc	MOV dword ptr [ESP + 0x8],EAX
0041df00	MOV dword ptr [ESP + 0xc],EDX
0041df04	JMP 0x0041df0e
0041df06	MOV dword ptr [ESP + 0x8],ECX
0041df0a	MOV dword ptr [ESP + 0xc],ECX
0041df0e	FLD double ptr [ESP + 0x8]
0041df12	FSTP float ptr [ESI + 0x6420]
0041df18	FLD float ptr [ESI + 0x6424]
0041df1e	FSUB double ptr [0x004f9238]
0041df24	FSTP double ptr [ESP + 0x10]
0041df28	FLD double ptr [ESP + 0x10]
0041df2c	FCOMP double ptr [0x004f9190]
0041df32	FNSTSW AX
0041df34	TEST AH,0x41
0041df37	JNZ 0x0041df4b
0041df39	MOV EAX,dword ptr [ESP + 0x10]
0041df3d	MOV EDX,dword ptr [ESP + 0x14]
0041df41	MOV dword ptr [ESP + 0x8],EAX
0041df45	MOV dword ptr [ESP + 0xc],EDX
0041df49	JMP 0x0041df53
0041df4b	MOV dword ptr [ESP + 0x8],ECX
0041df4f	MOV dword ptr [ESP + 0xc],ECX
0041df53	FLD double ptr [ESP + 0x8]
0041df57	FSTP float ptr [ESI + 0x6424]
0041df5d	FLD float ptr [ESI + 0x6428]
0041df63	FSUB double ptr [0x004f9238]
0041df69	FSTP double ptr [ESP + 0x10]
0041df6d	FLD double ptr [ESP + 0x10]
0041df71	FCOMP double ptr [0x004f9190]
0041df77	FNSTSW AX
0041df79	TEST AH,0x41
0041df7c	JNZ 0x0041df90
0041df7e	MOV EAX,dword ptr [ESP + 0x10]
0041df82	MOV EDX,dword ptr [ESP + 0x14]
0041df86	MOV dword ptr [ESP + 0x8],EAX
0041df8a	MOV dword ptr [ESP + 0xc],EDX
0041df8e	JMP 0x0041df98
0041df90	MOV dword ptr [ESP + 0x8],ECX
0041df94	MOV dword ptr [ESP + 0xc],ECX
0041df98	FLD double ptr [ESP + 0x8]
0041df9c	FSTP float ptr [ESI + 0x6428]
0041dfa2	FLD float ptr [ESI + 0x642c]
0041dfa8	FSUB double ptr [0x004f9238]
0041dfae	FSTP double ptr [ESP + 0x10]
0041dfb2	FLD double ptr [ESP + 0x10]
0041dfb6	FCOMP double ptr [0x004f9190]
0041dfbc	FNSTSW AX
0041dfbe	TEST AH,0x41
0041dfc1	JNZ 0x0041dfd5
0041dfc3	MOV EAX,dword ptr [ESP + 0x10]
0041dfc7	MOV EDX,dword ptr [ESP + 0x14]
0041dfcb	MOV dword ptr [ESP + 0x8],EAX
0041dfcf	MOV dword ptr [ESP + 0xc],EDX
0041dfd3	JMP 0x0041dfdd
0041dfd5	MOV dword ptr [ESP + 0x8],ECX
0041dfd9	MOV dword ptr [ESP + 0xc],ECX
0041dfdd	FLD double ptr [ESP + 0x8]
0041dfe1	FSTP float ptr [ESI + 0x642c]
0041dfe7	FLD float ptr [ESI + 0x6430]
0041dfed	FSUB double ptr [0x004f9238]
0041dff3	FSTP double ptr [ESP + 0x10]
0041dff7	FLD double ptr [ESP + 0x10]
0041dffb	FCOMP double ptr [0x004f9190]
0041e001	FNSTSW AX
0041e003	TEST AH,0x41
0041e006	JNZ 0x0041e01a
0041e008	MOV EAX,dword ptr [ESP + 0x10]
0041e00c	MOV EDX,dword ptr [ESP + 0x14]
0041e010	MOV dword ptr [ESP + 0x8],EAX
0041e014	MOV dword ptr [ESP + 0xc],EDX
0041e018	JMP 0x0041e022
0041e01a	MOV dword ptr [ESP + 0x8],ECX
0041e01e	MOV dword ptr [ESP + 0xc],ECX
0041e022	FLD double ptr [ESP + 0x8]
0041e026	FSTP float ptr [ESI + 0x6430]
0041e02c	FLD float ptr [ESI + 0x6434]
0041e032	FSUB double ptr [0x004f9238]
0041e038	FSTP double ptr [ESP + 0x10]
0041e03c	FLD double ptr [ESP + 0x10]
0041e040	FCOMP double ptr [0x004f9190]
0041e046	FNSTSW AX
0041e048	TEST AH,0x41
0041e04b	JNZ 0x0041e05f
0041e04d	MOV EAX,dword ptr [ESP + 0x10]
0041e051	MOV EDX,dword ptr [ESP + 0x14]
0041e055	MOV dword ptr [ESP + 0x8],EAX
0041e059	MOV dword ptr [ESP + 0xc],EDX
0041e05d	JMP 0x0041e067
0041e05f	MOV dword ptr [ESP + 0x8],ECX
0041e063	MOV dword ptr [ESP + 0xc],ECX
0041e067	FLD double ptr [ESP + 0x8]
0041e06b	FSTP float ptr [ESI + 0x6434]
0041e071	FLD float ptr [ESI + 0x6438]
0041e077	FSUB double ptr [0x004f9238]
0041e07d	FSTP double ptr [ESP + 0x10]
0041e081	FLD double ptr [ESP + 0x10]
0041e085	FCOMP double ptr [0x004f9190]
0041e08b	FNSTSW AX
0041e08d	TEST AH,0x41
0041e090	JNZ 0x0041e0a4
0041e092	MOV EAX,dword ptr [ESP + 0x10]
0041e096	MOV EDX,dword ptr [ESP + 0x14]
0041e09a	MOV dword ptr [ESP + 0x8],EAX
0041e09e	MOV dword ptr [ESP + 0xc],EDX
0041e0a2	JMP 0x0041e0ac
0041e0a4	MOV dword ptr [ESP + 0x8],ECX
0041e0a8	MOV dword ptr [ESP + 0xc],ECX
0041e0ac	FLD double ptr [ESP + 0x8]
0041e0b0	FSTP float ptr [ESI + 0x6438]
0041e0b6	FLD float ptr [ESI + 0x643c]
0041e0bc	FSUB double ptr [0x004f9238]
0041e0c2	FSTP double ptr [ESP + 0x10]
0041e0c6	FLD double ptr [ESP + 0x10]
0041e0ca	FCOMP double ptr [0x004f9190]
0041e0d0	FNSTSW AX
0041e0d2	TEST AH,0x41
0041e0d5	JNZ 0x0041e0f6
0041e0d7	MOV EAX,dword ptr [ESP + 0x10]
0041e0db	MOV ECX,dword ptr [ESP + 0x14]
0041e0df	MOV dword ptr [ESP + 0x8],EAX
0041e0e3	MOV dword ptr [ESP + 0xc],ECX
0041e0e7	FLD double ptr [ESP + 0x8]
0041e0eb	FSTP float ptr [ESI + 0x643c]
0041e0f1	POP ESI
0041e0f2	MOV ESP,EBP
0041e0f4	POP EBP
0041e0f5	RET
0041e0f6	MOV dword ptr [ESP + 0x8],ECX
0041e0fa	MOV dword ptr [ESP + 0xc],ECX
0041e0fe	FLD double ptr [ESP + 0x8]
0041e102	FSTP float ptr [ESI + 0x643c]
0041e108	POP ESI
0041e109	MOV ESP,EBP
0041e10b	POP EBP
0041e10c	RET
