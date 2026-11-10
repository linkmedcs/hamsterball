/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0041dc10 name: candidate_Cascade_vslot_18 */

void __fastcall candidate_Cascade_vslot_18(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  int *piVar5;
  int *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dc256;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar1 = operator_new(0x10d0);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_0046c8c0(puVar1,*(undefined4 *)(param_1[0x21e] + 0x174),
                          s_levels_levelcascade_0050e2e8);
  }
  local_4 = 0xffffffff;
  param_1[0x22b] = (int)puVar1;
  puVar1 = operator_new(0x10d0);
  local_4 = 1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00465700(puVar1);
  }
  local_4 = 0xffffffff;
  param_1[0x22c] = (int)puVar1;
  FUN_0040dba0((int)param_1);
  (**(code **)(*param_1 + 0x80))();
  local_10 = param_1 + 0x10d8;
  iVar2 = 0;
  piVar4 = param_1 + 0x1908;
  do {
    iVar2 = iVar2 + 1;
    piVar5 = local_10;
    pbVar3 = (byte *)FUN_0046b9b0((byte *)s_N_BUMPER_d_0050e2fc,(wchar_t)iVar2);
    FUN_00471370((void *)param_1[0x22b],pbVar3,(int)piVar5);
    *piVar4 = 0;
    local_10 = local_10 + 0x106;
    piVar4 = piVar4 + 1;
  } while (iVar2 < 8);
  ExceptionList = pvStack_c;
  return;
}


