/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00414310 name: candidate_Level1_load */

void __fastcall candidate_Level1_load(int *param_1)

{
  undefined4 *puVar1;
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
    puVar1 = FUN_0046c8c0(puVar1,*(undefined4 *)(param_1[0x21e] + 0x174),s_levels_level1_0050d66c);
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
  ExceptionList = pvStack_c;
  return;
}


