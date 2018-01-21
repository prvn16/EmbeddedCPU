/*
 * File: arm_cortex_a_counter_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "arm_cortex_a_counter_ca.h"

CA_HWImpl_TestResults CA_arm_cortex_a_counter_HWRes;
CA_PWS_TestResults CA_arm_cortex_a_counter_PWSRes;
const CA_HWImpl CA_arm_cortex_a_counter_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  1,                                   /* PortableWordSizes */
  "ARM Compatible->ARM Cortex"         /* HWDeviceType */
};

CA_HWImpl CA_arm_cortex_a_counter_ActHW;
void arm_cortex_a_counter_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_arm_cortex_a_counter_ActHW,
    &CA_arm_cortex_a_counter_ExpHW, &CA_arm_cortex_a_counter_PWSRes);
  if (!CA_arm_cortex_a_counter_ActHW.portableWordSizes) {
    caVerifyHWImpl(&CA_arm_cortex_a_counter_ActHW,
                   &CA_arm_cortex_a_counter_ExpHW,
                   &CA_arm_cortex_a_counter_HWRes);
  }                                    /* if */
}
