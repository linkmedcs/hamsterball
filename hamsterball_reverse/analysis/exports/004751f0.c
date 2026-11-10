/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004751f0 name: candidate_Level1_vslot_17 */

void __thiscall candidate_Level1_vslot_17(void *this,char param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)((int)this + 0x30);
  if (param_1 != '\0') {
    (**(code **)(*(int *)(iVar1 + 0x428) + 4))(*(undefined4 *)(iVar1 + 0x424));
    *(void **)(iVar1 + 0x424) = this;
    return;
  }
  if (*(void **)(iVar1 + 0x424) == this) {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x428) + 8))();
    *(undefined4 *)(iVar1 + 0x424) = uVar2;
  }
  return;
}


