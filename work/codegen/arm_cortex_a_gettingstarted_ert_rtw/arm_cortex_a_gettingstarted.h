/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_gettingstarted.h
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

#ifndef RTW_HEADER_arm_cortex_a_gettingstarted_h_
#define RTW_HEADER_arm_cortex_a_gettingstarted_h_
#include <stddef.h>
#ifndef arm_cortex_a_gettingstarted_COMMON_INCLUDES_
# define arm_cortex_a_gettingstarted_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* arm_cortex_a_gettingstarted_COMMON_INCLUDES_ */

#include "arm_cortex_a_gettingstarted_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_arm_cortex_a_gettings_T {
  const char_T *errorStatus;
};

/* Model entry point functions */
extern void arm_cortex_a_gettingstarted_initialize(void);
extern void arm_cortex_a_gettingstarted_step(void);
extern void arm_cortex_a_gettingstarted_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arm_cortex_a_getting_T *const arm_cortex_a_gettingstarted_M;

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
 * '<Root>' : 'arm_cortex_a_gettingstarted'
 * '<S1>'   : 'arm_cortex_a_gettingstarted/Oscillator'
 * '<S2>'   : 'arm_cortex_a_gettingstarted/Slider Gain'
 */
#endif                                 /* RTW_HEADER_arm_cortex_a_gettingstarted_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
