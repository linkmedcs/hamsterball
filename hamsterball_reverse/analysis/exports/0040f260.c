/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 0040f260 name: candidate_Level1_vslot_23 */

void __thiscall candidate_Level1_vslot_23(void *this,void *param_1)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 extraout_ECX;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004dd8e6;
  local_c = ExceptionList;
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 1:
    *(undefined4 *)((int)param_1 + 0x34) = 0x96;
    *(undefined4 *)((int)param_1 + 0x30) = 2;
    break;
  case 2:
    iVar4 = *(int *)((int)param_1 + 0x34) + -1;
    *(int *)((int)param_1 + 0x34) = iVar4;
    if (iVar4 < 1) {
      *(undefined4 *)((int)param_1 + 0x38) = 0;
      *(undefined4 *)((int)param_1 + 0x30) = 3;
    }
    break;
  case 3:
    if ((*(char *)(*(int *)((int)this + 0x878) + 0x234) == '\0') ||
       (*(char *)(*(int *)(*(int *)((int)this + 0x878) + 0x220) + 0x11) == '\0')) {
      ExceptionList = &local_c;
      *(undefined4 *)((int)param_1 + 0x30) = 4;
      iVar4 = *(int *)(*(int *)((int)this + 0x878) + 0x220);
      if (*(char *)(iVar4 + 0x11) == '\0') {
        if (*(char *)(iVar4 + 0x10) != '\0') {
          ExceptionList = pvVar2;
          return;
        }
        if (*(int *)((int)this + 0x362c) == 1) {
          puVar3 = operator_new(0x98);
          local_4 = 1;
          if (puVar3 != (undefined4 *)0x0) {
            FUN_00457ca0(extraout_ECX,param_1,puVar3,(int)this);
            FUN_0045fb80();
            ExceptionList = local_c;
            return;
          }
        }
        else {
          pvVar2 = operator_new(0x24);
          if (pvVar2 != (void *)0x0) {
            FUN_00459c50((int)this,param_1);
            FUN_0045fb80();
            ExceptionList = local_c;
            return;
          }
        }
      }
      else {
        puVar3 = operator_new(0x4e8);
        local_4 = 0;
        if (puVar3 != (undefined4 *)0x0) {
          FUN_00459e40(param_1,puVar3,(int)this);
          FUN_0045fb80();
          ExceptionList = local_c;
          return;
        }
      }
      FUN_0045fb80();
    }
    else {
      ExceptionList = &local_c;
      *(undefined4 *)((int)param_1 + 0x30) = 4;
      *(undefined1 *)(*(int *)((int)this + 0x878) + 0x5d2) = 1;
      *(undefined1 *)(*(int *)((int)this + 0x878) + 0x672) = 1;
      if (*(char *)((int)param_1 + 0x24) != '\0') {
        pvVar2 = operator_new(0x24);
        if (pvVar2 != (void *)0x0) {
          FUN_00459c50((int)this,param_1);
        }
        FUN_0045fb80();
        piVar1 = (int *)(*(int *)((int)this + 0x878) + 0xb34 + *(int *)((int)param_1 + 0x14) * 4);
        *piVar1 = *piVar1 + 4;
      }
    }
    break;
  case 4:
    if (*(int *)((int)this + 0x8b4) == 0) {
      *(undefined4 *)((int)param_1 + 0x30) = 5;
    }
  }
  ExceptionList = local_c;
  return;
}


