/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FIR.h
 *
 * Code generated for Simulink model 'FIR'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 04:31:31 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FIR_h_
#define RTW_HEADER_FIR_h_
#include <string.h>
#include <stddef.h>
#ifndef FIR_COMMON_INCLUDES_
# define FIR_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FIR_COMMON_INCLUDES_ */

#include "FIR_types.h"
#include "NE10.h"
#include "NE10_mask_table.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  ne10_fir_instance_f32_t S;           /* synthesized block */
  real32_T pState[139];                /* synthesized block */
  real32_T qCoeff[64];                 /* synthesized block */
} DW_FIR_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T OriginalSignal[76];         /* '<Root>/In1' */
} ExtU_FIR_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Out1[76];                   /* '<Root>/Out1' */
} ExtY_FIR_T;

/* Real-time Model Data Structure */
struct tag_RTM_FIR_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_FIR_T FIR_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_FIR_T FIR_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_FIR_T FIR_Y;

/* Model entry point functions */
extern void FIR_initialize(void);
extern void FIR_step(void);
extern void FIR_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FIR_T *const FIR_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('fir_ne10/FIR')    - opens subsystem fir_ne10/FIR
 * hilite_system('fir_ne10/FIR/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fir_ne10'
 * '<S1>'   : 'fir_ne10/FIR'
 */
#endif                                 /* RTW_HEADER_FIR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
