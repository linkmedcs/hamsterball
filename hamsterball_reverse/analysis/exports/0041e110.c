/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0041e110 name: candidate_Cascade_vslot_24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall candidate_Cascade_vslot_24(void *this,int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int local_7c;
  float *local_78;
  int local_74;
  undefined **local_68;
  float local_64 [4];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_004dd098;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  candidate_Level1_vslot_24((int)this);
  fVar1 = *(float *)(param_1 + 0x790) + (float)_DAT_004f9200;
  fVar2 = *(float *)(param_1 + 0x794) + (float)_DAT_004f9200;
  *(float *)(param_1 + 0x790) = fVar1;
  *(float *)(param_1 + 0x794) = fVar2;
  FUN_004614c0(fVar1,fVar2);
  local_7c = (int)this + 0x4360;
  local_78 = (float *)((int)this + 0x6420);
  local_74 = 8;
  do {
    if (*local_78 != _DAT_004f91b0) {
      local_68 = &PTR_LAB_004f5d0c;
      local_20 = 0;
      pfVar4 = local_64;
      for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar4 = 0.0;
        pfVar4 = pfVar4 + 1;
      }
      local_1b = 0;
      local_c = 0;
      local_64[3] = *local_78;
      local_1c = local_64[3] != (float)_DAT_004f91b8;
      local_64[0] = 1.0;
      local_64[1] = 1.0;
      local_64[2] = 1.0;
      local_54 = 0x3f800000;
      local_50 = 0x3f800000;
      local_4c = 0x3f800000;
      local_34 = 0x3f800000;
      local_30 = 0x3f800000;
      local_2c = 0x3f800000;
      local_28 = 0x3f800000;
      *(undefined ****)(param_1 + 0x7c0) = &local_68;
      local_48 = local_64[3];
      (**(code **)(**(int **)((int)this + 0x8ac) + 0x50))(local_7c);
      local_c = 0xffffffff;
      local_68 = &PTR_LAB_004f5d0c;
    }
    local_78 = local_78 + 1;
    local_7c = local_7c + 0x418;
    local_74 = local_74 + -1;
  } while (local_74 != 0);
  *(undefined4 *)(param_1 + 0x7c0) = 0;
  fVar1 = *(float *)(param_1 + 0x790) - (float)_DAT_004f9200;
  fVar2 = *(float *)(param_1 + 0x794) - (float)_DAT_004f9200;
  *(float *)(param_1 + 0x790) = fVar1;
  *(float *)(param_1 + 0x794) = fVar2;
  FUN_004614c0(fVar1,fVar2);
  ExceptionList = pvStack_14;
  return;
}


