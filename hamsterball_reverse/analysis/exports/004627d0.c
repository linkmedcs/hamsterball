/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004627d0 name: probe_Motion_ctor */

void probe_Motion_ctor(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  undefined4 local_c [3];
  
  unaff_ESI[4] = in_EAX;
  *unaff_ESI = &PTR_FUN_004f5d40;
  unaff_ESI[6] = &PTR_FUN_004f63fc;
  unaff_ESI[0x10b] = 0;
  unaff_ESI[0x10a] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[0x109] = 0;
  puVar2 = unaff_ESI + 8;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  unaff_ESI[0x108] = 0;
  unaff_ESI[0x10c] = &PTR_FUN_004f63fc;
  unaff_ESI[0x211] = 0;
  unaff_ESI[0x210] = 0;
  unaff_ESI[0x10d] = 0;
  unaff_ESI[0x20f] = 0;
  puVar2 = unaff_ESI + 0x10e;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  unaff_ESI[0x20e] = 0;
  unaff_ESI[0x212] = &PTR_FUN_004f63fc;
  unaff_ESI[0x317] = 0;
  unaff_ESI[0x316] = 0;
  unaff_ESI[0x213] = 0;
  unaff_ESI[0x315] = 0;
  puVar2 = unaff_ESI + 0x214;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  unaff_ESI[0x314] = 0;
  unaff_ESI[0x31d] = 0;
  if (unaff_ESI + 0x329 != local_c) {
    unaff_ESI[0x329] = 0;
    unaff_ESI[0x32a] = 0;
    unaff_ESI[0x32b] = 0;
  }
  probe_Motion_reset((int)unaff_ESI);
  return;
}


