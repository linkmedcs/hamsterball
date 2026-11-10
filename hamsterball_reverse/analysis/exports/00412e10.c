/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00412e10 name: candidate_Level1_vslot_29 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall candidate_Level1_vslot_29(void *this,int *param_1,int *param_2)

{
  char cVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  char *pcVar8;
  char *pcVar9;
  void *pvVar10;
  undefined **ppuVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  short sVar18;
  byte *pbVar19;
  bool bVar20;
  float10 fVar21;
  ulonglong uVar22;
  double dVar23;
  uint uStack_40;
  undefined **local_3c;
  undefined **ppuStack_38;
  undefined **local_34;
  int local_2c;
  undefined1 local_28;
  undefined **ppuStack_24;
  undefined **ppuStack_1c;
  undefined **ppuStack_14;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar16 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004db828;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar5 = __strnicmp(*(char **)(param_2[1] + 0x864),s_N_SECRET_0050d3fc,8);
  if (iVar5 == 0) {
    *(undefined1 *)(*(int *)(*param_2 + 0x47c) + 0x10e4) = 1;
  }
  iVar5 = __strnicmp(*(char **)(param_2[1] + 0x864),s_N_UNLOCKSECRET_0050d408,0xe);
  if (iVar5 == 0) {
    FUN_00428c70();
  }
  iVar5 = __strnicmp(*(char **)(param_2[1] + 0x864),s_E_NODIZZY_0050d418,9);
  if (iVar5 == 0) {
    local_3c = &PTR_FUN_004f4fd8;
    local_34 = (undefined **)0x0;
    local_2c = 0;
    local_28 = 1;
    local_4 = 0;
    FUN_0047a5c0();
    puVar6 = FUN_0047a620();
    while (puVar6 != (undefined4 *)0x0) {
      iVar5 = __stricmp((char *)puVar6[1],&DAT_0050d424);
      if (iVar5 == 0) {
        lVar7 = _atol((char *)puVar6[2]);
        if (lVar7 <= param_1[0xbd]) {
          lVar7 = param_1[0xbd];
        }
        param_1[0xbd] = lVar7;
        param_1[0xbb] = 0;
      }
      (**(code **)*puVar6)(1);
      puVar6 = FUN_0047a620();
    }
    local_4 = 0xffffffff;
    if (local_2c != 0) {
      __close(local_2c);
    }
    _free(local_34);
  }
  iVar5 = __strnicmp(*(char **)(param_2[1] + 0x864),s_E_SAFESWITCH_0050d42c,0xc);
  if (iVar5 == 0) {
    pcVar8 = _strchr(*(char **)(param_2[1] + 0x864),0x28);
    if (pcVar8 == (char *)0x0) {
      *(undefined1 *)(param_1 + 0x30b) = DAT_00510889;
    }
    else {
      iVar5 = 0xc2c - (int)pcVar8;
      do {
        cVar1 = *pcVar8;
        pcVar8[(int)param_1 + iVar5] = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
    }
  }
  iVar5 = __stricmp(*(char **)(param_2[1] + 0x864),s_E_LIMIT_0050d43c);
  if (iVar5 == 0) {
    *(undefined1 *)(param_1 + 0x1da) = 0;
    *(undefined1 *)((int)param_1 + 0x2e9) = 1;
    if (((*(char *)(*(int *)((int)this + 0x878) + 0x237) != '\0') && (param_1[6] != -1)) &&
       (*(char *)(param_1[5] + 0x47b8) == '\0')) {
      iVar17 = 0;
      iVar5 = 0;
      piVar15 = (int *)(param_1[5] + 0x47a8);
      do {
        iVar14 = *(int *)((int)this + 0x878) + iVar5;
        if (((*(char *)(iVar14 + 0x5d3) == '\0') && (iVar17 != param_1[6])) &&
           ((iVar14 = *(int *)(iVar14 + 0x5d8), *(char *)(iVar14 + 0x768) != '\0' &&
            (*(char *)(iVar14 + 0x2f8) == '\0')))) {
          *piVar15 = *piVar15 + 1;
        }
        iVar5 = iVar5 + 0xa0;
        iVar17 = iVar17 + 1;
        piVar15 = piVar15 + 1;
      } while (iVar5 < 0x280);
    }
  }
  iVar5 = __stricmp(*(char **)(param_2[1] + 0x864),s_E_BREAK_0050d444);
  if (iVar5 == 0) {
    (**(code **)(*param_1 + 0x20))();
  }
  iVar5 = __stricmp(*(char **)(param_2[1] + 0x864),s_E_JUMP_0050d44c);
  if ((iVar5 == 0) && (param_1[0x1f7] < 1)) {
    iVar5 = *(int *)(*(int *)((int)this + 0x878) + 0x498);
    FUN_0046be80((float)param_1[0x59],(float)param_1[0x5a],(float)param_1[0x5b]);
    FUN_00467bd0(iVar5);
    param_1[0x1f7] = 10;
    param_1[0x202] = 10;
    iVar5 = param_1[0xbd];
    param_1[0xa7] = 0x3b03126f;
    param_1[0xa8] = 1;
    if (iVar5 < 200) {
      iVar5 = 200;
    }
    param_1[0xbd] = iVar5;
    param_1[0xbb] = 0;
  }
  iVar5 = __strnicmp(*(char **)(param_2[1] + 0x864),s_E_ACTION_0050d454,8);
  if (iVar5 == 0) {
    local_3c = &PTR_FUN_004f4fd8;
    local_34 = (undefined **)0x0;
    local_2c = 0;
    local_28 = 1;
    local_4 = 1;
    FUN_0047a5c0();
    puVar6 = FUN_0047a620();
    while (puVar6 != (undefined4 *)0x0) {
      iVar5 = __stricmp((char *)puVar6[1],&DAT_0050d460);
      if ((iVar5 == 0) &&
         ((iVar5 = __stricmp((char *)puVar6[2],&DAT_0050d468), iVar5 == 0 ||
          (iVar5 = __stricmp((char *)puVar6[2],(char *)&PTR_DAT_0050d470), iVar5 == 0)))) {
        iVar5 = piVar16[0xcc];
        piVar15 = (int *)piVar16[0x1ce];
        sVar18 = 0;
        if (0 < iVar5) {
          do {
            if (*piVar15 == param_2[1]) {
              sVar18 = sVar18 + 1;
            }
            piVar15 = piVar15 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          if (0 < sVar18) break;
        }
        FUN_0045fb80();
      }
      iVar5 = __stricmp((char *)puVar6[1],s_SCORE_0050d474);
      if (iVar5 == 0) {
        lVar7 = _atol((char *)puVar6[2]);
        param_1 = (int *)(float)lVar7;
        iVar5 = *(int *)((int)this + 0x878);
        iVar17 = *(int *)(iVar5 + 0x23c);
        if (iVar17 == 0) {
          param_1 = (int *)((float)param_1 / _DAT_004f91c8);
        }
        else if (iVar17 != 1) {
          if (iVar17 == 2) {
            param_1 = (int *)((float)param_1 + (float)param_1);
          }
          else {
            param_1 = (int *)0x0;
          }
        }
        *(float *)(piVar16[6] * 0xa0 + 0x5e0 + iVar5) =
             (float)param_1 + *(float *)(piVar16[6] * 0xa0 + 0x5e0 + iVar5);
        uVar22 = FUN_004d9e34();
        pcVar8 = (char *)FUN_0046b9b0(&DAT_0050d47c,(wchar_t)uVar22);
        if ((void *)piVar16[0x30a] != (void *)0x0) {
          _free((void *)piVar16[0x30a]);
        }
        pcVar9 = pcVar8;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        pvVar10 = operator_new((uint)(pcVar9 + (1 - (int)(pcVar8 + 1))));
        piVar16[0x30a] = (int)pvVar10;
        iVar5 = (int)pvVar10 - (int)pcVar8;
        do {
          cVar1 = *pcVar8;
          pcVar8[iVar5] = cVar1;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        piVar16[3] = 200;
      }
      puVar6 = FUN_0047a620();
    }
    local_4 = 0xffffffff;
    if (local_2c != 0) {
      __close(local_2c);
    }
    _free(local_34);
  }
  ppuVar11 = (undefined **)__strnicmp(*(char **)(param_2[1] + 0x864),s_E_TRAJECTORY_0050d480,0xc);
  if (ppuVar11 == (undefined **)0x0) {
    ppuStack_24 = &PTR_FUN_004f4fd8;
    uStack_10 = 1;
    local_4 = 2;
    local_3c = ppuVar11;
    ppuStack_38 = ppuVar11;
    local_34 = ppuVar11;
    ppuStack_1c = ppuVar11;
    ppuStack_14 = ppuVar11;
    FUN_0047a5c0();
    puVar6 = FUN_0047a620();
    while (puVar6 != (undefined4 *)0x0) {
      iVar5 = __stricmp((char *)puVar6[1],&DAT_0050d490);
      if (iVar5 == 0) {
        dVar23 = _atof((char *)puVar6[2]);
        local_3c = (undefined **)(float)dVar23;
      }
      iVar5 = __stricmp((char *)puVar6[1],&DAT_0050d494);
      if (iVar5 == 0) {
        dVar23 = _atof((char *)puVar6[2]);
        ppuStack_38 = (undefined **)(float)dVar23;
      }
      iVar5 = __stricmp((char *)puVar6[1],&DAT_0050d498);
      if (iVar5 == 0) {
        dVar23 = _atof((char *)puVar6[2]);
        local_34 = (undefined **)(float)dVar23;
      }
      (**(code **)*puVar6)(1);
      puVar6 = FUN_0047a620();
    }
    iVar5 = piVar16[0x69];
    if ((undefined ***)(iVar5 + 0xca4) != &local_3c) {
      *(undefined ***)(iVar5 + 0xca4) = local_3c;
      *(undefined ***)(iVar5 + 0xca8) = ppuStack_38;
      *(undefined ***)(iVar5 + 0xcac) = local_34;
    }
    local_4 = 0xffffffff;
    if (ppuStack_14 != (undefined **)0x0) {
      __close((int)ppuStack_14);
    }
    _free(ppuStack_1c);
  }
  iVar5 = __stricmp(*(char **)(param_2[1] + 0x864),s_N_NOCONTROL_0050d49c);
  if (iVar5 == 0) {
    piVar16[0x202] = 10;
  }
  iVar5 = __stricmp(*(char **)(param_2[1] + 0x864),s_N_WATER_0050d4a8);
  if (iVar5 == 0) {
    *(undefined1 *)((int)piVar16 + 0x2d5) = 1;
    piVar16[0xb6] = 10;
  }
  iVar5 = __stricmp(*(char **)(param_2[1] + 0x864),s_N_TARPIT_0050d4b0);
  if (iVar5 == 0) {
    if ((char)piVar16[0xb3] == '\0') {
      piVar16[0xb4] = piVar16[0x5a];
      iVar5 = *(int *)(*(int *)((int)this + 0x878) + 0x480);
      FUN_0046be80((float)piVar16[0x59],(float)piVar16[0x5a],(float)piVar16[0x5b]);
      FUN_00467bd0(iVar5);
    }
    *(undefined1 *)(piVar16 + 0xb3) = 1;
    *(undefined1 *)(piVar16 + 0x1da) = 0;
  }
  iVar5 = __stricmp((char *)(*(int *)(param_2[1] + 0x864) + 2),s_DROPIN_0050d4bc);
  if (((iVar5 == 0) && (fVar21 = FUN_0040c0f0(), (float10)_DAT_004f91c8 < fVar21)) &&
     (piVar16[0x1f2] < 1)) {
    FUN_00467bd0(*(int *)(*(int *)((int)this + 0x878) + 0x45c));
    iVar5 = piVar16[0xbd];
    piVar16[0x1f2] = 0x32;
    if (iVar5 < 200) {
      iVar5 = 200;
    }
    piVar16[0xbd] = iVar5;
    piVar16[0xbb] = 0;
  }
  iVar5 = __stricmp((char *)(*(int *)(param_2[1] + 0x864) + 2),s_PIPEBONK_0050d4c4);
  if ((iVar5 == 0) && (piVar16[500] < 1)) {
    iVar5 = 2;
    do {
      iVar5 = iVar5 * 2;
    } while (iVar5 < 5);
    (&DAT_0050f1cc)[DAT_0050f1c4] =
         (&DAT_0050f1cc)[DAT_0050f1c8] + (&DAT_0050f1cc)[DAT_0050f1c4] & 0x3fffffff;
    iVar5 = DAT_0050f1c4 + 1;
    if (iVar5 == 0x37) {
      iVar5 = 0;
    }
    iVar17 = DAT_0050f1c8 + 1;
    if (iVar17 == 0x37) {
      iVar17 = 0;
    }
    local_3c = (undefined **)piVar16[0x59];
    fVar3 = (float)piVar16[0x5b];
    fVar4 = (float)piVar16[0x5a];
    iVar14 = 2;
    do {
      iVar14 = iVar14 * 2;
    } while (iVar14 < 3);
    uVar12 = (&DAT_0050f1cc)[iVar17] + (&DAT_0050f1cc)[iVar5] & 0x3fffffff;
    (&DAT_0050f1cc)[iVar5] = uVar12;
    DAT_0050f1c4 = iVar5 + 1;
    if (DAT_0050f1c4 == 0x37) {
      DAT_0050f1c4 = 0;
    }
    DAT_0050f1c8 = iVar17 + 1;
    if (DAT_0050f1c8 == 0x37) {
      DAT_0050f1c8 = 0;
    }
    iVar5 = *(int *)(*(int *)((int)this + 0x878) + 0x468 +
                    (((int)uVar12 >> 6 & iVar14 - 1U) % 3) * 4);
    FUN_0046be80((float)local_3c,fVar4,fVar3);
    FUN_00467bd0(iVar5);
    iVar5 = piVar16[0xbd];
    piVar16[500] = 10;
    if (iVar5 < 100) {
      iVar5 = 100;
    }
    piVar16[0xbd] = iVar5;
    piVar16[0xbb] = 0;
  }
  iVar5 = __stricmp((char *)(*(int *)(param_2[1] + 0x864) + 2),s_POPOUT_0050d4d0);
  if ((iVar5 == 0) && (piVar16[499] < 1)) {
    FUN_00467bd0(*(int *)(*(int *)((int)this + 0x878) + 0x464));
    iVar5 = piVar16[0xbd];
    piVar16[499] = 0x32;
    if (iVar5 < 100) {
      iVar5 = 100;
    }
    piVar16[0xbd] = iVar5;
    piVar16[0xbb] = 0;
  }
  iVar5 = __stricmp((char *)(*(int *)(param_2[1] + 0x864) + 2),&DAT_0050d4d8);
  if ((iVar5 == 0) && (piVar16[0x1f5] < 1)) {
    FUN_00467bd0(*(int *)(*(int *)((int)this + 0x878) + 0x4c8));
    piVar16[0x1f5] = 0x32;
  }
  pbVar13 = *(byte **)(param_2[1] + 0x864);
  pbVar19 = &DAT_0050d4dc;
  do {
    bVar2 = *pbVar13;
    bVar20 = bVar2 < *pbVar19;
    if (bVar2 != *pbVar19) {
LAB_00413894:
      iVar5 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
      goto LAB_00413899;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar13[1];
    bVar20 = bVar2 < pbVar19[1];
    if (bVar2 != pbVar19[1]) goto LAB_00413894;
    pbVar13 = pbVar13 + 2;
    pbVar19 = pbVar19 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_00413899:
  if (((iVar5 == 0) && ((char)piVar16[0x53] == '\0')) && ((char)piVar16[0x1da] != '\0')) {
    if (*(char *)((int)this + 0xcd0) == '\0') {
      *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Reach_Goal_1_0050d4e4;
      FUN_00477f40(s_Goal__0050d4f4);
      iVar5 = *(int *)((int)this + 0x878);
      *(undefined1 *)((int)this + 0xcd0) = 1;
      if (((*(char *)(*(int *)(iVar5 + 0x220) + 0x11) != '\0') && (*(char *)(iVar5 + 0x234) == '\0')
          ) && (*(int *)(iVar5 + 0x908) != 0)) {
        *(undefined4 *)(*(int *)(iVar5 + 0x908) + 0x524) = *(undefined4 *)(iVar5 + 0x5e4);
      }
      *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Reach_Goal_2_0050d4fc;
    }
    *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Reach_Goal_3_0050d50c;
    iVar5 = piVar16[6] * 0xa0 + *(int *)((int)this + 0x878);
    if (*(char *)(iVar5 + 0x5d2) == '\0') {
      *(undefined4 *)(iVar5 + 0x5f8) = 1;
    }
    *(undefined1 *)(piVar16[6] * 0xa0 + 0x5d2 + *(int *)((int)this + 0x878)) = 1;
    *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Reach_Goal_4_0050d51c;
    *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x294) + 4) =
         *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x29c) + 4);
    *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x2b4) + 4) =
         *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 700) + 4);
    *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Reach_Goal_5_0050d52c;
    iVar5 = *(int *)((int)this + 0x878);
    if (*(char *)(iVar5 + 0x236) != '\0') {
      *(undefined4 *)(*(int *)(iVar5 + 0x294) + 4) = *(undefined4 *)(*(int *)(iVar5 + 0x2a4) + 4);
      *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x2b4) + 4) =
           *(undefined4 *)(*(int *)(*(int *)((int)this + 0x878) + 0x2c4) + 4);
    }
    *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Reach_Goal_6_0050d53c;
    if (*(char *)(*(int *)((int)this + 0x878) + piVar16[6] * -0xa0 + 0x68c) == '\0') {
      *(undefined1 *)(piVar16[6] * 0xa0 + 0x5ec + *(int *)((int)this + 0x878)) = 1;
    }
    *(char **)(*(int *)((int)this + 0x878) + 0x210) = s_Update_0050d54c;
  }
  pbVar13 = *(byte **)(param_2[1] + 0x864);
  pcVar8 = s_N_MOUSETRAP_0050d554;
  do {
    bVar2 = *pbVar13;
    bVar20 = bVar2 < (byte)*pcVar8;
    if (bVar2 != *pcVar8) {
LAB_00413a89:
      iVar5 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
      goto LAB_00413a8e;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar13[1];
    bVar20 = bVar2 < (byte)pcVar8[1];
    if (bVar2 != pcVar8[1]) goto LAB_00413a89;
    pbVar13 = pbVar13 + 2;
    pcVar8 = pcVar8 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_00413a8e:
  if (iVar5 == 0) {
    iVar5 = 2;
    do {
      iVar5 = iVar5 * 2;
    } while (iVar5 < 0x32);
    uVar12 = (&DAT_0050f1cc)[DAT_0050f1c8] + (&DAT_0050f1cc)[DAT_0050f1c4] & 0x3fffffff;
    (&DAT_0050f1cc)[DAT_0050f1c4] = uVar12;
    DAT_0050f1c4 = DAT_0050f1c4 + 1;
    if (DAT_0050f1c4 == 0x37) {
      DAT_0050f1c4 = 0;
    }
    DAT_0050f1c8 = DAT_0050f1c8 + 1;
    if (DAT_0050f1c8 == 0x37) {
      DAT_0050f1c8 = 0;
    }
    uStack_40 = ((int)uVar12 >> 6 & iVar5 - 1U) % 0x32;
    iVar5 = FUN_00467280(&PTR_PTR_0050f1c0,2,'\0');
    if (iVar5 == 1) {
      uStack_40 = -uStack_40;
    }
    iVar5 = 2;
    do {
      iVar5 = iVar5 * 2;
    } while (iVar5 < 0x32);
    uVar12 = (&DAT_0050f1cc)[DAT_0050f1c8] + (&DAT_0050f1cc)[DAT_0050f1c4] & 0x3fffffff;
    (&DAT_0050f1cc)[DAT_0050f1c4] = uVar12;
    DAT_0050f1c4 = DAT_0050f1c4 + 1;
    if (DAT_0050f1c4 == 0x37) {
      DAT_0050f1c4 = 0;
    }
    DAT_0050f1c8 = DAT_0050f1c8 + 1;
    if (DAT_0050f1c8 == 0x37) {
      DAT_0050f1c8 = 0;
    }
    param_1 = (int *)(((int)uVar12 >> 6 & iVar5 - 1U) % 0x32);
    iVar5 = FUN_00467280(&PTR_PTR_0050f1c0,2,'\0');
    if (iVar5 == 1) {
      param_1 = (int *)-(int)param_1;
    }
    local_3c = (undefined **)(float)(int)param_1;
    ppuStack_38 = (undefined **)0x0;
    local_34 = (undefined **)(float)(int)uStack_40;
    FUN_0040c0f0();
    iVar5 = piVar16[0x69];
    if (&local_3c != (undefined ***)(iVar5 + 0xca4)) {
      local_3c = *(undefined ***)(iVar5 + 0xca4);
      ppuStack_38 = *(undefined ***)(iVar5 + 0xca8);
      local_34 = *(undefined ***)(iVar5 + 0xcac);
    }
    fVar21 = FUN_0040c0f0();
    param_1 = (int *)(float)fVar21;
    if (_DAT_004f91b0 < (float)param_1) {
      param_1 = (int *)(_DAT_004f91a0 / (float)param_1);
    }
    iVar5 = piVar16[0x69];
    local_3c = (undefined **)((float)param_1 * (float)local_3c * _DAT_004f9224);
    local_34 = (undefined **)((float)local_34 * (float)param_1 * _DAT_004f9224);
    if ((undefined ***)(iVar5 + 0xca4) != &local_3c) {
      *(undefined ***)(iVar5 + 0xca4) = local_3c;
      *(undefined4 *)(iVar5 + 0xca8) = 0x41700000;
      *(undefined ***)(iVar5 + 0xcac) = local_34;
    }
    iVar5 = *(int *)((int)this + 0x1d38) + 1;
    *(int *)((int)this + 0x1d38) = iVar5;
    if (0xff < iVar5) {
      *(undefined4 *)((int)this + 0x1d38) = 1;
    }
    iVar5 = *(int *)((int)this + 0x1d38) * 4;
    *(undefined4 *)(iVar5 + 0x1938 + (int)this) = 0;
    if (*(int *)((int)this + 0x1934) < 1) {
      iVar17 = 0;
    }
    else {
      iVar17 = **(int **)((int)this + 0x1d3c);
      *(undefined4 *)(iVar5 + 0x1938 + (int)this) = 1;
    }
    if (iVar17 != 0) {
      while (*(int *)(*param_2 + 0x47c) != *(int *)(iVar17 + 0x10d4)) {
        iVar14 = *(int *)(iVar5 + 0x1938 + (int)this);
        if (*(int *)((int)this + 0x1934) <= iVar14) {
          ExceptionList = pvStack_c;
          return;
        }
        iVar17 = *(int *)(*(int *)((int)this + 0x1d3c) + iVar14 * 4);
        *(int *)(iVar5 + 0x1938 + (int)this) = iVar14 + 1;
        if (iVar17 == 0) {
          ExceptionList = pvStack_c;
          return;
        }
      }
      FUN_00467bd0(*(int *)(*(int *)(*(int *)(iVar17 + 0x10d0) + 0x878) + 0x454));
      *(undefined1 *)(iVar17 + 0x10d8) = 1;
      *(undefined4 *)(iVar17 + 0x10ec) = 0x42480000;
      iVar5 = *(int *)((int)this + 0x257c);
      piVar16 = *(int **)((int)this + 0x2984);
      sVar18 = 0;
      if (0 < iVar5) {
        do {
          if (*piVar16 == iVar17) {
            sVar18 = sVar18 + 1;
          }
          piVar16 = piVar16 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        if (0 < sVar18) {
          ExceptionList = pvStack_c;
          return;
        }
      }
      FUN_0045fb80();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


