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
#include "arm_cortex_a_profiling.h"
#include "arm_cortex_a_profiling_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "rt_logging.h"
#include "linuxinitialize.h"
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

    arm_cortex_a_profiling_step(subRateId);

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

    arm_cortex_a_profiling_step(0);

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
  arm_cortex_a_profiling_terminate();

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
  arm_cortex_a_profiling_initialize();

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
