/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040cd10 name: candidate_Board_ctor */

undefined4 * __thiscall candidate_Board_ctor(void *this,undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_c7c;
  undefined4 local_c78 [3];
  undefined4 local_c6c [792];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004db971;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00474d20(this,param_1);
  *param_1 = &PTR_FUN_004f8400;
  param_1[0x221] = &PTR_LAB_004f5c74;
  *(undefined1 *)(param_1 + 0x222) = 0;
  param_1[0x223] = 100;
  param_1[0x224] = 0;
  param_1[0x226] = &PTR_LAB_004f5c74;
  *(undefined1 *)(param_1 + 0x227) = 0;
  param_1[0x228] = 100;
  param_1[0x229] = 0;
  param_1[0x22e] = &PTR_FUN_004f63fc;
  param_1[0x333] = 0;
  param_1[0x332] = 0;
  param_1[0x22f] = 0;
  param_1[0x331] = 0;
  puVar2 = param_1 + 0x230;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x330] = 0;
  param_1[0x335] = &PTR_FUN_004f63fc;
  param_1[0x43a] = 0;
  param_1[0x439] = 0;
  param_1[0x336] = 0;
  param_1[0x438] = 0;
  puVar2 = param_1 + 0x337;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x437] = 0;
  param_1[0x43b] = &PTR_FUN_004f63fc;
  param_1[0x540] = 0;
  param_1[0x53f] = 0;
  param_1[0x43c] = 0;
  param_1[0x53e] = 0;
  puVar2 = param_1 + 0x43d;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x53d] = 0;
  param_1[0x541] = &PTR_LAB_004f90c0;
  param_1[0x542] = 0;
  param_1[0x543] = 0;
  param_1[0x544] = 0;
  param_1[0x545] = 0x437f0000;
  param_1[0x546] = &PTR_FUN_004f63fc;
  param_1[0x64b] = 0;
  param_1[0x64a] = 0;
  param_1[0x547] = 0;
  param_1[0x649] = 0;
  puVar2 = param_1 + 0x548;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x648] = 0;
  param_1[0x64c] = &PTR_FUN_004f63fc;
  param_1[0x751] = 0;
  param_1[0x750] = 0;
  param_1[0x64d] = 0;
  param_1[0x74f] = 0;
  puVar2 = param_1 + 0x64e;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x74e] = 0;
  param_1[0x752] = &PTR_FUN_004f63fc;
  param_1[0x857] = 0;
  param_1[0x856] = 0;
  param_1[0x753] = 0;
  param_1[0x855] = 0;
  puVar2 = param_1 + 0x754;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x854] = 0;
  param_1[0x858] = &PTR_FUN_004f63fc;
  param_1[0x95d] = 0;
  param_1[0x95c] = 0;
  param_1[0x859] = 0;
  param_1[0x95b] = 0;
  puVar2 = param_1 + 0x85a;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x95a] = 0;
  param_1[0x95e] = &PTR_FUN_004f63fc;
  param_1[0xa63] = 0;
  param_1[0xa62] = 0;
  param_1[0x95f] = 0;
  param_1[0xa61] = 0;
  puVar2 = param_1 + 0x960;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xa60] = 0;
  param_1[0xa74] = &PTR_FUN_004f63fc;
  param_1[0xb79] = 0;
  param_1[0xb78] = 0;
  param_1[0xa75] = 0;
  param_1[0xb77] = 0;
  puVar2 = param_1 + 0xa76;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xb76] = 0;
  param_1[0xb7a] = &PTR_FUN_004f63fc;
  param_1[0xc7f] = 0;
  param_1[0xc7e] = 0;
  param_1[0xb7b] = 0;
  param_1[0xc7d] = 0;
  puVar2 = param_1 + 0xb7c;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xc7c] = 0;
  param_1[0xc80] = &PTR_FUN_004f63fc;
  param_1[0xd85] = 0;
  param_1[0xd84] = 0;
  param_1[0xc81] = 0;
  param_1[0xd83] = 0;
  puVar2 = param_1 + 0xc82;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xd82] = 0;
  param_1[0xd8a] = &PTR_FUN_004f63fc;
  param_1[0xe8f] = 0;
  param_1[0xe8e] = 0;
  param_1[0xd8b] = 0;
  param_1[0xe8d] = 0;
  puVar2 = param_1 + 0xd8c;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xe8c] = 0;
  local_4 = 0xf;
  _eh_vector_constructor_iterator_(param_1 + 0xeaa,0x14,4,FUN_0045faa0,FUN_0045fac0);
  param_1[0xebe] = &PTR_FUN_004f59c8;
  param_1[0xebf] = &PTR_FUN_004f63fc;
  param_1[0xfc4] = 0;
  param_1[0xfc3] = 0;
  param_1[0xec0] = 0;
  param_1[0xfc2] = 0;
  puVar2 = param_1 + 0xec1;
  for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xfc1] = 0;
  local_4._0_1_ = 0x11;
  _eh_vector_constructor_iterator_(param_1 + 0xfc7,0xc,2,FUN_0040c650,candidate_Beginner_vslot_21);
  param_1[0x21e] = param_2;
  *(undefined1 *)(param_1 + 0x220) = 0;
  param_1[0x10d3] = 0;
  local_4 = CONCAT31(local_4._1_3_,0x12);
  if (5 < *(int *)(*(int *)(param_2 + 0x220) + 8)) {
    uVar1 = FUN_00432260(param_2);
    if ((char)uVar1 == '\0') {
      param_1[0x10d3] = 1;
      param_1[0x10d4] = 0x9c4;
    }
  }
  *(undefined1 *)(param_1 + 0x10d7) = 0;
  if (param_1 + 0x10d0 != local_c78) {
    param_1[0x10d0] = 0;
    param_1[0x10d1] = 0xc3160000;
    param_1[0x10d2] = 0;
  }
  *(undefined1 *)(param_1 + 0xa6b) = 1;
  param_1[0x22d] = 0;
  param_1[0xa6c] = 0;
  *(undefined1 *)(param_1 + 0x334) = 0;
  param_1[0x22b] = 0;
  param_1[0x21f] = 0;
  *(undefined1 *)(param_1 + 0xe90) = 0;
  param_1[0xa6e] = 0x43070000;
  param_1[0xa6f] = 0x44898000;
  param_1[0xd87] = 0;
  param_1[0xd88] = 0x3f800000;
  param_1[0x223] = 0x19;
  param_1[0x228] = 0x32;
  param_1[0x21a] = s_Board_0050d1e8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x44480000;
  param_1[4] = 0x44160000;
  param_1[0xd89] = 0;
  if ((void *)param_1[0xe8d] != (void *)0x0) {
    _free((void *)param_1[0xe8d]);
  }
  param_1[0xe8d] = 0;
  param_1[0xd8b] = 0;
  local_c7c = 0;
  do {
    *(undefined1 *)(local_c7c + 0x5d2 + param_1[0x21e]) = 0;
    *(undefined1 *)(local_c7c + 0x5ec + param_1[0x21e]) = 0;
    iVar4 = *(int *)(param_1[0x21e] + 0x220);
    if ((*(char *)(iVar4 + 0x11) != '\0') || (*(int *)(iVar4 + 8) == 1)) {
      *(undefined4 *)(local_c7c + 0x5f0 + param_1[0x21e]) = 0;
    }
    *(undefined4 *)(local_c7c + 0x5f4 + param_1[0x21e]) = 0;
    if (*(char *)(local_c7c + param_1[0x21e] + 0x5d3) == '\0') {
      FUN_0045fb80();
      *(undefined4 *)(local_c7c + 0x5f8 + param_1[0x21e]) = 0;
      param_1[0xd89] = param_1[0xd89] + 1;
    }
    local_c7c = local_c7c + 0xa0;
  } while (local_c7c < 0x280);
  puVar2 = operator_new(0x418);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_004f63fc;
    puVar2[0x105] = 2;
    puVar2[0x104] = 0;
    puVar2[1] = 0;
    puVar2[0x103] = 0;
    puVar5 = puVar2 + 2;
    for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    puVar2[0x102] = 0;
  }
  param_1[0xe91] = puVar2;
  FUN_00401700(local_c6c,(int)param_1);
  *(undefined4 *)(param_1[0xe91] + 0x410) = 8;
  param_1[0xa73] = 0;
  param_1[0xe93] = 0;
  param_1[0xe94] = 0;
  *(undefined1 *)(param_1 + 0xe95) = 1;
  *(undefined1 *)(param_1 + 0xe92) = 0;
  local_4._0_1_ = 0x13;
  if (*(char *)(*(int *)(param_1[0x21e] + 0x220) + 0x10) != '\0') {
    *(undefined1 *)(param_1 + 0xe92) = 1;
  }
  param_1[0xa6d] = 800;
  param_1[0xea2] = 0x42480000;
  param_1[0xea3] = 0x42480000;
  param_1[0xea5] = 0x42480000;
  param_1[0xea4] = 0x443b8000;
  param_1[0xea6] = 0x42480000;
  param_1[0xea7] = 0x44098000;
  param_1[0xea9] = 0x44098000;
  param_1[0xea8] = 0x443b8000;
  param_1[0xeab] = 0x3f800000;
  param_1[0xeac] = 0x3f800000;
  param_1[0xead] = 0x3f800000;
  param_1[0xeae] = 0x3f800000;
  param_1[0xeb0] = 0;
  param_1[0xeb2] = 0x3f800000;
  param_1[0xeb3] = 0x3f800000;
  param_1[0xeb1] = 0x3f000000;
  param_1[0xeb5] = 0x3f800000;
  param_1[0xeb6] = 0x3e800000;
  param_1[0xeb7] = 0x3e800000;
  param_1[0xeb8] = 0x3f800000;
  param_1[0xeba] = 0x3f800000;
  param_1[0xebb] = 0x3f800000;
  param_1[0xebc] = 0;
  param_1[0xebd] = 0x3f800000;
  iVar4 = *(int *)(param_1[0x21e] + 0x178);
  *(undefined4 *)(iVar4 + 0x914) = 0x43fa0000;
  *(undefined4 *)(iVar4 + 0x918) = 0x44bb8000;
  iVar4 = param_1[0x21e];
  param_1[0xfc5] = 0;
  *(undefined1 *)(param_1 + 0xfcd) = 0;
  param_1[0xa64] = 100;
  param_1[0x10cd] = 0x3f800000;
  *(undefined1 *)(param_1 + 0x10cf) = 0;
  param_1[0xd86] = 0;
  if (((*(char *)(*(int *)(iVar4 + 0x220) + 0x11) != '\0') && (*(char *)(iVar4 + 0x234) == '\0')) &&
     (*(int *)(iVar4 + 0x90c) != 0)) {
    *(undefined4 *)(*(int *)(iVar4 + 0x90c) + 0x41c) = 0;
    puVar2 = operator_new(0xc60);
    local_4._0_1_ = 0x14;
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_00401700(puVar2,(int)param_1);
    }
    param_1[0xd86] = piVar3;
    local_4._0_1_ = 0x13;
    (**(code **)(*piVar3 + 4))();
    FUN_00401030((void *)param_1[0xd86],&PTR_LAB_004f90c0,1.0,1.0,0.0,0.35);
    *(undefined4 *)(param_1[0xd86] + 0x18) = 0xffffffff;
    *(undefined4 *)(param_1[0xd86] + 0x278) = 0x3f000000;
    *(undefined4 *)(param_1[0xd86] + 0x27c) = 0x3dcccccd;
    *(undefined4 *)(param_1[0xd86] + 0x284) = 0x41d00000;
    *(undefined4 *)(param_1[0xd86] + 0x1a0) = 0x3f4ccccd;
    *(undefined4 *)(param_1[0xd86] + 0x188) = 0x4479c000;
    *(undefined1 *)(param_1[0xd86] + 0x281) = 0;
  }
  local_4 = CONCAT31(local_4._1_3_,0x12);
  FUN_00401c60(local_c6c);
  ExceptionList = pvStack_c;
  return param_1;
}


