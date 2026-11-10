/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00410c40 name: candidate_Level1_vslot_27 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall candidate_Level1_vslot_27(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  void *pvVar4;
  char *this_00;
  ulonglong uVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined **ppuVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float local_54;
  uint local_50;
  float local_4c;
  float local_40;
  float local_3c;
  undefined **local_24;
  float local_20 [5];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dd888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((-800 < *(int *)((int)this + 0x29b4)) &&
     (ExceptionList = &local_c,
     *(char *)(*(int *)(*(int *)((int)this + 0x878) + 0x220) + 0x10) == '\0')) {
    local_4c = (float)(*(int *)((int)this + 0x29b4) * -2);
    ExceptionList = &local_c;
    FUN_0040c410(param_1);
    FUN_004015e0(*(void **)((int)this + 0x29b0),*(int *)((int)this + 0x29b4) + 400,0x82,5,5);
  }
  if (*(char *)((int)this + 0x3a48) == '\0') {
    iVar6 = *(int *)((int)this + 0x3a4c);
    if (iVar6 == 0) {
      local_4c = *(float *)(*(int *)((int)this + 0x878) + 0x394);
    }
    if (iVar6 == 1) {
      local_4c = *(float *)(*(int *)((int)this + 0x878) + 0x398);
    }
    if (iVar6 == 2) {
      local_4c = *(float *)(*(int *)((int)this + 0x878) + 0x39c);
    }
    if (_DAT_004f91a0 <= *(float *)((int)this + 0x3a50)) {
      local_54 = 1.0;
    }
    else {
      local_54 = *(float *)((int)this + 0x3a50);
    }
    local_24 = (undefined **)0x43aa8000;
    local_20[0] = 149.0;
    local_20[1] = 307.0;
    local_20[2] = 166.0;
    local_20[3] = 353.0;
    local_20[4] = 216.0;
    local_40 = 0.0;
    local_3c = 0.0;
    if ((iVar6 == 2) && ((float)_DAT_004f9498 < *(float *)((int)this + 0x3a50))) {
      iVar1 = 2;
      do {
        iVar1 = iVar1 * 2;
      } while (iVar1 < 0x19);
      uVar2 = (&DAT_0050f1cc)[DAT_0050f1c8] + (&DAT_0050f1cc)[DAT_0050f1c4] & 0x3fffffff;
      (&DAT_0050f1cc)[DAT_0050f1c4] = uVar2;
      DAT_0050f1c4 = DAT_0050f1c4 + 1;
      if (DAT_0050f1c4 == 0x37) {
        DAT_0050f1c4 = 0;
      }
      DAT_0050f1c8 = DAT_0050f1c8 + 1;
      if (DAT_0050f1c8 == 0x37) {
        DAT_0050f1c8 = 0;
      }
      local_50 = ((int)uVar2 >> 6 & iVar1 - 1U) % 0x19;
      iVar1 = FUN_00467280(&PTR_PTR_0050f1c0,2,'\0');
      if (iVar1 == 1) {
        local_50 = -local_50;
      }
      local_40 = (float)(int)local_50;
      iVar1 = 2;
      do {
        iVar1 = iVar1 * 2;
      } while (iVar1 < 0x19);
      uVar2 = (&DAT_0050f1cc)[DAT_0050f1c8] + (&DAT_0050f1cc)[DAT_0050f1c4] & 0x3fffffff;
      (&DAT_0050f1cc)[DAT_0050f1c4] = uVar2;
      DAT_0050f1c4 = DAT_0050f1c4 + 1;
      if (DAT_0050f1c4 == 0x37) {
        DAT_0050f1c4 = 0;
      }
      DAT_0050f1c8 = DAT_0050f1c8 + 1;
      if (DAT_0050f1c8 == 0x37) {
        DAT_0050f1c8 = 0;
      }
      local_50 = ((int)uVar2 >> 6 & iVar1 - 1U) % 0x19;
      iVar1 = FUN_00467280(&PTR_PTR_0050f1c0,2,'\0');
      if (iVar1 == 1) {
        local_50 = -local_50;
      }
      local_3c = (float)(int)local_50;
    }
    local_4 = 0;
    FUN_00468410((int)local_4c,&PTR_LAB_004f86e0,
                 (local_40 + _DAT_004f92e8) -
                 ((float)(&local_24)[iVar6 * 2] / _DAT_004f91c8) * local_54,
                 ((local_3c + _DAT_004f92ec) - (local_20[iVar6 * 2] / _DAT_004f91c8) * local_54) +
                 _DAT_004f91e8,local_54 * (float)(&local_24)[iVar6 * 2],
                 local_54 * local_20[iVar6 * 2],&PTR_LAB_004f86e0,0,0,0x3f800000,0x3f800000);
    local_4 = 0xffffffff;
  }
  if (*(int *)((int)this + 0x29cc) != 0) {
    iVar6 = *(int *)(*(int *)((int)this + 0x878) + 0x220);
    if ((*(char *)(iVar6 + 0x10) == '\0') && (*(char *)(iVar6 + 0x11) == '\0')) {
      FUN_0040c500(*(undefined4 *)(*(int *)((int)this + 0x878) + 0x31c),(byte *)s_Score_0050d2cc,3,3
                   ,&PTR_LAB_004f90c0,0x3f666666,0x3f666666,0x3f800000,0x3f800000,&PTR_LAB_004f90c0,
                   0,0,0,0x3f800000);
      ppuVar12 = &PTR_LAB_004f90c0;
      uVar16 = 0x3f800000;
      uVar13 = 0;
      uVar14 = 0;
      uVar15 = 0;
      ppuVar7 = &PTR_LAB_004f90c0;
      uVar8 = 0x3f800000;
      uVar9 = 0x3f800000;
      uVar10 = 0x3f800000;
      uVar11 = 0x3f800000;
      iVar1 = 3;
      iVar6 = 3;
      uVar5 = FUN_004d9e34();
      pbVar3 = (byte *)FUN_0046b9b0(&DAT_0050d2d4,(wchar_t)uVar5);
      FUN_0040c500(*(undefined4 *)(*(int *)((int)this + 0x878) + 0x31c),pbVar3,iVar6,iVar1,ppuVar7,
                   uVar8,uVar9,uVar10,uVar11,ppuVar12,uVar13,uVar14,uVar15,uVar16);
      if (*(char *)(*(int *)((int)this + 0x878) + 0x673) == '\0') {
        FUN_0040c5a0(s_Player_2_0050d2dc,0x31b,0,3,3);
        iVar1 = 3;
        iVar6 = 3;
        uVar9 = 0x12;
        uVar8 = 0x31b;
        pvVar4 = (void *)FUN_0046b9b0(&DAT_0050d2e8,
                                      SUB82((double)*(float *)(*(int *)((int)this + 0x878) + 0x680),
                                            0));
        FUN_0040c5a0(pvVar4,uVar8,uVar9,iVar6,iVar1);
      }
    }
    if (((*(int *)((int)this + 0x29cc) != 0) &&
        (*(char *)(*(int *)(*(int *)((int)this + 0x878) + 0x220) + 0x11) != '\0')) &&
       (*(char *)(*(int *)((int)this + 0x878) + 0x234) == '\0')) {
      local_4 = 1;
      FUN_0040c330(&PTR_LAB_004f86e0,460.0,17.0,80.0,46.666668);
      uVar8 = *(undefined4 *)((int)this + 0x4334);
      local_24 = &PTR_LAB_004f90c0;
      local_20[0] = 1.0;
      local_20[1] = 1.0;
      local_20[2] = 1.0;
      *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x328) + 0x428) = 0x3ee38e39;
      *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x318) + 0x428) = 0x3ee38e39;
      iVar1 = 3;
      iVar6 = 3;
      uVar10 = 10;
      uVar9 = 0x20b;
      local_4 = CONCAT31(local_4._1_3_,2);
      local_20[3] = (float)uVar8;
      pvVar4 = (void *)FUN_0046b9b0(&DAT_0050d2f0,(wchar_t)(*(int *)((int)this + 0x29a8) / 100));
      FUN_0040c5a0(pvVar4,uVar9,uVar10,iVar6,iVar1);
      uVar9 = *(undefined4 *)((int)this + 0x4334);
      ppuVar12 = &PTR_LAB_004f90c0;
      uVar14 = 0;
      uVar15 = 0;
      uVar16 = 0;
      ppuVar7 = &PTR_LAB_004f90c0;
      uVar10 = 0x3f800000;
      uVar11 = 0x3f800000;
      uVar13 = 0x3f800000;
      iVar1 = 3;
      iVar6 = 3;
      pbVar3 = (byte *)FUN_0046b9b0((byte *)s____1d_0050d2f4,
                                    (wchar_t)((*(int *)((int)this + 0x29a8) / 10) % 10));
      FUN_0040c500(*(undefined4 *)(*(int *)((int)this + 0x878) + 0x318),pbVar3,iVar6,iVar1,ppuVar7,
                   uVar10,uVar11,uVar13,uVar8,ppuVar12,uVar14,uVar15,uVar16,uVar9);
      *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x328) + 0x428) = 0x3f800000;
      *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x318) + 0x428) = 0x3f800000;
      if (*(int *)((int)this + 0x361c) % 0x32 < 0x19) {
        this_00 = s_Target__0050d2fc;
      }
      else {
        this_00 = s_Target__0050d304;
      }
      FUN_004015e0(this_00,500,0xffffffff,2,2);
      local_4 = 0xffffffff;
    }
  }
  FUN_00461d60(param_1,0,0,800,600);
  ExceptionList = local_c;
  return;
}


