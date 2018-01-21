/*
 * File: arm_cortex_a_top_model_pil_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "arm_cortex_a_top_model_pil_ca.h"

CA_HWImpl_TestResults CA_arm_cortex_a_top_model_pil_HWRes;
CA_PWS_TestResults CA_arm_cortex_a_top_model_pil_PWSRes;
const CA_HWImpl CA_arm_cortex_a_top_model_pil_ExpHW = {
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

CA_HWImpl CA_arm_cortex_a_top_model_pil_ActHW;
void arm_cortex_a_top_model_pil_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_arm_cortex_a_top_model_pil_ActHW,
    &CA_arm_cortex_a_top_model_pil_ExpHW, &CA_arm_cortex_a_top_model_pil_PWSRes);
  if (!CA_arm_cortex_a_top_model_pil_ActHW.portableWordSizes) {
    caVerifyHWImpl(&CA_arm_cortex_a_top_model_pil_ActHW,
                   &CA_arm_cortex_a_top_model_pil_ExpHW,
                   &CA_arm_cortex_a_top_model_pil_HWRes);
  }                                    /* if */
}
