/*
 * File: simple_addition_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "simple_addition_ca.h"

CA_HWImpl_TestResults CA_simple_addition_HWRes;
CA_PWS_TestResults CA_simple_addition_PWSRes;
const CA_HWImpl CA_simple_addition_ExpHW = {
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
  0,                                   /* PortableWordSizes */
  "ARM Compatible->ARM Cortex"         /* HWDeviceType */
};

CA_HWImpl CA_simple_addition_ActHW;
void simple_addition_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_simple_addition_ActHW, &CA_simple_addition_ExpHW,
    &CA_simple_addition_PWSRes);
  if (!CA_simple_addition_ActHW.portableWordSizes) {
    caVerifyHWImpl(&CA_simple_addition_ActHW, &CA_simple_addition_ExpHW,
                   &CA_simple_addition_HWRes);
  }                                    /* if */
}
