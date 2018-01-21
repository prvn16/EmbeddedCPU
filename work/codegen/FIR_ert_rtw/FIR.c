/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FIR.c
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

#include "FIR.h"
#include "FIR_private.h"

/* Block states (auto storage) */
DW_FIR_T FIR_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_FIR_T FIR_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_FIR_T FIR_Y;

/* Real-time model */
RT_MODEL_FIR_T FIR_M_;
RT_MODEL_FIR_T *const FIR_M = &FIR_M_;

/* Model step function */
void FIR_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/FIR' */
  /* DiscreteFir: '<S1>/Discrete FIR Filter' incorporates:
   *  Inport: '<Root>/In1'
   *  Outport: '<Root>/Out1'
   */
  ne10_fir_float_neon(&FIR_DW.S, &FIR_U.OriginalSignal[0], &FIR_Y.Out1[0], 76U);

  /* End of Outputs for SubSystem: '<Root>/FIR' */
}

/* Model initialize function */
void FIR_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FIR_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&FIR_DW, 0,
                sizeof(DW_FIR_T));

  /* external inputs */
  (void)memset((void *)&FIR_U, 0, sizeof(ExtU_FIR_T));

  /* external outputs */
  (void) memset(&FIR_Y.Out1[0], 0,
                76U*sizeof(real32_T));

  {
    static const real_T tmp[64] = { 0.00080778838472719806,
      0.00042905548705667897, -0.00048044594457101258, -0.0011208949727419544,
      -0.00067153095025518231, 0.00081627957461897257, 0.0019948413989975796,
      0.0012178679321087436, -0.0014807767617716296, -0.0035792352851763774,
      -0.0021482720299582495, 0.0025611589713199021, 0.0060668058880321883,
      0.0035710582331055637, -0.0041814121108098038, -0.00974679970620418,
      -0.0056581816627061876, 0.0065499591788642786, 0.015134310555718202,
      0.0087341600345598423, -0.010083986843950706, -0.02332488960899784,
      -0.013534943883501994, 0.015798100253775035, 0.037201242224336004,
      0.022183461342827875, -0.026963778809924024, -0.0674616366846787,
      -0.044177580479455629, 0.062708470695937782, 0.21095500478317686,
      0.31788480079554055, 0.31788480079554055, 0.21095500478317686,
      0.062708470695937782, -0.044177580479455629, -0.0674616366846787,
      -0.026963778809924024, 0.022183461342827875, 0.037201242224336004,
      0.015798100253775035, -0.013534943883501994, -0.02332488960899784,
      -0.010083986843950706, 0.0087341600345598423, 0.015134310555718202,
      0.0065499591788642786, -0.0056581816627061876, -0.00974679970620418,
      -0.0041814121108098038, 0.0035710582331055637, 0.0060668058880321883,
      0.0025611589713199021, -0.0021482720299582495, -0.0035792352851763774,
      -0.0014807767617716296, 0.0012178679321087436, 0.0019948413989975796,
      0.00081627957461897257, -0.00067153095025518231, -0.0011208949727419544,
      -0.00048044594457101258, 0.00042905548705667897, 0.00080778838472719806 };

    int32_T i;

    /* SystemInitialize for Atomic SubSystem: '<Root>/FIR' */
    /* InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter' */
    for (i = 0; i < 64; i++) {
      FIR_DW.qCoeff[i] = (real32_T)tmp[i];
    }

    ne10_fir_init_float(&FIR_DW.S, 64U, &FIR_DW.qCoeff[0], &FIR_DW.pState[0],
                        76U);

    /* End of InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter' */
    /* End of SystemInitialize for SubSystem: '<Root>/FIR' */
  }
}

/* Model terminate function */
void FIR_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
