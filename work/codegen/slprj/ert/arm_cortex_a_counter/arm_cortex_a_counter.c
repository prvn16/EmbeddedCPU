/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_counter.c
 *
 * Code generated for Simulink model 'arm_cortex_a_counter'.
 *
 * Model version                  : 1.147
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 07:41:38 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arm_cortex_a_counter.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

arm_cortex_a_counter_Parameters arm_cortex_a_counterrtP = {
  /* Computed Parameter: PreviousOutput_InitialCondition
   * Referenced by: '<Root>/Previous Output'
   */
  50U
};

/* System initialize for referenced model: 'arm_cortex_a_counter' */
void arm_cortex_a_counter_Init(arm_cortex_a_counter_rtDW *localDW)
{
  /* InitializeConditions for Switch: '<Root>/Switch1' incorporates:
   *  UnitDelay: '<Root>/Previous Output'
   */
  localDW->PreviousOutput_DSTATE =
    arm_cortex_a_counterrtP.PreviousOutput_InitialCondition;
}

/* Output and update for referenced model: 'arm_cortex_a_counter' */
void arm_cortex_a_counter(boolean_T rtu_input_ticks_to_count, boolean_T
  rtu_input_reset, uint8_T *rty_output, arm_cortex_a_counter_rtDW *localDW,
  uint8_T rtp_myLower, uint8_T rtp_myUpper)
{
  uint8_T rtb_Add;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/C1'
   */
  if (rtu_input_reset) {
    localDW->PreviousOutput_DSTATE = rtp_myLower;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain'
   */
  rtb_Add = (uint8_T)(uint32_T)((uint32_T)(rtu_input_ticks_to_count ? (int32_T)
    rtP_Increment : 0) + (uint32_T)localDW->PreviousOutput_DSTATE);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/C1'
   *  Constant: '<Root>/C5'
   *  RelationalOperator: '<Root>/upper GE input'
   */
  if (rtp_myUpper >= rtb_Add) {
    *rty_output = rtb_Add;
  } else {
    *rty_output = rtp_myLower;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Update for Switch: '<Root>/Switch1' incorporates:
   *  UnitDelay: '<Root>/Previous Output'
   */
  localDW->PreviousOutput_DSTATE = *rty_output;
}

/* Model initialize function */
void arm_cortex_a_counter_initialize(const char_T **rt_errorStatus,
  arm_cortex_a_counter_RT_MODEL *const arm_cortex_a_counterrtM)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(arm_cortex_a_counterrtM, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
