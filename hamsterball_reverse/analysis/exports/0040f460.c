/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040f460 name: candidate_Level1_vslot_35 */

/* WARNING: Removing unreachable block (ram,0x0040f756) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall candidate_Level1_vslot_35(void *this,float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  void *this_00;
  void *this_01;
  float *pfVar7;
  float10 fVar8;
  float local_48;
  float local_34;
  float local_20;
  float *local_1c;
  float fStack_18;
  float local_14;
  float *pfStack_10;
  float fStack_c;
  
  local_48 = 0.0;
  iVar4 = 3;
  iVar6 = 0;
  if (*(char *)(*(int *)((int)this + 0x878) + 0x234) != '\0') {
    iVar4 = *(int *)(*(int *)((int)this + 0x878) + 0xb24 + param_2 * 4);
    iVar6 = iVar4;
  }
  if (iVar6 <= iVar4) {
    local_34 = (float)((iVar4 - iVar6) + 1);
    iVar4 = iVar6 * 4 + 0x54c;
    do {
      FUN_00479630(&local_20);
      pfVar7 = local_1c;
      fVar1 = local_20;
      if (((local_20 != _DAT_004f91b0) || ((float)local_1c != _DAT_004f91b0)) &&
         (fVar8 = (float10)FUN_004cab24(this_00,SUB81((double)(local_20 * local_20 +
                                                              (float)local_1c * (float)local_1c),0))
         , (float)pfVar7 < (float)fVar8)) {
        local_34 = fVar1;
        FUN_004cab24(this_01,SUB81((double)(fVar1 * fVar1 + (float)pfVar7 * (float)pfVar7),0));
        if (*(int *)(*(int *)(iVar4 + (int)pfVar7[0x21e]) + 8) == 2) {
          local_48 = 1.0;
        }
        else {
          local_48 = 10.0;
        }
      }
      iVar4 = iVar4 + 4;
      local_34 = (float)((int)local_34 + -1);
    } while (local_34 != 0.0);
  }
  FUN_004615d0();
  if (local_48 == _DAT_004f91b0) {
    local_20 = local_14;
    pfVar7 = pfStack_10;
    fStack_18 = fStack_c;
  }
  else {
    FUN_004d9e34();
    FUN_004d9e34();
    pfVar5 = (float *)FUN_004615d0();
    pfVar7 = &local_20;
    if (pfVar7 == pfVar5) goto LAB_0040f68e;
    local_20 = *pfVar5;
    pfVar7 = (float *)pfVar5[1];
    fStack_18 = pfVar5[2];
  }
  local_1c = pfVar7;
LAB_0040f68e:
  fVar1 = fStack_18 - fStack_c;
  fVar2 = (float)local_1c - (float)pfStack_10;
  local_20 = local_20 - local_14;
  fVar3 = fVar1 * fVar1 + fVar2 * fVar2 + local_20 * local_20;
  if ((NAN(fVar3) || NAN(_DAT_004f91b0)) || fVar3 < _DAT_004f91b0 == (fVar3 == _DAT_004f91b0)) {
    FUN_004cab24(pfVar7,SUB81((double)fVar3,0));
  }
  if (param_1 != &local_20) {
    *param_1 = local_20 * 0.0 * 0.12;
    param_1[1] = fVar2 * 0.0 * 0.12;
    param_1[2] = fVar1 * 0.0 * 0.12;
  }
  return;
}


