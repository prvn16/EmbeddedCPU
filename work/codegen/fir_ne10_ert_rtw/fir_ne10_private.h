/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fir_ne10_private.h
 *
 * Code generated for Simulink model 'fir_ne10'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 03:44:20 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_fir_ne10_private_h_
#define RTW_HEADER_fir_ne10_private_h_
#include "rtwtypes.h"

extern void RandSrc_GZ_R(real32_T y[], const real32_T mean[], int32_T meanLen,
  const real32_T xstd[], int32_T xstdLen, uint32_T state[], int32_T nChans,
  int32_T nSamps);
extern void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T
  nChans);

#endif                                 /* RTW_HEADER_fir_ne10_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
