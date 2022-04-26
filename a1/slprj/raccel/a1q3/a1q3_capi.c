#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "a1q3_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#else
#include "builtin_typeid_types.h"
#include "a1q3.h"
#include "a1q3_capi.h"
#include "a1q3_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"a1q3/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "a1q3/Zero-Pole" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 2 , 0 , TARGET_STRING ( "a1q3/OpAmp/Gain" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING ( "a1q3/OpAmp/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"a1q3/OpAmp/Transfer Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , {
0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 5 , TARGET_STRING (
"a1q3/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 6 , TARGET_STRING
( "a1q3/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 7 ,
TARGET_STRING ( "a1q3/Step" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 8
, TARGET_STRING ( "a1q3/Step1" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , {
9 , TARGET_STRING ( "a1q3/Step1" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 }
, { 10 , TARGET_STRING ( "a1q3/Step1" ) , TARGET_STRING ( "After" ) , 0 , 0 ,
0 } , { 11 , TARGET_STRING ( "a1q3/Zero-Pole" ) , TARGET_STRING ( "A" ) , 0 ,
1 , 0 } , { 12 , TARGET_STRING ( "a1q3/Zero-Pole" ) , TARGET_STRING ( "B" ) ,
0 , 0 , 0 } , { 13 , TARGET_STRING ( "a1q3/Zero-Pole" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 14 , TARGET_STRING ( "a1q3/OpAmp/Gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 15 , TARGET_STRING ( "den" ) , 0 , 3 , 0 } , { 16
, TARGET_STRING ( "num" ) , 0 , 4 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . e3dakysr2n , & rtB . mippkmrbkp ,
& rtB . ooz4ahftrc , & rtB . ja141j5m0t , & rtB . kwx2wq3sbg , & rtP .
Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal , & rtP . Step1_Time , &
rtP . Step1_Y0 , & rtP . Step1_YFinal , & rtP . ZeroPole_A [ 0 ] , & rtP .
ZeroPole_B , & rtP . ZeroPole_C [ 0 ] , & rtP . Gain_Gain , & rtP . den [ 0 ]
, & rtP . num [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL )
} ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 5 , 1 , 3 , 1 , 1 , 4 , 1 , 3 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
( int8_T ) 0 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 5 , rtRootInputs , 0 , rtRootOutputs , 0 } ,
{ rtBlockParameters , 10 , rtModelParameters , 2 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 3379805521U , 1128858002U , 2745392081U ,
999842641U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * a1q3_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void a1q3_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void a1q3_host_InitializeDataMapInfo ( a1q3_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
