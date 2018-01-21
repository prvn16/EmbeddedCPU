/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.247
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 06:57:39 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"

/* Block signals and states (auto storage) */
D_Work rtDWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Controller_step(void)
{
  real32_T rtb_UnitDelay1;
  real32_T rtb_UnitDelay2;
  real32_T rtb_Sum2;

  /* Outputs for Atomic SubSystem: '<Root>/Controller' */
  /* UnitDelay: '<S1>/Unit Delay1' */
  rtb_UnitDelay1 = rtDWork.UnitDelay1_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay2' */
  rtb_UnitDelay2 = rtDWork.UnitDelay2_DSTATE;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain4'
   *  Sum: '<S1>/Sum3'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay2'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  rtb_Sum2 = (0.25F * rtDWork.UnitDelay3_DSTATE + 0.25F *
              rtDWork.UnitDelay2_DSTATE) + 0.25F * rtDWork.UnitDelay1_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtDWork.UnitDelay1_DSTATE = rtU.In1;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  rtDWork.UnitDelay2_DSTATE = rtb_UnitDelay1;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  rtDWork.UnitDelay3_DSTATE = rtb_UnitDelay2;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Inport: '<Root>/In1'
   *  Sum: '<S1>/Sum1'
   */
  rtY.Out1 = 0.25F * rtU.In1 + rtb_Sum2;

  /* End of Outputs for SubSystem: '<Root>/Controller' */
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
