/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "code_profiling_utility_functions.h"
#include "arm_cortex_a_top_model_pil.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"

unsigned int profilingDataIdx = 0;
unsigned long int _tmwrunningCoreID;
struct _profilingData
{
  unsigned long int sectionID[400];
  unsigned long int timerValue[400];
  unsigned long int coreID[400];
} profilingData;

pthread_mutex_t profilingDataStoreMutex;
void store_code_profiling_data_point(void * pData, uint32_T numMemUnits,
  uint32_T sectionId)
{
  uint32_T * pTimerValue = (uint32_T *) pData;
  size_t elNum = 0;
  size_t numEls = numMemUnits/sizeof(uint32_T);
  if (profilingDataIdx==400) {
    return;
  }

  for (elNum=0; elNum<numEls; ++elNum) {
    profilingData.sectionID[profilingDataIdx] = sectionId;
    profilingData.timerValue[profilingDataIdx] = pTimerValue[elNum];
    profilingData.coreID[profilingDataIdx] = _tmwrunningCoreID;
    profilingDataIdx++;
  }
}

void code_profiling_atomic_read_store(uint32_T sectionId)
{
  pthread_mutex_lock(&profilingDataStoreMutex);

  /* Using a timer that increments on each tick. */
  uint32_T timerValue = (uint32_T)profileReadTimer();
  store_code_profiling_data_point((void *)(&timerValue), (uint32_T)(sizeof
    (uint32_T)), sectionId);
  pthread_mutex_unlock(&profilingDataStoreMutex);
}

#define UNUSED(x)                      x = x

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(rtM) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);
    taskTimeStart_(2U);
    arm_cortex_a_top_model_pil_step();
    taskTimeEnd_(2U);

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(rtM) == (NULL)));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(rtM, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  taskTimeStart_(3U);
  arm_cortex_a_top_model_pil_terminate();
  taskTimeEnd_(3U);

  {
    FILE* fid;
    unsigned int i;
    fid = fopen("arm_cortex_a_top_model_pil.txt", "w");
    if (fid!=NULL) {
      for (i=0; i<profilingDataIdx; i++) {
        fprintf(fid, "%lu, %lu, %lu\n",
                profilingData.sectionID[i], profilingData.timerValue[i],
                profilingData.coreID[i]);
      }

      fclose(fid);
    }
  }

  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  rtmSetErrorStatus(rtM, 0);

  /* Initialize model */
  taskTimeStart_(1U);
  arm_cortex_a_top_model_pil_initialize();
  taskTimeEnd_(1U);

  /* Call RTOS Initialization function */
  myRTOSInit(0.1, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);
  pthread_mutex_destroy(&profilingDataStoreMutex);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
