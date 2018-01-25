/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_gettingstarted.c
 *
 * Code generated for Simulink model 'arm_cortex_a_gettingstarted'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 09:25:00 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arm_cortex_a_gettingstarted.h"
#include "arm_cortex_a_gettingstarted_private.h"

/* Real-time model */
RT_MODEL_arm_cortex_a_getting_T arm_cortex_a_gettingstarted_M_;
RT_MODEL_arm_cortex_a_getting_T *const arm_cortex_a_gettingstarted_M =
  &arm_cortex_a_gettingstarted_M_;

/* Model step function */
void arm_cortex_a_gettingstarted_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void arm_cortex_a_gettingstarted_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arm_cortex_a_gettingstarted_M, (NULL));
}

/* Model terminate function */
void arm_cortex_a_gettingstarted_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
