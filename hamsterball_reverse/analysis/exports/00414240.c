/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00414240 name: candidate_WarmUp_Level1_ctor */

undefined4 * __thiscall candidate_WarmUp_Level1_ctor(void *this,undefined4 *param_1,int param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dca48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  candidate_Board_ctor(this,param_1,param_2);
  *param_1 = &PTR_candidate_Level1_vslot_00_004f82d8;
  param_1[0x21a] = s_Board__Warm_Up__0050d62c;
  param_1[0xa6c] = s_WARM_UP_RACE_0050d63c;
  param_1[0x21c] = *(undefined4 *)(param_1[5] + 0x1dc);
  local_4 = 0;
  param_1[0x542] = 0x3f800000;
  param_1[0x543] = 0;
  param_1[0x544] = 0x3f800000;
  param_1[0x545] = 0x3f800000;
  FUN_00413d80((int)param_1,s_BEGINNERRACE_0050d64c);
  param_1[0x10ce] = s_Hamster_Nation_0050d65c;
  ExceptionList = local_c;
  return param_1;
}


