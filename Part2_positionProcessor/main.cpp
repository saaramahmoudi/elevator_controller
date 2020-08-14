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
 * File: position_signalGenerator.h
 *
 * Code generated for Simulink model 'position_signalGenerator'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul  3 20:17:28 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_signalGenerator_h_
#define RTW_HEADER_position_signalGenerator_h_
#include <math.h>
#include <stddef.h>
#ifndef position_signalGenerator_COMMON_INCLUDES_
# define position_signalGenerator_COMMON_INCLUDES_

#endif                                 /* position_signalGenerator_COMMON_INCLUDES_ */


/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define position_signalGenerator_M     (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T counter;                      /* '<Root>/Position Sensor ' */
  real_T last;                         /* '<Root>/Position Sensor ' */
  real_T last_counter;                 /* '<Root>/Position Sensor ' */
  uint8_T is_active_c3_position_signalGen;/* '<Root>/Position Sensor ' */
  uint8_T is_c3_position_signalGenerator;/* '<Root>/Position Sensor ' */
  uint8_T is_pos_cal;                  /* '<Root>/Position Sensor ' */
  uint8_T was_pos_cal;                 /* '<Root>/Position Sensor ' */
  uint8_T temporalCounter_i1;          /* '<Root>/Position Sensor ' */
  uint8_T temporalCounter_i2;          /* '<Root>/Position Sensor ' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Outport;                      /* '<Root>/Outport' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Outport1;                     /* '<Root>/Outport1' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void position_signalGenerator_initialize(void);
extern void position_signalGenerator_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'position_signalGenerator'
 * '<S1>'   : 'position_signalGenerator/Position Sensor '
 */
#endif                                 /* RTW_HEADER_position_signalGenerator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

//code.c generated by matlab

/*
 * File: position_signalGenerator.c
 *
 * Code generated for Simulink model 'position_signalGenerator'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul  3 20:17:28 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */



/* Named constants for Chart: '<Root>/Position Sensor ' */
#define IN_between_1_2                 ((uint8_T)1U)
#define IN_between_2_3                 ((uint8_T)2U)
#define IN_floor_1                     ((uint8_T)3U)
#define IN_floor_2                     ((uint8_T)4U)
#define IN_floor_3                     ((uint8_T)5U)
#define IN_init                        ((uint8_T)1U)
#define IN_pos_detection               ((uint8_T)2U)
#define IN_read_pulse_1_2              ((uint8_T)6U)
#define IN_read_pulse_2_3              ((uint8_T)7U)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void pos_detection(const real_T *SignalGenerator);

/* Function for Chart: '<Root>/Position Sensor ' */
static void pos_detection(const real_T *SignalGenerator)
{
  if (rtDW.temporalCounter_i1 >= 150U) {
    rtDW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/Outport1' incorporates:
     *  Outport: '<Root>/Out3'
     */
    rtY.Outport1 = fabs(rtY.Out3 - rtDW.last_counter);

    /* Outport: '<Root>/Out3' */
    rtDW.last_counter = rtY.Out3;
  }

  switch (rtDW.is_pos_cal) {
   case IN_between_1_2:
    /* Outport: '<Root>/Outport' */
    rtY.Outport = -1.0;
    if ((rtDW.temporalCounter_i2 >= 1U) && (rtDW.last != *SignalGenerator)) {
      rtDW.is_pos_cal = IN_read_pulse_1_2;
      rtDW.was_pos_cal = IN_read_pulse_1_2;
      rtDW.counter++;
      rtDW.last = *SignalGenerator;
    } else {
      if ((rtDW.temporalCounter_i2 >= 1U) && (rtDW.last == *SignalGenerator)) {
        rtDW.is_pos_cal = IN_between_1_2;
        rtDW.was_pos_cal = IN_between_1_2;
        rtDW.temporalCounter_i2 = 0U;

        /* Outport: '<Root>/Outport' */
        rtY.Outport = -1.0;

        /* Outport: '<Root>/Out3' incorporates:
         *  Outport: '<Root>/Out1'
         *  Outport: '<Root>/Out2'
         */
        rtY.Out3 = (400.0 - rtDW.counter) * rtY.Out2 + rtY.Out1 * rtDW.counter;
      }
    }
    break;

   case IN_between_2_3:
    /* Outport: '<Root>/Outport' */
    rtY.Outport = -1.0;
    if ((rtDW.temporalCounter_i2 >= 1U) && (rtDW.last != *SignalGenerator)) {
      rtDW.is_pos_cal = IN_read_pulse_2_3;
      rtDW.was_pos_cal = IN_read_pulse_2_3;
      rtDW.counter++;
      rtDW.last = *SignalGenerator;
    }
    break;

   case IN_floor_1:
    /* Outport: '<Root>/Out1' */
    rtY.Out1 = 1.0;

    /* Outport: '<Root>/Out2' */
    rtY.Out2 = 0.0;
    rtDW.is_pos_cal = IN_between_1_2;
    rtDW.was_pos_cal = IN_between_1_2;
    rtDW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/Outport' */
    rtY.Outport = -1.0;

    /* Outport: '<Root>/Out3' incorporates:
     *  Outport: '<Root>/Out1'
     *  Outport: '<Root>/Out2'
     */
    rtY.Out3 = (400.0 - rtDW.counter) * rtY.Out2 + rtY.Out1 * rtDW.counter;
    break;

   case IN_floor_2:
    /* Outport: '<Root>/Out1' */
    rtY.Out1 = 1.0;

    /* Outport: '<Root>/Out2' */
    rtY.Out2 = 0.0;
    rtDW.is_pos_cal = IN_between_2_3;
    rtDW.was_pos_cal = IN_between_2_3;
    rtDW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/Outport' */
    rtY.Outport = -1.0;

    /* Outport: '<Root>/Out3' incorporates:
     *  Outport: '<Root>/Out1'
     *  Outport: '<Root>/Out2'
     */
    rtY.Out3 = (rtDW.counter + 400.0) * rtY.Out1 + (800.0 - rtDW.counter) *
      rtY.Out2;
    break;

   case IN_floor_3:
    /* Outport: '<Root>/Outport' */
    rtY.Outport = 3.0;

    /* Outport: '<Root>/Out1' */
    rtY.Out1 = 0.0;

    /* Outport: '<Root>/Out2' */
    rtY.Out2 = 0.0;
    break;

   case IN_read_pulse_1_2:
    /* Outport: '<Root>/Out2' incorporates:
     *  Outport: '<Root>/Out1'
     *  Outport: '<Root>/Out3'
     *  Outport: '<Root>/Outport'
     */
    if ((rtDW.counter == 400.0) && (rtY.Out2 == 1.0)) {
      rtDW.is_pos_cal = IN_floor_1;
      rtDW.was_pos_cal = IN_floor_1;
      rtDW.counter = 0.0;
      rtY.Outport = 1.0;
      rtY.Out3 = 0.0;
    } else if ((rtDW.counter == 400.0) && (rtY.Out1 == 1.0)) {
      rtDW.is_pos_cal = IN_floor_2;
      rtDW.was_pos_cal = IN_floor_2;
      rtDW.counter = 0.0;
      rtY.Outport = 2.0;
      rtY.Out3 = 400.0;
    } else {
      if (rtDW.counter != 400.0) {
        rtDW.is_pos_cal = IN_between_1_2;
        rtDW.was_pos_cal = IN_between_1_2;
        rtDW.temporalCounter_i2 = 0U;
        rtY.Outport = -1.0;
        rtY.Out3 = (400.0 - rtDW.counter) * rtY.Out2 + rtY.Out1 * rtDW.counter;
      }
    }
    break;

   default:
    /* Outport: '<Root>/Out1' incorporates:
     *  Outport: '<Root>/Out2'
     *  Outport: '<Root>/Out3'
     *  Outport: '<Root>/Outport'
     */
    if ((rtDW.counter == 400.0) && (rtY.Out1 == 1.0)) {
      rtDW.is_pos_cal = IN_floor_3;
      rtDW.was_pos_cal = IN_floor_3;
      rtDW.counter = 0.0;
      rtY.Outport = 3.0;
      rtY.Out3 = 800.0;
    } else if ((rtDW.counter == 400.0) && (rtY.Out2 == 1.0)) {
      rtDW.is_pos_cal = IN_floor_2;
      rtDW.was_pos_cal = IN_floor_2;
      rtDW.counter = 0.0;
      rtY.Outport = 2.0;
      rtY.Out3 = 400.0;
    } else {
      if (rtDW.counter != 400.0) {
        rtDW.is_pos_cal = IN_between_2_3;
        rtDW.was_pos_cal = IN_between_2_3;
        rtDW.temporalCounter_i2 = 0U;
        rtY.Outport = -1.0;
        rtY.Out3 = (rtDW.counter + 400.0) * rtY.Out1 + (800.0 - rtDW.counter) *
          rtY.Out2;
      }
    }
    break;
  }
}

/* Model step function */
void position_signalGenerator_step(void)
{
  real_T SignalGenerator;

  /* SignalGenerator: '<Root>/Signal Generator' */
  SignalGenerator = 50.0 * rtM->Timing.t[0];
  if (SignalGenerator - floor(SignalGenerator) >= 0.5) {
    SignalGenerator = 1.0;
  } else {
    SignalGenerator = -1.0;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Chart: '<Root>/Position Sensor ' incorporates:
   *  Outport: '<Root>/Out1'
   *  Outport: '<Root>/Out2'
   *  Outport: '<Root>/Out3'
   */
  if (rtDW.temporalCounter_i1 < 255U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < 3U) {
    rtDW.temporalCounter_i2++;
  }

  if (rtDW.is_active_c3_position_signalGen == 0U) {
    rtDW.is_active_c3_position_signalGen = 1U;
    rtDW.is_c3_position_signalGenerator = IN_init;
  } else if (rtDW.is_c3_position_signalGenerator == IN_init) {
    rtDW.counter = 0.0;
    rtDW.last_counter = 0.0;

    /* Outport: '<Root>/Out3' */
    rtY.Out3 = 0.0;
    rtDW.is_c3_position_signalGenerator = IN_pos_detection;
    rtDW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/Outport1' incorporates:
     *  Outport: '<Root>/Out3'
     */
    rtY.Outport1 = fabs(rtY.Out3 - rtDW.last_counter);
    rtDW.last_counter = rtY.Out3;
    switch (rtDW.was_pos_cal) {
     case IN_between_1_2:
      rtDW.is_pos_cal = IN_between_1_2;
      rtDW.was_pos_cal = IN_between_1_2;
      rtDW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/Outport' */
      rtY.Outport = -1.0;
      rtY.Out3 = (400.0 - rtDW.counter) * rtY.Out2 + rtY.Out1 * rtDW.counter;
      break;

     case IN_between_2_3:
      rtDW.is_pos_cal = IN_between_2_3;
      rtDW.was_pos_cal = IN_between_2_3;
      rtDW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/Outport' */
      rtY.Outport = -1.0;
      rtY.Out3 = (rtDW.counter + 400.0) * rtY.Out1 + (800.0 - rtDW.counter) *
        rtY.Out2;
      break;

     case IN_floor_1:
      rtDW.is_pos_cal = IN_floor_1;
      rtDW.was_pos_cal = IN_floor_1;
      rtDW.counter = 0.0;

      /* Outport: '<Root>/Outport' */
      rtY.Outport = 1.0;
      rtY.Out3 = 0.0;
      break;

     case IN_floor_2:
      rtDW.is_pos_cal = IN_floor_2;
      rtDW.was_pos_cal = IN_floor_2;
      rtDW.counter = 0.0;

      /* Outport: '<Root>/Outport' */
      rtY.Outport = 2.0;
      rtY.Out3 = 400.0;
      break;

     case IN_floor_3:
      rtDW.is_pos_cal = IN_floor_3;
      rtDW.was_pos_cal = IN_floor_3;
      rtDW.counter = 0.0;

      /* Outport: '<Root>/Outport' */
      rtY.Outport = 3.0;
      rtY.Out3 = 800.0;
      break;

     case IN_read_pulse_1_2:
      rtDW.is_pos_cal = IN_read_pulse_1_2;
      rtDW.was_pos_cal = IN_read_pulse_1_2;
      rtDW.counter++;
      rtDW.last = SignalGenerator;
      break;

     case IN_read_pulse_2_3:
      rtDW.is_pos_cal = IN_read_pulse_2_3;
      rtDW.was_pos_cal = IN_read_pulse_2_3;
      rtDW.counter++;
      rtDW.last = SignalGenerator;
      break;

     default:
      rtDW.is_pos_cal = IN_floor_1;
      rtDW.was_pos_cal = IN_floor_1;
      rtDW.counter = 0.0;

      /* Outport: '<Root>/Outport' */
      rtY.Outport = 1.0;
      rtY.Out3 = 0.0;
      break;
    }
  } else {
    pos_detection(&SignalGenerator);
  }

  /* End of Chart: '<Root>/Position Sensor ' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    (++rtM->Timing.clockTick0) * rtM->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.0066666666666666671s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0066666666666666671, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }
}

/* Model initialize function */
void position_signalGenerator_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.0066666666666666671;
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