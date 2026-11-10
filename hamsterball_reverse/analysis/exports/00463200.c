/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 00463200 name: probe_EllipsoidMove */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
probe_EllipsoidMove(void *this,float *param_1,float *param_2,float *param_3,float *param_4,
                   undefined4 param_5,undefined1 *param_6)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  float10 fVar8;
  uint local_d4;
  float local_cc;
  float local_c8;
  float local_c4;
  undefined4 local_c0;
  int local_bc;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  undefined4 uStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  int *local_5c;
  float local_58 [3];
  undefined1 local_4c [12];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar8 = FUN_0040c0f0();
  if ((float10)_DAT_004f4038 <= fVar8) {
    local_2c = param_2[2] / param_4[2];
    local_30 = param_2[1] / param_4[1];
    local_34 = *param_2 / *param_4;
    local_c4 = param_3[2] / param_4[2];
    local_c8 = param_3[1] / param_4[1];
    local_cc = *param_3 / *param_4;
    FUN_004626a0();
    if (&local_c != param_4) {
      local_c = *param_4;
      local_8 = param_4[1];
      local_4 = param_4[2];
    }
    FUN_00482ae0(param_2,param_3,local_40);
    local_c8 = local_30;
    local_cc = local_34;
    local_c4 = local_2c;
    local_d4 = 0;
    if (*(int *)((int)this + 0xc60) != 0) {
      do {
        FUN_00462730();
        iVar6 = *(int *)((int)this + 0x838) + 1;
        *(int *)((int)this + 0x838) = iVar6;
        if (0xff < iVar6) {
          *(undefined4 *)((int)this + 0x838) = 1;
        }
        iVar6 = *(int *)((int)this + 0x838) * 4;
        *(undefined4 *)(iVar6 + 0x438 + (int)this) = 0;
        if (*(int *)((int)this + 0x434) < 1) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = (int *)**(undefined4 **)((int)this + 0x83c);
          *(undefined4 *)(iVar6 + 0x438 + (int)this) = 1;
        }
        while (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))(this,local_4c,&local_c0);
          iVar3 = *(int *)(iVar6 + 0x438 + (int)this);
          if (*(int *)((int)this + 0x434) <= iVar3) break;
          piVar7 = *(int **)(*(int *)((int)this + 0x83c) + iVar3 * 4);
          *(int *)(iVar6 + 0x438 + (int)this) = iVar3 + 1;
        }
        if (local_bc == 0) {
          local_cc = local_28 + local_cc;
          local_c8 = local_24 + local_c8;
          local_c4 = local_20 + local_c4;
          break;
        }
        if (local_5c == (int *)0x0) break;
        *param_6 = 1;
        pfVar4 = (float *)(**(code **)(*local_5c + 0xc))(local_58,this,local_4c,&local_c0,param_5);
        if (&local_cc != pfVar4) {
          local_cc = *pfVar4;
          local_c8 = pfVar4[1];
          local_c4 = pfVar4[2];
        }
        uStack_6c = *(undefined4 *)((int)this + 0xc74);
        fStack_90 = fStack_90 * *param_4;
        fStack_8c = fStack_8c * param_4[1];
        fStack_88 = fStack_88 * param_4[2];
        fStack_78 = fStack_78 * *param_4;
        fStack_74 = fStack_74 * param_4[1];
        fStack_70 = fStack_70 * param_4[2];
        fStack_84 = fStack_84 * *param_4;
        fStack_80 = fStack_80 * param_4[1];
        fStack_7c = fStack_7c * param_4[2];
        fStack_68 = fStack_68 * *param_4;
        fStack_64 = fStack_64 * param_4[1];
        fStack_60 = fStack_60 * param_4[2];
        fStack_ac = fStack_ac * *param_4;
        fStack_a8 = fStack_a8 * param_4[1];
        fStack_a4 = fStack_a4 * param_4[2];
        if (*(char *)((int)this + 0x14) != '\0') {
          pvVar5 = operator_new(0x68);
          if (pvVar5 != (void *)0x0) {
            FUN_00462730();
          }
          FUN_00463660(&local_c0);
          FUN_0045fb80();
        }
        if (((local_bc == 4) || (fStack_10 < _DAT_004f4038)) ||
           (local_d4 = local_d4 + 1, *(uint *)((int)this + 0xc60) <= local_d4)) break;
      } while( true );
    }
    fVar1 = param_4[2];
    fVar2 = param_4[1];
    if ((float *)((int)this + 0xc80) != local_58) {
      *(float *)((int)this + 0xc80) = local_28 * *param_4;
      *(float *)((int)this + 0xc84) = local_24 * fVar2;
      *(float *)((int)this + 0xc88) = local_20 * fVar1;
    }
    fVar1 = param_4[2];
    fVar2 = *param_4;
    param_1[1] = local_c8 * param_4[1];
    *param_1 = local_cc * fVar2;
    param_1[2] = local_c4 * fVar1;
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    return;
  }
  return;
}


