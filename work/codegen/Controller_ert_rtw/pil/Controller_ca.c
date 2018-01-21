/*
 * File: Controller_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Controller_ca.h"

CA_HWImpl_TestResults CA_Controller_HWRes;
CA_PWS_TestResults CA_Controller_PWSRes;
const CA_HWImpl CA_Controller_ExpHW = {
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

CA_HWImpl CA_Controller_ActHW;
void Controller_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Controller_ActHW, &CA_Controller_ExpHW,
    &CA_Controller_PWSRes);
  if (!CA_Controller_ActHW.portableWordSizes) {
    caVerifyHWImpl(&CA_Controller_ActHW, &CA_Controller_ExpHW,
                   &CA_Controller_HWRes);
  }                                    /* if */
}
