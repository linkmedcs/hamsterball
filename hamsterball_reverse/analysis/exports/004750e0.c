/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004750e0 name: candidate_Level1_vslot_15 */

void __thiscall candidate_Level1_vslot_15(void *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)((int)this + 0x43c) + 1;
  *(int *)((int)this + 0x43c) = iVar3;
  if (0xff < iVar3) {
    *(undefined4 *)((int)this + 0x43c) = 1;
  }
  iVar3 = *(int *)((int)this + 0x43c) * 4;
  *(undefined4 *)(iVar3 + 0x3c + (int)this) = 0;
  if (*(int *)((int)this + 0x38) < 1) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)**(undefined4 **)((int)this + 0x440);
    *(undefined4 *)(iVar3 + 0x3c + (int)this) = 1;
  }
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return;
    }
    (**(code **)(*(int *)(param_1 + 0x428) + 0xc))(piVar4);
    if (*(int **)(param_1 + 0x41c) == piVar4) {
      *(undefined4 *)(param_1 + 0x41c) = 0;
    }
    if (*(int **)(param_1 + 0x424) == piVar4) {
      uVar2 = (**(code **)(*(int *)(param_1 + 0x428) + 8))();
      *(undefined4 *)(param_1 + 0x424) = uVar2;
    }
    FUN_0045fe10((int)piVar4);
    piVar4[0xc] = 0;
    (**(code **)(**(int **)(param_1 + 0x844) + 0x74))();
    (**(code **)(*piVar4 + 0x3c))(param_1);
    iVar1 = *(int *)(iVar3 + 0x3c + (int)this);
    if (*(int *)((int)this + 0x38) <= iVar1) break;
    piVar4 = *(int **)(*(int *)((int)this + 0x440) + iVar1 * 4);
    *(int *)(iVar3 + 0x3c + (int)this) = iVar1 + 1;
  }
  return;
}


