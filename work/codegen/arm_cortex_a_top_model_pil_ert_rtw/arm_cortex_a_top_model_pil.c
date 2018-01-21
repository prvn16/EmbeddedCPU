/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_top_model_pil.c
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

#include "arm_cortex_a_top_model_pil.h"

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static boolean_T enableA;
static boolean_T enableB;

/* External inputs (root inport signals with auto storage) */
ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void CounterTypeA_Init(void);
static void CounterTypeA(void);
static void CounterTypeB_Init(void);
static void CounterTypeB(void);

/* System initialize for enable system: '<Root>/CounterTypeA' */
static void CounterTypeA_Init(void)
{
  /* SystemInitialize for Switch: '<S1>/Switch1' incorporates:
   *  Outport: '<Root>/count_a'
   *  Outport: '<S1>/count'
   */
  rtY.count_a = 25U;
}

/* Output and update for enable system: '<Root>/CounterTypeA' */
static void CounterTypeA(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/CounterTypeA' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (enableA) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/C1'
     *  Inport: '<Root>/reset'
     *  Inport: '<Root>/ticks_to_count'
     *  Sum: '<S1>/Add'
     */
    if (rtU.reset) {
      rtY.count_a = 20U;
    }

    rtY.count_a = (uint8_T)(uint32_T)((uint32_T)rtU.ticks_to_count + (uint32_T)
      rtY.count_a);

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/C5'
     *  RelationalOperator: '<S1>/upper GE input'
     */
    if (!(40 >= (int32_T)rtY.count_a)) {
      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/C1'
       *  Outport: '<Root>/count_a'
       */
      rtY.count_a = 20U;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* End of Outputs for SubSystem: '<Root>/CounterTypeA' */
}

/* System initialize for enable system: '<Root>/CounterTypeB' */
static void CounterTypeB_Init(void)
{
  /* SystemInitialize for Switch: '<S2>/Switch1' incorporates:
   *  Outport: '<Root>/count_b'
   *  Outport: '<S2>/count'
   */
  rtY.count_b = 15U;
}

/* Output and update for enable system: '<Root>/CounterTypeB' */
static void CounterTypeB(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/CounterTypeB' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (enableB) {
    /* Switch: '<S2>/Switch1' incorporates:
     *  Constant: '<S2>/C1'
     *  Inport: '<Root>/reset'
     *  Inport: '<Root>/ticks_to_count'
     *  Outport: '<Root>/count_b'
     *  Sum: '<S2>/Add'
     */
    if (rtU.reset) {
      rtY.count_b = 0U;
    }

    rtY.count_b = (uint8_T)(uint32_T)((uint32_T)rtU.ticks_to_count + (uint32_T)
      rtY.count_b);

    /* End of Switch: '<S2>/Switch1' */
  }

  /* End of Outputs for SubSystem: '<Root>/CounterTypeB' */
}

/* Model step function */
void arm_cortex_a_top_model_pil_step(void)
{
  /* Logic: '<Root>/Logical Operator2' incorporates:
   *  Inport: '<Root>/count_enable'
   *  Inport: '<Root>/counter_mode'
   *  Logic: '<Root>/Logical Operator'
   */
  enableA = ((!rtU.counter_mode) && rtU.count_enable);

  /* Outputs for Enabled SubSystem: '<Root>/CounterTypeA' */
  CounterTypeA();

  /* End of Outputs for SubSystem: '<Root>/CounterTypeA' */

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Inport: '<Root>/count_enable'
   *  Inport: '<Root>/counter_mode'
   */
  enableB = (rtU.counter_mode && rtU.count_enable);

  /* Outputs for Enabled SubSystem: '<Root>/CounterTypeB' */
  CounterTypeB();

  /* End of Outputs for SubSystem: '<Root>/CounterTypeB' */
}

/* Model initialize function */
void arm_cortex_a_top_model_pil_initialize(void)
{
  /* SystemInitialize for Enabled SubSystem: '<Root>/CounterTypeA' */
  CounterTypeA_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/CounterTypeA' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/CounterTypeB' */
  CounterTypeB_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/CounterTypeB' */
}

/* Model terminate function */
void arm_cortex_a_top_model_pil_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
