#include "rt_logging_mmi.h"
#include "a1q3_capi.h"
#include <math.h>
#include "a1q3.h"
#include "a1q3_private.h"
#include "a1q3_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.6 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct
* S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . nue5cxorun [ 0 ] = 0.0 ; rtX
. b0eamntmef [ 0 ] = 0.0 ; rtX . nue5cxorun [ 1 ] = 0.0 ; rtX . b0eamntmef [
1 ] = 0.0 ; rtX . nue5cxorun [ 2 ] = 0.0 ; rtX . b0eamntmef [ 2 ] = 0.0 ; }
void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void
* pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T tmp ; real_T
tmp_p ; rtB . kwx2wq3sbg = 0.0 ; rtB . kwx2wq3sbg += rtP . num [ 0 ] / rtP .
den [ 0 ] * rtX . nue5cxorun [ 0 ] ; rtB . kwx2wq3sbg += rtP . num [ 1 ] /
rtP . den [ 0 ] * rtX . nue5cxorun [ 1 ] ; rtB . kwx2wq3sbg += rtP . num [ 2
] / rtP . den [ 0 ] * rtX . nue5cxorun [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { rtDW . cad043p41y = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Step_Time )
; rtDW . itthgn12is = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Step1_Time ) ; if
( rtDW . cad043p41y == 1 ) { tmp = rtP . Step_YFinal ; } else { tmp = rtP .
Step_Y0 ; } if ( rtDW . itthgn12is == 1 ) { tmp_p = rtP . Step1_YFinal ; }
else { tmp_p = rtP . Step1_Y0 ; } rtB . e3dakysr2n = tmp - tmp_p ; } rtB .
ja141j5m0t = rtB . e3dakysr2n - rtB . kwx2wq3sbg ; rtB . ooz4ahftrc = rtP .
Gain_Gain * rtB . ja141j5m0t ; rtB . mippkmrbkp = 0.0 ; rtB . mippkmrbkp +=
rtP . ZeroPole_C [ 0 ] * rtX . b0eamntmef [ 0 ] ; rtB . mippkmrbkp += rtP .
ZeroPole_C [ 1 ] * rtX . b0eamntmef [ 1 ] ; rtB . mippkmrbkp += rtP .
ZeroPole_C [ 2 ] * rtX . b0eamntmef [ 2 ] ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives (
void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot
-> nue5cxorun [ 0 ] = 0.0 ; _rtXdot -> nue5cxorun [ 0 ] += - rtP . den [ 1 ]
/ rtP . den [ 0 ] * rtX . nue5cxorun [ 0 ] ; _rtXdot -> nue5cxorun [ 1 ] =
0.0 ; _rtXdot -> nue5cxorun [ 0 ] += - rtP . den [ 2 ] / rtP . den [ 0 ] *
rtX . nue5cxorun [ 1 ] ; _rtXdot -> nue5cxorun [ 2 ] = 0.0 ; _rtXdot ->
nue5cxorun [ 0 ] += - rtP . den [ 3 ] / rtP . den [ 0 ] * rtX . nue5cxorun [
2 ] ; _rtXdot -> nue5cxorun [ 1 ] += rtX . nue5cxorun [ 0 ] ; _rtXdot ->
nue5cxorun [ 2 ] += rtX . nue5cxorun [ 1 ] ; _rtXdot -> nue5cxorun [ 0 ] +=
rtB . ooz4ahftrc ; _rtXdot -> b0eamntmef [ 0 ] = 0.0 ; _rtXdot -> b0eamntmef
[ 1 ] = 0.0 ; _rtXdot -> b0eamntmef [ 2 ] = 0.0 ; _rtXdot -> b0eamntmef [ 0 ]
+= rtP . ZeroPole_A [ 0 ] * rtX . b0eamntmef [ 0 ] ; _rtXdot -> b0eamntmef [
1 ] += rtX . b0eamntmef [ 0 ] * rtP . ZeroPole_A [ 1 ] ; _rtXdot ->
b0eamntmef [ 1 ] += rtX . b0eamntmef [ 1 ] * rtP . ZeroPole_A [ 2 ] ; _rtXdot
-> b0eamntmef [ 1 ] += rtX . b0eamntmef [ 2 ] * rtP . ZeroPole_A [ 3 ] ;
_rtXdot -> b0eamntmef [ 2 ] += rtX . b0eamntmef [ 1 ] * rtP . ZeroPole_A [ 4
] ; _rtXdot -> b0eamntmef [ 0 ] += rtP . ZeroPole_B * rtB . e3dakysr2n ; }
void MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV
-> kpluieqruq = ssGetT ( rtS ) - rtP . Step_Time ; _rtZCSV -> nlc5c22ya4 =
ssGetT ( rtS ) - rtP . Step1_Time ; } void MdlTerminate ( void ) { } static
void mr_a1q3_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_a1q3_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j , const
void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_a1q3_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_a1q3_restoreDataFromMxArray ( void * destData , const mxArray * srcArray ,
mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_a1q3_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_a1q3_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_a1q3_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_a1q3_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_a1q3_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void
mr_a1q3_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T *
varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j )
) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T
* ) srcData , numBytes ) ; } static void
mr_a1q3_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_a1q3_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_a1q3_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_a1q3_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber
( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( double ) fieldVal )
) ; } static uint_T mr_a1q3_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_a1q3_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_a1q3_GetDWork ( ) { static const char * ssDWFieldNames [ 3
] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_a1q3_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 2 ] = {
"rtDW.cad043p41y" , "rtDW.itthgn12is" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 2 , rtdwDataFieldNames ) ;
mr_a1q3_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW .
cad043p41y ) , sizeof ( rtDW . cad043p41y ) ) ; mr_a1q3_cacheDataAsMxArray (
rtdwData , 0 , 1 , ( const void * ) & ( rtDW . itthgn12is ) , sizeof ( rtDW .
itthgn12is ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return
ssDW ; } void mr_a1q3_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_a1q3_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof
( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 )
; mr_a1q3_restoreDataFromMxArray ( ( void * ) & ( rtDW . cad043p41y ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . cad043p41y ) ) ;
mr_a1q3_restoreDataFromMxArray ( ( void * ) & ( rtDW . itthgn12is ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . itthgn12is ) ) ; } } mxArray *
mr_a1q3_GetSimStateDisallowedBlocks ( ) { mxArray * data = mxCreateCellMatrix
( 1 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const char * blockType [ 1
] = { "Scope" , } ; static const char * blockPath [ 1 ] = { "a1q3/Scope" , }
; static const int reason [ 1 ] = { 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ]
< 1 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript (
data , 2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [
subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2
, subs ) ; mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0
] ] ) ) ; subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs
[ 0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 6 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 8 ) ;
ssSetNumBlockIO ( rtS , 5 ) ; ssSetNumBlockParams ( rtS , 23 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 3379805521U ) ; ssSetChecksumVal ( rtS , 1 ,
1128858002U ) ; ssSetChecksumVal ( rtS , 2 , 2745392081U ) ; ssSetChecksumVal
( rtS , 3 , 999842641U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 20 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
a1q3_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS , true )
; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 )
; ssSetModelName ( rtS , "a1q3" ) ; ssSetPath ( rtS , "a1q3" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 1.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 3 , 3 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 3 , 3 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = { "a1q3/OpAmp/Transfer Fcn" ,
"a1q3/Zero-Pole" } ; static const char_T * rt_LoggedStateNames [ ] = { "" ,
"" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 }
; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . nue5cxorun [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . b0eamntmef [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ;
static real_T absTol [ 6 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 6 ] = { 0U , 0U , 0U , 0U , 0U , 0U
} ; static real_T contStateJacPerturbBoundMinVec [ 6 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 6 ] ; static uint8_T zcAttributes [ 2 ] = {
( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 1 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
e3dakysr2n ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 6 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.02 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 1 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 2 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 2 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3379805521U ) ; ssSetChecksumVal ( rtS , 1 ,
1128858002U ) ; ssSetChecksumVal ( rtS , 2 , 2745392081U ) ; ssSetChecksumVal
( rtS , 3 , 999842641U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_a1q3_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_a1q3_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_a1q3_SetDWork )
; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS )
) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
