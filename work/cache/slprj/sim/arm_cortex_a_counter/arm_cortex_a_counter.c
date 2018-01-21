#include "__cf_arm_cortex_a_counter.h"
#include "arm_cortex_a_counter_capi.h"
#include "arm_cortex_a_counter.h"
#include "arm_cortex_a_counter_private.h"
static RegMdlInfo rtMdlInfo_arm_cortex_a_counter [ 48 ] = { { "ook1zpy4mwv" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "monq2ysjzs" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "d4ccowkg5h" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "gub2m5dxrk" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "or431ytzkb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "i2bwx0tksj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "nzvevvzkmy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "apknpn1nyd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "hsjr1ubieg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "kkcf2m3nxj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "ie4qubhdwq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "eh1vcbiwds" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "bw3c2maqrj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "ltrjgjnnxt" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "peqipiosn4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "f0giliidwt" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "ggymz5tofv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "ayfhzrsk12" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "idg3ieb4jm" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "ogcjy0ejl1" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "gvjexzpmrk" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "arm_cortex_a_counter" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "g4r2uvlaxy2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "lqjz1jjfadt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "pdidv4c35re" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "fakt2co0wwy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "il5ltnywbhs" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "g4r2uvlaxy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "lqjz1jjfad" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "pdidv4c35r" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "fakt2co0ww" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "fhykojq0lr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT
, 0 , - 1 , ( void * ) "arm_cortex_a_counter" } , { "cnqf2i2olu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } , { "SilCounterBus" , MDL_INFO_ID_DATA_TYPE , 0 , -
1 , ( NULL ) } , { "mr_arm_cortex_a_counter_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_cacheBitFieldToMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "arm_cortex_a_counter" } , {
"mr_arm_cortex_a_counter_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "mr_arm_cortex_a_counter_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 ,
( void * ) "arm_cortex_a_counter" } , { "mr_arm_cortex_a_counter_GetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "arm_cortex_a_counter" } ,
{ "arm_cortex_a_counter.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } ,
{ "arm_cortex_a_counter.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * )
"arm_cortex_a_counter" } } ; i2z1nhgs02i i2z1nhgs02 = { 50U } ; void
ayfhzrsk12 ( ie4qubhdwq * localDW ) { localDW -> b5aieudxfw = i2z1nhgs02 .
P_1 ; } void ggymz5tofv ( ie4qubhdwq * localDW ) { localDW -> b5aieudxfw =
i2z1nhgs02 . P_1 ; } void arm_cortex_a_counter ( const boolean_T * nizo3ahhbg
, const boolean_T * guxeap50sc , uint8_T * bisxx2u4hy , ie4qubhdwq * localDW
, uint8_T rtp_myLower , uint8_T rtp_myUpper ) { uint8_T bd2wpmlfht ; if ( *
guxeap50sc ) { bd2wpmlfht = rtp_myLower ; } else { bd2wpmlfht = localDW ->
b5aieudxfw ; } bd2wpmlfht = ( uint8_T ) ( ( uint32_T ) ( * nizo3ahhbg ? (
int32_T ) rtP_Increment : 0 ) + bd2wpmlfht ) ; if ( rtp_myUpper >= bd2wpmlfht
) { * bisxx2u4hy = bd2wpmlfht ; } else { * bisxx2u4hy = rtp_myLower ; } }
void arm_cortex_a_counterTID1 ( void ) { } void f0giliidwt ( uint8_T *
bisxx2u4hy , ie4qubhdwq * localDW ) { localDW -> b5aieudxfw = * bisxx2u4hy ;
} void f0giliidwtTID1 ( void ) { } void ltrjgjnnxt ( cnqf2i2olu * const
ppw5xgjxps ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( ppw5xgjxps -> _mdlRefSfcnS , "arm_cortex_a_counter" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void idg3ieb4jm (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , cnqf2i2olu
* const ppw5xgjxps , ie4qubhdwq * localDW , void * sysRanPtr , int contextTid
, rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath ,
int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( void ) memset ( ( void * ) ppw5xgjxps , 0 , sizeof (
cnqf2i2olu ) ) ; ppw5xgjxps -> Timing . mdlref_GlobalTID [ 0 ] = mdlref_TID0
; ppw5xgjxps -> Timing . mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; ppw5xgjxps ->
_mdlRefSfcnS = ( _mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) )
{ slmrRunPluginEvent ( ppw5xgjxps -> _mdlRefSfcnS , "arm_cortex_a_counter" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } ( void ) memset ( ( void * )
localDW , 0 , sizeof ( ie4qubhdwq ) ) ;
arm_cortex_a_counter_InitializeDataMapInfo ( ppw5xgjxps , localDW , sysRanPtr
, contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != (
NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
ppw5xgjxps -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( ppw5xgjxps ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
ppw5xgjxps -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void
mr_arm_cortex_a_counter_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo
= false ; ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ;
if ( regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo (
mdlRefSfcnS , modelName , rtMdlInfo_arm_cortex_a_counter , 48 ) ; * retVal =
1 ; } static void mr_arm_cortex_a_counter_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_arm_cortex_a_counter_cacheDataAsMxArray ( mxArray * destArray
, mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_arm_cortex_a_counter_restoreDataFromMxArray
( void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_arm_cortex_a_counter_restoreDataFromMxArray (
void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) { memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData
( mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_arm_cortex_a_counter_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) ; static void
mr_arm_cortex_a_counter_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j
, mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_arm_cortex_a_counter_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_arm_cortex_a_counter_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_arm_cortex_a_counter_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_arm_cortex_a_counter_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_arm_cortex_a_counter_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_arm_cortex_a_counter_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_arm_cortex_a_counter_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_arm_cortex_a_counter_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_arm_cortex_a_counter_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_arm_cortex_a_counter_extractBitFieldFromCellArrayWithOffset
( const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_arm_cortex_a_counter_GetDWork ( const
ook1zpy4mwv * mdlrefDW ) { static const char * ssDWFieldNames [ 3 ] = {
"NULL->rtb" , "rtdw" , "NULL->rtzce" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ; { static const char *
rtdwDataFieldNames [ 1 ] = { "mdlrefDW->rtdw.b5aieudxfw" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 1 , rtdwDataFieldNames ) ;
mr_arm_cortex_a_counter_cacheDataAsMxArray ( rtdwData , 0 , 0 , & ( mdlrefDW
-> rtdw . b5aieudxfw ) , sizeof ( mdlrefDW -> rtdw . b5aieudxfw ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_arm_cortex_a_counter_SetDWork ( ook1zpy4mwv * mdlrefDW , const mxArray *
ssDW ) { { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_arm_cortex_a_counter_restoreDataFromMxArray ( & ( mdlrefDW -> rtdw .
b5aieudxfw ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW -> rtdw . b5aieudxfw ) )
; } } void mr_arm_cortex_a_counter_RegisterSimStateChecksum ( SimStruct * S )
{ const uint32_T chksum [ 4 ] = { 2372432092U , 784264833U , 1466202943U ,
4147165689U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"arm_cortex_a_counter" , & chksum [ 0 ] ) ; } mxArray *
mr_arm_cortex_a_counter_GetSimStateDisallowedBlocks ( ) { return NULL ; }
