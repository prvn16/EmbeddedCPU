/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_profiling.h
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

#ifndef RTW_HEADER_arm_cortex_a_profiling_h_
#define RTW_HEADER_arm_cortex_a_profiling_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef arm_cortex_a_profiling_COMMON_INCLUDES_
# define arm_cortex_a_profiling_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_logging.h"
#endif                                 /* arm_cortex_a_profiling_COMMON_INCLUDES_ */

#include "arm_cortex_a_profiling_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T DiscreteFIRFilter_l[760];   /* '<S2>/Discrete FIR Filter' */
  real32_T SineWave2_k[760];           /* '<S5>/Sine Wave2' */
  real32_T GaussianNoise2[760];        /* '<S5>/Gaussian Noise2' */
  real32_T SineWave[760];              /* '<S5>/Sine Wave' */
  real32_T SineWave2[76];              /* '<S4>/Sine Wave2' */
  real32_T GaussianNoise1[76];         /* '<S4>/Gaussian Noise1' */
  real32_T SineWave1[76];              /* '<S4>/Sine Wave1' */
} BlockIO_arm_cortex_a_profiling;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteFIRFilter_states[76];/* '<S3>/Discrete FIR Filter' */
  real32_T DiscreteFIRFilter_states_i[174];/* '<S2>/Discrete FIR Filter' */
  real32_T DiscreteFIRFilter_states_b[127];/* '<S1>/Discrete FIR Filter' */
  uint32_T GaussianNoise1_STATE_DWORK[2];/* '<S4>/Gaussian Noise1' */
  uint32_T GaussianNoise2_STATE_DWORK[2];/* '<S5>/Gaussian Noise2' */
  uint16_T SineWave1_TableIdx;         /* '<S4>/Sine Wave1' */
  uint16_T SineWave2_TableIdx;         /* '<S4>/Sine Wave2' */
  uint16_T SineWave_TableIdx;          /* '<S5>/Sine Wave' */
  uint16_T SineWave2_TableIdx_n;       /* '<S5>/Sine Wave2' */
} D_Work_arm_cortex_a_profiling;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: SineWave1_Values_SineTable
   * Referenced by: '<S4>/Sine Wave1'
   */
  real32_T SineWave1_Values_SineTable[3];

  /* Computed Parameter: SineWave2_Values_SineTable
   * Referenced by: '<S4>/Sine Wave2'
   */
  real32_T SineWave2_Values_SineTable[5];

  /* Computed Parameter: SineWave_Values_SineTable
   * Referenced by: '<S5>/Sine Wave'
   */
  real32_T SineWave_Values_SineTable[15];

  /* Computed Parameter: SineWave2_Values_SineTable_c
   * Referenced by: '<S5>/Sine Wave2'
   */
  real32_T SineWave2_Values_SineTable_c[25];
} ConstParam_arm_cortex_a_profili;

/* Parameters (auto storage) */
struct Parameters_arm_cortex_a_profili_ {
  real32_T GaussianNoise1_MeanVal;     /* Mask Parameter: GaussianNoise1_MeanVal
                                        * Referenced by: '<S4>/Gaussian Noise1'
                                        */
  real32_T GaussianNoise2_MeanVal;     /* Mask Parameter: GaussianNoise2_MeanVal
                                        * Referenced by: '<S5>/Gaussian Noise2'
                                        */
  uint32_T GaussianNoise1_rawSeed;     /* Mask Parameter: GaussianNoise1_rawSeed
                                        * Referenced by: '<S4>/Gaussian Noise1'
                                        */
  uint32_T GaussianNoise2_rawSeed;     /* Mask Parameter: GaussianNoise2_rawSeed
                                        * Referenced by: '<S5>/Gaussian Noise2'
                                        */
  real32_T DiscreteFIRFilter_InitialStates;/* Computed Parameter: DiscreteFIRFilter_InitialStates
                                            * Referenced by: '<S1>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficients[128];/* Computed Parameter: DiscreteFIRFilter_Coefficients
                                                * Referenced by: '<S1>/Discrete FIR Filter'
                                                */
  real32_T DiscreteFIRFilter_InitialStat_a;/* Computed Parameter: DiscreteFIRFilter_InitialStat_a
                                            * Referenced by: '<S2>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficient_o[175];/* Computed Parameter: DiscreteFIRFilter_Coefficient_o
                                                 * Referenced by: '<S2>/Discrete FIR Filter'
                                                 */
  real32_T DiscreteFIRFilter_InitialSta_ae;/* Computed Parameter: DiscreteFIRFilter_InitialSta_ae
                                            * Referenced by: '<S3>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficient_p[77];/* Computed Parameter: DiscreteFIRFilter_Coefficient_p
                                                * Referenced by: '<S3>/Discrete FIR Filter'
                                                */
  real32_T GaussianNoise1_VarianceRTP; /* Computed Parameter: GaussianNoise1_VarianceRTP
                                        * Referenced by: '<S4>/Gaussian Noise1'
                                        */
  real32_T GaussianNoise2_VarianceRTP; /* Computed Parameter: GaussianNoise2_VarianceRTP
                                        * Referenced by: '<S5>/Gaussian Noise2'
                                        */
};

/* Real-time Model Data Structure */


/* Declare global externs for instrumentation */
extern void profileStart_a_bb0ce45fcf40b6f8(uint32_T);
extern void profileEnd_arm_65c744fc547b33df(uint32_T);
struct tag_RTM_arm_cortex_a_profiling {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_arm_cortex_a_profili arm_cortex_a_profiling_P;

/* Block signals (auto storage) */
extern BlockIO_arm_cortex_a_profiling arm_cortex_a_profiling_B;

/* Block states (auto storage) */
extern D_Work_arm_cortex_a_profiling arm_cortex_a_profiling_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_arm_cortex_a_profili arm_cortex_a_profiling_ConstP;

/* External function called from main */
extern void arm_cortex_a_profiling_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void arm_cortex_a_profiling_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void arm_cortex_a_profiling_initialize(void);
extern void arm_cortex_a_profiling_step(int_T tid);
extern void arm_cortex_a_profiling_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arm_cortex_a_profiling *const arm_cortex_a_profiling_M;

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
 * '<Root>' : 'arm_cortex_a_profiling'
 * '<S1>'   : 'arm_cortex_a_profiling/Bandpass'
 * '<S2>'   : 'arm_cortex_a_profiling/Highpass'
 * '<S3>'   : 'arm_cortex_a_profiling/Lowpass'
 * '<S4>'   : 'arm_cortex_a_profiling/Signal1'
 * '<S5>'   : 'arm_cortex_a_profiling/Signal2'
 */
#endif                                 /* RTW_HEADER_arm_cortex_a_profiling_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
