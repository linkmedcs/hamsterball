/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004115a0 name: candidate_Level1_vslot_28 */

void __thiscall candidate_Level1_vslot_28(void *this,int param_1)

{
  char cVar1;
  void *pvVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined **ppuVar12;
  undefined4 uVar13;
  undefined **ppuVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dd860;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)((int)this + 0x29cc) == 0) goto LAB_00411a73;
  iVar6 = *(int *)((int)this + 0x878);
  iVar4 = *(int *)(*(int *)((int)this + 0x29cc) + 0x18) * 0xa0 + 0x5c8 + iVar6;
  ExceptionList = &local_c;
  uVar7 = FUN_004d9e34();
  cVar1 = *(char *)(*(int *)(iVar6 + 0x220) + 0x11);
  if (cVar1 == '\0') {
LAB_00411823:
    iVar6 = (int)uVar7 / 2;
    local_4 = 2;
    FUN_0040c330(&PTR_LAB_004f86e0,(float)(iVar6 + -0x58),10.0,180.0,105.0);
    local_24 = *(undefined4 *)((int)this + 0x4334);
    local_2c = 0x3f800000;
    local_28 = 0x3f800000;
    local_4 = CONCAT31(local_4._1_3_,3);
    if ((*(int *)(iVar4 + 0x1c) < 0x44c) && (*(char *)((int)this + 0x89c) != '\0')) {
      local_24 = *(undefined4 *)((int)this + 0x4334);
      local_2c = 0;
      local_28 = 0;
    }
    if (*(int *)(iVar4 + 0x1c) < 600) {
      local_24 = *(undefined4 *)((int)this + 0x4334);
      local_2c = 0;
      local_28 = 0;
    }
    iVar11 = 5;
    iVar10 = 5;
    uVar9 = 0;
    iVar6 = iVar6 + 0x26;
    pvVar2 = (void *)FUN_0046b9b0(&DAT_0050d318,(wchar_t)(*(int *)(iVar4 + 0x1c) / 100));
    FUN_0040c5a0(pvVar2,iVar6,uVar9,iVar10,iVar11);
    uVar9 = *(undefined4 *)((int)this + 0x4334);
    iVar4 = *(int *)(iVar4 + 0x1c);
    pcVar8 = s____1d_0050d31c;
  }
  else {
    if (*(char *)(iVar6 + 0x234) != '\0') {
      FUN_00461d60(param_1,399,0,2,600);
      goto LAB_00411a73;
    }
    if (cVar1 == '\0') goto LAB_00411823;
    iVar6 = (int)uVar7 / 2;
    local_4 = 0;
    FUN_0040c330(&PTR_LAB_004f86e0,(float)(iVar6 + -0x58),10.0,180.0,105.0);
    local_24 = *(undefined4 *)((int)this + 0x4334);
    iVar11 = 5;
    iVar10 = 5;
    iVar6 = iVar6 + 0x26;
    uVar9 = 0;
    local_4 = CONCAT31(local_4._1_3_,1);
    pvVar2 = (void *)FUN_0046b9b0(&DAT_0050d30c,(wchar_t)(*(int *)(iVar4 + 0x1c) / 100));
    FUN_0040c5a0(pvVar2,iVar6,uVar9,iVar10,iVar11);
    uVar9 = *(undefined4 *)((int)this + 0x4334);
    local_2c = 0x3f800000;
    local_28 = 0x3f800000;
    iVar4 = *(int *)(iVar4 + 0x1c);
    pcVar8 = s____1d_0050d310;
  }
  uVar17 = 0;
  uVar16 = 0;
  uVar15 = 0;
  ppuVar14 = &PTR_LAB_004f90c0;
  uVar13 = 0x3f800000;
  ppuVar12 = &PTR_LAB_004f90c0;
  iVar10 = 5;
  iVar6 = 5;
  pbVar3 = (byte *)FUN_0046b9b0((byte *)pcVar8,(wchar_t)((iVar4 / 10) % 10));
  FUN_0040c500(*(undefined4 *)(*(int *)((int)this + 0x878) + 0x318),pbVar3,iVar6,iVar10,ppuVar12,
               uVar13,local_2c,local_28,local_24,ppuVar14,uVar15,uVar16,uVar17,uVar9);
  local_4 = 0xffffffff;
LAB_00411a73:
  iVar4 = *(int *)((int)this + 0xcc0) + 1;
  *(int *)((int)this + 0xcc0) = iVar4;
  if (0xff < iVar4) {
    *(undefined4 *)((int)this + 0xcc0) = 1;
  }
  iVar4 = *(int *)((int)this + 0xcc0) * 4;
  *(undefined4 *)(iVar4 + 0x8c0 + (int)this) = 0;
  if (*(int *)((int)this + 0x8bc) < 1) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)**(undefined4 **)((int)this + 0xcc4);
    *(undefined4 *)(iVar4 + 0x8c0 + (int)this) = 1;
  }
  while( true ) {
    if (piVar5 == (int *)0x0) {
      ExceptionList = local_c;
      return;
    }
    (**(code **)(*piVar5 + 8))();
    iVar6 = *(int *)(iVar4 + 0x8c0 + (int)this);
    if (*(int *)((int)this + 0x8bc) <= iVar6) break;
    piVar5 = *(int **)(*(int *)((int)this + 0xcc4) + iVar6 * 4);
    *(int *)(iVar4 + 0x8c0 + (int)this) = iVar6 + 1;
  }
  ExceptionList = local_c;
  return;
}


