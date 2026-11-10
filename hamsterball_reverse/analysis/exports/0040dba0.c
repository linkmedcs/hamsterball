/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040dba0 name: FUN_0040dba0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040dba0(int param_1)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char acStack_424 [4];
  
  acStack_424[0] = -0x4a;
  acStack_424[1] = -0x25;
  acStack_424[2] = '@';
  acStack_424[3] = '\0';
  piVar3 = operator_new(0x80);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = (int)&PTR_LAB_004f5b6c;
    piVar3[1] = 0;
    piVar3[2] = 0;
    piVar3[3] = 0;
    piVar3[4] = 0;
    piVar3[5] = 0;
    piVar3[6] = 0;
  }
  acStack_424[0] = '\0';
  acStack_424[1] = '\0';
  acStack_424[2] = 'H';
  acStack_424[3] = -0x3e;
  *(int **)(param_1 + 0x87c) = piVar3;
  (**(code **)(*piVar3 + 8))(0);
  (**(code **)(**(int **)(param_1 + 0x87c) + 0xc))
            (acStack_424 + 0xc,*(undefined4 *)(param_1 + 0x29bc));
  (**(code **)(**(int **)(*(int *)(param_1 + 0x878) + 0x174) + 4))(*(undefined4 *)(param_1 + 0x87c))
  ;
  if (*(int **)(param_1 + 0x8ac) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x8ac) + 4))();
    uVar4 = FUN_0042bd10();
    iVar5 = *(int *)(*(int *)(param_1 + 0x878) + 0x174);
    piVar3 = *(int **)(iVar5 + 0x154);
    (**(code **)(*piVar3 + 200))(piVar3,0x22,uVar4);
    *(uint *)(iVar5 + 0x738) = uVar4;
    uVar4 = FUN_0042bd10();
    iVar5 = *(int *)(*(int *)(param_1 + 0x878) + 0x174);
    piVar3 = *(int **)(iVar5 + 0x154);
    (**(code **)(*piVar3 + 200))(piVar3,0x8b,uVar4);
    *(uint *)(iVar5 + 0x730) = uVar4;
    FUN_00471240();
    *(undefined4 *)(param_1 + 0x3f18) = 0;
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x878) + 0x220) + 0x12) == '\0') {
      iVar5 = FUN_004716b0(s_CAMERALOCUS_0050d1f0);
      *(int *)(param_1 + 0x3f18) = iVar5;
      if (iVar5 != 0) {
        *(int *)(param_1 + 0x3f1c) = iVar5;
        *(undefined4 *)(param_1 + 0x3f20) = 0;
      }
    }
  }
  iVar5 = *(int *)(param_1 + 0x878);
  *(undefined4 *)(param_1 + 0x870) = *(undefined4 *)(iVar5 + 0x240);
  *(undefined4 *)(*(int *)(iVar5 + 0x294) + 4) = *(undefined4 *)(*(int *)(iVar5 + 0x298) + 4);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x878) + 0x2b4) + 4) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x878) + 0x2b8) + 4);
  FUN_00428d70();
  iVar5 = *(int *)(param_1 + 0x878);
  if (*(char *)(iVar5 + 0x236) != '\0') {
    *(undefined4 *)(*(int *)(iVar5 + 0x294) + 4) = *(undefined4 *)(*(int *)(iVar5 + 0x2a0) + 4);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x878) + 0x2b4) + 4) =
         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x878) + 0x2c0) + 4);
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x878) + 0x174);
  piVar3 = *(int **)(iVar5 + 0x154);
  (**(code **)(*piVar3 + 200))(piVar3,0x1c,1);
  *(undefined1 *)(iVar5 + 0x734) = 1;
  fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 0x878) + 0x174) + 0x188);
  FUN_004614c0(20.0,(fVar1 + fVar1) * _DAT_004f94c0 + _DAT_004f94bc);
  iVar5 = *(int *)(*(int *)(param_1 + 0x878) + 0x174);
  fVar1 = *(float *)(iVar5 + 0x188);
  FUN_00461340(*(float *)(iVar5 + 0x188) * _DAT_004f94b8 + _DAT_004f94b8,
               (fVar1 + fVar1) * _DAT_004f94c0 + _DAT_004f94bc);
  *(undefined1 *)(param_1 + 0x3f24) = 1;
  *(undefined1 *)(param_1 + 0x3f30) = 1;
  if (*(int *)(*(int *)(param_1 + 0x878) + 0x538) != 0) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x878) + 0x220);
    if (*(char *)(iVar5 + 0x10) != '\0') {
      pcVar7 = *(char **)(param_1 + 0x4338);
      iVar5 = -(int)pcVar7;
      do {
        cVar2 = *pcVar7;
        pcVar7[(int)(acStack_424 + iVar5)] = cVar2;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      pcVar7 = s___No_Intro_0050d1fc;
      do {
        pcVar6 = pcVar7;
        pcVar7 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      pcVar7 = acStack_424 + -1;
      do {
        pcVar8 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar8 != '\0');
      pcVar8 = s___No_Intro_0050d1fc;
      for (uVar4 = (uint)(pcVar6 + -0x50d1fb) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = (uint)(pcVar6 + -0x50d1fb) & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_004782a0(0,acStack_424,4.0);
      return;
    }
    FUN_004782a0(iVar5,*(char **)(param_1 + 0x4338),2.0);
  }
  return;
}


