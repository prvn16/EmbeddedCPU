/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_external_mode.c
 *
 * Code generated for Simulink model 'arm_cortex_a_external_mode'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 08:09:05 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arm_cortex_a_external_mode.h"
#include "arm_cortex_a_external_mode_private.h"
#include "arm_cortex_a_external_mode_dt.h"

/* Block signals (auto storage) */
B_arm_cortex_a_external_mode_T arm_cortex_a_external_mode_B;

/* Block states (auto storage) */
DW_arm_cortex_a_external_mode_T arm_cortex_a_external_mode_DW;

/* Real-time model */
RT_MODEL_arm_cortex_a_externa_T arm_cortex_a_external_mode_M_;
RT_MODEL_arm_cortex_a_externa_T *const arm_cortex_a_external_mode_M =
  &arm_cortex_a_external_mode_M_;

/* Model step function */
void arm_cortex_a_external_mode_step(void)
{
  real_T rtb_ManualSwitch;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_ManualSwitch = (arm_cortex_a_external_mode_DW.clockTickCounter <
                      arm_cortex_a_external_mode_P.PulseGenerator_Duty) &&
    (arm_cortex_a_external_mode_DW.clockTickCounter >= 0) ?
    arm_cortex_a_external_mode_P.PulseGenerator_Amp : 0.0;
  if (arm_cortex_a_external_mode_DW.clockTickCounter >=
      arm_cortex_a_external_mode_P.PulseGenerator_Period - 1.0) {
    arm_cortex_a_external_mode_DW.clockTickCounter = 0;
  } else {
    arm_cortex_a_external_mode_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  if (arm_cortex_a_external_mode_P.ManualSwitch_CurrentSetting != 1) {
    rtb_ManualSwitch = sin(((real_T)arm_cortex_a_external_mode_DW.counter +
      arm_cortex_a_external_mode_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
      arm_cortex_a_external_mode_P.SineWave_NumSamp) *
      arm_cortex_a_external_mode_P.SineWave_Amp +
      arm_cortex_a_external_mode_P.SineWave_Bias;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<Root>/Gain' */
  arm_cortex_a_external_mode_B.Gain = arm_cortex_a_external_mode_P.Gain_Gain *
    rtb_ManualSwitch;

  /* Update for Sin: '<Root>/Sine Wave' */
  arm_cortex_a_external_mode_DW.counter++;
  if (arm_cortex_a_external_mode_DW.counter ==
      arm_cortex_a_external_mode_P.SineWave_NumSamp) {
    arm_cortex_a_external_mode_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, arm_cortex_a_external_mode_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(arm_cortex_a_external_mode_M)!=-1) &&
        !((rtmGetTFinal(arm_cortex_a_external_mode_M)-
           arm_cortex_a_external_mode_M->Timing.taskTime0) >
          arm_cortex_a_external_mode_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(arm_cortex_a_external_mode_M, "Simulation finished");
    }

    if (rtmGetStopRequested(arm_cortex_a_external_mode_M)) {
      rtmSetErrorStatus(arm_cortex_a_external_mode_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++arm_cortex_a_external_mode_M->Timing.clockTick0)) {
    ++arm_cortex_a_external_mode_M->Timing.clockTickH0;
  }

  arm_cortex_a_external_mode_M->Timing.taskTime0 =
    arm_cortex_a_external_mode_M->Timing.clockTick0 *
    arm_cortex_a_external_mode_M->Timing.stepSize0 +
    arm_cortex_a_external_mode_M->Timing.clockTickH0 *
    arm_cortex_a_external_mode_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void arm_cortex_a_external_mode_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)arm_cortex_a_external_mode_M, 0,
                sizeof(RT_MODEL_arm_cortex_a_externa_T));
  rtmSetTFinal(arm_cortex_a_external_mode_M, -1);
  arm_cortex_a_external_mode_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  arm_cortex_a_external_mode_M->Sizes.checksums[0] = (1291589343U);
  arm_cortex_a_external_mode_M->Sizes.checksums[1] = (2486349586U);
  arm_cortex_a_external_mode_M->Sizes.checksums[2] = (630271805U);
  arm_cortex_a_external_mode_M->Sizes.checksums[3] = (2502422148U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    arm_cortex_a_external_mode_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arm_cortex_a_external_mode_M->extModeInfo,
      &arm_cortex_a_external_mode_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arm_cortex_a_external_mode_M->extModeInfo,
                        arm_cortex_a_external_mode_M->Sizes.checksums);
    rteiSetTPtr(arm_cortex_a_external_mode_M->extModeInfo, rtmGetTPtr
                (arm_cortex_a_external_mode_M));
  }

  /* block I/O */
  (void) memset(((void *) &arm_cortex_a_external_mode_B), 0,
                sizeof(B_arm_cortex_a_external_mode_T));

  /* states (dwork) */
  (void) memset((void *)&arm_cortex_a_external_mode_DW, 0,
                sizeof(DW_arm_cortex_a_external_mode_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    arm_cortex_a_external_mode_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  arm_cortex_a_external_mode_DW.clockTickCounter = 0;

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  arm_cortex_a_external_mode_DW.counter = 0;
}

/* Model terminate function */
void arm_cortex_a_external_mode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
