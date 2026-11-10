/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00410160 name: candidate_Level1_vslot_20 */

void __fastcall candidate_Level1_vslot_20(int param_1)

{
  int iVar1;
  int iVar2;
  float unaff_EBP;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x2dd8) + 1;
  *(int *)(param_1 + 0x2dd8) = iVar2;
  if (0xff < iVar2) {
    *(undefined4 *)(param_1 + 0x2dd8) = 1;
  }
  iVar2 = *(int *)(param_1 + 0x2dd8);
  *(undefined4 *)(param_1 + 0x29d8 + iVar2 * 4) = 0;
  if (*(int *)(param_1 + 0x29d4) < 1) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)**(undefined4 **)(param_1 + 0x2ddc);
    *(undefined4 *)(param_1 + 0x29d8 + iVar2 * 4) = 1;
  }
  if (piVar3 != (int *)0x0) {
    do {
      FUN_0040e440(piVar3,'\x01',unaff_EBP);
      (**(code **)(*piVar3 + 0x10))();
      if ((char)piVar3[0xba] != '\0') {
        if ((((char)piVar3[0xc9] == '\0') && (piVar3[6] != -1)) ||
           (*(char *)(*(int *)(param_1 + 0x878) + 0x237) != '\0')) {
          FUN_00407cd0();
        }
        else {
          FUN_0045fe10((int)piVar3);
          (**(code **)*piVar3)(1);
        }
      }
      iVar1 = *(int *)(param_1 + 0x29d8 + iVar2 * 4);
      if (*(int *)(param_1 + 0x29d4) <= iVar1) break;
      piVar3 = *(int **)(*(int *)(param_1 + 0x2ddc) + iVar1 * 4);
      *(int *)(param_1 + 0x29d8 + iVar2 * 4) = iVar1 + 1;
    } while (piVar3 != (int *)0x0);
  }
  iVar2 = *(int *)(param_1 + 0x3608) + 1;
  *(int *)(param_1 + 0x3608) = iVar2;
  if (0xff < iVar2) {
    *(undefined4 *)(param_1 + 0x3608) = 1;
  }
  iVar2 = *(int *)(param_1 + 0x3608);
  *(undefined4 *)(param_1 + 0x3208 + iVar2 * 4) = 0;
  if (*(int *)(param_1 + 0x3204) < 1) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)**(undefined4 **)(param_1 + 0x360c);
    *(undefined4 *)(param_1 + 0x3208 + iVar2 * 4) = 1;
  }
  while (piVar3 != (int *)0x0) {
    FUN_0040e440(piVar3,'\x01',unaff_EBP);
    (**(code **)(*piVar3 + 0x10))();
    if ((char)piVar3[0xba] != '\0') {
      if (((char)piVar3[0xc9] == '\0') && (piVar3[6] != -1)) {
        FUN_00407cd0();
      }
      else {
        FUN_0045fe10((int)piVar3);
        (**(code **)*piVar3)(1);
      }
    }
    iVar1 = *(int *)(param_1 + 0x3208 + iVar2 * 4);
    if (*(int *)(param_1 + 0x3204) <= iVar1) break;
    piVar3 = *(int **)(*(int *)(param_1 + 0x360c) + iVar1 * 4);
    *(int *)(param_1 + 0x3208 + iVar2 * 4) = iVar1 + 1;
  }
  iVar2 = *(int *)(param_1 + 0x878);
  if ((*(char *)(*(int *)(iVar2 + 0x220) + 0x11) != '\0') && (*(char *)(iVar2 + 0x234) == '\0')) {
    FUN_0042e210(*(int *)(iVar2 + 0x908));
    iVar2 = *(int *)(*(int *)(param_1 + 0x878) + 0x90c);
    if (iVar2 != 0) {
      piVar3 = (int *)(iVar2 + 0x41c);
      *piVar3 = *piVar3 + 1;
      iVar2 = *(int *)(*(int *)(param_1 + 0x878) + 0x90c);
      if (*(int *)(iVar2 + 8) <= *(int *)(iVar2 + 0x41c)) {
        *(int *)(iVar2 + 0x41c) = *(int *)(iVar2 + 8) + -1;
      }
    }
  }
  return;
}


