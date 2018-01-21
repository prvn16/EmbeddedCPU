/*
 * arm_cortex_a_external_mode_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "arm_cortex_a_external_mode".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Jan 21 08:09:05 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&arm_cortex_a_external_mode_B.Gain), 0, 0, 1 }
  ,

  { (char_T *)(&arm_cortex_a_external_mode_DW.Scope_PWORK.LoggedData), 11, 0, 1
  },

  { (char_T *)(&arm_cortex_a_external_mode_DW.clockTickCounter), 6, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  3U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&arm_cortex_a_external_mode_P.PulseGenerator_Amp), 0, 0, 9 },

  { (char_T *)(&arm_cortex_a_external_mode_P.ManualSwitch_CurrentSetting), 3, 0,
    1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] arm_cortex_a_external_mode_dt.h */
