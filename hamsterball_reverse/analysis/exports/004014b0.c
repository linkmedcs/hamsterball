/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.
 * Original executable SHA-256: 047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58
 * Function: 004014b0 name: probe_SetDirectionScale */

void probe_SetDirectionScale(float param_1)

{
  int in_EAX;
  float local_c [3];
  
  *(float *)(in_EAX + 0xc64) = param_1;
  if ((float *)(in_EAX + 0xc98) != local_c) {
    *(float *)(in_EAX + 0xc98) = param_1 * *(float *)(in_EAX + 0xc8c);
    *(float *)(in_EAX + 0xc9c) = param_1 * *(float *)(in_EAX + 0xc90);
    *(float *)(in_EAX + 0xca0) = param_1 * *(float *)(in_EAX + 0xc94);
  }
  return;
}


