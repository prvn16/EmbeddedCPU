/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_profiling_private.h
 *
 * Code generated for Simulink model 'arm_cortex_a_profiling'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 09:39:31 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_arm_cortex_a_profiling_private_h_
#define RTW_HEADER_arm_cortex_a_profiling_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "arm_cortex_a_profiling.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void RandSrc_GZ_R(real32_T y[], const real32_T mean[], int32_T meanLen,
  const real32_T xstd[], int32_T xstdLen, uint32_T state[], int32_T nChans,
  int32_T nSamps);
extern void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T
  nChans);
extern void arm_cortex_a_profiling_step0(void);
extern void arm_cortex_a_profiling_step1(void);

#endif                                 /* RTW_HEADER_arm_cortex_a_profiling_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
