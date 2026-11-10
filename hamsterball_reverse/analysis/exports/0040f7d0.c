/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040f7d0 name: candidate_Level1_vslot_31 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall candidate_Level1_vslot_31(void *this,int param_1)

{
  int iVar1;
  float *pfVar2;
  undefined1 *puVar3;
  float unaff_EDI;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  undefined4 local_80 [17];
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004dd218;
  local_c = ExceptionList;
  if (*(char *)((int)this + 0x3a48) == '\0') {
    return;
  }
  if (*(char *)(param_1 + 10) != '\0') {
    return;
  }
  if (*(char *)(param_1 + 9) != '\0') {
    return;
  }
  if (*(char *)(*(int *)((int)this + 0x878) + 0x237) == '\0') {
    ExceptionList = &local_c;
    FUN_0040e440(*(void **)(param_1 + 0x10),'\0',unaff_EDI);
  }
  else {
    ExceptionList = &local_c;
    (**(code **)(**(int **)(*(int *)((int)this + 0x878) + 0x174) + 4))
              (*(undefined4 *)((int)this + 0x87c));
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x748);
  if (iVar1 == 0) {
    FUN_00466f10(local_80);
    iVar1 = *(int *)(param_1 + 0x10);
    uStack_4 = 0;
    FUN_00466fa0(*(undefined4 *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x168),
                 *(undefined4 *)(iVar1 + 0x16c));
    FUN_00461540((int)local_80);
    fStack_98 = *(float *)(*(int *)(param_1 + 0x10) + 0x168);
    fStack_90 = fStack_98;
    fStack_88 = fStack_98;
    FUN_004615a0();
    puVar3 = auStack_30;
LAB_0040fade:
    pfVar2 = (float *)(**(code **)(*(int *)this + 0x8c))(puVar3,*(undefined4 *)(param_1 + 0x14));
    if (&fStack_9c != pfVar2) {
      fStack_98 = pfVar2[1];
      fStack_9c = *pfVar2;
      fStack_94 = pfVar2[2];
    }
  }
  else {
    if (iVar1 == 1) {
      FUN_00466f10(local_80);
      iVar1 = *(int *)(param_1 + 0x10);
      uStack_4 = 1;
      FUN_00466fa0(*(undefined4 *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x168),
                   *(undefined4 *)(iVar1 + 0x16c));
      FUN_00461540((int)local_80);
      fStack_9c = *(float *)(*(int *)(param_1 + 0x10) + 0x164);
      fStack_8c = fStack_9c;
      FUN_004615a0();
      puVar3 = auStack_24;
      goto LAB_0040fade;
    }
    if (iVar1 != 2) goto LAB_0040fb14;
    FUN_00466f10(local_80);
    iVar1 = *(int *)(param_1 + 0x10);
    uStack_4 = 2;
    FUN_00466fa0(*(undefined4 *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x168),
                 *(undefined4 *)(iVar1 + 0x16c));
    FUN_00461540((int)local_80);
    fStack_94 = *(float *)(*(int *)(param_1 + 0x10) + 0x16c);
    fStack_90 = fStack_94;
    FUN_004615a0();
    pfVar2 = (float *)(**(code **)(*(int *)this + 0x8c))(auStack_3c,*(undefined4 *)(param_1 + 0x14))
    ;
    if (&fStack_9c != pfVar2) {
      fStack_9c = *pfVar2;
      fStack_98 = pfVar2[1];
      fStack_94 = pfVar2[2];
    }
    pfVar2 = (float *)FUN_0040bf40(&fStack_9c);
    if (&fStack_9c != pfVar2) {
      fStack_9c = *pfVar2;
      fStack_98 = pfVar2[1];
      fStack_94 = pfVar2[2];
    }
  }
  uStack_4 = 0xffffffff;
LAB_0040fb14:
  (**(code **)(**(int **)(param_1 + 0x10) + 0x14))(fStack_9c,fStack_98,fStack_94);
  if ((((fStack_9c != _DAT_004f91b0) || (fStack_98 != _DAT_004f91b0)) ||
      (fStack_94 != _DAT_004f91b0)) &&
     ((iVar1 = *(int *)(param_1 + 0x10), *(char *)(iVar1 + 0x2f8) != '\0' &&
      (*(char *)(iVar1 + 0x2f9) == '\0')))) {
    *(undefined1 *)(iVar1 + 0x2f8) = 0;
    fStack_9c = 0.0;
    fStack_98 = 0.0;
    fStack_94 = 0.0;
    FUN_00401510(&fStack_9c);
  }
  ExceptionList = local_c;
  return;
}


