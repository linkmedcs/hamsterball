/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004105b0 name: candidate_Level1_vslot_26 */

void __thiscall candidate_Level1_vslot_26(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  (**(code **)(**(int **)(param_1 + 0x154) + 0x94))
            (*(int **)(param_1 + 0x154),0x100,(undefined4 *)(param_1 + 0x750));
  puVar4 = (undefined4 *)(param_1 + 0x750);
  puVar5 = (undefined4 *)(param_1 + 0x224);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_00481a30();
  (**(code **)(**(int **)((int)this + 0x8ac) + 0x4c))();
  (**(code **)(**(int **)(param_1 + 0x154) + 0x94))
            (*(int **)(param_1 + 0x154),0x100,(undefined4 *)(param_1 + 0x750));
  puVar4 = (undefined4 *)(param_1 + 0x750);
  puVar5 = (undefined4 *)(param_1 + 0x224);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_00481a30();
  iVar2 = *(int *)((int)this + 0x3a44);
  iVar6 = *(int *)(iVar2 + 0x408) + 1;
  *(int *)(iVar2 + 0x408) = iVar6;
  if (0xff < iVar6) {
    *(undefined4 *)(iVar2 + 0x408) = 1;
  }
  iVar2 = *(int *)(iVar2 + 0x408);
  iVar6 = *(int *)((int)this + 0x3a44);
  *(undefined4 *)(iVar6 + 8 + iVar2 * 4) = 0;
  if (*(int *)(iVar6 + 4) < 1) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)**(undefined4 **)(iVar6 + 0x40c);
    *(undefined4 *)(iVar6 + 8 + iVar2 * 4) = 1;
  }
  while( true ) {
    if (piVar3 == (int *)0x0) {
      return;
    }
    (**(code **)(*piVar3 + 0xc))();
    iVar6 = *(int *)((int)this + 0x3a44);
    iVar1 = *(int *)(iVar6 + 8 + iVar2 * 4);
    if (*(int *)(iVar6 + 4) <= iVar1) break;
    piVar3 = *(int **)(*(int *)(iVar6 + 0x40c) + iVar1 * 4);
    *(int *)(iVar6 + 8 + iVar2 * 4) = iVar1 + 1;
  }
  return;
}


