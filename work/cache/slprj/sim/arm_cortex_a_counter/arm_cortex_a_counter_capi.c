#include "__cf_arm_cortex_a_counter.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "arm_cortex_a_counter_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "arm_cortex_a_counter.h"
#include "arm_cortex_a_counter_capi.h"
#include "arm_cortex_a_counter_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, TARGET_STRING ( "arm_cortex_a_counter/Previous Output" ) , TARGET_STRING (
"" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 0 , - 1 , ( NULL ) , ( NULL
) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void arm_cortex_a_counter_InitializeDataAddr ( void * dataAddr [ ] ,
ie4qubhdwq * localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW ->
b5aieudxfw ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void arm_cortex_a_counter_InitializeVarDimsAddr ( int32_T *
vardimsAddr [ ] ) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 }
} ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 1 , 1
} ; static const real_T rtcapiStoredFloats [ ] = { 0.2 , 0.0 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } } ; static int_T
rtContextSystems [ 2 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] =
{ { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 2 , rtContextSystems , loggingMetaInfo , 0 , NULL ,
{ 0 , NULL , NULL } , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockStates , 1 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 2527674964U , 1863036740U , 3879346710U ,
4260106318U } , & mmiStaticInfoLogging , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * arm_cortex_a_counter_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void arm_cortex_a_counter_InitializeSystemRan ( cnqf2i2olu * const
ppw5xgjxps , sysRanDType * systemRan [ ] , ie4qubhdwq * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER (
ppw5xgjxps ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemTid [ 1 ] = rootTid ;
systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1
] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void arm_cortex_a_counter_InitializeDataMapInfo ( cnqf2i2olu * const
ppw5xgjxps , ie4qubhdwq * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( ppw5xgjxps -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ppw5xgjxps -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ppw5xgjxps -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; arm_cortex_a_counter_InitializeDataAddr ( ppw5xgjxps
-> DataMapInfo . dataAddress , localDW ) ; rtwCAPI_SetDataAddressMap (
ppw5xgjxps -> DataMapInfo . mmi , ppw5xgjxps -> DataMapInfo . dataAddress ) ;
arm_cortex_a_counter_InitializeVarDimsAddr ( ppw5xgjxps -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( ppw5xgjxps -> DataMapInfo .
mmi , ppw5xgjxps -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath (
ppw5xgjxps -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath (
ppw5xgjxps -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetInstanceLoggingInfo
( ppw5xgjxps -> DataMapInfo . mmi , & ppw5xgjxps -> DataMapInfo .
mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( ppw5xgjxps -> DataMapInfo .
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ppw5xgjxps -> DataMapInfo .
mmi , 0 ) ; arm_cortex_a_counter_InitializeSystemRan ( ppw5xgjxps ,
ppw5xgjxps -> DataMapInfo . systemRan , localDW , ppw5xgjxps -> DataMapInfo .
systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( ppw5xgjxps ->
DataMapInfo . mmi , ppw5xgjxps -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( ppw5xgjxps -> DataMapInfo . mmi , ppw5xgjxps ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( ppw5xgjxps ->
DataMapInfo . mmi , & ppw5xgjxps -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void arm_cortex_a_counter_host_InitializeDataMapInfo (
arm_cortex_a_counter_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
