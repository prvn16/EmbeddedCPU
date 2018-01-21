#include "__cf_arm_cortex_a_counter.h"
#ifndef RTW_HEADER_arm_cortex_a_counter_h_
#define RTW_HEADER_arm_cortex_a_counter_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef arm_cortex_a_counter_COMMON_INCLUDES_
#define arm_cortex_a_counter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "arm_cortex_a_counter_types.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
typedef struct { uint8_T b5aieudxfw ; } ie4qubhdwq ; struct i2z1nhgs02i_ {
uint8_T P_1 ; } ; struct fhykojq0lr { struct SimStruct_tag * _mdlRefSfcnS ;
struct { rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 1 ] ; int32_T * vardimsAddress [ 1
] ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ;
struct { int_T mdlref_GlobalTID [ 2 ] ; } Timing ; } ; typedef struct {
ie4qubhdwq rtdw ; cnqf2i2olu rtm ; } ook1zpy4mwv ; extern uint8_T
rtP_Increment ; extern void idg3ieb4jm ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , int_T mdlref_TID1 , cnqf2i2olu * const ppw5xgjxps , ie4qubhdwq
* localDW , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_arm_cortex_a_counter_MdlInfoRegFcn (
SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern
mxArray * mr_arm_cortex_a_counter_GetDWork ( const ook1zpy4mwv * mdlrefDW ) ;
extern void mr_arm_cortex_a_counter_SetDWork ( ook1zpy4mwv * mdlrefDW , const
mxArray * ssDW ) ; extern void
mr_arm_cortex_a_counter_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_arm_cortex_a_counter_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * arm_cortex_a_counter_GetCAPIStaticMap
( void ) ; extern void ayfhzrsk12 ( ie4qubhdwq * localDW ) ; extern void
ggymz5tofv ( ie4qubhdwq * localDW ) ; extern void f0giliidwt ( uint8_T *
bisxx2u4hy , ie4qubhdwq * localDW ) ; extern void f0giliidwtTID1 ( void ) ;
extern void arm_cortex_a_counter ( const boolean_T * nizo3ahhbg , const
boolean_T * guxeap50sc , uint8_T * bisxx2u4hy , ie4qubhdwq * localDW ,
uint8_T rtp_myLower , uint8_T rtp_myUpper ) ; extern void
arm_cortex_a_counterTID1 ( void ) ; extern void ltrjgjnnxt ( cnqf2i2olu *
const ppw5xgjxps ) ;
#endif
