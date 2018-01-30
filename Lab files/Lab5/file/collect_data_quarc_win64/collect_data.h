/*
 * collect_data.h
 *
 * Code generation for model "collect_data".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Nov 02 11:40:15 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_collect_data_h_
#define RTW_HEADER_collect_data_h_
#ifndef collect_data_COMMON_INCLUDES_
# define collect_data_COMMON_INCLUDES_
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
#endif                                 /* collect_data_COMMON_INCLUDES_ */

#include "collect_data_types.h"

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
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T voltage2;                     /* '<Root>/voltage2' */
  real_T Xdot[4];                      /* '<Root>/StateMachine' */
} BlockIO_collect_data;

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

  uint8_T is_active_c2_collect_data;   /* '<Root>/StateMachine' */
  uint8_T is_active_c1_collect_data;   /* '<Root>/Animation' */
  boolean_T isStable;                  /* '<Root>/StateMachine' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/StateMachine' */
  boolean_T isStable_e;                /* '<Root>/Animation' */
  boolean_T doneDoubleBufferReInit_o;  /* '<Root>/Animation' */
} D_Work_collect_data;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<Root>/Integrator' */
} ContinuousStates_collect_data;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<Root>/Integrator' */
} StateDerivatives_collect_data;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<Root>/Integrator' */
} StateDisabled_collect_data;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_collect_data_ {
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
  real_T SineWave1_Amp;                /* Expression: 3
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 3
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 7
                                        * Referenced by: '<Root>/Sine Wave 2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave 2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 7
                                        * Referenced by: '<Root>/Sine Wave 2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave 2'
                                        */
  real_T voltage2_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/voltage2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_collect_data {
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
    real_T odeY[4];
    real_T odeF[3][4];
    ODE3_IntgData intgData;
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
extern Parameters_collect_data collect_data_P;

/* Block signals (auto storage) */
extern BlockIO_collect_data collect_data_B;

/* Continuous states (auto storage) */
extern ContinuousStates_collect_data collect_data_X;

/* Block states (auto storage) */
extern D_Work_collect_data collect_data_DWork;

/* Model entry point functions */
extern void collect_data_initialize(void);
extern void collect_data_step(void);
extern void collect_data_terminate(void);

/* Real-time Model object */
extern RT_MODEL_collect_data *const collect_data_M;

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
 * '<Root>' : 'collect_data'
 * '<S1>'   : 'collect_data/Animation'
 * '<S2>'   : 'collect_data/StateMachine'
 */
#endif                                 /* RTW_HEADER_collect_data_h_ */
