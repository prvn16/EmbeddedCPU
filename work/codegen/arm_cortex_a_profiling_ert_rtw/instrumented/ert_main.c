/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "code_profiling_utility_functions.h"
#include "arm_cortex_a_profiling.h"
#include "arm_cortex_a_profiling_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "rt_logging.h"
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
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name */
#ifndef SAVEFILE
# define MATFILE2(file)                #file ".mat"
# define MATFILE1(file)                MATFILE2(file)
# define MATFILE                       MATFILE1(MODEL)
#else
# define MATFILE                       QUOTE(SAVEFILE)
#endif

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    taskTimeStart_(2U + subRateId);
    arm_cortex_a_profiling_step(subRateId);
    taskTimeEnd_(2U + subRateId);

    /* Get model outputs here */
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(arm_cortex_a_profiling_M) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(arm_cortex_a_profiling_M, 1)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    taskTimeStart_(2U);
    arm_cortex_a_profiling_step(0);
    taskTimeEnd_(2U);

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(arm_cortex_a_profiling_M) == (NULL)));
    runModel = !stopRequested;
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(arm_cortex_a_profiling_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i],(void *)&threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  rt_StopDataLogging(MATFILE, arm_cortex_a_profiling_M->rtwLogInfo);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  taskTimeStart_(4U);
  arm_cortex_a_profiling_terminate();
  taskTimeEnd_(4U);

  {
    FILE* fid;
    unsigned int i;
    fid = fopen("arm_cortex_a_profiling.txt", "w");
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
  subratePriority[0] = 39;
  rtmSetErrorStatus(arm_cortex_a_profiling_M, 0);

  /* Initialize model */
  taskTimeStart_(1U);
  arm_cortex_a_profiling_initialize();
  taskTimeEnd_(1U);

  /* Call RTOS Initialization function */
  myRTOSInit(0.02, 1);

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
