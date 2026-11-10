/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00410350 name: candidate_Level1_vslot_24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall candidate_Level1_vslot_24(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_13e [78];
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined1 auStack_c8 [76];
  undefined1 auStack_7c [88];
  undefined1 auStack_24 [12];
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004dcaab;
  pvStack_c = ExceptionList;
  uVar5 = 1;
  puVar4 = (undefined1 *)0x1;
  if (*(char *)(param_1 + 0x3a40) == '\0') {
    ExceptionList = &pvStack_c;
    (**(code **)(**(int **)(param_1 + 0x8ac) + 0x48))();
  }
  else {
    ExceptionList = &pvStack_c;
    (**(code **)(**(int **)(param_1 + 0x8b0) + 0x48))(1,1);
  }
  iVar2 = *(int *)(param_1 + 0x2568) + 1;
  *(int *)(param_1 + 0x2568) = iVar2;
  if (0xff < iVar2) {
    *(undefined4 *)(param_1 + 0x2568) = 1;
  }
  iVar2 = *(int *)(param_1 + 0x2568) * 4;
  *(undefined4 *)(iVar2 + 0x2168 + param_1) = 0;
  if (*(int *)(param_1 + 0x2164) < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = **(int **)(param_1 + 0x256c);
    *(undefined4 *)(iVar2 + 0x2168 + param_1) = 1;
  }
  if (iVar3 != 0) {
    do {
      uStack_ec = 0;
      uStack_f0 = 0;
      uStack_e8 = 0x3f800000;
      thunk_FUN_00493465(auStack_24,*(undefined4 *)(iVar3 + 0x1c),*(undefined4 *)(iVar3 + 0x20),
                         *(undefined4 *)(iVar3 + 0x24));
      thunk_FUN_00492bb9();
      thunk_FUN_00493621(&uStack_f0,
                         ((_DAT_004f91e4 - *(float *)(iVar3 + 0x14)) * _DAT_004f925c) /
                         _DAT_004f91e8);
      thunk_FUN_00492bb9();
      iVar1 = thunk_FUN_004936be(auStack_7c,
                                 (-*(float *)(iVar3 + 0x10) * _DAT_004f925c) / _DAT_004f91e8);
      thunk_FUN_00492bb9();
      uVar5 = thunk_FUN_004934f5(auStack_c8,*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),
                                 *(undefined4 *)(iVar3 + 0xc));
      puVar4 = auStack_13e + -10;
      thunk_FUN_00492bb9();
      FUN_0047a340(*(void **)(param_1 + 0x3f14));
      iVar2 = *(int *)(iVar1 + 0x2160 + param_1);
      pvStack_c = (void *)0xffffffff;
      if (*(int *)(param_1 + 0x2164) <= iVar2) break;
      iVar3 = *(int *)(*(int *)(param_1 + 0x256c) + iVar2 * 4);
      *(int *)(iVar1 + 0x2160 + param_1) = iVar2 + 1;
    } while (iVar3 != 0);
  }
  (**(code **)(*(int *)(param_1 + 0x3af8) + 8))(uStack_4,puVar4,uVar5);
  ExceptionList = pvStack_18;
  return;
}


