//typedef
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;


//third library : rtwtypes.h

#ifndef RTWTYPES_H
#define RTWTYPES_H

/* Logical type definitions */
#if (!defined(__cplusplus))
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
#endif

/*=======================================================================*
 * Target hardware information
 *   Device type: Atmel->AVR
 *   Number of bits:     char:   8    short:   16    int:  16
 *                       long:  32    long long:  64
 *                       native word size:   8
 *   Byte ordering: LittleEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef int int16_T;
typedef unsigned int uint16_T;
typedef long int32_T;
typedef unsigned long uint32_T;
typedef long long int64_T;
typedef unsigned long long uint64_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, char_T, byte_T, int_T, uint_T,       *
 *                           ulong_T, ulonglong_T.                           *
 *===========================================================================*/
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef unsigned long long ulonglong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MAX_int32_T                    ((int32_T)(2147483647L))
#define MIN_int32_T                    ((int32_T)(-2147483647L-1L))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFUL))
#define MAX_int64_T                    ((int64_T)(9223372036854775807LL))
#define MIN_int64_T                    ((int64_T)(-9223372036854775807LL-1LL))
#define MAX_uint64_T                   ((uint64_T)(0xFFFFFFFFFFFFFFFFULL))

/* Block D-Work pointer type */
typedef void * pointer_T;

#endif                                 /* RTWTYPES_H */

//fourth library
#include <stddef.h>
//fifth library : rtmodel.h
#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_
/* Macros generated for backwards compatibility  */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif
#endif   
/////////////////////////////////STEP AND INIT////////////////////////////////////////////////
//rtw_continuous.h
/* Copyright 1990-2014 The MathWorks, Inc. */

/*
 * File: rtw_continuous.h     
 *
 * Abstract:
 *   Type definitions for continuous-time support.
 *
 */

#ifndef RTW_CONTINUOUS_H__
#define RTW_CONTINUOUS_H__

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else

#endif

/* For models registering MassMatrix */
typedef enum {
    SS_MATRIX_NONE,
    SS_MATRIX_CONSTANT,
    SS_MATRIX_TIMEDEP,
    SS_MATRIX_STATEDEP
} ssMatrixType;
    
typedef enum {
    SOLVER_MODE_AUTO,          /* only occurs in
                                  mdlInitializeSizes/mdlInitializeSampleTimes */
    SOLVER_MODE_SINGLETASKING,
    SOLVER_MODE_MULTITASKING
} SolverMode;

typedef enum {
    MINOR_TIME_STEP,
    MAJOR_TIME_STEP
} SimTimeStep;

/* =============================================================================
 * Model methods object
 * =============================================================================
 */
typedef void (*rtMdlInitializeSizesFcn)(void *rtModel);
typedef void (*rtMdlInitializeSampleTimesFcn)(void *rtModel);
typedef void (*rtMdlStartFcn)(void *rtModel);
typedef void (*rtMdlOutputsFcn)(void *rtModel, int_T tid);
typedef void (*rtMdlUpdateFcn)(void *rtModel, int_T tid);
typedef void (*rtMdlDerivativesFcn)(void *rtModel);
typedef void (*rtMdlProjectionFcn)(void *rtModel);
typedef void (*rtMdlMassMatrixFcn)(void *rtModel);
typedef void (*rtMdlForcingFunctionFcn)(void *rtModel);
typedef void (*rtMdlTerminateFcn)(void *rtModel);
#ifdef RT_MALLOC
typedef real_T (*rtMdlDiscreteEventsFcn)(void  *pModel,
                                         int_T  rtmNumSampTimes, 
                                         void  *rtmTimingData, 
                                         int_T  *rtmSampleHitPtr, 
                                         int_T  *rtmPerTaskSampleHits);
#endif

typedef struct _RTWRTModelMethodsInfo_tag {
    void                          *rtModelPtr;
    rtMdlInitializeSizesFcn       rtmInitSizesFcn;
    rtMdlInitializeSampleTimesFcn rtmInitSampTimesFcn;
    rtMdlStartFcn                 rtmStartFcn;
    rtMdlOutputsFcn               rtmOutputsFcn;
    rtMdlUpdateFcn                rtmUpdateFcn;
    rtMdlDerivativesFcn           rtmDervisFcn;
    rtMdlProjectionFcn            rtmProjectionFcn;
    rtMdlMassMatrixFcn            rtmMassMatrixFcn;
    rtMdlForcingFunctionFcn       rtmForcingFunctionFcn;
    rtMdlTerminateFcn             rtmTerminateFcn;
#ifdef  RT_MALLOC
    rtMdlDiscreteEventsFcn        rtmDiscreteEventsFcn;
#endif
} RTWRTModelMethodsInfo;

#define rtmiSetRTModelPtr(M,rtmp) ((M).rtModelPtr = (rtmp))
#define rtmiGetRTModelPtr(M)      (M).rtModelPtr

#define rtmiSetInitSizesFcn(M,fp) \
  ((M).rtmInitSizesFcn = ((rtMdlInitializeSizesFcn)(fp)))
#define rtmiSetInitSampTimesFcn(M,fp) \
  ((M).rtmInitSampTimesFcn = ((rtMdlInitializeSampleTimesFcn)(fp)))
#define rtmiSetStartFcn(M,fp) \
  ((M).rtmStartFcn = ((rtMdlStartFcn)(fp)))
#define rtmiSetOutputsFcn(M,fp) \
  ((M).rtmOutputsFcn = ((rtMdlOutputsFcn)(fp)))
#define rtmiSetUpdateFcn(M,fp) \
  ((M).rtmUpdateFcn = ((rtMdlUpdateFcn)(fp)))
#define rtmiSetDervisFcn(M,fp) \
  ((M).rtmDervisFcn = ((rtMdlDerivativesFcn)(fp)))
#define rtmiSetProjectionFcn(M,fp) \
  ((M).rtmProjectionFcn = ((rtMdlProjectionFcn)(fp)))
#define rtmiSetMassMatrixFcn(M,fp) \
  ((M).rtmMassMatrixFcn = ((rtMdlMassMatrixFcn)(fp)))
#define rtmiSetForcingFunctionFcn(M,fp) \
  ((M).rtmForcingFunctionFcn = ((rtMdlForcingFunctionFcn)(fp)))
#define rtmiSetTerminateFcn(M,fp) \
  ((M).rtmTerminateFcn = ((rtMdlTerminateFcn)(fp)))
#ifdef  RT_MALLOC
#define rtmiSetDiscreteEventsFcn(M,fp) \
  ((M).rtmDiscreteEventsFcn = ((rtMdlDiscreteEventsFcn)(fp)))
#endif

#define rtmiInitializeSizes(M)                  \
    ((*(M).rtmInitSizesFcn)((M).rtModelPtr))
#define rtmiInitializeSampleTimes(M)                    \
    ((*(M).rtmInitSampTimesFcn)((M).rtModelPtr))
#define rtmiStart(M) \
    ((*(M).rtmStartFcn)((M).rtModelPtr))
#define rtmiOutputs(M, tid) \
    ((*(M).rtmOutputsFcn)((M).rtModelPtr,tid))
#define rtmiUpdate(M, tid) \
    ((*(M).rtmUpdateFcn)((M).rtModelPtr,tid))
#define rtmiDerivatives(M) \
    ((*(M).rtmDervisFcn)((M).rtModelPtr))
#define rtmiProjection(M) \
    ((*(M).rtmProjectionFcn)((M).rtModelPtr))
#define rtmiMassMatrix(M) \
    ((*(M).rtmMassMatrixFcn)((M).rtModelPtr))
#define rtmiForcingFunction(M) \
    ((*(M).rtmForcingFunctionFcn)((M).rtModelPtr))
#define rtmiTerminate(M) \
    ((*(M).rtmTerminateFcn)((M).rtModelPtr))
#ifdef  RT_MALLOC
#define rtmiDiscreteEvents(M,x1,x2,x3,x4)                               \
    ((*(M).rtmDiscreteEventsFcn)((M).rtModelPtr,(x1),(x2),(x3),(x4)))
#endif
#endif /* __RTW_CONTINUOUS_H__ */

//rtw_solver.h
/*
 * File: rtw_solver.h     
 *
 * Abstract:
 *   Type definitions for continuous-time solver support.
 *
 */

/* Copyright 1990-2017 The MathWorks, Inc. */

#ifndef RTW_SOLVER_H__
#define RTW_SOLVER_H__



/* =============================================================================
 * Solver object
 * =============================================================================
 */
#ifndef NO_FLOATS /* ERT integer-only */
/*
 * Enum for solver tolerance
 */
typedef enum {
    SL_SOLVER_TOLERANCE_AUTO  = 0,  /* Set Automatically by Solver */
    SL_SOLVER_TOLERANCE_LOCAL = 1,  /* Set Locally, e.g., by Blocks */
    SL_SOLVER_TOLERANCE_GLOBAL = 2, /* Set Globally, e.g., by Block Diagram */
    SL_SOLVER_TOLERANCE_UNDEFINED = 255 /* Signal uninitialized */
} SL_SolverToleranceControlFlag_T;


/*
 * Enum for jacobian method control
 */
typedef enum {
    SL_JM_BD_AUTO = 0,
    SL_JM_BD_SPARSE_PERTURBATION,
    SL_JM_BD_FULL_PERTURBATION,
    SL_JM_BD_SPARSE_ANALYTICAL,
    SL_JM_BD_FULL_ANALYTICAL
} slJmBdControl;


typedef struct _ssSolverInfo_tag {
    void        *rtModelPtr;

    SimTimeStep *simTimeStepPtr;
    void        *solverData;
    const char_T  *solverName;
    boolean_T   isVariableStepSolver;
    boolean_T   solverNeedsReset;
    SolverMode  solverMode;

    time_T      solverStopTime;
    time_T      *stepSizePtr;
    time_T      minStepSize;
    time_T      maxStepSize;
    time_T      fixedStepSize;
      
    int_T       solverShapePreserveControl;
    int_T       solverMaxConsecutiveMinStep;
    int_T       maxNumMinSteps;
    int_T       solverMaxOrder;
    real_T      solverConsecutiveZCsStepRelTol;
    int_T       solverMaxConsecutiveZCs;
   
    int_T       solverExtrapolationOrder;
    int_T       solverNumberNewtonIterations;

    int_T       solverRefineFactor;
    real_T      solverRelTol;
    real_T      unused_real_T_1;

    real_T      **dXPtr;
    time_T      **tPtr;

    int_T       *numContStatesPtr;
    real_T      **contStatesPtr;

    int_T*      numPeriodicContStatesPtr;
    int_T**     periodicContStateIndicesPtr;
    real_T**    periodicContStateRangesPtr;

    real_T*     zcSignalVector;
    uint8_T*    zcEventsVector;
    uint8_T*    zcSignalAttrib;
    int_T       zcSignalVectorLength;
    uint8_T*    reserved;

    boolean_T   foundContZcEvents;
    boolean_T   isAtLeftPostOfContZcEvent;
    boolean_T   isAtRightPostOfContZcEvent;
    boolean_T   adaptiveZcDetection;

    int_T       numZcSignals;

    boolean_T   stateProjection;
    boolean_T   robustResetMethod;  /* user's preference */
    boolean_T   updateJacobianAtReset; /* S-Fcn request (sticky) */
    boolean_T   consistencyChecking;

    ssMatrixType  massMatrixType;
    int_T         massMatrixNzMax;
    int_T*        massMatrixIr; 
    int_T*        massMatrixJc; 
    real_T*       massMatrixPr; 

    const char_T **errStatusPtr;

    RTWRTModelMethodsInfo *modelMethodsPtr;
    real_T      zcThreshold;
    int_T       zeroCrossAlgorithm;
    int_T       consecutiveZCsError;
    boolean_T   CTOutputIncnstWithState;
    boolean_T   isComputingJacobian;
    slJmBdControl solverJacobianMethodControl;
    int_T       ignoredZcDiagnostic;
    int_T       maskedZcDiagnostic;
    boolean_T   isOutputMethodComputed;
} ssSolverInfo;

/* Support old name RTWSolverInfo */
typedef ssSolverInfo RTWSolverInfo;

#define rtsiSetRTModelPtr(S,rtmp) ((S)->rtModelPtr = (rtmp))
#define rtsiGetRTModelPtr(S)      (S)->rtModelPtr

#define rtsiSetSimTimeStepPtr(S,stp) ((S)->simTimeStepPtr = (stp))
#define rtsiGetSimTimeStepPtr(S) ((S)->simTimeStepPtr)
#define rtsiGetSimTimeStep(S)        *((S)->simTimeStepPtr)
#define rtsiSetSimTimeStep(S,st)     (*((S)->simTimeStepPtr) = (st))

#define rtsiSetSolverData(S,sd) ((S)->solverData = (sd))
#define rtsiGetSolverData(S)    (S)->solverData

#define rtsiSetSolverName(S,sn) ((S)->solverName = (sn))
#define rtsiGetSolverName(S)    (S)->solverName

#define rtsiSetVariableStepSolver(S,vs) ((S)->isVariableStepSolver = (vs))
#define rtsiIsVariableStepSolver(S)     (S)->isVariableStepSolver

#define rtsiSetSolverNeedsReset(S,sn) ((S)->solverNeedsReset = (sn))
#define rtsiGetSolverNeedsReset(S)    (S)->solverNeedsReset

#define rtsiSetContTimeOutputInconsistentWithStateAtMajorStep(S,sn) ((S)->CTOutputIncnstWithState  = (sn))
#define rtsiGetContTimeOutputInconsistentWithStateAtMajorStep(S)    (S)->CTOutputIncnstWithState 

#define rtsiSetBlkStateChange(S,sn) ((S)->CTOutputIncnstWithState  = (sn))
#define rtsiGetBlkStateChange(S)    (S)->CTOutputIncnstWithState 

#define rtsiSetBlockStateForSolverChangedAtMajorStep(S,sn) ((S)->solverNeedsReset = (sn))
#define rtsiGetBlockStateForSolverChangedAtMajorStep(S)    (S)->solverNeedsReset

#define rtsiSetSolverMode(S,sm) ((S)->solverMode = (sm))
#define rtsiGetSolverMode(S)    (S)->solverMode

#define rtsiSetSolverStopTime(S,st) ((S)->solverStopTime = (st))
#define rtsiGetSolverStopTime(S)    (S)->solverStopTime

#define rtsiSetStepSizePtr(S,ssp) ((S)->stepSizePtr = (ssp))
#define rtsiSetStepSize(S,ss)     (*((S)->stepSizePtr) = (ss))
#define rtsiGetStepSize(S)        *((S)->stepSizePtr)

#define rtsiSetMinStepSize(S,ss) (((S)->minStepSize = (ss)))
#define rtsiGetMinStepSize(S)    (S)->minStepSize

#define rtsiSetMaxStepSize(S,ss) ((S)->maxStepSize = (ss))
#define rtsiGetMaxStepSize(S)    (S)->maxStepSize

#define rtsiSetFixedStepSize(S,ss) ((S)->fixedStepSize = (ss))
#define rtsiGetFixedStepSize(S)    (S)->fixedStepSize

#define rtsiSetMaxNumMinSteps(S,mns) ((S)->maxNumMinSteps = (mns))
#define rtsiGetMaxNumMinSteps(S)     (S)->maxNumMinSteps

#define rtsiSetSolverMaxOrder(S,smo) ((S)->solverMaxOrder = (smo))
#define rtsiGetSolverMaxOrder(S)     (S)->solverMaxOrder

#define rtsiSetSolverJacobianMethodControl(S,smcm)   (ssGetSolverInfo(S)->solverJacobianMethodControl = (smcm))
#define rtsiGetSolverJacobianMethodControl(S)        ssGetSolverInfo(S)->solverJacobianMethodControl

#define rtsiSetSolverShapePreserveControl(S,smcm)   (ssGetSolverInfo(S)->solverShapePreserveControl = (smcm))
#define rtsiGetSolverShapePreserveControl(S)        ssGetSolverInfo(S)->solverShapePreserveControl

#define rtsiSetSolverConsecutiveZCsStepRelTol(S,scr) (ssGetSolverInfo(S)->solverConsecutiveZCsStepRelTol = (scr))
#define rtsiGetSolverConsecutiveZCsStepRelTol(S)     ssGetSolverInfo(S)->solverConsecutiveZCsStepRelTol  

#define rtsiSetSolverMaxConsecutiveZCs(S,smcz)       (ssGetSolverInfo(S)->solverMaxConsecutiveZCs = (smcz))
#define rtsiGetSolverMaxConsecutiveZCs(S)            ssGetSolverInfo(S)->solverMaxConsecutiveZCs

#define rtsiSetSolverMaxConsecutiveMinStep(S,smcm)   (ssGetSolverInfo(S)->solverMaxConsecutiveMinStep = (smcm))
#define rtsiGetSolverMaxConsecutiveMinStep(S)        ssGetSolverInfo(S)->solverMaxConsecutiveMinStep

#define rtsiSetSolverExtrapolationOrder(S,seo) ((S)->solverExtrapolationOrder = (seo))
#define rtsiGetSolverExtrapolationOrder(S)      (S)->solverExtrapolationOrder

#define rtsiSetSolverNumberNewtonIterations(S,nni) ((S)->solverNumberNewtonIterations = (nni))
#define rtsiGetSolverNumberNewtonIterations(S)      (S)->solverNumberNewtonIterations

#define rtsiSetSolverRefineFactor(S,smo) ((S)->solverRefineFactor = (smo))
#define rtsiGetSolverRefineFactor(S)     (S)->solverRefineFactor

#define rtsiSetSolverRelTol(S,smo) ((S)->solverRelTol = (smo))
#define rtsiGetSolverRelTol(S)     (S)->solverRelTol

#define rtsiSetSolverMassMatrixType(S,type)  ((S)->massMatrixType = (type))
#define rtsiGetSolverMassMatrixType(S)  (S)->massMatrixType

#define rtsiSetSolverMassMatrixNzMax(S,nzMax)  ((S)->massMatrixNzMax = (nzMax))
#define rtsiGetSolverMassMatrixNzMax(S)  (S)->massMatrixNzMax

#define rtsiSetSolverMassMatrixIr(S,ir)  ((S)->massMatrixIr = (ir))
#define rtsiGetSolverMassMatrixIr(S)  (S)->massMatrixIr

#define rtsiSetSolverMassMatrixJc(S,jc)  ((S)->massMatrixJc = (jc))
#define rtsiGetSolverMassMatrixJc(S)  (S)->massMatrixJc

#define rtsiSetSolverMassMatrixPr(S,pr)  ((S)->massMatrixPr = (pr))
#define rtsiGetSolverMassMatrixPr(S)  (S)->massMatrixPr

#define rtsiSetdXPtr(S,dxp) ((S)->dXPtr = (dxp))
#define rtsiSetdX(S,dx)     (*((S)->dXPtr) = (dx))
#define rtsiGetdX(S)        *((S)->dXPtr)

#define rtsiSetTPtr(S,tp) ((S)->tPtr = (tp))
#define rtsiSetT(S,t)     ((*((S)->tPtr))[0] = (t))
#define rtsiGetT(S)       (*((S)->tPtr))[0]

#define rtsiSetContStatesPtr(S,cp) ((S)->contStatesPtr = (cp))
#define rtsiGetContStates(S)       *((S)->contStatesPtr)

#define rtsiSetNumContStatesPtr(S,cp) ((S)->numContStatesPtr = (cp))
#define rtsiGetNumContStates(S)       *((S)->numContStatesPtr)

#define rtsiSetNumPeriodicContStatesPtr(S,cp) ((S)->numPeriodicContStatesPtr = (cp))
#define rtsiGetNumPeriodicContStates(S)       *((S)->numPeriodicContStatesPtr)

#define rtsiSetPeriodicContStateIndicesPtr(S,cp) ((S)->periodicContStateIndicesPtr = (cp))
#define rtsiGetPeriodicContStateIndices(S)       *((S)->periodicContStateIndicesPtr)

#define rtsiSetPeriodicContStateRangesPtr(S,cp) ((S)->periodicContStateRangesPtr = (cp))
#define rtsiGetPeriodicContStateRanges(S)       *((S)->periodicContStateRangesPtr)

#define rtsiSetErrorStatusPtr(S,esp) ((S)->errStatusPtr = (esp))
#define rtsiSetErrorStatus(S,es) (*((S)->errStatusPtr) = (es))
#define rtsiGetErrorStatus(S)    *((S)->errStatusPtr)

#define rtsiSetModelMethodsPtr(S,mmp) ((S)->modelMethodsPtr = (mmp))
#define rtsiGetModelMethodsPtr(S)     (S)->modelMethodsPtr

#define rtsiSetSolverComputingJacobian(S,val) ((S)->isComputingJacobian = (val))
#define rtsiIsSolverComputingJacobian(S)    (S)->isComputingJacobian

#define rtsiSetSolverOutputComputed(S,val) ((S)->isOutputMethodComputed = (val))
#define rtsiIsSolverOutputComputed(S) (S)->isOutputMethodComputed

#endif /* !NO_FLOATS */

#endif /* RTW_SOLVER_H__ */

//code.h generated by matlab
/*
 * File: safety.h
 *
 * Code generated for Simulink model 'safety'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul  4 19:12:51 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_safety_h_
#define RTW_HEADER_safety_h_
#include <stddef.h>
#ifndef safety_COMMON_INCLUDES_
# define safety_COMMON_INCLUDES_

#endif                                 /* safety_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define safety_M                       (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_safety;         /* '<Root>/Chart' */
  uint8_T is_c3_safety;                /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Inport;                       /* '<Root>/Inport' */
  real_T Inport1;                      /* '<Root>/Inport1' */
  real_T Inport2;                      /* '<Root>/Inport2' */
  real_T Inport3;                      /* '<Root>/Inport3' */
  real_T Inport4;                      /* '<Root>/Inport4' */
  real_T Inport5;                      /* '<Root>/Inport5' */
  real_T Inport6;                      /* '<Root>/Inport6' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void safety_initialize(void);
extern void safety_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'safety'
 * '<S1>'   : 'safety/Chart'
 */
#endif                                 /* RTW_HEADER_safety_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */


//code.c generated by matlab
/*
 * File: safety.c
 *
 * Code generated for Simulink model 'safety'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul  4 19:12:51 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */


/* Named constants for Chart: '<Root>/Chart' */
#define IN_both_dir_stop               ((uint8_T)1U)
#define IN_door_stop                   ((uint8_T)2U)
#define IN_down_stop                   ((uint8_T)3U)
#define IN_monitor                     ((uint8_T)4U)
#define IN_speed_stop                  ((uint8_T)5U)
#define IN_stop_button                 ((uint8_T)6U)
#define IN_top_stop                    ((uint8_T)7U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void safety_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/Inport'
   *  Inport: '<Root>/Inport1'
   *  Inport: '<Root>/Inport2'
   *  Inport: '<Root>/Inport3'
   *  Inport: '<Root>/Inport4'
   *  Inport: '<Root>/Inport5'
   *  Inport: '<Root>/Inport6'
   */
  if (rtDW.temporalCounter_i1 < 3U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_safety == 0U) {
    rtDW.is_active_c3_safety = 1U;
    rtDW.is_c3_safety = IN_monitor;
    rtDW.temporalCounter_i1 = 0U;
  } else {
    switch (rtDW.is_c3_safety) {
     case IN_both_dir_stop:
      if ((rtDW.temporalCounter_i1 >= 1U) && ((rtU.Inport6 == 0.0) ||
           (rtU.Inport2 == 0.0))) {
        rtDW.is_c3_safety = IN_monitor;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport6 == 1.0) &&
            (rtU.Inport2 == 1.0)) {
          rtDW.is_c3_safety = IN_both_dir_stop;
          rtDW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/Out1' */
          rtY.Out1 = 1.0;
        }
      }
      break;

     case IN_door_stop:
      if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport1 == 1.0)) {
        rtDW.is_c3_safety = IN_door_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else {
        if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport1 == 0.0)) {
          rtDW.is_c3_safety = IN_monitor;
          rtDW.temporalCounter_i1 = 0U;
        }
      }
      break;

     case IN_down_stop:
      if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport3 == 800.0) &&
          (rtU.Inport == -1.0) && (rtU.Inport6 == 1.0)) {
        rtDW.is_c3_safety = IN_down_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else {
        if ((rtDW.temporalCounter_i1 >= 1U) && ((rtU.Inport != -1.0) ||
             (rtU.Inport2 == 0.0))) {
          rtDW.is_c3_safety = IN_monitor;
          rtDW.temporalCounter_i1 = 0U;
        }
      }
      break;

     case IN_monitor:
      if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport1 == 1.0) && (rtU.Inport
           == -1.0)) {
        rtDW.is_c3_safety = IN_door_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport5 == 1.0)) {
        rtDW.is_c3_safety = IN_stop_button;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport3 == 800.0) &&
                 (rtU.Inport == -1.0) && (rtU.Inport6 == 1.0)) {
        rtDW.is_c3_safety = IN_top_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport4 > 50.0)) {
        rtDW.is_c3_safety = IN_speed_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport3 == 0.0) &&
                 (rtU.Inport == -1.0) && (rtU.Inport2 == 1.0)) {
        rtDW.is_c3_safety = IN_down_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport6 == 1.0) &&
                 (rtU.Inport2 == 1.0)) {
        rtDW.is_c3_safety = IN_both_dir_stop;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else {
        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 0.0;
      }
      break;

     case IN_speed_stop:
      if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport4 <= 50.0)) {
        rtDW.is_c3_safety = IN_monitor;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport4 > 50.0)) {
          rtDW.is_c3_safety = IN_speed_stop;
          rtDW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/Out1' */
          rtY.Out1 = 1.0;
        }
      }
      break;

     case IN_stop_button:
      if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport5 == 1.0)) {
        rtDW.is_c3_safety = IN_stop_button;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/Out1' */
        rtY.Out1 = 1.0;
      } else {
        if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport5 == 0.0)) {
          rtDW.is_c3_safety = IN_monitor;
          rtDW.temporalCounter_i1 = 0U;
        }
      }
      break;

     default:
      if ((rtDW.temporalCounter_i1 >= 1U) && ((rtU.Inport != -1.0) ||
           (rtU.Inport6 == 0.0))) {
        rtDW.is_c3_safety = IN_monitor;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        if ((rtDW.temporalCounter_i1 >= 1U) && (rtU.Inport3 == 800.0) &&
            (rtU.Inport == -1.0) && (rtU.Inport6 == 1.0)) {
          rtDW.is_c3_safety = IN_top_stop;
          rtDW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/Out1' */
          rtY.Out1 = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void safety_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */




void setup(){

}
void loop(){

}