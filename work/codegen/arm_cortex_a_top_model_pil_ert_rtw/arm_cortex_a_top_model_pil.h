/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_top_model_pil.h
 *
 * Code generated for Simulink model 'arm_cortex_a_top_model_pil'.
 *
 * Model version                  : 1.250
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 07:51:16 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_arm_cortex_a_top_model_pil_h_
#define RTW_HEADER_arm_cortex_a_top_model_pil_h_
#include <stddef.h>
#ifndef arm_cortex_a_top_model_pil_COMMON_INCLUDES_
# define arm_cortex_a_top_model_pil_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* arm_cortex_a_top_model_pil_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define arm_cortex_a_top_model_pil_M   (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T ticks_to_count;            /* '<Root>/ticks_to_count' */
  boolean_T reset;                     /* '<Root>/reset' */
  boolean_T counter_mode;              /* '<Root>/counter_mode' */
  boolean_T count_enable;              /* '<Root>/count_enable' */
} ExternalInputs;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T count_a;                     /* '<Root>/count_a' */
  uint8_T count_b;                     /* '<Root>/count_b' */
} ExternalOutputs;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs rtY;

/* Model entry point functions */
extern void arm_cortex_a_top_model_pil_initialize(void);
extern void arm_cortex_a_top_model_pil_step(void);
extern void arm_cortex_a_top_model_pil_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'arm_cortex_a_top_model_pil'
 * '<S1>'   : 'arm_cortex_a_top_model_pil/CounterTypeA'
 * '<S2>'   : 'arm_cortex_a_top_model_pil/CounterTypeB'
 */
#endif                                 /* RTW_HEADER_arm_cortex_a_top_model_pil_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
