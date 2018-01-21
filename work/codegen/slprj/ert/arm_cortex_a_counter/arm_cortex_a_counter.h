/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_counter.h
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

#ifndef RTW_HEADER_arm_cortex_a_counter_h_
#define RTW_HEADER_arm_cortex_a_counter_h_
#include "rtwtypes.h"
#ifndef arm_cortex_a_counter_COMMON_INCLUDES_
# define arm_cortex_a_counter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* arm_cortex_a_counter_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct arm_cortex_a_counter_tag_RTM arm_cortex_a_counter_RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_SilCounterBus_
#define DEFINED_TYPEDEF_FOR_SilCounterBus_

/* This bus contains counter inputs */
typedef struct {
  boolean_T ticks_to_count;
  boolean_T reset;
} SilCounterBus;

#endif

/* Block signals and states (auto storage) for model 'arm_cortex_a_counter' */
typedef struct {
  uint8_T PreviousOutput_DSTATE;       /* '<Root>/Previous Output' */
} arm_cortex_a_counter_rtDW;

/* Parameters (auto storage) */
struct arm_cortex_a_counter_Parameters_ {
  uint8_T PreviousOutput_InitialCondition;/* Computed Parameter: PreviousOutput_InitialCondition
                                           * Referenced by: '<Root>/Previous Output'
                                           */
};

/* Parameters (auto storage) */
typedef struct arm_cortex_a_counter_Parameters_ arm_cortex_a_counter_Parameters;

/* Real-time Model Data Structure */
struct arm_cortex_a_counter_tag_RTM {
  const char_T **errorStatus;
};

typedef struct {
  arm_cortex_a_counter_rtDW rtdw;
  arm_cortex_a_counter_RT_MODEL rtm;
} arm_cortex_a_coun_rtMdlrefDWork;

/* Model block global parameters (auto storage) */
extern uint8_T rtP_Increment;          /* Variable: Increment
                                        * Referenced by: '<Root>/Gain'
                                        */
extern arm_cortex_a_counter_Parameters arm_cortex_a_counterrtP;

/* Model reference registration function */
extern void arm_cortex_a_counter_initialize(const char_T **rt_errorStatus,
  arm_cortex_a_counter_RT_MODEL *const arm_cortex_a_counterrtM);
extern void arm_cortex_a_counter_Init(arm_cortex_a_counter_rtDW *localDW);
extern void arm_cortex_a_counter(boolean_T rtu_input_ticks_to_count, boolean_T
  rtu_input_reset, uint8_T *rty_output, arm_cortex_a_counter_rtDW *localDW,
  uint8_T rtp_myLower, uint8_T rtp_myUpper);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'arm_cortex_a_counter'
 */
#endif                                 /* RTW_HEADER_arm_cortex_a_counter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
