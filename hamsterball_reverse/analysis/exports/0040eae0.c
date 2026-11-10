/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040eae0 name: candidate_Level1_vslot_22 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall candidate_Level1_vslot_22(int *param_1)

{
  int iVar1;
  void *this;
  bool bVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  void *this_00;
  undefined4 extraout_ECX;
  int *piVar7;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  short sVar8;
  int iVar9;
  int *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004dd61c;
  local_c = ExceptionList;
  iVar5 = param_1[0xe8c];
  bVar2 = false;
  ExceptionList = &local_c;
  param_1[0xe8c] = iVar5 + 1;
  if (0xff < iVar5 + 1) {
    param_1[0xe8c] = 1;
  }
  iVar5 = param_1[0xe8c];
  param_1[iVar5 + 0xd8c] = 0;
  if (param_1[0xd8b] < 1) {
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)param_1[0xe8d];
    param_1[iVar5 + 0xd8c] = 1;
  }
  if (iVar9 != 0) {
    do {
      if ((*(char *)(iVar9 + 10) == '\0') ||
         ((**(code **)(*param_1 + 0x5c))(iVar9), *(int *)(iVar9 + 0x30) != 5)) {
        bVar2 = true;
      }
      iVar1 = param_1[iVar5 + 0xd8c];
      if (param_1[0xd8b] <= iVar1) break;
      iVar9 = *(int *)(param_1[0xe8d] + iVar1 * 4);
      param_1[iVar5 + 0xd8c] = iVar1 + 1;
    } while (iVar9 != 0);
    if (bVar2) {
      ExceptionList = local_c;
      return;
    }
  }
  puVar4 = (undefined4 *)0x0;
  if (param_1[0xd89] < 1) {
    ExceptionList = local_c;
    return;
  }
  if ((((char)param_1[0x10cf] != '\0') &&
      (*(char *)(*(int *)(param_1[0x21e] + 0x220) + 0x10) == '\0')) &&
     (*(char *)(*(int *)(param_1[0x21e] + 0x220) + 0x11) == '\0')) {
    *(undefined1 *)(param_1 + 0x21d) = 1;
    iVar5 = param_1[0x330];
    param_1[0x330] = iVar5 + 1;
    if (0xff < iVar5 + 1) {
      param_1[0x330] = 1;
    }
    iVar5 = param_1[0x330];
    param_1[iVar5 + 0x230] = 0;
    if (0 < param_1[0x22f]) {
      puVar4 = *(undefined4 **)param_1[0x331];
      param_1[iVar5 + 0x230] = 1;
    }
    if (puVar4 != (undefined4 *)0x0) {
      do {
        (**(code **)*puVar4)(1);
        iVar9 = param_1[iVar5 + 0x230];
        if (param_1[0x22f] <= iVar9) break;
        puVar4 = *(undefined4 **)(param_1[0x331] + iVar9 * 4);
        param_1[iVar5 + 0x230] = iVar9 + 1;
      } while (puVar4 != (undefined4 *)0x0);
    }
    if ((void *)param_1[0x331] != (void *)0x0) {
      _free((void *)param_1[0x331]);
    }
    param_1[0x331] = 0;
    param_1[0x22f] = 0;
    puVar4 = operator_new(0xcfc);
    if (puVar4 != (undefined4 *)0x0) {
      FUN_0045e710(this_00,puVar4);
    }
    FUN_004748d0();
    ExceptionList = local_c;
    return;
  }
  if (((float)param_1[0xd88] == _DAT_004f91b0) &&
     (iVar5 = *(int *)(param_1[0x21e] + 0x538), iVar5 != 0)) {
    iVar9 = *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x16c);
    *(undefined1 *)(iVar5 + 0x530) = 1;
    *(undefined1 *)(iVar5 + 0x531) = 0;
    *(float *)(iVar5 + 0x52c) = ((float)iVar9 / _DAT_004f93a8) * (float)_DAT_004f91d0;
  }
  fVar3 = (float)param_1[0xd88] + _DAT_004f9400;
  param_1[0xd88] = (int)fVar3;
  if (*(char *)(*(int *)(param_1[0x21e] + 0x220) + 0x10) != '\0') {
    param_1[0xd88] = (int)(fVar3 + _DAT_004f9230);
  }
  if ((float)param_1[0xd88] < _DAT_004f91a0) {
    ExceptionList = local_c;
    return;
  }
  iVar5 = param_1[0x330];
  param_1[0x330] = iVar5 + 1;
  if (0xff < iVar5 + 1) {
    param_1[0x330] = 1;
  }
  iVar5 = param_1[0x330];
  param_1[iVar5 + 0x230] = 0;
  if (0 < param_1[0x22f]) {
    puVar4 = *(undefined4 **)param_1[0x331];
    param_1[iVar5 + 0x230] = 1;
  }
  while (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
    iVar9 = param_1[iVar5 + 0x230];
    if (param_1[0x22f] <= iVar9) break;
    puVar4 = *(undefined4 **)(param_1[0x331] + iVar9 * 4);
    param_1[iVar5 + 0x230] = iVar9 + 1;
  }
  if ((void *)param_1[0x331] != (void *)0x0) {
    _free((void *)param_1[0x331]);
  }
  param_1[0x331] = 0;
  param_1[0x22f] = 0;
  iVar5 = 0;
  do {
    iVar9 = iVar5 + param_1[0x21e];
    iVar5 = iVar5 + 0xa0;
    *(undefined4 *)(iVar9 + 0x5e8) = *(undefined4 *)(iVar9 + 0x5e4);
  } while (iVar5 < 0x280);
  iVar5 = param_1[0x21e];
  this = *(void **)(iVar5 + 0x220);
  if (*(char *)((int)this + 0x11) == '\0') {
    if (*(char *)((int)this + 0x10) == '\0') {
      FUN_0042d140(this,'\x01');
      ExceptionList = local_c;
      return;
    }
    FUN_0046c150();
    piVar6 = operator_new(0x87c);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      FUN_00474d20(extraout_ECX_00,piVar6);
      *piVar6 = (int)&PTR_FUN_004f7d90;
      piVar6[0x21e] = iVar5;
      piVar6[0x21a] = (int)&DAT_0050cf98;
      FUN_004782a0(extraout_ECX_01,s_Main_Theme___No_Intro_0050cfac,2.0);
    }
    iVar9 = *(int *)(iVar5 + 0x184);
    *(int **)(iVar5 + 0x228) = piVar6;
    iVar5 = *(int *)(iVar9 + 8);
    piVar7 = *(int **)(iVar9 + 0x410);
    sVar8 = 0;
    if (iVar5 < 1) {
LAB_0040f196:
      FUN_0045fb80();
      piVar6[0xc] = iVar9;
      (**(code **)(**(int **)(iVar9 + 0x844) + 0x74))();
      (**(code **)(*piVar6 + 0x38))(iVar9);
    }
    else {
      do {
        if ((int *)*piVar7 == piVar6) {
          sVar8 = sVar8 + 1;
        }
        piVar7 = piVar7 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (sVar8 < 1) goto LAB_0040f196;
    }
    puVar4 = operator_new(0xd18);
    uStack_4 = 3;
    if (puVar4 == (undefined4 *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = FUN_00438a30((void *)param_1[0x21e],puVar4);
    }
    iVar5 = *(int *)(param_1[0x21e] + 0x184);
    iVar9 = *(int *)(iVar5 + 8);
    piVar7 = *(int **)(iVar5 + 0x410);
    sVar8 = 0;
    uStack_4 = 0xffffffff;
    if (0 < iVar9) {
      do {
        if ((int *)*piVar7 == piVar6) {
          sVar8 = sVar8 + 1;
        }
        piVar7 = piVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      if (0 < sVar8) goto LAB_0040f232;
    }
    FUN_0045fb80();
    piVar6[0xc] = iVar5;
    (**(code **)(**(int **)(iVar5 + 0x844) + 0x74))();
    (**(code **)(*piVar6 + 0x38))(iVar5);
LAB_0040f232:
    FUN_00431940();
    ExceptionList = local_c;
    return;
  }
  FUN_00431940();
  iVar5 = param_1[0x21e];
  FUN_0046c150();
  piVar6 = operator_new(0x87c);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    FUN_00474d20(extraout_ECX,piVar6);
    *piVar6 = (int)&PTR_FUN_004f7d90;
    piVar6[0x21e] = iVar5;
    piVar6[0x21a] = (int)&DAT_0050cf98;
    iVar9 = *(int *)(iVar5 + 0x534);
    *(undefined1 *)(iVar9 + 0x531) = 1;
    *(undefined1 *)(iVar9 + 0x530) = 0;
    *(float *)(iVar9 + 0x52c) =
         ((float)*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 0x16c) / _DAT_004f93a8) *
         (float)_DAT_004f91d0;
    FUN_00477f40(s_Main_Theme___No_Intro_0050cfac);
    *(undefined4 *)(iVar9 + 0x528) = 0;
    BASS_ChannelSetAttributes(*(undefined4 *)(iVar9 + 8),0xffffffff,0,0xffffff9b);
  }
  *(int **)(iVar5 + 0x228) = piVar6;
  iVar5 = *(int *)(iVar5 + 0x184);
  iVar9 = *(int *)(iVar5 + 8);
  piVar7 = *(int **)(iVar5 + 0x410);
  sVar8 = 0;
  if (iVar9 < 1) {
LAB_0040ef31:
    FUN_0045fb80();
    piVar6[0xc] = iVar5;
    (**(code **)(**(int **)(iVar5 + 0x844) + 0x74))();
    (**(code **)(*piVar6 + 0x38))(iVar5);
  }
  else {
    do {
      if ((int *)*piVar7 == piVar6) {
        sVar8 = sVar8 + 1;
      }
      piVar7 = piVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    if (sVar8 < 1) goto LAB_0040ef31;
  }
  if (*(char *)(param_1[0x21e] + 0x234) == '\0') {
    local_10 = operator_new(0xd18);
    uStack_4 = 2;
    if (local_10 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_00439770((void *)param_1[0x21e]);
    }
    iVar5 = *(int *)(param_1[0x21e] + 0x184);
    iVar9 = *(int *)(iVar5 + 8);
    puVar4 = *(undefined4 **)(iVar5 + 0x410);
    sVar8 = 0;
    if (iVar9 < 1) goto LAB_0040f056;
    do {
      if ((int *)*puVar4 == piVar6) {
        sVar8 = sVar8 + 1;
      }
      puVar4 = puVar4 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  else if (*(char *)(param_1[0x21e] + 0x237) == '\0') {
    local_10 = operator_new(0xd18);
    uStack_4 = 1;
    if (local_10 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      FUN_00438a30((void *)param_1[0x21e],local_10);
      *local_10 = (int)&PTR_FUN_004f7b70;
      local_10[0x21a] = (int)s_Time_Trial_Menu_0050af40;
      local_10[0x222] = (int)s_CHOOSE_A_PARTY_RACE__0050af50;
      piVar6 = local_10;
    }
    iVar5 = *(int *)(param_1[0x21e] + 0x184);
    iVar9 = *(int *)(iVar5 + 8);
    piVar7 = *(int **)(iVar5 + 0x410);
    sVar8 = 0;
    if (iVar9 < 1) goto LAB_0040f056;
    do {
      if ((int *)*piVar7 == piVar6) {
        sVar8 = sVar8 + 1;
      }
      piVar7 = piVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  else {
    local_10 = operator_new(0xcdc);
    uStack_4 = 0;
    if (local_10 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = FUN_0043a790((void *)param_1[0x21e],local_10);
    }
    iVar5 = *(int *)(param_1[0x21e] + 0x184);
    iVar9 = *(int *)(iVar5 + 8);
    piVar7 = *(int **)(iVar5 + 0x410);
    sVar8 = 0;
    if (iVar9 < 1) goto LAB_0040f056;
    do {
      if ((int *)*piVar7 == piVar6) {
        sVar8 = sVar8 + 1;
      }
      piVar7 = piVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (0 < sVar8) {
    ExceptionList = local_c;
    return;
  }
LAB_0040f056:
  uStack_4 = 0xffffffff;
  FUN_0045fb80();
  piVar6[0xc] = iVar5;
  (**(code **)(**(int **)(iVar5 + 0x844) + 0x74))();
  (**(code **)(*piVar6 + 0x38))(iVar5);
  ExceptionList = local_10;
  return;
}


