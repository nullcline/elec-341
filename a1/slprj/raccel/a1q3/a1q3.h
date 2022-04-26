#ifndef RTW_HEADER_a1q3_h_
#define RTW_HEADER_a1q3_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef a1q3_COMMON_INCLUDES_
#define a1q3_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "a1q3_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME a1q3
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (5) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T kwx2wq3sbg ; real_T e3dakysr2n ; real_T ja141j5m0t ;
real_T ooz4ahftrc ; real_T mippkmrbkp ; } B ; typedef struct { struct { void
* LoggedData [ 2 ] ; } embnbxlj4s ; int_T cad043p41y ; int_T itthgn12is ; }
DW ; typedef struct { real_T nue5cxorun [ 3 ] ; real_T b0eamntmef [ 3 ] ; } X
; typedef struct { real_T nue5cxorun [ 3 ] ; real_T b0eamntmef [ 3 ] ; } XDot
; typedef struct { boolean_T nue5cxorun [ 3 ] ; boolean_T b0eamntmef [ 3 ] ;
} XDis ; typedef struct { real_T nue5cxorun [ 3 ] ; real_T b0eamntmef [ 3 ] ;
} CStateAbsTol ; typedef struct { real_T nue5cxorun [ 3 ] ; real_T b0eamntmef
[ 3 ] ; } CXPtMin ; typedef struct { real_T nue5cxorun [ 3 ] ; real_T
b0eamntmef [ 3 ] ; } CXPtMax ; typedef struct { real_T kpluieqruq ; real_T
nlc5c22ya4 ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T den [ 4 ] ; real_T num [ 3 ] ; real_T
Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T Step1_Time ; real_T
Step1_Y0 ; real_T Step1_YFinal ; real_T Gain_Gain ; real_T ZeroPole_A [ 5 ] ;
real_T ZeroPole_B ; real_T ZeroPole_C [ 3 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_a1q3_GetDWork ( ) ; extern void
mr_a1q3_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_a1q3_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * a1q3_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
