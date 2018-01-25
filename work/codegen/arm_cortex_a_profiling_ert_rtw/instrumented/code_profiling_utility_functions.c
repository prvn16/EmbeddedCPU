/*
 * File: code_profiling_utility_functions.c
 *
 * Code generated for instrumentation.
 *
 */

#include "code_profiling_utility_functions.h"

/* Code instrumentation offset(s) for model  */
#define taskTimeStart__offset          0
#define taskTimeEnd__offset            0

/* Code instrumentation offset(s) for model arm_cortex_a_profiling */
#define profileStart_a_bb0ce45fcf40b6f8_offset 4
#define profileEnd_arm_65c744fc547b33df_offset 4

void xilUploadProfilingData(uint32_T sectionId)
{
  code_profiling_atomic_read_store(sectionId);
}

/* For real-time, multitasking case this function is stubbed out. */
void xilProfilingTimerFreeze(void)
{
}

/* For real-time, multitasking case this function is stubbed out. */
void xilProfilingTimerUnFreeze(void)
{
}

void taskTimeStart(uint32_T sectionId)
{
  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreeze();
}

void taskTimeEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
}

void profileStart(uint32_T sectionId)
{
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreeze();
}

void profileEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
  xilProfilingTimerUnFreeze();
}

/* Code instrumentation method(s) for model  */
void taskTimeStart_(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart__offset + sectionId);
}

void taskTimeEnd_(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd__offset + sectionId);
}

/* Code instrumentation method(s) for model arm_cortex_a_profiling */
void profileStart_a_bb0ce45fcf40b6f8(uint32_T sectionId)
{
  profileStart(profileStart_a_bb0ce45fcf40b6f8_offset + sectionId);
}

void profileEnd_arm_65c744fc547b33df(uint32_T sectionId)
{
  profileEnd(profileEnd_arm_65c744fc547b33df_offset + sectionId);
}
