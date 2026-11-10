/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040fbc0 name: candidate_Level1_vslot_19 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall candidate_Level1_vslot_19(int param_1)

{
  int iVar1;
  float fVar2;
  void **ppvVar3;
  char cVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_14 = ExceptionList;
  local_c = 0xffffffff;
  puStack_10 = &LAB_004db1cb;
  ExceptionList = &local_14;
  iVar8 = *(int *)(param_1 + 0x3f14);
  ppvVar3 = &local_14;
  if (iVar8 != 0) {
    *(float *)(iVar8 + 0x28) = *(float *)(iVar8 + 0x28) + _DAT_004f91cc;
    ppvVar3 = ExceptionList;
  }
  ExceptionList = ppvVar3;
  iVar8 = *(int *)(param_1 + 0x2980) + 1;
  *(int *)(param_1 + 0x2980) = iVar8;
  if (0xff < iVar8) {
    *(undefined4 *)(param_1 + 0x2980) = 1;
  }
  iVar8 = *(int *)(param_1 + 0x2980);
  *(undefined4 *)(param_1 + 0x2580 + iVar8 * 4) = 0;
  if (*(int *)(param_1 + 0x257c) < 1) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)**(undefined4 **)(param_1 + 0x2984);
    *(undefined4 *)(param_1 + 0x2580 + iVar8 * 4) = 1;
  }
  while (piVar9 != (int *)0x0) {
    cVar4 = (**(code **)(*piVar9 + 0x2c))();
    if (cVar4 == '\0') {
      FUN_0045fe10((int)piVar9);
    }
    iVar10 = *(int *)(param_1 + 0x2580 + iVar8 * 4);
    if (*(int *)(param_1 + 0x257c) <= iVar10) break;
    piVar9 = *(int **)(*(int *)(param_1 + 0x2984) + iVar10 * 4);
    *(int *)(param_1 + 0x2580 + iVar8 * 4) = iVar10 + 1;
  }
  fVar2 = *(float *)(param_1 + 0x3620) - (float)_DAT_004f94a0;
  *(float *)(param_1 + 0x3620) = fVar2;
  if (fVar2 < _DAT_004f91b0) {
    *(undefined4 *)(param_1 + 0x3620) = 0;
  }
  if (*(int *)(param_1 + 0x361c) == 0x19) {
    iVar8 = *(int *)(param_1 + 0x3a30) + 1;
    *(int *)(param_1 + 0x3a30) = iVar8;
    if (0xff < iVar8) {
      *(undefined4 *)(param_1 + 0x3a30) = 1;
    }
    iVar8 = *(int *)(param_1 + 0x3a30) * 4;
    *(undefined4 *)(iVar8 + 0x3630 + param_1) = 0;
    if (*(int *)(param_1 + 0x362c) < 1) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(param_1 + 0x3a34);
      *(undefined4 *)(iVar8 + 0x3630 + param_1) = 1;
    }
    while (iVar10 != 0) {
      if (*(int *)(iVar10 + 0x20) != 0) {
        puVar5 = operator_new(0x30);
        puVar7 = (undefined4 *)0x0;
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = &PTR_LAB_004f6508;
          puVar5[1] = param_1;
          puVar5[2] = iVar10;
          puVar5[3] = *(undefined4 *)(param_1 + 0x878);
          *(int *)(param_1 + 0x8b4) = *(int *)(param_1 + 0x8b4) + 1;
          puVar5[4] = 0;
          *(undefined1 *)(puVar5 + 6) = 0;
          *(undefined1 *)(puVar5 + 10) = 0;
          *(undefined1 *)((int)puVar5 + 0x29) = 0;
          *(undefined1 *)((int)puVar5 + 0x2a) = 0;
          *(undefined1 *)((int)puVar5 + 0x19) = 1;
          *puVar5 = &PTR_FUN_004f6544;
          puVar5[5] = 200000;
          puVar5[7] = 200;
          puVar5[8] = 0x42480000;
          puVar5[9] = 0x43480000;
          puVar5[0xb] = s_RACE_TIME__0050d2b4;
          puVar7 = puVar5;
        }
        if (*(int *)(param_1 + 0xccc) == 0) {
          if (*(int *)(param_1 + 0x8bc) == 0) {
            *(undefined4 *)(param_1 + 0x8bc) = 1;
            pvVar6 = _malloc(4);
            *(void **)(param_1 + 0xcc4) = pvVar6;
            puVar5 = (undefined4 *)(param_1 + 0x8c0);
            for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            **(undefined4 **)(param_1 + 0xcc4) = puVar7;
          }
          else {
            iVar10 = *(int *)(param_1 + 0x8bc) + 1;
            *(int *)(param_1 + 0x8bc) = iVar10;
            pvVar6 = _realloc(*(void **)(param_1 + 0xcc4),iVar10 * 4);
            *(void **)(param_1 + 0xcc4) = pvVar6;
            *(undefined4 **)((int)pvVar6 + *(int *)(param_1 + 0x8bc) * 4 + -4) = puVar7;
          }
        }
        else {
          FUN_0045fc20(param_1 + 0x8b8,(int)puVar7);
        }
      }
      iVar1 = *(int *)(iVar8 + 0x3630 + param_1);
      if (*(int *)(param_1 + 0x362c) <= iVar1) break;
      iVar10 = *(int *)(*(int *)(param_1 + 0x3a34) + iVar1 * 4);
      *(int *)(iVar8 + 0x3630 + param_1) = iVar1 + 1;
    }
  }
  if (*(char *)(param_1 + 0x3a48) == '\0') {
    if ((*(int *)(param_1 + 0x8b4) == 0) && (0x19 < *(int *)(param_1 + 0x361c))) {
      iVar8 = 0;
      do {
        fVar2 = *(float *)(param_1 + 0x3a50) + (float)_DAT_004f91d0;
        *(float *)(param_1 + 0x3a50) = fVar2;
        if (((*(int *)(param_1 + 0x3a4c) == 2) && ((float)_DAT_004f9498 <= fVar2)) &&
           (*(char *)(param_1 + 0x3a54) != '\0')) {
          FUN_00467bd0(*(int *)(*(int *)(param_1 + 0x878) + 0x440));
          *(undefined1 *)(param_1 + 0x3a54) = 0;
        }
        local_20 = (uint)(*(int *)(param_1 + 0x3a4c) == 2) << 1;
        if ((double)local_20 + _DAT_004f9490 < (double)*(float *)(param_1 + 0x3a50)) {
          iVar10 = *(int *)(param_1 + 0x3a4c) + 1;
          *(undefined4 *)(param_1 + 0x3a50) = 0;
          *(int *)(param_1 + 0x3a4c) = iVar10;
          if (2 < iVar10) {
            *(undefined1 *)(param_1 + 0x3a48) = 1;
            break;
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 3);
    }
    if (*(char *)(param_1 + 0x3a48) == '\0') {
      ExceptionList = local_14;
      return;
    }
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x878) + 0x220);
  if ((*(char *)(iVar8 + 0x10) == '\0') && (*(char *)(iVar8 + 0x11) == '\0')) {
    iVar8 = *(int *)(param_1 + 0x3a30) + 1;
    *(int *)(param_1 + 0x3a30) = iVar8;
    if (0xff < iVar8) {
      *(undefined4 *)(param_1 + 0x3a30) = 1;
    }
    iVar8 = *(int *)(param_1 + 0x3a30) * 4;
    *(undefined4 *)(iVar8 + 0x3630 + param_1) = 0;
    if (*(int *)(param_1 + 0x362c) < 1) {
      pvVar6 = (void *)0x0;
    }
    else {
      pvVar6 = (void *)**(int **)(param_1 + 0x3a34);
      *(undefined4 *)(iVar8 + 0x3630 + param_1) = 1;
    }
    if (pvVar6 != (void *)0x0) {
      while( true ) {
        if (*(char *)((int)pvVar6 + 10) == '\0') {
          piVar9 = (int *)((int)pvVar6 + 0x1c);
          *piVar9 = *piVar9 + -1;
          if ((*piVar9 < 0) && (*(int *)((int)pvVar6 + 0x20) < 1)) {
            *(undefined4 *)((int)pvVar6 + 0x1c) = 0;
            *(undefined1 *)((int)pvVar6 + 10) = 1;
            *(undefined1 *)(*(int *)((int)pvVar6 + 0x10) + 0x14c) = 1;
            FUN_0046c150();
            *(undefined1 *)(param_1 + 0x880) = 1;
            puVar7 = operator_new(0x60);
            local_c = 0;
            if (puVar7 != (undefined4 *)0x0) {
              FUN_00459130(pvVar6,puVar7,param_1);
            }
            local_c = 0xffffffff;
            FUN_0045fb80();
            BASS_ChannelStop(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x878) + 0x538) + 8));
            FUN_00477f40(s_Game_Over_0050d2c0);
          }
        }
        iVar10 = *(int *)(iVar8 + 0x3630 + param_1);
        if (*(int *)(param_1 + 0x362c) <= iVar10) break;
        pvVar6 = *(void **)(*(int *)(param_1 + 0x3a34) + iVar10 * 4);
        *(int *)(iVar8 + 0x3630 + param_1) = iVar10 + 1;
        if (pvVar6 == (void *)0x0) {
          ExceptionList = local_14;
          return;
        }
      }
    }
  }
  else {
    iVar8 = *(int *)(param_1 + 0x3a30) + 1;
    *(int *)(param_1 + 0x3a30) = iVar8;
    if (0xff < iVar8) {
      *(undefined4 *)(param_1 + 0x3a30) = 1;
    }
    iVar8 = *(int *)(param_1 + 0x3a30) * 4;
    iVar10 = 0;
    *(undefined4 *)(iVar8 + 0x3630 + param_1) = 0;
    if (0 < *(int *)(param_1 + 0x362c)) {
      iVar10 = **(int **)(param_1 + 0x3a34);
      *(undefined4 *)(iVar8 + 0x3630 + param_1) = 1;
    }
    while (iVar10 != 0) {
      if (*(char *)(iVar10 + 10) == '\0') {
        *(int *)(iVar10 + 0x1c) = *(int *)(iVar10 + 0x1c) + 1;
      }
      iVar1 = *(int *)(iVar8 + 0x3630 + param_1);
      if (*(int *)(param_1 + 0x362c) <= iVar1) {
        ExceptionList = local_14;
        return;
      }
      iVar10 = *(int *)(*(int *)(param_1 + 0x3a34) + iVar1 * 4);
      *(int *)(iVar8 + 0x3630 + param_1) = iVar1 + 1;
    }
  }
  ExceptionList = local_14;
  return;
}


