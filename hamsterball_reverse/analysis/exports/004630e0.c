/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004630e0 name: probe_Motion_reset */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall probe_Motion_reset(int param_1)

{
  float fVar1;
  undefined4 local_c [3];
  
  *(undefined4 *)(param_1 + 0xc60) = 3;
  *(undefined4 *)(param_1 + 0xc68) = 0x3f0e147b;
  *(undefined4 *)(param_1 + 0xc6c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xc70) = 0x447a0000;
  *(undefined4 *)(param_1 + 0xc78) = 0x41c80000;
  *(undefined1 *)(param_1 + 0xc7c) = 1;
  if ((undefined4 *)(param_1 + 0xc80) != local_c) {
    *(undefined4 *)(param_1 + 0xc80) = 0;
    *(undefined4 *)(param_1 + 0xc84) = 0;
    *(undefined4 *)(param_1 + 0xc88) = 0;
  }
  if ((undefined4 *)(param_1 + 0xc8c) != local_c) {
    *(undefined4 *)(param_1 + 0xc8c) = 0;
    *(undefined4 *)(param_1 + 0xc90) = 0xbf800000;
    *(undefined4 *)(param_1 + 0xc94) = 0;
  }
  fVar1 = _DAT_004f402c * _DAT_004f9208;
  *(undefined1 *)(param_1 + 0x14) = 1;
  probe_SetDirectionScale
            ((_DAT_004f91a0 / (*(float *)(param_1 + 0xc78) / _DAT_004f4028)) * _DAT_004f4030 * fVar1
            );
  return;
}


