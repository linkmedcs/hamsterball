/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00474e90 name: candidate_Level1_vslot_03 */

void __thiscall candidate_Level1_vslot_03(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(undefined4 *)((int)this + 0x870);
  *(undefined4 *)((int)this + 0x864) = 0;
  iVar4 = *(int *)((int)this + 0x854) + 1;
  *(int *)((int)this + 0x854) = iVar4;
  if (0xff < iVar4) {
    *(undefined4 *)((int)this + 0x854) = 1;
  }
  iVar4 = *(int *)((int)this + 0x854) * 4;
  *(undefined4 *)((int)this + iVar4 + 0x454) = 0;
  if (*(int *)((int)this + 0x450) < 1) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)**(undefined4 **)((int)this + 0x858);
    *(undefined4 *)((int)this + iVar4 + 0x454) = 1;
  }
  while (piVar5 != (int *)0x0) {
    if ((*(char *)((int)piVar5 + 0x16) != '\0') &&
       (cVar2 = (**(code **)(*piVar5 + 4))(param_1,param_2), cVar2 != '\0')) {
      if ((char)piVar5[5] != '\0') {
        uVar3 = *(undefined4 *)(*(int *)((int)this + 0x14) + 0x1e4);
      }
      if (*(char *)((int)piVar5 + 0x15) != '\0') {
        uVar3 = *(undefined4 *)(*(int *)((int)this + 0x14) + 0x1e8);
      }
      *(int **)((int)this + 0x864) = piVar5;
    }
    iVar1 = *(int *)((int)this + iVar4 + 0x454);
    if (*(int *)((int)this + 0x450) <= iVar1) break;
    piVar5 = *(int **)(*(int *)((int)this + 0x858) + iVar1 * 4);
    *(int *)((int)this + iVar4 + 0x454) = iVar1 + 1;
  }
  (**(code **)(**(int **)((int)this + 0x14) + 0x7c))(uVar3);
  return;
}


