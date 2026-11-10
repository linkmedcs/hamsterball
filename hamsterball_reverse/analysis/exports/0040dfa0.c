/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040dfa0 name: candidate_Level1_vslot_01 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall candidate_Level1_vslot_01(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *this;
  void *this_00;
  int iVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  bool bVar8;
  undefined4 auStackY_230 [128];
  undefined4 *in_stack_ffffffd4;
  float in_stack_ffffffd8;
  float in_stack_ffffffdc;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dcacb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[0xd87] = param_1[0xd87] + 1;
  if (param_1[0x10d3] != 0) {
    iVar5 = param_1[0x10d4] + -1;
    param_1[0x10d4] = iVar5;
    if (iVar5 < 1) {
      if (iVar5 == 0) {
        param_1[0x10d5] = 0;
        param_1[0x10d6] = 0;
      }
      if (_DAT_004f9268 <= (float)param_1[0x10d5]) {
        *(undefined1 *)(param_1 + 0x21d) = 1;
        in_stack_ffffffd8 = 5.957875e-39;
        puVar2 = operator_new(0x1160);
        local_4 = 4;
        if (puVar2 != (undefined4 *)0x0) {
          in_stack_ffffffd8 = (float)param_1[0x21e];
          in_stack_ffffffd4 = puVar2;
          FUN_00452c30(this,puVar2,(int)in_stack_ffffffd8,
                       (byte *)s_You_have_reached_the_end_of_the_d_0050d208);
          *puVar2 = &PTR_FUN_004f6698;
          puVar2[0x457] = param_1;
        }
        local_4 = 0xffffffff;
        in_stack_ffffffdc = 5.95799e-39;
        FUN_004748d0();
        param_1[0x10d3] = 0;
      }
      iVar5 = param_1[0x10d6];
      param_1[0x10d6] = iVar5 + 1;
      if ((float)(iVar5 + 1) < (float)param_1[0x10d5]) {
        ExceptionList = local_c;
        return;
      }
      param_1[0x10d6] = 0;
      param_1[0x10d5] = (int)((float)param_1[0x10d5] + (float)_DAT_004f9218);
    }
  }
  if (((char)param_1[0x10d7] == '\0') || (*(int *)(*(int *)(param_1[0x21e] + 0x184) + 8) < 2)) {
    if (((*(int *)(param_1[0x21e] + 0x5f8) < 3) || (4 < *(int *)(param_1[0x21e] + 0x5f8))) &&
       ((char)param_1[0x220] == '\0')) {
      in_stack_ffffffdc = 5.958203e-39;
      uVar3 = FUN_00432110();
      if ((char)uVar3 != '\0') {
        in_stack_ffffffdc = 1.4013e-45;
        in_stack_ffffffd8 = 5.958219e-39;
        FUN_00422150('\x01');
      }
    }
    if ((char)param_1[0xa6b] != '\0') {
      iVar5 = param_1[0xb76];
      param_1[0xb76] = iVar5 + 1;
      if (0xff < iVar5 + 1) {
        param_1[0xb76] = 1;
      }
      iVar5 = param_1[0xb76];
      param_1[iVar5 + 0xa76] = 0;
      if (param_1[0xa75] < 1) {
        this_00 = (void *)0x0;
      }
      else {
        this_00 = *(void **)param_1[0xb77];
        param_1[iVar5 + 0xa76] = 1;
      }
      while (this_00 != (void *)0x0) {
        in_stack_ffffffdc = *(float *)((int)this_00 + 0x16c);
        in_stack_ffffffd8 = *(float *)((int)this_00 + 0x168);
        in_stack_ffffffd4 = *(undefined4 **)((int)this_00 + 0x164);
        FUN_00409b60(this_00,(float)in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc);
        iVar4 = param_1[iVar5 + 0xa76];
        if (param_1[0xa75] <= iVar4) break;
        this_00 = *(void **)(param_1[0xb77] + iVar4 * 4);
        param_1[iVar5 + 0xa76] = iVar4 + 1;
      }
      *(undefined1 *)(param_1 + 0xa6b) = 0;
    }
    piVar6 = (int *)0x0;
    if ((param_1[0xd8b] == 1) && (param_1[0xfc6] != 0)) {
      iVar5 = *(int *)(param_1[0x21e] + 0x5d8);
      if (auStackY_230 + 0x81 != (undefined4 *)(iVar5 + 0x758)) {
        in_stack_ffffffd4 = *(undefined4 **)(iVar5 + 0x758);
        in_stack_ffffffd8 = *(float *)(iVar5 + 0x75c);
        in_stack_ffffffdc = *(float *)(iVar5 + 0x760);
      }
      FUN_0040c660(param_1 + 0xfc7,(float)in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc);
    }
    iVar5 = param_1[0x224];
    *(undefined1 *)(param_1 + 0x225) = 0;
    param_1[0x224] = iVar5 + 1;
    if (param_1[0x223] <= iVar5 + 1) {
      param_1[0x224] = 0;
      *(bool *)(param_1 + 0x222) = (char)param_1[0x222] == '\0';
      *(undefined1 *)(param_1 + 0x225) = 1;
    }
    iVar5 = param_1[0x229];
    *(undefined1 *)(param_1 + 0x22a) = 0;
    param_1[0x229] = iVar5 + 1;
    if (param_1[0x228] <= iVar5 + 1) {
      param_1[0x229] = 0;
      *(bool *)(param_1 + 0x227) = (char)param_1[0x227] == '\0';
      *(undefined1 *)(param_1 + 0x22a) = 1;
    }
    bVar7 = (char)param_1[0xe92] != '\0';
    iVar5 = param_1[0xa6d];
    if (bVar7) {
      iVar4 = iVar5 + 800;
      bVar8 = iVar5 == -800;
    }
    else {
      bVar8 = iVar5 == 0;
      iVar4 = iVar5;
    }
    if (!bVar8 && (bVar7 && SBORROW4(iVar5,-800)) == iVar4 < 0) {
      param_1[0xa6d] = iVar5 + -10;
    }
    iVar5 = param_1[0x330];
    param_1[0x330] = iVar5 + 1;
    if (0xff < iVar5 + 1) {
      param_1[0x330] = 1;
    }
    iVar5 = param_1[0x330];
    param_1[iVar5 + 0x230] = 0;
    if (0 < param_1[0x22f]) {
      piVar6 = *(int **)param_1[0x331];
      param_1[iVar5 + 0x230] = 1;
    }
    if (piVar6 != (int *)0x0) {
      do {
        (**(code **)(*piVar6 + 4))();
        if ((char)piVar6[6] != '\0') {
          FUN_0045fe10((int)piVar6);
          (**(code **)*piVar6)();
        }
        iVar4 = param_1[iVar5 + 0x230];
        if (param_1[0x22f] <= iVar4) break;
        piVar6 = *(int **)(param_1[0x331] + iVar4 * 4);
        param_1[iVar5 + 0x230] = iVar4 + 1;
      } while (piVar6 != (int *)0x0);
    }
    if ((param_1[0xd8b] != 1) || (*(char *)(*(int *)(param_1[0x21e] + 0x5d8) + 0x14c) == '\0')) {
      (**(code **)(*param_1 + 0x4c))();
      (**(code **)(*param_1 + 0x50))();
      (**(code **)(*param_1 + 0x54))();
      (**(code **)(*param_1 + 0x58))();
      iVar5 = param_1[0xe8c];
      param_1[0xe8c] = iVar5 + 1;
      if (0xff < iVar5 + 1) {
        param_1[0xe8c] = 1;
      }
      iVar5 = param_1[0xe8c];
      param_1[iVar5 + 0xd8c] = 0;
      if (param_1[0xd8b] < 1) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)param_1[0xe8d];
        param_1[iVar5 + 0xd8c] = 1;
      }
      while (iVar4 != 0) {
        (**(code **)(*param_1 + 0x7c))();
        iVar1 = param_1[iVar5 + 0xd8c];
        if (param_1[0xd8b] <= iVar1) break;
        iVar4 = *(int *)(param_1[0xe8d] + iVar1 * 4);
        param_1[iVar5 + 0xd8c] = iVar1 + 1;
      }
      (**(code **)(param_1[0xebe] + 4))();
    }
  }
  ExceptionList = local_c;
  return;
}


