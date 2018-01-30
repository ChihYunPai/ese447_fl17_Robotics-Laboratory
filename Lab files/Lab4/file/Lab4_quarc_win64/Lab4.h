/*
 * Lab4.h
 *
 * Code generation for model "Lab4".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Sat Nov 04 17:44:01 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Lab4_h_
#define RTW_HEADER_Lab4_h_
#ifndef Lab4_COMMON_INCLUDES_
# define Lab4_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* Lab4_COMMON_INCLUDES_ */

#include "Lab4_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T degreetoradius[4];            /* '<Root>/degree to radius' */
  real_T Integrator[4];                /* '<Root>/Integrator' */
  real_T voltage1;                     /* '<Root>/voltage1' */
  real_T voltage2;                     /* '<Root>/voltage2' */
  real_T Xdot[4];                      /* '<Root>/StateMachine' */
} BlockIO_Lab4;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } V_PWORK;                           /* '<Root>/V' */

  struct {
    void *LoggedData;
  } X_PWORK;                           /* '<Root>/X' */

  int32_T sfEvent;                     /* '<Root>/StateMachine' */
  int32_T sfEvent_m;                   /* '<Root>/Animation' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<Root>/Integrator' */

  uint8_T is_active_c2_Lab4;           /* '<Root>/StateMachine' */
  uint8_T is_active_c1_Lab4;           /* '<Root>/Animation' */
  boolean_T isStable;                  /* '<Root>/StateMachine' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/StateMachine' */
  boolean_T isStable_e;                /* '<Root>/Animation' */
  boolean_T doneDoubleBufferReInit_o;  /* '<Root>/Animation' */
} D_Work_Lab4;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<Root>/Integrator' */
} ContinuousStates_Lab4;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<Root>/Integrator' */
} StateDerivatives_Lab4;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<Root>/Integrator' */
} StateDisabled_Lab4;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_Lab4_ {
  real_T q1_Value;                     /* Expression: 0
                                        * Referenced by: '<Root>/q1'
                                        */
  real_T q1dot_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/q1dot'
                                        */
  real_T q2_Value;                     /* Expression: 180
                                        * Referenced by: '<Root>/q2'
                                        */
  real_T q2dot_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/q2dot'
                                        */
  real_T degreetoradius_Gain;          /* Expression: pi/180
                                        * Referenced by: '<Root>/degree to radius'
                                        */
  real_T voltage1_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/voltage1'
                                        */
  real_T voltage2_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/voltage2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Lab4 {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    real_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][4];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_Lab4 Lab4_P;

/* Block signals (auto storage) */
extern BlockIO_Lab4 Lab4_B;

/* Continuous states (auto storage) */
extern ContinuousStates_Lab4 Lab4_X;

/* Block states (auto storage) */
extern D_Work_Lab4 Lab4_DWork;

/* Model entry point functions */
extern void Lab4_initialize(void);
extern void Lab4_step(void);
extern void Lab4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lab4 *const Lab4_M;

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
 * '<Root>' : 'Lab4'
 * '<S1>'   : 'Lab4/Animation'
 * '<S2>'   : 'Lab4/StateMachine'
 */
#endif                                 /* RTW_HEADER_Lab4_h_ */
