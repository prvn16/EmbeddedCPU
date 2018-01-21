/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fir_ne10.h
 *
 * Code generated for Simulink model 'fir_ne10'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 21 03:44:20 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_fir_ne10_h_
#define RTW_HEADER_fir_ne10_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef fir_ne10_COMMON_INCLUDES_
# define fir_ne10_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* fir_ne10_COMMON_INCLUDES_ */

#include "fir_ne10_types.h"
#include "NE10.h"
#include "NE10_mask_table.h"
#include "mw_neon.h"

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
  real32_T ukHzSineWave_AccFreqNorm;   /* '<Root>/1 kHz Sine Wave' */
  real32_T ukHzSineWave_AccFreqNorm_n; /* '<Root>/3 kHz Sine Wave' */
  real32_T pState[139];                /* synthesized block */
  real32_T qCoeff[64];                 /* synthesized block */
  uint32_T GaussianNoise_STATE_DWORK[2];/* '<Root>/Gaussian Noise' */
} DW_fir_ne10_T;

/* Parameters (auto storage) */
struct P_fir_ne10_T_ {
  real32_T ukHzSineWave_Amplitude;     /* Mask Parameter: ukHzSineWave_Amplitude
                                        * Referenced by: '<Root>/1 kHz Sine Wave'
                                        */
  real32_T ukHzSineWave_Amplitude_e;   /* Mask Parameter: ukHzSineWave_Amplitude_e
                                        * Referenced by: '<Root>/3 kHz Sine Wave'
                                        */
  real32_T ukHzSineWave_Frequency;     /* Mask Parameter: ukHzSineWave_Frequency
                                        * Referenced by: '<Root>/1 kHz Sine Wave'
                                        */
  real32_T ukHzSineWave_Frequency_f;   /* Mask Parameter: ukHzSineWave_Frequency_f
                                        * Referenced by: '<Root>/3 kHz Sine Wave'
                                        */
  real32_T GaussianNoise_MeanVal;      /* Mask Parameter: GaussianNoise_MeanVal
                                        * Referenced by: '<Root>/Gaussian Noise'
                                        */
  real32_T ukHzSineWave_Phase;         /* Mask Parameter: ukHzSineWave_Phase
                                        * Referenced by: '<Root>/1 kHz Sine Wave'
                                        */
  real32_T ukHzSineWave_Phase_m;       /* Mask Parameter: ukHzSineWave_Phase_m
                                        * Referenced by: '<Root>/3 kHz Sine Wave'
                                        */
  uint32_T GaussianNoise_rawSeed;      /* Mask Parameter: GaussianNoise_rawSeed
                                        * Referenced by: '<Root>/Gaussian Noise'
                                        */
  real32_T GaussianNoise_VarianceRTP;  /* Computed Parameter: GaussianNoise_VarianceRTP
                                        * Referenced by: '<Root>/Gaussian Noise'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_fir_ne10_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_fir_ne10_T fir_ne10_P;

/* Block states (auto storage) */
extern DW_fir_ne10_T fir_ne10_DW;

/* Model entry point functions */
extern void fir_ne10_initialize(void);
extern void fir_ne10_step(void);
extern void fir_ne10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_fir_ne10_T *const fir_ne10_M;

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
 * '<Root>' : 'fir_ne10'
 * '<S1>'   : 'fir_ne10/FIR'
 */
#endif                                 /* RTW_HEADER_fir_ne10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
