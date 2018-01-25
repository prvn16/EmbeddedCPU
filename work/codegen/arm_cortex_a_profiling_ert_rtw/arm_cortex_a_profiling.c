/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arm_cortex_a_profiling.c
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

#include "arm_cortex_a_profiling.h"
#include "arm_cortex_a_profiling_private.h"

/* Block signals (auto storage) */
BlockIO_arm_cortex_a_profiling arm_cortex_a_profiling_B;

/* Block states (auto storage) */
D_Work_arm_cortex_a_profiling arm_cortex_a_profiling_DWork;

/* Real-time model */
RT_MODEL_arm_cortex_a_profiling arm_cortex_a_profiling_M_;
RT_MODEL_arm_cortex_a_profiling *const arm_cortex_a_profiling_M =
  &arm_cortex_a_profiling_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void arm_cortex_a_profiling_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(arm_cortex_a_profiling_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (arm_cortex_a_profiling_M->Timing.TaskCounters.TID[1])++;
  if ((arm_cortex_a_profiling_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    arm_cortex_a_profiling_M->Timing.TaskCounters.TID[1] = 0;
  }
}

void RandSrc_GZ_R(real32_T y[], const real32_T mean[], int32_T meanLen, const
                  real32_T xstd[], int32_T xstdLen, uint32_T state[], int32_T
                  nChans, int32_T nSamps)
{
  int32_T i;
  int32_T j;
  real32_T r;
  real32_T x;
  real32_T s;
  real32_T y_0;
  int32_T chan;
  uint32_T icng;
  uint32_T jsr;
  int32_T samp;
  static const real32_T vt[65] = { 0.340945F, 0.45731461F, 0.539779305F,
    0.606242716F, 0.663169086F, 0.713697493F, 0.759612501F, 0.80203563F,
    0.841722727F, 0.879210174F, 0.914894819F, 0.949079096F, 0.98200053F,
    1.01384926F, 1.04478097F, 1.07492542F, 1.10439169F, 1.13327384F, 1.16165304F,
    1.18960094F, 1.21718144F, 1.24445164F, 1.27146351F, 1.29826498F, 1.32490075F,
    1.35141253F, 1.37783992F, 1.40422106F, 1.43059289F, 1.45699155F, 1.48345268F,
    1.51001215F, 1.53670609F, 1.56357121F, 1.59064543F, 1.61796796F, 1.64558017F,
    1.67352545F, 1.7018503F, 1.73060453F, 1.75984216F, 1.78962231F, 1.82001F,
    1.85107696F, 1.88290441F, 1.91558313F, 1.9492166F, 1.98392391F, 2.0198431F,
    2.05713558F, 2.09599304F, 2.13664508F, 2.17937136F, 2.22451758F, 2.27251863F,
    2.32393384F, 2.37950087F, 2.44022179F, 2.50751162F, 2.58346581F, 2.67139149F,
    2.77699423F, 2.77699423F, 2.77699423F, 2.77699423F };

  /* S-Function (sdsprandsrc2): '<S4>/Gaussian Noise1' */
  /* RandSrc_GZ_R */
  for (chan = 0; chan < nChans; chan++) {
    icng = state[chan << 1];
    jsr = state[(chan << 1) + 1];
    for (samp = 0; samp < nSamps; samp++) {
      icng = 69069U * icng + 1234567U;
      jsr ^= jsr << 13;
      jsr ^= jsr >> 17;
      jsr ^= jsr << 5;
      i = (int32_T)(icng + jsr);
      j = (i & 63) + 1;
      r = (real32_T)i * 4.65661287E-10F * vt[j];
      if (!((real32_T)fabs(r) <= vt[j - 1])) {
        x = ((real32_T)fabs(r) - vt[j - 1]) / (vt[j] - vt[j - 1]);
        icng = 69069U * icng + 1234567U;
        jsr ^= jsr << 13;
        jsr ^= jsr >> 17;
        jsr ^= jsr << 5;
        y_0 = (real32_T)(int32_T)(icng + jsr) * 2.32830644E-10F + 0.5F;
        s = x + y_0;
        if (s > 1.30119801F) {
          r = r < 0.0F ? 0.487899214F * x - 0.487899214F : 0.487899214F -
            0.487899214F * x;
        } else {
          if (!(s <= 0.96892792F)) {
            x = 0.487899214F - 0.487899214F * x;
            if (y_0 > 12.6770601F - (real32_T)exp(-0.5F * x * x) * 12.3758602F)
            {
              r = r < 0.0F ? -x : x;
            } else {
              if (!((real32_T)exp(-0.5F * vt[j] * vt[j]) + y_0 * 0.0195830297F /
                    vt[j] <= (real32_T)exp(-0.5F * r * r))) {
                do {
                  icng = 69069U * icng + 1234567U;
                  jsr ^= jsr << 13;
                  jsr ^= jsr >> 17;
                  jsr ^= jsr << 5;
                  x = (real32_T)log((real32_T)(int32_T)(icng + jsr) *
                                    2.32830644E-10F + 0.5F) / 2.77699399F;
                  icng = 69069U * icng + 1234567U;
                  jsr ^= jsr << 13;
                  jsr ^= jsr >> 17;
                  jsr ^= jsr << 5;
                } while ((real32_T)log((real32_T)(int32_T)(icng + jsr) *
                                       2.32830644E-10F + 0.5F) * -2.0F <= x * x);

                r = r < 0.0F ? x - 2.77699399F : 2.77699399F - x;
              }
            }
          }
        }
      }

      y[chan * nSamps + samp] = xstd[xstdLen > 1 ? chan : 0] * r + mean[meanLen >
        1 ? chan : 0];
    }

    state[chan << 1] = icng;
    state[(chan << 1) + 1] = jsr;
  }

  /* End of S-Function (sdsprandsrc2): '<S4>/Gaussian Noise1' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S4>/Gaussian Noise1' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    state[i << 1] = 362436069U;
    state[(i << 1) + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S4>/Gaussian Noise1' */
}

/* Model step function for TID0 */
void arm_cortex_a_profiling_step0(void) /* Sample time: [0.02s, 0.0s] */
{
  int32_T j;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  for (j = 0; j < 76; j++) {
    /* S-Function (sdspsine2): '<S4>/Sine Wave1' */
    arm_cortex_a_profiling_B.SineWave1[j] =
      arm_cortex_a_profiling_ConstP.SineWave1_Values_SineTable[arm_cortex_a_profiling_DWork.SineWave1_TableIdx];
    arm_cortex_a_profiling_DWork.SineWave1_TableIdx++;
    if (arm_cortex_a_profiling_DWork.SineWave1_TableIdx >= ((uint16_T)3U)) {
      arm_cortex_a_profiling_DWork.SineWave1_TableIdx = 0U;
    }

    /* End of S-Function (sdspsine2): '<S4>/Sine Wave1' */

    /* S-Function (sdspsine2): '<S4>/Sine Wave2' */
    arm_cortex_a_profiling_B.SineWave2[j] =
      arm_cortex_a_profiling_ConstP.SineWave2_Values_SineTable[arm_cortex_a_profiling_DWork.SineWave2_TableIdx];
    arm_cortex_a_profiling_DWork.SineWave2_TableIdx++;
    if (arm_cortex_a_profiling_DWork.SineWave2_TableIdx >= ((uint16_T)5U)) {
      arm_cortex_a_profiling_DWork.SineWave2_TableIdx = 0U;
    }

    /* End of S-Function (sdspsine2): '<S4>/Sine Wave2' */
  }

  /* S-Function (sdsprandsrc2): '<S4>/Gaussian Noise1' */
  RandSrc_GZ_R(arm_cortex_a_profiling_B.GaussianNoise1,
               &arm_cortex_a_profiling_P.GaussianNoise1_MeanVal, 1,
               &arm_cortex_a_profiling_P.GaussianNoise1_VarianceRTP, 1,
               arm_cortex_a_profiling_DWork.GaussianNoise1_STATE_DWORK, 1, 76);

  /* Sum: '<S4>/Sum1' */
  for (j = 0; j < 76; j++) {
    arm_cortex_a_profiling_B.SineWave1[j] =
      (arm_cortex_a_profiling_B.SineWave1[j] +
       arm_cortex_a_profiling_B.SineWave2[j]) +
      arm_cortex_a_profiling_B.GaussianNoise1[j];
  }

  /* End of Sum: '<S4>/Sum1' */

  /* Outputs for Atomic SubSystem: '<Root>/Bandpass' */
  /* DiscreteFir: '<S1>/Discrete FIR Filter' */
  /* Consume delay line and beginning of input samples */
  /* Update delay line for next frame */
  for (j = 50; j >= 0; j--) {
    arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_b[76 + j] =
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_b[j];
  }

  for (j = 0; j < 76; j++) {
    arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_b[75 - j] =
      arm_cortex_a_profiling_B.SineWave1[j];
  }

  /* End of DiscreteFir: '<S1>/Discrete FIR Filter' */
  /* End of Outputs for SubSystem: '<Root>/Bandpass' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(arm_cortex_a_profiling_M->rtwLogInfo,
                      (&arm_cortex_a_profiling_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(arm_cortex_a_profiling_M)!=-1) &&
        !((rtmGetTFinal(arm_cortex_a_profiling_M)-
           arm_cortex_a_profiling_M->Timing.taskTime0) >
          arm_cortex_a_profiling_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(arm_cortex_a_profiling_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++arm_cortex_a_profiling_M->Timing.clockTick0)) {
    ++arm_cortex_a_profiling_M->Timing.clockTickH0;
  }

  arm_cortex_a_profiling_M->Timing.taskTime0 =
    arm_cortex_a_profiling_M->Timing.clockTick0 *
    arm_cortex_a_profiling_M->Timing.stepSize0 +
    arm_cortex_a_profiling_M->Timing.clockTickH0 *
    arm_cortex_a_profiling_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void arm_cortex_a_profiling_step1(void) /* Sample time: [0.04s, 0.0s] */
{
  int32_T i;
  real32_T acc1;
  int32_T j;
  for (j = 0; j < 760; j++) {
    /* S-Function (sdspsine2): '<S5>/Sine Wave' */
    arm_cortex_a_profiling_B.SineWave[j] =
      arm_cortex_a_profiling_ConstP.SineWave_Values_SineTable[arm_cortex_a_profiling_DWork.SineWave_TableIdx];
    arm_cortex_a_profiling_DWork.SineWave_TableIdx++;
    if (arm_cortex_a_profiling_DWork.SineWave_TableIdx >= ((uint16_T)15U)) {
      arm_cortex_a_profiling_DWork.SineWave_TableIdx = 0U;
    }

    /* End of S-Function (sdspsine2): '<S5>/Sine Wave' */

    /* S-Function (sdspsine2): '<S5>/Sine Wave2' */
    arm_cortex_a_profiling_B.SineWave2_k[j] =
      arm_cortex_a_profiling_ConstP.SineWave2_Values_SineTable_c[arm_cortex_a_profiling_DWork.SineWave2_TableIdx_n];
    arm_cortex_a_profiling_DWork.SineWave2_TableIdx_n++;
    if (arm_cortex_a_profiling_DWork.SineWave2_TableIdx_n >= ((uint16_T)25U)) {
      arm_cortex_a_profiling_DWork.SineWave2_TableIdx_n = 0U;
    }

    /* End of S-Function (sdspsine2): '<S5>/Sine Wave2' */
  }

  /* S-Function (sdsprandsrc2): '<S5>/Gaussian Noise2' */
  RandSrc_GZ_R(arm_cortex_a_profiling_B.GaussianNoise2,
               &arm_cortex_a_profiling_P.GaussianNoise2_MeanVal, 1,
               &arm_cortex_a_profiling_P.GaussianNoise2_VarianceRTP, 1,
               arm_cortex_a_profiling_DWork.GaussianNoise2_STATE_DWORK, 1, 760);

  /* Sum: '<S5>/Sum2' */
  for (j = 0; j < 760; j++) {
    arm_cortex_a_profiling_B.SineWave[j] = (arm_cortex_a_profiling_B.SineWave[j]
      + arm_cortex_a_profiling_B.SineWave2_k[j]) +
      arm_cortex_a_profiling_B.GaussianNoise2[j];
  }

  /* End of Sum: '<S5>/Sum2' */

  /* Outputs for Atomic SubSystem: '<Root>/Highpass' */
  /* DiscreteFir: '<S2>/Discrete FIR Filter' */
  /* Consume delay line and beginning of input samples */
  for (i = 0; i < 174; i++) {
    acc1 = 0.0F;
    for (j = 0; j < i + 1; j++) {
      acc1 += arm_cortex_a_profiling_B.SineWave[i - j] *
        arm_cortex_a_profiling_P.DiscreteFIRFilter_Coefficient_o[j];
    }

    for (j = 0; j < 174 - i; j++) {
      acc1 += arm_cortex_a_profiling_P.DiscreteFIRFilter_Coefficient_o[(i + j) +
        1] * arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_i[j];
    }

    arm_cortex_a_profiling_B.DiscreteFIRFilter_l[i] = acc1;
  }

  /* Consume remaining input samples */
  for (i = 174; i < 760; i++) {
    acc1 = 0.0F;
    for (j = 0; j < 175; j++) {
      acc1 += arm_cortex_a_profiling_B.SineWave[i - j] *
        arm_cortex_a_profiling_P.DiscreteFIRFilter_Coefficient_o[j];
    }

    arm_cortex_a_profiling_B.DiscreteFIRFilter_l[i] = acc1;
  }

  /* Update delay line for next frame */
  for (i = 0; i < 174; i++) {
    arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_i[173 - i] =
      arm_cortex_a_profiling_B.SineWave[i + 586];
  }

  /* End of DiscreteFir: '<S2>/Discrete FIR Filter' */
  /* End of Outputs for SubSystem: '<Root>/Highpass' */

  /* Outputs for Atomic SubSystem: '<Root>/Lowpass' */
  /* DiscreteFir: '<S3>/Discrete FIR Filter' */
  /* Consume delay line and beginning of input samples */
  /* Consume remaining input samples */
  /* Update delay line for next frame */
  for (i = 0; i < 76; i++) {
    arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states[75 - i] =
      arm_cortex_a_profiling_B.DiscreteFIRFilter_l[i + 684];
  }

  /* End of DiscreteFir: '<S3>/Discrete FIR Filter' */
  /* End of Outputs for SubSystem: '<Root>/Lowpass' */
}

/* Model step wrapper function for compatibility with a static main program */
void arm_cortex_a_profiling_step(int_T tid)
{
  switch (tid) {
   case 0 :
    arm_cortex_a_profiling_step0();
    break;

   case 1 :
    arm_cortex_a_profiling_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void arm_cortex_a_profiling_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)arm_cortex_a_profiling_M, 0,
                sizeof(RT_MODEL_arm_cortex_a_profiling));
  rtmSetTFinal(arm_cortex_a_profiling_M, 5.0);
  arm_cortex_a_profiling_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    arm_cortex_a_profiling_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(arm_cortex_a_profiling_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(arm_cortex_a_profiling_M->rtwLogInfo, (NULL));
    rtliSetLogT(arm_cortex_a_profiling_M->rtwLogInfo, "");
    rtliSetLogX(arm_cortex_a_profiling_M->rtwLogInfo, "");
    rtliSetLogXFinal(arm_cortex_a_profiling_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(arm_cortex_a_profiling_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(arm_cortex_a_profiling_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(arm_cortex_a_profiling_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(arm_cortex_a_profiling_M->rtwLogInfo, 1);
    rtliSetLogY(arm_cortex_a_profiling_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(arm_cortex_a_profiling_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(arm_cortex_a_profiling_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&arm_cortex_a_profiling_DWork, 0,
                sizeof(D_Work_arm_cortex_a_profiling));

  {
    int32_T i;
    for (i = 0; i < 76; i++) {
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 174; i++) {
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_i[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 127; i++) {
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_b[i] = 0.0F;
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(arm_cortex_a_profiling_M->rtwLogInfo, 0.0,
    rtmGetTFinal(arm_cortex_a_profiling_M),
    arm_cortex_a_profiling_M->Timing.stepSize0, (&rtmGetErrorStatus
    (arm_cortex_a_profiling_M)));

  {
    int32_T i;

    /* Start for S-Function (sdspsine2): '<S4>/Sine Wave1' */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave1_TableIdx = 0U;

    /* Start for S-Function (sdspsine2): '<S4>/Sine Wave2' */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave2_TableIdx = 0U;

    /* Start for S-Function (sdspsine2): '<S5>/Sine Wave' */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave_TableIdx = 0U;

    /* Start for S-Function (sdspsine2): '<S5>/Sine Wave2' */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave2_TableIdx_n = 0U;

    /* InitializeConditions for S-Function (sdspsine2): '<S4>/Sine Wave1' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave1_TableIdx = 0U;

    /* InitializeConditions for S-Function (sdspsine2): '<S4>/Sine Wave2' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave2_TableIdx = 0U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S4>/Gaussian Noise1' */
    RandSrcInitState_GZ(&arm_cortex_a_profiling_P.GaussianNoise1_rawSeed,
                        arm_cortex_a_profiling_DWork.GaussianNoise1_STATE_DWORK,
                        1);

    /* InitializeConditions for S-Function (sdspsine2): '<S5>/Sine Wave' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave_TableIdx = 0U;

    /* InitializeConditions for S-Function (sdspsine2): '<S5>/Sine Wave2' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Full-cycle Table lookup */
    arm_cortex_a_profiling_DWork.SineWave2_TableIdx_n = 0U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S5>/Gaussian Noise2' */
    RandSrcInitState_GZ(&arm_cortex_a_profiling_P.GaussianNoise2_rawSeed,
                        arm_cortex_a_profiling_DWork.GaussianNoise2_STATE_DWORK,
                        1);

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bandpass' */
    /* InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter' */
    for (i = 0; i < 127; i++) {
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_b[i] =
        arm_cortex_a_profiling_P.DiscreteFIRFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter' */
    /* End of SystemInitialize for SubSystem: '<Root>/Bandpass' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Highpass' */
    /* InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter' */
    for (i = 0; i < 174; i++) {
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states_i[i] =
        arm_cortex_a_profiling_P.DiscreteFIRFilter_InitialStat_a;
    }

    /* End of InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter' */
    /* End of SystemInitialize for SubSystem: '<Root>/Highpass' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Lowpass' */
    /* InitializeConditions for DiscreteFir: '<S3>/Discrete FIR Filter' */
    for (i = 0; i < 76; i++) {
      arm_cortex_a_profiling_DWork.DiscreteFIRFilter_states[i] =
        arm_cortex_a_profiling_P.DiscreteFIRFilter_InitialSta_ae;
    }

    /* End of InitializeConditions for DiscreteFir: '<S3>/Discrete FIR Filter' */
    /* End of SystemInitialize for SubSystem: '<Root>/Lowpass' */
  }
}

/* Model terminate function */
void arm_cortex_a_profiling_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
