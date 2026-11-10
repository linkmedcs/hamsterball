/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004106b0 name: candidate_Level1_vslot_25 */

void __thiscall candidate_Level1_vslot_25(void *this,int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar5 = *(int *)((int)this + 0x3a44);
  if (*(void **)(iVar5 + 0x40c) != (void *)0x0) {
    _free(*(void **)(iVar5 + 0x40c));
  }
  *(undefined4 *)(iVar5 + 0x40c) = 0;
  *(undefined4 *)(iVar5 + 4) = 0;
  iVar5 = *(int *)((int)this + 0x2dd8) + 1;
  *(int *)((int)this + 0x2dd8) = iVar5;
  if (0xff < iVar5) {
    *(undefined4 *)((int)this + 0x2dd8) = 1;
  }
  iVar5 = *(int *)((int)this + 0x2dd8) * 4;
  *(undefined4 *)(iVar5 + 0x29d8 + (int)this) = 0;
  if (*(int *)((int)this + 0x29d4) < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = **(int **)((int)this + 0x2ddc);
    *(undefined4 *)(iVar5 + 0x29d8 + (int)this) = 1;
  }
  while (iVar6 != 0) {
    iVar1 = *(int *)((int)this + 0x3a44);
    if (*(int *)(iVar1 + 0x414) == 0) {
      if (*(int *)(iVar1 + 4) == 0) {
        *(undefined4 *)(iVar1 + 4) = 1;
        pvVar2 = _malloc(4);
        *(void **)(iVar1 + 0x40c) = pvVar2;
        puVar7 = (undefined4 *)(iVar1 + 8);
        for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        **(int **)(iVar1 + 0x40c) = iVar6;
      }
      else {
        iVar3 = *(int *)(iVar1 + 4) + 1;
        *(int *)(iVar1 + 4) = iVar3;
        pvVar2 = _realloc(*(void **)(iVar1 + 0x40c),iVar3 * 4);
        *(void **)(iVar1 + 0x40c) = pvVar2;
        *(int *)((int)pvVar2 + *(int *)(iVar1 + 4) * 4 + -4) = iVar6;
      }
    }
    else {
      FUN_0045fc20(iVar1,iVar6);
    }
    iVar1 = *(int *)(iVar5 + 0x29d8 + (int)this);
    if (*(int *)((int)this + 0x29d4) <= iVar1) break;
    iVar6 = *(int *)(*(int *)((int)this + 0x2ddc) + iVar1 * 4);
    *(int *)(iVar5 + 0x29d8 + (int)this) = iVar1 + 1;
  }
  iVar5 = *(int *)((int)this + 0x3608) + 1;
  *(int *)((int)this + 0x3608) = iVar5;
  if (0xff < iVar5) {
    *(undefined4 *)((int)this + 0x3608) = 1;
  }
  iVar5 = *(int *)((int)this + 0x3608) * 4;
  *(undefined4 *)(iVar5 + 0x3208 + (int)this) = 0;
  if (*(int *)((int)this + 0x3204) < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = **(int **)((int)this + 0x360c);
    *(undefined4 *)(iVar5 + 0x3208 + (int)this) = 1;
  }
  while (iVar6 != 0) {
    iVar1 = *(int *)((int)this + 0x3a44);
    if (*(int *)(iVar1 + 0x414) == 0) {
      if (*(int *)(iVar1 + 4) == 0) {
        *(undefined4 *)(iVar1 + 4) = 1;
        pvVar2 = _malloc(4);
        *(void **)(iVar1 + 0x40c) = pvVar2;
        puVar7 = (undefined4 *)(iVar1 + 8);
        for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        **(int **)(iVar1 + 0x40c) = iVar6;
      }
      else {
        iVar3 = *(int *)(iVar1 + 4) + 1;
        *(int *)(iVar1 + 4) = iVar3;
        pvVar2 = _realloc(*(void **)(iVar1 + 0x40c),iVar3 * 4);
        *(void **)(iVar1 + 0x40c) = pvVar2;
        *(int *)((int)pvVar2 + *(int *)(iVar1 + 4) * 4 + -4) = iVar6;
      }
    }
    else {
      FUN_0045fc20(iVar1,iVar6);
    }
    iVar1 = *(int *)(iVar5 + 0x3208 + (int)this);
    if (*(int *)((int)this + 0x3204) <= iVar1) break;
    iVar6 = *(int *)(*(int *)((int)this + 0x360c) + iVar1 * 4);
    *(int *)(iVar5 + 0x3208 + (int)this) = iVar1 + 1;
  }
  if (*(char *)(param_1 + 0x70c) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x154) + 200))(*(int **)(param_1 + 0x154),0xe,0);
    *(undefined1 *)(param_1 + 0x70c) = 0;
    *(int *)(param_1 + 0x7c8) = *(int *)(param_1 + 0x7c8) + 1;
  }
  iVar5 = *(int *)((int)this + 0x2dd8) + 1;
  *(int *)((int)this + 0x2dd8) = iVar5;
  if (0xff < iVar5) {
    *(undefined4 *)((int)this + 0x2dd8) = 1;
  }
  iVar5 = *(int *)((int)this + 0x2dd8) * 4;
  *(undefined4 *)(iVar5 + 0x29d8 + (int)this) = 0;
  if (*(int *)((int)this + 0x29d4) < 1) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)**(undefined4 **)((int)this + 0x2ddc);
    *(undefined4 *)(iVar5 + 0x29d8 + (int)this) = 1;
  }
  while (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x1c))();
    iVar6 = *(int *)(iVar5 + 0x29d8 + (int)this);
    if (*(int *)((int)this + 0x29d4) <= iVar6) break;
    piVar4 = *(int **)(*(int *)((int)this + 0x2ddc) + iVar6 * 4);
    *(int *)(iVar5 + 0x29d8 + (int)this) = iVar6 + 1;
  }
  iVar5 = *(int *)((int)this + 0x3608) + 1;
  *(int *)((int)this + 0x3608) = iVar5;
  if (0xff < iVar5) {
    *(undefined4 *)((int)this + 0x3608) = 1;
  }
  iVar5 = *(int *)((int)this + 0x3608) * 4;
  *(undefined4 *)((int)this + iVar5 + 0x3208) = 0;
  if (*(int *)((int)this + 0x3204) < 1) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)**(undefined4 **)((int)this + 0x360c);
    *(undefined4 *)((int)this + iVar5 + 0x3208) = 1;
  }
  if (piVar4 != (int *)0x0) {
    do {
      (**(code **)(*piVar4 + 0x1c))();
      iVar6 = *(int *)((int)this + iVar5 + 0x3208);
      if (*(int *)((int)this + 0x3204) <= iVar6) break;
      piVar4 = *(int **)(*(int *)((int)this + 0x360c) + iVar6 * 4);
      *(int *)((int)this + iVar5 + 0x3208) = iVar6 + 1;
    } while (piVar4 != (int *)0x0);
  }
  if (*(char *)(param_1 + 0x70c) != '\x01') {
    (**(code **)(**(int **)(param_1 + 0x154) + 200))(*(int **)(param_1 + 0x154),0xe,1);
    *(undefined1 *)(param_1 + 0x70c) = 1;
    *(int *)(param_1 + 0x7c8) = *(int *)(param_1 + 0x7c8) + 1;
  }
  iVar5 = *(int *)((int)this + 0x878);
  if (((*(char *)(*(int *)(iVar5 + 0x220) + 0x11) != '\0') && (*(char *)(iVar5 + 0x234) == '\0')) &&
     (*(int *)(iVar5 + 0x90c) != 0)) {
    FUN_0042e2b0(*(int *)(iVar5 + 0x90c));
    *(undefined4 *)(*(int *)((int)this + 0x3618) + 0x2fc) = 0x3ee66666;
    (**(code **)(**(int **)((int)this + 0x3618) + 8))();
  }
  iVar5 = *(int *)((int)this + 0x3a44);
  iVar6 = *(int *)(iVar5 + 0x408) + 1;
  *(int *)(iVar5 + 0x408) = iVar6;
  if (0xff < iVar6) {
    *(undefined4 *)(iVar5 + 0x408) = 1;
  }
  iVar5 = *(int *)(iVar5 + 0x408);
  iVar6 = *(int *)((int)this + 0x3a44);
  *(undefined4 *)(iVar6 + 8 + iVar5 * 4) = 0;
  if (*(int *)(iVar6 + 4) < 1) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)**(undefined4 **)(iVar6 + 0x40c);
    *(undefined4 *)(iVar6 + 8 + iVar5 * 4) = 1;
  }
  while (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))();
    iVar6 = *(int *)((int)this + 0x3a44);
    iVar1 = *(int *)(iVar6 + 8 + iVar5 * 4);
    if (*(int *)(iVar6 + 4) <= iVar1) break;
    piVar4 = *(int **)(*(int *)(iVar6 + 0x40c) + iVar1 * 4);
    *(int *)(iVar6 + 8 + iVar5 * 4) = iVar1 + 1;
  }
  if (*(int *)(*(int *)((int)this + 0x8ac) + 0xcbc) != 0) {
    iVar5 = *(int *)((int)this + 0x2dd8) + 1;
    *(int *)((int)this + 0x2dd8) = iVar5;
    if (0xff < iVar5) {
      *(undefined4 *)((int)this + 0x2dd8) = 1;
    }
    iVar5 = *(int *)((int)this + 0x2dd8) * 4;
    *(undefined4 *)((int)this + iVar5 + 0x29d8) = 0;
    if (*(int *)((int)this + 0x29d4) < 1) {
      iVar6 = 0;
    }
    else {
      iVar6 = **(int **)((int)this + 0x2ddc);
      *(undefined4 *)((int)this + iVar5 + 0x29d8) = 1;
    }
    while (iVar6 != 0) {
      FUN_00406ed0();
      iVar1 = *(int *)((int)this + iVar5 + 0x29d8);
      if (*(int *)((int)this + 0x29d4) <= iVar1) break;
      iVar6 = *(int *)(*(int *)((int)this + 0x2ddc) + iVar1 * 4);
      *(int *)((int)this + iVar5 + 0x29d8) = iVar1 + 1;
    }
    iVar5 = *(int *)((int)this + 0x3608) + 1;
    *(int *)((int)this + 0x3608) = iVar5;
    if (0xff < iVar5) {
      *(undefined4 *)((int)this + 0x3608) = 1;
    }
    iVar5 = *(int *)((int)this + 0x3608) * 4;
    *(undefined4 *)((int)this + iVar5 + 0x3208) = 0;
    if (*(int *)((int)this + 0x3204) < 1) {
      iVar6 = 0;
    }
    else {
      iVar6 = **(int **)((int)this + 0x360c);
      *(undefined4 *)((int)this + iVar5 + 0x3208) = 1;
    }
    while (iVar6 != 0) {
      FUN_00406ed0();
      iVar1 = *(int *)((int)this + iVar5 + 0x3208);
      if (*(int *)((int)this + 0x3204) <= iVar1) {
        return;
      }
      iVar6 = *(int *)(*(int *)((int)this + 0x360c) + iVar1 * 4);
      *(int *)((int)this + iVar5 + 0x3208) = iVar1 + 1;
    }
  }
  return;
}


