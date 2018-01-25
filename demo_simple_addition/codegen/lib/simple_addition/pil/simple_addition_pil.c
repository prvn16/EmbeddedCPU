/*
 * simple_addition_pil.c
 *
 * Automatically generated host I/O interface for:
 * Component: simple_addition
 * Execution Mode: PIL
 *
 */

#include <stdio.h>
#include <string.h>
#include "mex.h"
#include "coder/connectivity_core/xilutils/xilutils.h"
#include "rtiostream_utils.h"
#include "coder/connectivity/xilcomms_rtiostream/xilcomms_rtiostream.h"
#include "coder/connectivity/XILHostAppSvc/XILHostAppSvc_CInterface.h"
#include "coder/connectivity/CodeInstrHostAppSvc/CodeInstrHostAppSvc_CInterface.h"
#include "coder/connectivity/CoderAssumpHostAppSvc/CoderAssumpHostAppSvc_CInterface.h"
#include "_coder_simple_addition_api.h"
#include "_coder_simple_addition_info.h"
#include "coder/connectivity/memunit/MemUnitTransformerType.h"
#include "xil_host_interface.h"

/* Response case labels */
enum ResponseIDs {
  RESPONSE_ERROR = 0,
  RESPONSE_OUTPUT_DATA = 1,
  RESPONSE_PRINTF = 2,
  RESPONSE_FOPEN = 3,
  RESPONSE_FPRINTF = 4,
  RESPONSE_SIGNAL_RAISED = 5
};

typedef struct {
  FILE ** Fd;
  mwSize size;
  int32_T fidOffset;
} targetIOFd_T;

typedef enum {
  XIL_INIT_COMMAND = 0,
  XIL_INITIALIZE_COMMAND,
  XIL_SYSTEM_INITIALIZE_COMMAND,
  XIL_OUTPUT_COMMAND,
  XIL_TERMINATE_COMMAND,
  XIL_ENABLE_COMMAND,
  XIL_DISABLE_COMMAND,
  XIL_CONST_OUTPUT_COMMAND,
  XIL_PROCESS_PARAMS_COMMAND,
  XIL_CLIENT_SERVER_COMMAND,
  XIL_SHUTDOWN_COMMAND,
  XIL_UPDATE_COMMAND,
  XIL_SYSTEM_RESET_COMMAND,
  XIL_PAUSE_COMMAND
}
  XIL_COMMAND_TYPE_ENUM;

static targetIOFd_T *targetIOFdPtr = NULL;
static XIL_RtIOStreamData_T* rtIOStreamDataPtr = NULL;
static SIL_DEBUGGING_DATA_T* silDebuggingDataPtr = NULL;
static XIL_IOBuffer_T* IOBufferPtr = NULL;
static int* pCommErrorOccurred = NULL;
static int* pIsXILApplicationStarted = NULL;
static void* pXILService = NULL;
static void* pComms = NULL;
static void* pConnectionOptions = NULL;
static void* pXILUtils = NULL;
static void* pMemUnitTransformer = NULL;
static void* pCodeInstrService = NULL;
static time_T simTime = 1;
static void* pCoderAssumptionsApp = NULL;
static boolean_T firstTime= 0;
static boolean_T pKeepUtilsActive= 0;
static boolean_T executingClearMEX= 0;
static void (*cleanUp)(void);
static void callStopHookAndFreeSFcnMemory();
static void mdlTerminate();
static void xilThrowException(void* pXILUtils)
{
  if (pXILUtils == NULL) {
    mexPrintf("pXILUtils is NULL!");
    return;
  }                                    /* if */

  pKeepUtilsActive = 1;
  callStopHookAndFreeSFcnMemory();
  if (!executingClearMEX) {
    /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
    (*cleanUp)();
  }                                    /* if */

  {
    mxArray * pMException = xilMATLABUtilsGetException(pXILUtils);
    if (pMException == NULL) {
      mexPrintf("pMException is NULL!\n");
    } else {
      mxArray * rhs[1];
      rhs[0] = pMException;
      xilUtilsCallMATLAB(pXILUtils, 0, 0, 1, rhs,
                         "rtw.pil.SILPILInterface.throwMException");
    }                                  /* if */
  }
}

/* grow the buffer for target I/O Fd array
 * targetIOFd->Fd is NULL on failure */
static void growTargetIOFd(targetIOFd_T * IOFd, mwSize requiredSize)
{
  if (IOFd->size < requiredSize) {
    IOFd->Fd = mxRealloc(IOFd->Fd, requiredSize * sizeof(FILE*));
    if (IOFd->Fd == NULL) {
      mexErrMsgTxt( "growTargetIOFd: mxRealloc failed.");
    } else {
      mexMakeMemoryPersistent(IOFd->Fd);
      IOFd->size = requiredSize;
    }                                  /* if */
  }                                    /* if */
}

static void closeAndFreeTargetIOFd()
{
  int i;
  if (targetIOFdPtr != NULL) {
    if (targetIOFdPtr->Fd != NULL) {
      for (i=0; i<targetIOFdPtr->size; i++) {
        if (targetIOFdPtr->Fd[i] != NULL) {
          fclose(targetIOFdPtr->Fd[i]);
        }                              /* if */
      }                                /* for */

      mxFree(targetIOFdPtr->Fd);
    }                                  /* if */

    mxFree(targetIOFdPtr);
  }                                    /* if */

  targetIOFdPtr = NULL;
}

/* receive one packet of data and dispatch to owning application */
static boolean_T recvData(void* pComms)
{
  if (pCommErrorOccurred == NULL) {
    mexErrMsgTxt( "pCommErrorOccurred is NULL.");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  if (pXILUtils == NULL) {
    mexErrMsgTxt( "pXILUtils is NULL.");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  *pCommErrorOccurred = (xilCommsRun(pComms, pXILUtils) !=
    XILCOMMS_RTIOSTREAM_SUCCESS);
  return (*pCommErrorOccurred?XILHOSTAPPSVC_ERROR:XILHOSTAPPSVC_SUCCESS);
}

/* send data via xil comms */
static boolean_T sendData(void* pXILService, XIL_IOBuffer_T* IOBuffer, mwSize
  sendSize)
{
  if (pCommErrorOccurred == NULL) {
    mexErrMsgTxt( "pCommErrorOccurred is NULL.");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  *pCommErrorOccurred = (xilHostAppSvcSend(pXILService, IOBuffer->data, sendSize)
    != XILHOSTAPPSVC_SUCCESS);
  return (*pCommErrorOccurred?XILHOSTAPPSVC_ERROR:XILHOSTAPPSVC_SUCCESS);
}

/* implements command dispatch */
static boolean_T commandDispatch(XIL_IOBuffer_T* IOBuffer, mwSize dataOutSize)
{
  if (pXILService == NULL) {
    mexErrMsgTxt( "pXILService is NULL!");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  /* send the data */
  if (sendData(pXILService, IOBuffer, dataOutSize) != XILHOSTAPPSVC_SUCCESS) {
    xilThrowException(pXILUtils);
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

/* implements command response */
static boolean_T commandResponse(XIL_IOBuffer_T* IOBuffer,
  XILCommandResponseType* commandType)
{
  if (pXILService == NULL) {
    mexErrMsgTxt( "pXILService is NULL!");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  {
    /* receive the response data */
    uint8_T COMMAND_COMPLETE = 0;
    if (pComms == NULL) {
      mexErrMsgTxt( "pComms is NULL!");
      return XILHOSTAPPSVC_ERROR;
    }                                  /* if */

    while (!COMMAND_COMPLETE) {
      xilHostAppSvcSetIsResponseComplete(pXILService, 0);
      if (recvData(pComms) != XILHOSTAPPSVC_SUCCESS) {
        xilThrowException(pXILUtils);
        return XILHOSTAPPSVC_ERROR;
      }                                /* if */

      COMMAND_COMPLETE = xilHostAppSvcGetIsResponseComplete(pXILService);
    }                                  /* while */

    /* determine command response type */
    *commandType = (XILCommandResponseType) COMMAND_COMPLETE;
    IOBuffer->nextMemUnit = (void*)IOBuffer->data;
    IOBuffer->bufferDataSize = xilHostAppSvcGetPayloadSizeForOneStep(pXILService);
    IOBuffer->readData = ((IOBuffer->bufferDataSize>0)?true:false);
    return XILHOSTAPPSVC_SUCCESS;
  }
}

void xilReadData(uint8_T *dst, size_t numElements, mem_unit_type_T dataTypeId)
{
  xilReadDataInternal(dst, numElements, dataTypeId, true, IOBufferPtr,
                      pMemUnitTransformer);
}

void xilWriteData(uint8_T *src, size_t numElements, mem_unit_type_T dataTypeId)
{
  xilWriteDataInternal(src, numElements, dataTypeId, true, IOBufferPtr,
                       pMemUnitTransformer, pXILService);
}

static void mdlInitializeSizes();
static void mdlSetupRuntimeResources();
static void mdlStart();
static void mdlCleanupRuntimeResources();
void xilInitializeHost(void (*cleanUpArg)(void))
{
  cleanUp = cleanUpArg;
  mdlInitializeSizes();
  mdlSetupRuntimeResources();
  mdlStart();
}

/* returns data needed by code instrumentation service */
static CodeInstrServiceData_T* codeInstrServiceData(uint8_T memUnitSizeBytes)
{
  CodeInstrServiceData_T* pCodeInstrServiceData = (CodeInstrServiceData_T*)
    mxCalloc(1, sizeof(CodeInstrServiceData_T));
  const char * simulinkBlockPath =
    "C:\\Sumpurn\\Project\\sEmbeddedCPU\\demo_simple_addition\\codegen\\lib\\simple_addition\\simple_addition";
  if (pCodeInstrServiceData == NULL) {
    mexErrMsgTxt(
                 "Error in allocating memory for code instrumentation data through mxCalloc.");
    return NULL;
  }                                    /* if */

  pCodeInstrServiceData->infoPath =
    "C:\\Sumpurn\\Project\\sEmbeddedCPU\\demo_simple_addition\\codegen\\lib\\simple_addition\\pil";
  pCodeInstrServiceData->blockPath = simulinkBlockPath;
  pCodeInstrServiceData->rootModel = "";
  pCodeInstrServiceData->memUnitSize = memUnitSizeBytes;
  pCodeInstrServiceData->isProfilingEnabled = true;
  pCodeInstrServiceData->inTheLoopType = 3;
  pCodeInstrServiceData->silPilInterfaceFcn =
    "@coder.connectivity.MATLABInterface.getSILPILInterface";
  return pCodeInstrServiceData;
}

static void callStopHookAndFreeSFcnMemory()
{
  closeAndFreeTargetIOFd();
  if ((pIsXILApplicationStarted != NULL) && (*pIsXILApplicationStarted == 1)) {
    {
      if (pXILUtils) {
        mxArray *rhs[3];
        const char * simulinkBlockPath =
          "C:\\Sumpurn\\Project\\sEmbeddedCPU\\demo_simple_addition\\codegen\\lib\\simple_addition\\simple_addition";
        rhs[ 0 ] = mxCreateString(
          "@coder.connectivity.MATLABInterface.getSILPILInterface");
        rhs[ 1 ] = mxCreateDoubleScalar( 3 );
        rhs[ 2 ] = mxCreateString(simulinkBlockPath);
        if (xilUtilsCallMATLAB(pXILUtils, 0, NULL, 3, rhs,
                               "rtw.pil.SILPILInterface.sfunctionPILStopHook")!=
            XIL_UTILS_SUCCESS) {
          xilThrowException(pXILUtils);
        }                              /* if */
      }                                /* if */
    }
  }                                    /* if */

  if (pIsXILApplicationStarted != NULL) {
    *pIsXILApplicationStarted = 0;
  }                                    /* if */

  if (rtIOStreamDataPtr != NULL) {
    {
      int errorStatus = rtIOStreamUnloadLib(&rtIOStreamDataPtr->libH);
      if (errorStatus) {
        mexErrMsgTxt( "rtIOStreamUnloadLib failed.");
      }                                /* if */
    }

    mxFree(rtIOStreamDataPtr->lib);
    mxDestroyArray(rtIOStreamDataPtr->MATLABObject);
    mxFree(rtIOStreamDataPtr);
    rtIOStreamDataPtr = NULL;
  }                                    /* if */

  if (silDebuggingDataPtr != NULL) {
    mxFree(silDebuggingDataPtr->componentBlockPath);
    mxFree(silDebuggingDataPtr->SILPILInterfaceFcnStr);
    mxFree(silDebuggingDataPtr);
    silDebuggingDataPtr = NULL;
  }                                    /* if */

  if (IOBufferPtr != NULL) {
    mxFree(IOBufferPtr->data);
    mxFree(IOBufferPtr);
    IOBufferPtr = NULL;
  }                                    /* if */

  closeAndFreeTargetIOFd();
  if (pCodeInstrService != NULL) {
    uint8_T memUnitSizeBytes = 1;
    CodeInstrServiceData_T* pCodeInstrServiceData = codeInstrServiceData
      (memUnitSizeBytes);
    codeInstrHostAppSvcDestroy(pCodeInstrService, pCodeInstrServiceData);
    mxFree(pCodeInstrServiceData);
  }                                    /* if */

  pCodeInstrService = NULL;
  if (pCoderAssumptionsApp != NULL) {
    coderAssumpHostAppSvcDestroy(pCoderAssumptionsApp);
    pCoderAssumptionsApp = NULL;
  }                                    /* if */

  if (pXILService != NULL) {
    xilHostAppSvcDestroy(pXILService);
    pXILService = NULL;
  }                                    /* if */

  if (pComms != NULL) {
    xilCommsDestroy(pComms);
    pComms = NULL;
  }                                    /* if */

  /* Reset firstTime flag to allow re-initialization */
  firstTime = 0;

  /* Reset pKeepUtilsActive flag */
  pKeepUtilsActive = 0;
}

static boolean_T processResponseError( )
{
  uint8_T errorId;
  xilReadDataInternal(&errorId, 1, MEM_UNIT_UINT8_TYPE, true, IOBufferPtr,
                      pMemUnitTransformer);
  if (errorId) {
    pKeepUtilsActive = 1;
    callStopHookAndFreeSFcnMemory();
    if (!executingClearMEX) {
      /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
      (*cleanUp)();
    }                                  /* if */

    {
      mxArray * rhs[ 2 ];
      rhs[0] = mxCreateString("PIL:pilverification:PILError");
      rhs[1] = mxCreateDoubleScalar(errorId);
      xilUtilsHandleError(pXILUtils, 2 , rhs );
      return XILHOSTAPPSVC_ERROR;
    }
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponsePrintf( )
{
  const int TARGET_IO_SUCCESS = 0;
  uint8_T PRINTF_ERROR;
  uint16_T PRINTF_SIZE;

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &PRINTF_ERROR;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT8_TYPE);
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &PRINTF_SIZE;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT16_TYPE);
        }
      }
    }
  }

  if (PRINTF_ERROR != TARGET_IO_SUCCESS) {
    pKeepUtilsActive = 1;
    callStopHookAndFreeSFcnMemory();
    if (!executingClearMEX) {
      /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
      (*cleanUp)();
    }                                  /* if */

    {
      mxArray * rhs[ 2 ];
      rhs[0] = mxCreateString("PIL:pil:TargetIOError");
      rhs[1] = mxCreateDoubleScalar(PRINTF_ERROR);
      xilUtilsHandleError(pXILUtils, 2 , rhs );
      return XILHOSTAPPSVC_ERROR;
    }
  } else {
    uint8_T *pPrintBuff;
    pPrintBuff = (uint8_T *) mxCalloc(PRINTF_SIZE, sizeof(uint8_T));
    if (pPrintBuff != NULL) {
      xilReadData(&(pPrintBuff[0]), PRINTF_SIZE, MEM_UNIT_UINT8_TYPE);
      if (pPrintBuff[PRINTF_SIZE-1] == '\0') {
        mexPrintf("%s", pPrintBuff);
      }                                /* if */

      mxFree(pPrintBuff);
    }                                  /* if */
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponseFopen( )
{
  uint16_T FOPEN_FID;
  uint16_T FOPEN_NAME_SIZE;

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FOPEN_FID;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT16_TYPE);
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FOPEN_NAME_SIZE;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT16_TYPE);
        }
      }
    }
  }

  if (targetIOFdPtr != NULL) {
    /* check fid increments by 1 */
    if (targetIOFdPtr->fidOffset + 1 == FOPEN_FID) {
      targetIOFdPtr->fidOffset = FOPEN_FID;
      growTargetIOFd(targetIOFdPtr, targetIOFdPtr->fidOffset + 1);
      if (targetIOFdPtr->Fd != NULL) {
        uint8_T *pFopenBuff;
        targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = NULL;
        pFopenBuff = (uint8_T *) mxCalloc(FOPEN_NAME_SIZE, sizeof(uint8_T));
        if (pFopenBuff != NULL) {
          xilReadData(&(pFopenBuff[0]), FOPEN_NAME_SIZE, MEM_UNIT_UINT8_TYPE);
          if (pFopenBuff[FOPEN_NAME_SIZE-1] == '\0') {
            FILE * tmpFd = NULL;
            tmpFd = fopen((char *) pFopenBuff,"w");
            if (tmpFd != NULL) {
              /* save the file descriptor */
              targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = tmpFd;
            } else {
              pKeepUtilsActive = 1;
              callStopHookAndFreeSFcnMemory();
              if (!executingClearMEX) {
                /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                (*cleanUp)();
              }                        /* if */

              {
                mxArray * rhs[ 2 ];
                rhs[0] = mxCreateString("PIL:pil:TargetIOFopenError");
                rhs[1] = mxCreateString((char *) pFopenBuff);
                xilUtilsHandleError(pXILUtils, 2 , rhs );
                return XILHOSTAPPSVC_ERROR;
              }
            }                          /* if */
          }                            /* if */

          mxFree(pFopenBuff);
        }                              /* if */
      }                                /* if */
    } else {
      pKeepUtilsActive = 1;
      callStopHookAndFreeSFcnMemory();
      if (!executingClearMEX) {
        /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
        (*cleanUp)();
      }                                /* if */

      {
        mxArray * rhs[ 2 ];
        rhs[0] = mxCreateString("PIL:pil:TargetIOFopenFidError");
        rhs[1] = mxCreateDoubleScalar(FOPEN_FID);
        xilUtilsHandleError(pXILUtils, 2 , rhs );
        return XILHOSTAPPSVC_ERROR;
      }
    }                                  /* if */
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponseFprintf( )
{
  const int TARGET_IO_SUCCESS = 0;
  uint8_T FPRINTF_ERROR;
  uint16_T FPRINTF_FID;
  uint16_T FPRINTF_SIZE;

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FPRINTF_ERROR;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT8_TYPE);
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FPRINTF_FID;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT16_TYPE);
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FPRINTF_SIZE;

      {
        size_t num_elements = 1;

        {
          xilReadData(simDataMemUnitPtr, num_elements, MEM_UNIT_UINT16_TYPE);
        }
      }
    }
  }

  if (FPRINTF_ERROR != TARGET_IO_SUCCESS) {
    pKeepUtilsActive = 1;
    callStopHookAndFreeSFcnMemory();
    if (!executingClearMEX) {
      /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
      (*cleanUp)();
    }                                  /* if */

    {
      mxArray * rhs[ 2 ];
      rhs[0] = mxCreateString("PIL:pil:TargetIOError");
      rhs[1] = mxCreateDoubleScalar(FPRINTF_ERROR);
      xilUtilsHandleError(pXILUtils, 2 , rhs );
      return XILHOSTAPPSVC_ERROR;
    }
  } else {
    if (targetIOFdPtr != NULL) {
      if (targetIOFdPtr->size > FPRINTF_FID) {
        if (targetIOFdPtr->Fd[FPRINTF_FID] != NULL) {
          uint8_T *pFprintfBuff;
          pFprintfBuff = (uint8_T *) mxCalloc(FPRINTF_SIZE, sizeof(uint8_T));
          if (pFprintfBuff != NULL) {
            xilReadData(&(pFprintfBuff[0]), FPRINTF_SIZE, MEM_UNIT_UINT8_TYPE);
            if (pFprintfBuff[FPRINTF_SIZE-1] == '\0') {
              fprintf(targetIOFdPtr->Fd[FPRINTF_FID], "%s", pFprintfBuff);
            }                          /* if */

            mxFree(pFprintfBuff);
          }                            /* if */
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponseSignalRaised( )
{
  const char *signalStr[5] = { "SIGFPE", "SIGILL", "SIGABRT", "SIGSEGV",
    "Unknown Signal" };

  uint8_T errorId;
  xilReadData(&errorId, 1, MEM_UNIT_UINT8_TYPE);
  pKeepUtilsActive = 1;
  callStopHookAndFreeSFcnMemory();
  if (!executingClearMEX) {
    /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
    (*cleanUp)();
  }                                    /* if */

  {
    mxArray * rhs[ 2 ];
    rhs[0] = mxCreateString("Connectivity:target:MATLABCoderCaughtTargetSignal");
    rhs[1] = mxCreateString(signalStr[errorId]);
    xilUtilsHandleError(pXILUtils, 2 , rhs );
    return XILHOSTAPPSVC_ERROR;
  }
}

static boolean_T processErrorAndTargetIOResponseCases( const int responseId)
{
  switch (responseId) {
   case RESPONSE_ERROR:
    {
      return processResponseError( );
    }

   case RESPONSE_PRINTF:
    {
      return processResponsePrintf( );
    }

   case RESPONSE_FOPEN:
    {
      return processResponseFopen( );
    }

   case RESPONSE_FPRINTF:
    {
      return processResponseFprintf( );
    }

   case RESPONSE_SIGNAL_RAISED:
    {
      return processResponseSignalRaised( );
    }

   default:
    {
      pKeepUtilsActive = 1;
      callStopHookAndFreeSFcnMemory();
      if (!executingClearMEX) {
        /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
        (*cleanUp)();
      }                                /* if */

      {
        mxArray * rhs[ 2 ];
        rhs[0] = mxCreateString("PIL:pilverification:UnknownResponseId");
        rhs[1] = mxCreateDoubleScalar(responseId);
        xilUtilsHandleError(pXILUtils, 2 , rhs );
        return XILHOSTAPPSVC_ERROR;
      }
    }
  }                                    /* switch */
}

static boolean_T startAndSetupApplication()
{
  {
    {
      mxArray *rhs[4];
      const char * simulinkBlockPath =
        "C:\\Sumpurn\\Project\\sEmbeddedCPU\\demo_simple_addition\\codegen\\lib\\simple_addition\\simple_addition";
      rhs[ 0 ] = mxCreateString(
        "@coder.connectivity.MATLABInterface.getSILPILInterface");
      rhs[ 1 ] = mxCreateDoubleScalar( 3 );
      rhs[ 2 ] = mxCreateString(simulinkBlockPath);
      rhs[3] = mxCreateString("uint8");

      {
        xilUtilsCallMATLAB(pXILUtils, 0, 0, 4, rhs,
                           "rtw.pil.SILPILInterface.sfunctionPILStartHook");
      }
    }

    {                                  /* record that the XIL application has started */
      *pIsXILApplicationStarted = 1;
    }
  }

  {
    mxArray *rhs[3];
    mxArray *lhs[5];
    const char * simulinkBlockPath =
      "C:\\Sumpurn\\Project\\sEmbeddedCPU\\demo_simple_addition\\codegen\\lib\\simple_addition\\simple_addition";
    rhs[ 0 ] = mxCreateString(
      "@coder.connectivity.MATLABInterface.getSILPILInterface");
    rhs[ 1 ] = mxCreateDoubleScalar( 3 );
    rhs[ 2 ] = mxCreateString(simulinkBlockPath);

    {
      xilUtilsCallMATLAB(pXILUtils, 5, lhs, 3, rhs,
                         "rtw.pil.SILPILInterface.sfunctionGetRtIOStreamInfoHook");
    }

    {
      rtIOStreamDataPtr = (XIL_RtIOStreamData_T*) mxCalloc(1, sizeof
        (XIL_RtIOStreamData_T));
      if (rtIOStreamDataPtr == NULL) {
        mexErrMsgTxt( "Error in allocating memory through mxCalloc.");
        return false;
      }                                /* if */

      rtIOStreamDataPtr->lib = mxArrayToString(lhs[0]);
      rtIOStreamDataPtr->MATLABObject = mxDuplicateArray(lhs[1]);
      mexMakeMemoryPersistent(rtIOStreamDataPtr);
      mexMakeMemoryPersistent(rtIOStreamDataPtr->lib);
      mexMakeArrayPersistent(rtIOStreamDataPtr->MATLABObject);
      rtIOStreamDataPtr->streamID = *mxGetPr(lhs[2]);
      rtIOStreamDataPtr->recvTimeout = *mxGetPr(lhs[3]);
      rtIOStreamDataPtr->sendTimeout = *mxGetPr(lhs[4]);
      rtIOStreamDataPtr->isRtIOStreamCCall = 1;
      rtIOStreamDataPtr->ioMxClassID = mxUINT8_CLASS;
      rtIOStreamDataPtr->ioDataSize = sizeof(uint8_T);
      rtIOStreamDataPtr->targetRecvBufferSizeBytes = 128;
      rtIOStreamDataPtr->targetSendBufferSizeBytes = 128;

      {
        int errorStatus = rtIOStreamLoadLib(&rtIOStreamDataPtr->libH,
          rtIOStreamDataPtr->lib);
        if (errorStatus) {
          mexErrMsgTxt( "rtIOStreamLoadLib failed.");
          return false;
        }                              /* if */
      }
    }

    {
      int i;
      for (i=0; i<5; i++) {
        mxDestroyArray(lhs[i]);
      }                                /* for */
    }
  }

  {
    IOBufferPtr = (XIL_IOBuffer_T *) mxCalloc(1, sizeof(XIL_IOBuffer_T));
    if (IOBufferPtr == NULL) {
      mexErrMsgTxt( "Error in allocating memory through mxCalloc.");
      return false;
    }                                  /* if */

    mexMakeMemoryPersistent(IOBufferPtr);
  }

  {
    const char * simulinkBlockPath =
      "C:\\Sumpurn\\Project\\sEmbeddedCPU\\demo_simple_addition\\codegen\\lib\\simple_addition\\simple_addition";
    silDebuggingDataPtr = (SIL_DEBUGGING_DATA_T*) mxCalloc(1, sizeof
      (SIL_DEBUGGING_DATA_T));
    if (silDebuggingDataPtr == NULL) {
      mexErrMsgTxt(
                   "Error in allocating memory through mxCalloc for SIL_DEBUGGING_DATA_T.");
      return false;
    }                                  /* if */

    silDebuggingDataPtr->componentBlockPath = strcpy((char *) mxCalloc(strlen
      (simulinkBlockPath)+1, sizeof(char)), simulinkBlockPath);
    silDebuggingDataPtr->SILPILInterfaceFcnStr = strcpy((char*) mxCalloc(55,
      sizeof(char)), "@coder.connectivity.MATLABInterface.getSILPILInterface");
    silDebuggingDataPtr->inTheLoopType = 3;
    mexMakeMemoryPersistent(silDebuggingDataPtr);
    mexMakeMemoryPersistent(silDebuggingDataPtr->componentBlockPath);
    mexMakeMemoryPersistent(silDebuggingDataPtr->SILPILInterfaceFcnStr);
  }

  {
    targetIOFdPtr = (targetIOFd_T *) mxCalloc(1, sizeof(targetIOFd_T));
    if (targetIOFdPtr == NULL) {
      return false;
    }                                  /* if */

    mexMakeMemoryPersistent(targetIOFdPtr);
    targetIOFdPtr->size = 0;
    targetIOFdPtr->Fd = NULL;
    targetIOFdPtr->fidOffset = -1;
  }

  {
    uint8_T memUnitSizeBytes = 1;
    uint8_T ioDataTypeSizeBytes = sizeof(uint8_T);
    CodeInstrServiceData_T* pCodeInstrServiceData = codeInstrServiceData
      (memUnitSizeBytes);
    if (xilCommsCreate(&pComms, rtIOStreamDataPtr, silDebuggingDataPtr,
                       memUnitSizeBytes, pMemUnitTransformer, pXILUtils) !=
        XILCOMMS_RTIOSTREAM_SUCCESS) {
      xilThrowException(pXILUtils);
      return false;
    }                                  /* if */

    if (xilHostAppSvcCreate(&pXILService, pComms, pXILUtils, IOBufferPtr,
                            memUnitSizeBytes, ioDataTypeSizeBytes, 0) !=
        XILHOSTAPPSVC_SUCCESS) {
      xilThrowException(pXILUtils);
      return false;
    }                                  /* if */

    {
      void * pCodeInstrMultiRunData = NULL;
      if (codeInstrHostAppSvcCreate(&pCodeInstrService, pCodeInstrServiceData,
           pComms, pMemUnitTransformer, 32, pXILUtils, memUnitSizeBytes, 0,
           pCodeInstrMultiRunData) != CODEINSTRHOSTAPPSVC_SUCCESS) {
        xilThrowException(pXILUtils);
        mxFree(pCodeInstrServiceData);
        return false;
      }                                /* if */

      mxFree(pCodeInstrServiceData);
    }

    {
      mxArray * codeGenComponent = mxCreateString("simple_addition");
      if (coderAssumpHostAppSvcCreate(&pCoderAssumptionsApp, pComms, pXILUtils,
           0, 1, codeGenComponent, 0, 0) != CODERASSUMPHOSTAPPSVC_SUCCESS) {
        xilThrowException(pXILUtils);
        return false;
      }                                /* if */
    }

    xilCommsRegisterApplication(pComms, pXILService);
    xilCommsRegisterApplication(pComms, pCodeInstrService);
    xilCommsRegisterApplication(pComms, pCoderAssumptionsApp);
  }

  {
    if (IOBufferPtr != NULL) {
      if (pXILService != NULL) {
        if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
            XILHOSTAPPSVC_SUCCESS) {
          xilThrowException(pXILUtils);
          return false;
        }                              /* if */

        IOBufferPtr->bufferDataSize = 0;
        if (IOBufferPtr->data != NULL) {
          /* write command id */
          {
            uint8_T commandDataArg = (uint8_T) XIL_INIT_COMMAND;
            xilWriteDataInternal(&commandDataArg, 1, MEM_UNIT_UINT8_TYPE, true,
                                 IOBufferPtr, pMemUnitTransformer, pXILService);
          }

          {
            {
              uint8_T * simDataMemUnitPtr;
              uint32_T commandDataFcnid = 0;
              simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

              {
                size_t num_elements = 1;

                {
                  xilWriteData(simDataMemUnitPtr, num_elements,
                               MEM_UNIT_UINT32_TYPE);
                }
              }
            }
          }
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }

  {
    {
      /* provide the time information to the code instrumentation service */
      {
        codeInstrHostAppSvcSetTime(pCodeInstrService, simTime);
      }

      /* dispatch command to the target */
      if (commandDispatch(IOBufferPtr, IOBufferPtr->bufferDataSize)!=
          XILHOSTAPPSVC_SUCCESS) {
        return false;
      }                                /* if */

      {
        XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
        while (commandResponseType != XIL_STEP_COMPLETE) {
          /* receive command from the target */
          if (commandResponse(IOBufferPtr, &commandResponseType) !=
              XILHOSTAPPSVC_SUCCESS) {
            return false;
          }                            /* if */

          if (IOBufferPtr->readData) {
            uint8_T responseId = 0;

#define RESPONSE_TYPE_SIZE             6

            while (IOBufferPtr->readData) {
              /* read response id */
              xilReadDataInternal(&responseId, 1, MEM_UNIT_UINT8_TYPE, true,
                                  IOBufferPtr, pMemUnitTransformer);
              switch (responseId) {
               case RESPONSE_ERROR:
               case RESPONSE_PRINTF:
               case RESPONSE_FOPEN:
               case RESPONSE_FPRINTF:
               case RESPONSE_SIGNAL_RAISED:
                {
                  if (processErrorAndTargetIOResponseCases( responseId)==
                      XILHOSTAPPSVC_ERROR) {
                    return false;
                  }                    /* if */
                  break;
                }

               case RESPONSE_OUTPUT_DATA:
                {
                  return false;
                  break;
                }

               case RESPONSE_TYPE_SIZE:
                {
                  uint8_T typeBytes;
                  uint8_T typeId;
                  xilReadDataInternal(&typeId, 1, MEM_UNIT_UINT8_TYPE, true,
                                      IOBufferPtr, pMemUnitTransformer);
                  xilReadDataInternal(&typeBytes, 1, MEM_UNIT_UINT8_TYPE, true,
                                      IOBufferPtr, pMemUnitTransformer);
                  switch (typeId) {
                   case mxSINGLE_CLASS:
                    {
                      if (typeBytes != 4) {
                        pKeepUtilsActive = 1;
                        callStopHookAndFreeSFcnMemory();
                        if (!executingClearMEX) {
                          /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                          (*cleanUp)();
                        }              /* if */

                        {
                          mxArray * rhs[ 3 ];
                          rhs[0] = mxCreateString(
                            "PIL:pilverification:SingleUnsupported");
                          rhs[1] = mxCreateDoubleScalar(4);
                          rhs[2] = mxCreateDoubleScalar(typeBytes);
                          xilUtilsHandleError(pXILUtils, 3 , rhs );
                          return false;
                        }
                      }                /* if */
                      break;
                    }

                   case mxDOUBLE_CLASS:
                    {
                      if (typeBytes != 8) {
                        pKeepUtilsActive = 1;
                        callStopHookAndFreeSFcnMemory();
                        if (!executingClearMEX) {
                          /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                          (*cleanUp)();
                        }              /* if */

                        {
                          mxArray * rhs[ 3 ];
                          rhs[0] = mxCreateString(
                            "PIL:pilverification:DoubleUnsupported");
                          rhs[1] = mxCreateDoubleScalar(8);
                          rhs[2] = mxCreateDoubleScalar(typeBytes);
                          xilUtilsHandleError(pXILUtils, 3 , rhs );
                          return false;
                        }
                      }                /* if */
                      break;
                    }

                   default:
                    {
                      pKeepUtilsActive = 1;
                      callStopHookAndFreeSFcnMemory();
                      if (!executingClearMEX) {
                        /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                        (*cleanUp)();
                      }                /* if */

                      {
                        mxArray * rhs[ 2 ];
                        rhs[0] = mxCreateString(
                          "PIL:pilverification:UnknownTypeId");
                        rhs[1] = mxCreateDoubleScalar(typeId);
                        xilUtilsHandleError(pXILUtils, 2 , rhs );
                        return false;
                      }
                      break;
                    }
                  }                    /* switch */
                  break;
                }

               default:
                {
                  pKeepUtilsActive = 1;
                  callStopHookAndFreeSFcnMemory();
                  if (!executingClearMEX) {
                    /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                    (*cleanUp)();
                  }                    /* if */

                  {
                    mxArray * rhs[ 2 ];
                    rhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    rhs[1] = mxCreateDoubleScalar(responseId);
                    xilUtilsHandleError(pXILUtils, 2 , rhs );
                    return false;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* while */
      }
    }
  }

  return true;
}

static void sendInitializeCommand()
{
  {
    if (IOBufferPtr != NULL) {
      if (pXILService != NULL) {
        if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
            XILHOSTAPPSVC_SUCCESS) {
          xilThrowException(pXILUtils);
          return;
        }                              /* if */

        IOBufferPtr->bufferDataSize = 0;
        if (IOBufferPtr->data != NULL) {
          /* write command id */
          {
            uint8_T commandDataArg = (uint8_T) XIL_INITIALIZE_COMMAND;
            xilWriteDataInternal(&commandDataArg, 1, MEM_UNIT_UINT8_TYPE, true,
                                 IOBufferPtr, pMemUnitTransformer, pXILService);
          }

          {
            {
              uint8_T * simDataMemUnitPtr;
              uint32_T commandDataFcnid = 0;
              simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

              {
                size_t num_elements = 1;

                {
                  xilWriteData(simDataMemUnitPtr, num_elements,
                               MEM_UNIT_UINT32_TYPE);
                }
              }
            }
          }
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }

  {
    {
      /* provide the time information to the code instrumentation service */
      {
        codeInstrHostAppSvcSetTime(pCodeInstrService, simTime);
      }

      /* dispatch command to the target */
      if (commandDispatch(IOBufferPtr, IOBufferPtr->bufferDataSize)!=
          XILHOSTAPPSVC_SUCCESS) {
        return;
      }                                /* if */

      {
        XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
        while (commandResponseType != XIL_STEP_COMPLETE) {
          /* receive command from the target */
          if (commandResponse(IOBufferPtr, &commandResponseType) !=
              XILHOSTAPPSVC_SUCCESS) {
            return;
          }                            /* if */

          if (IOBufferPtr->readData) {
            uint8_T responseId = 0;
            while (IOBufferPtr->readData) {
              /* read response id */
              xilReadDataInternal(&responseId, 1, MEM_UNIT_UINT8_TYPE, true,
                                  IOBufferPtr, pMemUnitTransformer);
              switch (responseId) {
               case RESPONSE_ERROR:
               case RESPONSE_PRINTF:
               case RESPONSE_FOPEN:
               case RESPONSE_FPRINTF:
               case RESPONSE_SIGNAL_RAISED:
                {
                  if (processErrorAndTargetIOResponseCases( responseId)==
                      XILHOSTAPPSVC_ERROR) {
                    return;
                  }                    /* if */
                  break;
                }

               case RESPONSE_OUTPUT_DATA:
                {
                  return;
                  break;
                }

               default:
                {
                  pKeepUtilsActive = 1;
                  callStopHookAndFreeSFcnMemory();
                  if (!executingClearMEX) {
                    /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                    (*cleanUp)();
                  }                    /* if */

                  {
                    mxArray * rhs[ 2 ];
                    rhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    rhs[1] = mxCreateDoubleScalar(responseId);
                    xilUtilsHandleError(pXILUtils, 2 , rhs );
                    return;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* while */
      }
    }
  }
}

static void mdlInitializeSizes()
{
  {
    mxArray * lhs[1];
    mxArray * error = NULL;
    char * installVersion;
    error = mexCallMATLABWithTrap(1, lhs, 0, NULL, "rtw.pil.getPILVersion");
    if (error != NULL) {
      mxDestroyArray(error);
      mexErrMsgTxt(
                   "Failed to determine the installed In-the-Loop version for comparison against the In-the-Loop s-function version (release 6.13 (R2017b)_12). To avoid this error, remove the In-the-Loop s-function from your MATLAB path (e.g. delete it or move to a clean working directory).");
      return;
    }                                  /* if */

    if (mxIsEmpty(lhs[0])) {
      mexErrMsgTxt( "rtw.pil.getPILVersion returned empty!");
      return;
    }                                  /* if */

    installVersion = mxArrayToString(lhs[0]);
    mxDestroyArray(lhs[0]);
    if (installVersion == NULL) {
      mexErrMsgTxt( "Failed to determine installed In-the-Loop version.");
      return;
    }                                  /* if */

    if (strcmp(installVersion, "6.13 (R2017b)_12") != 0) {
      mexErrMsgTxt(
                   "The In-the-Loop s-function is incompatible with the installed In-the-Loop version (see ver('ecoder')); it was generated for release 6.13 (R2017b)_12. To avoid this error, remove the In-the-Loop s-function from your MATLAB path (e.g. delete it or move to a clean working directory)");
      return;
    }                                  /* if */

    mxFree(installVersion);
  }
}

#define MDL_SETUP_RUNTIME_RESOURCES                              /* Change to #undef to remove function */
#if defined(MDL_SETUP_RUNTIME_RESOURCES)

static void mdlSetupRuntimeResources()
{
  {
    int retValXILUtils = XIL_UTILS_SUCCESS;
    if (pXILUtils == NULL) {
      retValXILUtils = xilMATLABUtilsCreate(&pXILUtils);
    }                                  /* if */

    if (retValXILUtils!=XIL_UTILS_SUCCESS) {
      mexErrMsgTxt( "Error instantiating XIL Utils!");
      return;
    }                                  /* if */
  }

  {
    pCommErrorOccurred = (int *) mxCalloc(1, sizeof(int));
    if (pCommErrorOccurred == NULL) {
      mexErrMsgTxt(
                   "Error in allocating memory for pCommErrorOccurred through mxCalloc.");
      return;
    }                                  /* if */

    *pCommErrorOccurred = 0;
    mexMakeMemoryPersistent(pCommErrorOccurred);
  }

  {
    pIsXILApplicationStarted = (int *) mxCalloc(1, sizeof(int));
    if (pIsXILApplicationStarted == NULL) {
      mexErrMsgTxt(
                   "Error in allocating memory for pIsXILApplicationStarted through mxCalloc.");
      return;
    }                                  /* if */

    *pIsXILApplicationStarted = 0;
    mexMakeMemoryPersistent(pIsXILApplicationStarted);
  }

  {
  }
}

#endif                                 /* MDL_SETUP_RUNTIME_RESOURCES */

#define MDL_START                                                /* Change to #undef to remove function */
#if defined(MDL_START)

static void mdlStart()
{
  {
    int *pIsXILApplicationStartedLocal = pIsXILApplicationStarted;
    if (pIsXILApplicationStartedLocal != NULL && (*pIsXILApplicationStartedLocal)
        != 0) {
      mexErrMsgTxt(
                   "Failed to start the application: another instance is already running.");
      return ;
    }                                  /* if */
  }

  {
    boolean_T applicationStarted = startAndSetupApplication();
    if (!applicationStarted) {
      return;
    }                                  /* if */
  }

  sendInitializeCommand();
}

#endif                                 /* MDL_START */

void xilPreEntryPointHost(uint32_T taskID)
{
  if (IOBufferPtr != NULL) {
    if (pXILService != NULL) {
      if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 9, 0)!=
          XILHOSTAPPSVC_SUCCESS) {
        xilThrowException(pXILUtils);
        return;
      }                                /* if */

      IOBufferPtr->bufferDataSize = 0;
      if (IOBufferPtr->data != NULL) {
        /* write command id */
        {
          uint8_T commandDataArg = (uint8_T) XIL_OUTPUT_COMMAND;
          xilWriteDataInternal(&commandDataArg, 1, MEM_UNIT_UINT8_TYPE, true,
                               IOBufferPtr, pMemUnitTransformer, pXILService);
        }

        {
          {
            uint8_T * simDataMemUnitPtr;
            uint32_T commandDataFcnidTID[2] = { 0, 0 };

            commandDataFcnidTID[1] = taskID;
            simDataMemUnitPtr = (uint8_T *) &commandDataFcnidTID[0];

            {
              size_t num_elements = 2;

              {
                xilWriteData(simDataMemUnitPtr, num_elements,
                             MEM_UNIT_UINT32_TYPE);
              }
            }
          }
        }
      }                                /* if */
    }                                  /* if */
  }                                    /* if */
}

void xilEntryPointHost(uint32_T taskID)
{
  {
    /* provide the time information to the code instrumentation service */
    {
      codeInstrHostAppSvcSetTime(pCodeInstrService, simTime++);
    }

    /* dispatch command to the target */
    if (commandDispatch(IOBufferPtr, IOBufferPtr->bufferDataSize)!=
        XILHOSTAPPSVC_SUCCESS) {
      return;
    }                                  /* if */

    {
      XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
      while (commandResponseType != XIL_STEP_COMPLETE) {
        /* receive command from the target */
        if (commandResponse(IOBufferPtr, &commandResponseType) !=
            XILHOSTAPPSVC_SUCCESS) {
          return;
        }                              /* if */

        if (IOBufferPtr->readData) {
          uint8_T responseId = 0;
          while (IOBufferPtr->readData) {
            /* read response id */
            xilReadDataInternal(&responseId, 1, MEM_UNIT_UINT8_TYPE, true,
                                IOBufferPtr, pMemUnitTransformer);
            switch (responseId) {
             case RESPONSE_ERROR:
             case RESPONSE_PRINTF:
             case RESPONSE_FOPEN:
             case RESPONSE_FPRINTF:
             case RESPONSE_SIGNAL_RAISED:
              {
                if (processErrorAndTargetIOResponseCases( responseId)==
                    XILHOSTAPPSVC_ERROR) {
                  return;
                }                      /* if */
                break;
              }

             case RESPONSE_OUTPUT_DATA:
              {
                return;
                break;
              }

             default:
              {
                pKeepUtilsActive = 1;
                callStopHookAndFreeSFcnMemory();
                if (!executingClearMEX) {
                  /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                  (*cleanUp)();
                }                      /* if */

                {
                  mxArray * rhs[ 2 ];
                  rhs[0] = mxCreateString(
                    "PIL:pilverification:UnknownResponseId");
                  rhs[1] = mxCreateDoubleScalar(responseId);
                  xilUtilsHandleError(pXILUtils, 2 , rhs );
                  return;
                }
                break;
              }
            }                          /* switch */
          }                            /* while */
        }                              /* if */
      }                                /* while */
    }
  }
}

void xilPostEntryPointHost(uint32_T taskID)
{
  if (IOBufferPtr->readData) {
    uint8_T responseId = 0;
    while (IOBufferPtr->readData) {
      /* read response id */
      xilReadDataInternal(&responseId, 1, MEM_UNIT_UINT8_TYPE, true, IOBufferPtr,
                          pMemUnitTransformer);
      switch (responseId) {
       case RESPONSE_ERROR:
       case RESPONSE_PRINTF:
       case RESPONSE_FOPEN:
       case RESPONSE_FPRINTF:
       case RESPONSE_SIGNAL_RAISED:
        {
          if (processErrorAndTargetIOResponseCases( responseId)==
              XILHOSTAPPSVC_ERROR) {
            return;
          }                            /* if */
          break;
        }

       default:
        {
          pKeepUtilsActive = 1;
          callStopHookAndFreeSFcnMemory();
          if (!executingClearMEX) {
            /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
            (*cleanUp)();
          }                            /* if */

          {
            mxArray * rhs[ 2 ];
            rhs[0] = mxCreateString("PIL:pilverification:UnknownResponseId");
            rhs[1] = mxCreateDoubleScalar(responseId);
            xilUtilsHandleError(pXILUtils, 2 , rhs );
            return;
          }
          break;
        }
      }                                /* switch */
    }                                  /* while */
  }                                    /* if */
}

void simple_addition_xil_terminate()
{
  int commErrorOccurred = 0;
  int isXILApplicationStarted = 0;

  /* MEX function is being cleared */
  executingClearMEX = 1;

  {
    if (pCommErrorOccurred != NULL) {
      commErrorOccurred = *pCommErrorOccurred;
    }                                  /* if */

    if (pIsXILApplicationStarted != NULL) {
      isXILApplicationStarted = *pIsXILApplicationStarted;
    }                                  /* if */
  }

  if (isXILApplicationStarted) {
    if (!commErrorOccurred) {
      {
        if (IOBufferPtr != NULL) {
          if (pXILService != NULL) {
            if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
                XILHOSTAPPSVC_SUCCESS) {
              xilThrowException(pXILUtils);
              callStopHookAndFreeSFcnMemory();
              return;
            }                          /* if */

            IOBufferPtr->bufferDataSize = 0;
            if (IOBufferPtr->data != NULL) {
              /* write command id */
              {
                uint8_T commandDataArg = (uint8_T) XIL_TERMINATE_COMMAND;
                xilWriteDataInternal(&commandDataArg, 1, MEM_UNIT_UINT8_TYPE,
                                     true, IOBufferPtr, pMemUnitTransformer,
                                     pXILService);
              }

              {
                {
                  uint8_T * simDataMemUnitPtr;
                  uint32_T commandDataFcnid = 0;
                  simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

                  {
                    size_t num_elements = 1;

                    {
                      xilWriteData(simDataMemUnitPtr, num_elements,
                                   MEM_UNIT_UINT32_TYPE);
                    }
                  }
                }
              }
            }                          /* if */
          }                            /* if */
        }                              /* if */
      }

      {
        {
          /* provide the time information to the code instrumentation service */
          {
            codeInstrHostAppSvcSetTime(pCodeInstrService, --simTime);
          }

          /* dispatch command to the target */
          if (commandDispatch(IOBufferPtr, IOBufferPtr->bufferDataSize)!=
              XILHOSTAPPSVC_SUCCESS) {
            callStopHookAndFreeSFcnMemory();
            return;
          }                            /* if */

          {
            XILCommandResponseType commandResponseType =
              XIL_COMMAND_NOT_COMPLETE;
            while (commandResponseType != XIL_STEP_COMPLETE) {
              /* receive command from the target */
              if (commandResponse(IOBufferPtr, &commandResponseType) !=
                  XILHOSTAPPSVC_SUCCESS) {
                callStopHookAndFreeSFcnMemory();
                return;
              }                        /* if */

              if (IOBufferPtr->readData) {
                uint8_T responseId = 0;
                while (IOBufferPtr->readData) {
                  /* read response id */
                  xilReadDataInternal(&responseId, 1, MEM_UNIT_UINT8_TYPE, true,
                                      IOBufferPtr, pMemUnitTransformer);
                  switch (responseId) {
                   case RESPONSE_ERROR:
                   case RESPONSE_PRINTF:
                   case RESPONSE_FOPEN:
                   case RESPONSE_FPRINTF:
                   case RESPONSE_SIGNAL_RAISED:
                    {
                      if (processErrorAndTargetIOResponseCases( responseId)==
                          XILHOSTAPPSVC_ERROR) {
                        callStopHookAndFreeSFcnMemory();
                        return;
                      }                /* if */
                      break;
                    }

                   case RESPONSE_OUTPUT_DATA:
                    {
                      callStopHookAndFreeSFcnMemory();
                      return;
                      break;
                    }

                   default:
                    {
                      pKeepUtilsActive = 1;
                      callStopHookAndFreeSFcnMemory();
                      if (!executingClearMEX) {
                        /* About to throw an error, call MEX API terminate function, unless MEX is clearing */
                        (*cleanUp)();
                      }                /* if */

                      {
                        mxArray * rhs[ 2 ];
                        rhs[0] = mxCreateString(
                          "PIL:pilverification:UnknownResponseId");
                        rhs[1] = mxCreateDoubleScalar(responseId);
                        xilUtilsHandleError(pXILUtils, 2 , rhs );
                        callStopHookAndFreeSFcnMemory();
                        return;
                      }
                      break;
                    }
                  }                    /* switch */
                }                      /* while */
              }                        /* if */
            }                          /* while */
          }
        }
      }

      {
        if (IOBufferPtr != NULL) {
          if (pXILService != NULL) {
            if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 1, 0)!=
                XILHOSTAPPSVC_SUCCESS) {
              xilThrowException(pXILUtils);
              callStopHookAndFreeSFcnMemory();
              return;
            }                          /* if */

            IOBufferPtr->bufferDataSize = 0;
            if (IOBufferPtr->data != NULL) {
              /* write command id */
              {
                uint8_T commandDataArg = (uint8_T) XIL_SHUTDOWN_COMMAND;
                xilWriteDataInternal(&commandDataArg, 1, MEM_UNIT_UINT8_TYPE,
                                     true, IOBufferPtr, pMemUnitTransformer,
                                     pXILService);
              }
            }                          /* if */
          }                            /* if */
        }                              /* if */
      }

      {
        {
          /* provide the time information to the code instrumentation service */
          {
            codeInstrHostAppSvcSetTime(pCodeInstrService, simTime);
          }

          /* dispatch command to the target */
          if (commandDispatch(IOBufferPtr, IOBufferPtr->bufferDataSize)!=
              XILHOSTAPPSVC_SUCCESS) {
            callStopHookAndFreeSFcnMemory();
            return;
          }                            /* if */
        }
      }
    }                                  /* if */
  }                                    /* if */

  callStopHookAndFreeSFcnMemory();
  mdlCleanupRuntimeResources();
}

#define MDL_CLEANUP_RUNTIME_RESOURCES                            /* Change to #undef to remove function */
#if defined(MDL_CLEANUP_RUNTIME_RESOURCES)

static void mdlCleanupRuntimeResources()
{
  {
    if (pIsXILApplicationStarted != NULL) {
      if (pKeepUtilsActive == 0) {
        mxFree(pIsXILApplicationStarted);
        pIsXILApplicationStarted = NULL;
      }                                /* if */
    }                                  /* if */

    if (pCommErrorOccurred != NULL) {
      mxFree(pCommErrorOccurred);
      pCommErrorOccurred = NULL;
    }                                  /* if */
  }

  if (pKeepUtilsActive != 1) {
    if (pXILUtils != NULL) {
      xilUtilsDestroy(pXILUtils);
      pXILUtils = NULL;
    }                                  /* if */
  }                                    /* if */
}

#endif                                 /* MDL_CLEANUP_RUNTIME_RESOURCES */
