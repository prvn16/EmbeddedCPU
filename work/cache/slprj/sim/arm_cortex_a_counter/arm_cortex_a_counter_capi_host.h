#include "__cf_arm_cortex_a_counter.h"
#ifndef RTW_HEADER_arm_cortex_a_counter_cap_host_h_
#define RTW_HEADER_arm_cortex_a_counter_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
arm_cortex_a_counter_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void arm_cortex_a_counter_host_InitializeDataMapInfo (
arm_cortex_a_counter_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
