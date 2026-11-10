/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00411b10 name: candidate_Level1_vslot_32 */

/* WARNING: Removing unreachable block (ram,0x00411d05) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall candidate_Level1_vslot_32(int *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  float *pfVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined1 *puVar11;
  int local_64;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c [3];
  undefined4 local_30 [3];
  undefined4 local_24 [3];
  undefined4 local_18 [3];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dba1b;
  local_c = ExceptionList;
  iVar1 = param_1[0xd8b];
  ExceptionList = &local_c;
  *(int *)(*(int *)(param_1[0x21e] + 0x178) + 0x850) = iVar1;
  iVar9 = param_1[0xe8c];
  param_1[0xe8c] = iVar9 + 1;
  if (0xff < iVar9 + 1) {
    param_1[0xe8c] = 1;
  }
  iVar9 = param_1[0xe8c];
  param_1[iVar9 + 0xd8c] = 0;
  if (param_1[0xd8b] < 1) {
    local_64 = 0;
  }
  else {
    local_64 = *(int *)param_1[0xe8d];
    param_1[iVar9 + 0xd8c] = 1;
  }
  if (local_64 != 0) {
    do {
      iVar2 = iVar1;
      if (1 < iVar1) {
        iVar2 = 2;
      }
      puVar11 = (undefined1 *)0x0;
      pcVar3 = (char *)FUN_0046b9b0((byte *)s_START_d__d_0050d324,(wchar_t)iVar2);
      pfVar4 = (float *)FUN_00471770(param_1[0x22b],local_3c,pcVar3,puVar11);
      if (&local_54 != pfVar4) {
        local_54 = *pfVar4;
        local_50 = pfVar4[1];
        local_4c = pfVar4[2];
      }
      if (*(char *)(param_1[0x21e] + 0x237) != '\0') {
        iVar2 = iVar1;
        if (1 < iVar1) {
          iVar2 = 2;
        }
        puVar11 = (undefined1 *)0x0;
        pcVar3 = (char *)FUN_0046b9b0((byte *)s_START_d__d_0050d330,(wchar_t)iVar2);
        pfVar4 = (float *)FUN_00471770(param_1[0x22b],local_30,pcVar3,puVar11);
        if (&local_54 != pfVar4) {
          local_54 = *pfVar4;
          local_50 = pfVar4[1];
          local_4c = pfVar4[2];
        }
      }
      if (param_1[0xd8b] == 1) {
        iVar2 = *(int *)(*(int *)(param_1[0x21e] + 0x220) + 8);
        if ((((iVar2 == 5) || (iVar2 == 0xb)) || (iVar2 == 0xc)) || (iVar2 == 0xe)) {
          uVar5 = (&DAT_0050f1cc)[DAT_0050f1c8] + (&DAT_0050f1cc)[DAT_0050f1c4] & 0x3fffffff;
          (&DAT_0050f1cc)[DAT_0050f1c4] = uVar5;
          DAT_0050f1c4 = DAT_0050f1c4 + 1;
          if (DAT_0050f1c4 == 0x37) {
            DAT_0050f1c4 = 0;
          }
          DAT_0050f1c8 = DAT_0050f1c8 + 1;
          if (DAT_0050f1c8 == 0x37) {
            DAT_0050f1c8 = 0;
          }
          puVar11 = (undefined1 *)0x0;
          if (((int)uVar5 >> 6 & 1U) == 0) {
            pcVar3 = (char *)FUN_0046b9b0((byte *)s_START2_1_0050d33c,L'\0');
            pfVar4 = (float *)FUN_00471770(param_1[0x22b],local_24,pcVar3,puVar11);
            if (&local_54 != pfVar4) {
              local_54 = *pfVar4;
              local_50 = pfVar4[1];
              local_4c = pfVar4[2];
            }
          }
          else {
            pcVar3 = (char *)FUN_0046b9b0((byte *)s_START2_2_0050d348,L'\0');
            pfVar4 = (float *)FUN_00471770(param_1[0x22b],local_18,pcVar3,puVar11);
            if (&local_54 != pfVar4) {
              local_54 = *pfVar4;
              local_50 = pfVar4[1];
              local_4c = pfVar4[2];
            }
          }
        }
        if ((param_1[0xd8b] == 1) &&
           (((FUN_00471770(param_1[0x22b],&local_48,s_START_DEBUG_0050d354,(undefined1 *)0x0),
             local_48 != _DAT_004f91b0 || (local_44 != _DAT_004f91b0)) ||
            (local_40 != _DAT_004f91b0)))) {
          local_54 = local_48;
          local_50 = local_44;
          local_4c = local_40;
        }
      }
      puVar6 = operator_new(0xc60);
      piVar8 = (int *)0x0;
      local_4 = 0;
      if (puVar6 != (undefined4 *)0x0) {
        piVar8 = FUN_00401700(puVar6,(int)param_1);
      }
      local_4 = 0xffffffff;
      (**(code **)(*piVar8 + 4))();
      iVar2 = *(int *)(local_64 + 0x14);
      FUN_00401030(piVar8,&PTR_LAB_004f90c0,(float)param_1[iVar2 * 5 + 0xeab],
                   (float)param_1[iVar2 * 5 + 0xeac],(float)param_1[iVar2 * 5 + 0xead],
                   (float)param_1[iVar2 * 5 + 0xeae]);
      iVar2 = *(int *)(local_64 + 0x14);
      piVar8[0x5a] = (int)(local_50 + _DAT_004f9378);
      piVar8[6] = iVar2;
      piVar8[0x9e] = 0x3f000000;
      piVar8[0x9f] = 0x3dcccccd;
      piVar8[0xa1] = 0x41d00000;
      piVar8[0x68] = 0x3f866666;
      piVar8[0x62] = 0x40a00000;
      piVar8[0x59] = (int)local_54;
      piVar8[0x5b] = (int)local_4c;
      if (param_1[0xb79] == 0) {
        if (param_1[0xa75] == 0) {
          param_1[0xa75] = 1;
          pvVar7 = _malloc(4);
          param_1[0xb77] = (int)pvVar7;
          piVar10 = param_1 + 0xa76;
          for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar10 = 0;
            piVar10 = piVar10 + 1;
          }
          *(int **)param_1[0xb77] = piVar8;
        }
        else {
          iVar2 = param_1[0xa75] + 1;
          param_1[0xa75] = iVar2;
          pvVar7 = _realloc((void *)param_1[0xb77],iVar2 * 4);
          param_1[0xb77] = (int)pvVar7;
          *(int **)((int)pvVar7 + param_1[0xa75] * 4 + -4) = piVar8;
        }
      }
      else {
        FUN_0045fc20((int)(param_1 + 0xa74),(int)piVar8);
      }
      *(undefined1 *)((int)piVar8 + 0x281) = 0;
      *(undefined1 *)((int)piVar8 + 0x769) = 1;
      *(int **)(local_64 + 0x10) = piVar8;
      iVar2 = param_1[iVar9 + 0xd8c];
      if (param_1[0xd8b] <= iVar2) break;
      local_64 = *(int *)(param_1[0xe8d] + iVar2 * 4);
      param_1[iVar9 + 0xd8c] = iVar2 + 1;
    } while (local_64 != 0);
  }
  iVar1 = *(int *)(param_1[0x22b] + 0x480);
  iVar9 = *(int *)(iVar1 + 0xc9c) + 1;
  *(int *)(iVar1 + 0xc9c) = iVar9;
  if (0xff < iVar9) {
    *(undefined4 *)(iVar1 + 0xc9c) = 1;
  }
  iVar1 = *(int *)(iVar1 + 0xc9c);
  iVar9 = *(int *)(param_1[0x22b] + 0x480);
  puVar6 = (undefined4 *)0x0;
  *(undefined4 *)(iVar9 + 0x89c + iVar1 * 4) = 0;
  if (0 < *(int *)(iVar9 + 0x898)) {
    puVar6 = (undefined4 *)**(undefined4 **)(iVar9 + 0xca0);
    *(undefined4 *)(iVar9 + 0x89c + iVar1 * 4) = 1;
  }
  while (puVar6 != (undefined4 *)0x0) {
    iVar9 = __strnicmp((char *)*puVar6,s_SAFESPOT_0050d360,8);
    if ((iVar9 == 0) || (iVar9 = __strnicmp((char *)*puVar6,s_SAFEPOS_0050d36c,7), iVar9 == 0)) {
      if (param_1[0x64b] == 0) {
        if (param_1[0x547] == 0) {
          param_1[0x547] = 1;
          pvVar7 = _malloc(4);
          param_1[0x649] = (int)pvVar7;
          piVar8 = param_1 + 0x548;
          for (iVar9 = 0x100; iVar9 != 0; iVar9 = iVar9 + -1) {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
          }
          *(undefined4 **)param_1[0x649] = puVar6;
        }
        else {
          iVar9 = param_1[0x547] + 1;
          param_1[0x547] = iVar9;
          pvVar7 = _realloc((void *)param_1[0x649],iVar9 * 4);
          param_1[0x649] = (int)pvVar7;
          *(undefined4 **)((int)pvVar7 + param_1[0x547] * 4 + -4) = puVar6;
        }
      }
      else {
        FUN_0045fc20((int)(param_1 + 0x546),(int)puVar6);
      }
    }
    iVar9 = *(int *)(param_1[0x22b] + 0x480);
    iVar2 = *(int *)(iVar9 + 0x89c + iVar1 * 4);
    if (*(int *)(iVar9 + 0x898) <= iVar2) break;
    puVar6 = *(undefined4 **)(*(int *)(iVar9 + 0xca0) + iVar2 * 4);
    *(int *)(iVar9 + 0x89c + iVar1 * 4) = iVar2 + 1;
  }
  if ((*(int *)(param_1[0x21e] + 0x23c) != 0) || (*(char *)(param_1[0x21e] + 0x237) != '\0')) {
    FUN_00412360((int)param_1);
  }
  if ((*(int *)(param_1[0x21e] + 0x23c) != 0) || (*(char *)(param_1[0x21e] + 0x237) != '\0')) {
    FUN_00412670((int)param_1);
  }
  FUN_00412140();
  FUN_00412830();
  FUN_004129d0((int)param_1);
  FUN_00412bc0(param_1);
  ExceptionList = local_c;
  return;
}


