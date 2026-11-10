/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040e890 name: candidate_Level1_vslot_02 */

void __thiscall candidate_Level1_vslot_02(void *this,int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float unaff_EDI;
  ulonglong uVar7;
  ulonglong uVar8;
  
  if (*(int *)((int)this + 0x362c) == 0) {
    FUN_00462110(0,0);
    (**(code **)(*param_1 + 4))(*(undefined4 *)((int)this + 0x87c));
    (**(code **)(*(int *)this + 0x60))(param_1);
    (**(code **)(*(int *)this + 100))(param_1);
    (**(code **)(*(int *)this + 0x68))(param_1);
    FUN_00462110(0,0);
    (**(code **)(*(int *)this + 0x70))(param_1);
    (**(code **)(*(int *)this + 0x6c))(param_1);
  }
  if (*(int *)((int)this + 0x362c) == 1) {
    FUN_00462110(0,0);
    if ((0 < *(int *)((int)this + 0x362c)) && (**(int **)((int)this + 0x3a34) != 0)) {
      iVar6 = *(int *)(**(int **)((int)this + 0x3a34) + 0x10);
      *(int *)((int)this + 0x29cc) = iVar6;
      iVar5 = *(int *)(*(int *)((int)this + 0x878) + 0x178);
      uVar1 = *(undefined4 *)(iVar6 + 0x16c);
      uVar2 = *(undefined4 *)(iVar6 + 0x168);
      *(undefined4 *)(iVar5 + 0x854) = *(undefined4 *)(iVar6 + 0x164);
      *(undefined4 *)(iVar5 + 0x858) = uVar2;
      *(undefined4 *)(iVar5 + 0x85c) = uVar1;
      FUN_0040e440(*(void **)((int)this + 0x29cc),'\x01',unaff_EDI);
    }
    (**(code **)(*(int *)this + 0x60))(param_1);
    (**(code **)(*(int *)this + 100))(param_1);
    (**(code **)(*(int *)this + 0x68))(param_1);
    FUN_00462110(0,0);
    (**(code **)(*(int *)this + 0x70))(param_1);
    (**(code **)(*(int *)this + 0x6c))(param_1);
  }
  if (*(int *)((int)this + 0x362c) == 2) {
    iVar6 = *(int *)((int)this + 0x3a30) + 1;
    *(int *)((int)this + 0x3a30) = iVar6;
    if (0xff < iVar6) {
      *(undefined4 *)((int)this + 0x3a30) = 1;
    }
    iVar6 = *(int *)((int)this + 0x3a30) * 4;
    *(undefined4 *)(iVar6 + 0x3630 + (int)this) = 0;
    if (*(int *)((int)this + 0x362c) < 1) {
      iVar5 = 0;
    }
    else {
      iVar5 = **(int **)((int)this + 0x3a34);
      *(undefined4 *)(iVar6 + 0x3630 + (int)this) = 1;
    }
    while (iVar5 != 0) {
      uVar7 = FUN_004d9e34();
      uVar8 = FUN_004d9e34();
      FUN_00462110((int)uVar7,(int)uVar8);
      pvVar3 = *(void **)(iVar5 + 0x10);
      *(void **)((int)this + 0x29cc) = pvVar3;
      FUN_0040e440(pvVar3,'\x01',unaff_EDI);
      (**(code **)(*(int *)this + 0x60))(param_1);
      (**(code **)(*(int *)this + 100))(param_1);
      (**(code **)(*(int *)this + 0x68))(param_1);
      iVar4 = *(int *)(iVar6 + 0x3630 + (int)this);
      if (*(int *)((int)this + 0x362c) <= iVar4) break;
      iVar5 = *(int *)(*(int *)((int)this + 0x3a34) + iVar4 * 4);
      *(int *)(iVar6 + 0x3630 + (int)this) = iVar4 + 1;
    }
    FUN_00462110(0,0);
    (**(code **)(*(int *)this + 0x70))(param_1);
    (**(code **)(*(int *)this + 0x6c))(param_1);
  }
  return;
}


