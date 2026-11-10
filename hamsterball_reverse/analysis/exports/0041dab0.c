/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0041dab0 name: candidate_InternalBeginner_Cascade_ctor */

undefined4 * __thiscall
candidate_InternalBeginner_Cascade_ctor(void *this,undefined4 *param_1,int param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dc5f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  candidate_Board_ctor(this,param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_candidate_Beginner_vslot_00_004f89d8;
  _eh_vector_constructor_iterator_(param_1 + 0x10d8,0x418,8,FUN_0041b410,FUN_0045fb50);
  param_1[0x21a] = s_Board__Beginner__0050e2a8;
  param_1[0xa6c] = s_BEGINNER_RACE_0050e2bc;
  param_1[0x21c] = *(undefined4 *)(param_1[5] + 0x1dc);
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x542] = 0x3f800000;
  param_1[0x543] = 0x3f400000;
  param_1[0x544] = 0x3e800000;
  param_1[0x545] = 0x3f800000;
  FUN_00413d80((int)param_1,s_CASCADERACE_0050e2cc);
  param_1[0x10ce] = s_Cascade_Race_0050e2d8;
  ExceptionList = local_c;
  return param_1;
}


