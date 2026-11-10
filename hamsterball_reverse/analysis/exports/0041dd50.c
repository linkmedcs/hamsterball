/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0041dd50 name: candidate_Cascade_vslot_29 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall candidate_Cascade_vslot_29(void *this,int *param_1,int *param_2)

{
  int iVar1;
  float *pfVar2;
  long lVar3;
  float10 fVar4;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = __strnicmp(*(char **)(param_2[1] + 0x864),s_N_BUMPER_0050e308,8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(*(int *)((int)this + 0x878) + 0x444);
    FUN_0046be80((float)param_1[0x59],(float)param_1[0x5a],(float)param_1[0x5b]);
    FUN_00467bd0(iVar1);
    pfVar2 = (float *)(param_1[0x69] + 0xca4);
    if (&local_c != pfVar2) {
      local_c = *pfVar2;
      local_4 = *(float *)(param_1[0x69] + 0xcac);
    }
    local_c = local_c * _DAT_004f9208;
    local_8 = 0;
    local_4 = local_4 * _DAT_004f9208;
    fVar4 = FUN_0040c0f0();
    if (fVar4 < (float10)_DAT_004f91cc) {
      FUN_0040bfe0(5.0);
    }
    fVar4 = FUN_0040c0f0();
    if ((float10)_DAT_004f91f8 < fVar4) {
      FUN_0040bfe0(10.0);
    }
    iVar1 = param_1[0x69];
    if ((float *)(iVar1 + 0xca4) != &local_c) {
      *(float *)(iVar1 + 0xca4) = local_c;
      *(undefined4 *)(iVar1 + 0xca8) = local_8;
      *(float *)(iVar1 + 0xcac) = local_4;
    }
    lVar3 = _atol((char *)(*(int *)(param_2[1] + 0x864) + 8));
    *(undefined4 *)((int)this + lVar3 * 4 + 0x641c) = 0x3f800000;
  }
  candidate_Level1_vslot_29(this,param_1,param_2);
  return;
}


