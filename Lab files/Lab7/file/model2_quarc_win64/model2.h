/*
 * model2.h
 *
 * Code generation for model "model2".
 *
 * Model version              : 1.55
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Dec 05 11:24:58 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_model2_h_
#define RTW_HEADER_model2_h_
#ifndef model2_COMMON_INCLUDES_
# define model2_COMMON_INCLUDES_
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
#include "hil.h"
#include "quanser_messages.h"
#include "rt_nonfinite.h"
#include "quanser_extern.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* model2_COMMON_INCLUDES_ */

#include "model2_types.h"

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
  real_T Toradius;                     /* '<S4>/To radius' */
  real_T Toradius1;                    /* '<S4>/To radius1' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T degreetoradius[4];            /* '<S5>/degree to radius' */
  real_T Integrator[4];                /* '<S5>/Integrator' */
  real_T q2dotSwitch;                  /* '<Root>/q2dot Switch' */
  real_T Memory;                       /* '<Root>/Memory' */
  real_T k1;                           /* '<Root>/k1' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T gain;                         /* '<S4>/gain' */
  real_T voltage2;                     /* '<S4>/voltage2' */
  real_T Saturation_p[2];              /* '<S5>/Saturation' */
  real_T Xdot[4];                      /* '<S5>/StateMachine' */
  real_T q2;                           /* '<S5>/MATLAB Function' */
  real_T q2dot;                        /* '<S5>/MATLAB Function' */
  real_T V;                            /* '<Root>/MATLAB Function2' */
  real_T output;                       /* '<Root>/MATLAB Function1' */
  real_T control;                      /* '<Root>/MATLAB Function' */
} BlockIO_model2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[2];  /* '<S4>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[2];  /* '<S4>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[2];  /* '<S4>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[2];  /* '<S4>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[2];  /* '<S4>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<S4>/HIL Initialize' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  t_card HILInitialize_Card;           /* '<S4>/HIL Initialize' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                 /* '<S4>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S4>/Derivative' */

  void *HILReadEncoder_PWORK;          /* '<S4>/HIL Read Encoder' */
  void *HILReadEncoder1_PWORK;         /* '<S4>/HIL Read Encoder1' */
  void *HILWriteAnalog_PWORK;          /* '<S4>/HIL Write Analog' */
  void *HILWriteAnalog1_PWORK;         /* '<S4>/HIL Write Analog1' */
  struct {
    void *LoggedData;
  } V_collect_2_PWORK;                 /* '<S4>/V_collect_2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } V_PWORK;                           /* '<S5>/V' */

  struct {
    void *LoggedData;
  } X_PWORK;                           /* '<S5>/X' */

  int32_T HILInitialize_ClockModes;    /* '<S4>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<S4>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<S4>/HIL Initialize' */
  int32_T HILReadEncoder_Buffer;       /* '<S4>/HIL Read Encoder' */
  int32_T HILReadEncoder1_Buffer;      /* '<S4>/HIL Read Encoder1' */
  int32_T sfEvent;                     /* '<S5>/StateMachine' */
  int32_T sfEvent_m;                   /* '<S5>/MATLAB Function' */
  int32_T sfEvent_p;                   /* '<S5>/Animation' */
  int32_T sfEvent_g;                   /* '<Root>/MATLAB Function2' */
  int32_T sfEvent_f;                   /* '<Root>/MATLAB Function1' */
  int32_T sfEvent_l;                   /* '<Root>/MATLAB Function' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S5>/Integrator' */

  uint8_T is_active_c3_model2;         /* '<S5>/StateMachine' */
  uint8_T is_active_c4_model2;         /* '<S5>/MATLAB Function' */
  uint8_T is_active_c1_model2;         /* '<S5>/Animation' */
  uint8_T is_active_c5_model2;         /* '<Root>/MATLAB Function2' */
  uint8_T is_active_c6_model2;         /* '<Root>/MATLAB Function1' */
  uint8_T is_active_c2_model2;         /* '<Root>/MATLAB Function' */
  boolean_T isStable;                  /* '<S5>/StateMachine' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/StateMachine' */
  boolean_T isStable_c;                /* '<S5>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S5>/MATLAB Function' */
  boolean_T isStable_e;                /* '<S5>/Animation' */
  boolean_T doneDoubleBufferReInit_lo; /* '<S5>/Animation' */
  boolean_T isStable_p;                /* '<Root>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_j;  /* '<Root>/MATLAB Function2' */
  boolean_T isStable_k;                /* '<Root>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_k;  /* '<Root>/MATLAB Function1' */
  boolean_T isStable_b;                /* '<Root>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_h;  /* '<Root>/MATLAB Function' */
} D_Work_model2;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
  real_T Integrator_CSTATE[4];         /* '<S5>/Integrator' */
} ContinuousStates_model2;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
  real_T Integrator_CSTATE[4];         /* '<S5>/Integrator' */
} StateDerivatives_model2;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S4>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE;        /* '<S4>/Transfer Fcn' */
  boolean_T Integrator_CSTATE[4];      /* '<S5>/Integrator' */
} StateDisabled_model2;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_model2_ {
  real_T Saturation2_UpperSat;         /* Expression: 10
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -10
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T Toradius_Gain;                /* Expression: 2*pi/4096
                                        * Referenced by: '<S4>/To radius'
                                        */
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T Toradius1_Gain;               /* Expression: -2*pi/4096
                                        * Referenced by: '<S4>/To radius1'
                                        */
  real_T q1_Value;                     /* Expression: 0
                                        * Referenced by: '<S5>/q1'
                                        */
  real_T q1dot_Value;                  /* Expression: 0
                                        * Referenced by: '<S5>/q1dot'
                                        */
  real_T q3_Value;                     /* Expression: 180
                                        * Referenced by: '<S5>/q3'
                                        */
  real_T q2dot1_Value;                 /* Expression: 0
                                        * Referenced by: '<S5>/q2dot1'
                                        */
  real_T degreetoradius_Gain;          /* Expression: pi/180
                                        * Referenced by: '<S5>/degree to radius'
                                        */
  real_T interval_1indegree_Value;     /* Expression: 35
                                        * Referenced by: '<Root>/interval_1 in degree'
                                        */
  real_T interval_2indegree_Value;     /* Expression: 10
                                        * Referenced by: '<Root>/interval_2 in degree'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T k1_Gain;                      /* Expression: 1
                                        * Referenced by: '<Root>/k1'
                                        */
  real_T k2_Gain;                      /* Expression: 0
                                        * Referenced by: '<Root>/k2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi/6
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi/6
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Kp_Gain;                      /* Expression: 12.1028
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Kv_Gain;                      /* Expression: -0.001
                                        * Referenced by: '<Root>/Kv'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S4>/gain'
                                        */
  real_T voltage2_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/voltage2'
                                        */
  real_T voltage2_Value_p;             /* Expression: 0
                                        * Referenced by: '<S5>/voltage2'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 10
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -10
                                        * Referenced by: '<S5>/Saturation'
                                        */
  int32_T HILInitialize_CKChannels;    /* Computed Parameter: HILInitialize_CKChannels
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  int32_T HILInitialize_POModes;       /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AIChannels[2];/* Computed Parameter: HILInitialize_AIChannels
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[2];/* Computed Parameter: HILInitialize_AOChannels
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[2];/* Computed Parameter: HILInitialize_EIChannels
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  uint32_T HILReadEncoder_Channels;    /* Computed Parameter: HILReadEncoder_Channels
                                        * Referenced by: '<S4>/HIL Read Encoder'
                                        */
  uint32_T HILReadEncoder1_Channels;   /* Computed Parameter: HILReadEncoder1_Channels
                                        * Referenced by: '<S4>/HIL Read Encoder1'
                                        */
  uint32_T HILWriteAnalog_Channels;    /* Computed Parameter: HILWriteAnalog_Channels
                                        * Referenced by: '<S4>/HIL Write Analog'
                                        */
  uint32_T HILWriteAnalog1_Channels;   /* Computed Parameter: HILWriteAnalog1_Channels
                                        * Referenced by: '<S4>/HIL Write Analog1'
                                        */
  uint8_T q2Switch_CurrentSetting;     /* Computed Parameter: q2Switch_CurrentSetting
                                        * Referenced by: '<Root>/q2 Switch'
                                        */
  uint8_T q2dotSwitch_CurrentSetting;  /* Computed Parameter: q2dotSwitch_CurrentSetting
                                        * Referenced by: '<Root>/q2dot Switch'
                                        */
  boolean_T HILInitialize_Active;      /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKStart;     /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKEnter;     /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S4>/HIL Initialize'
                                        */
  boolean_T HILReadEncoder_Active;     /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<S4>/HIL Read Encoder'
                                        */
  boolean_T HILReadEncoder1_Active;    /* Computed Parameter: HILReadEncoder1_Active
                                        * Referenced by: '<S4>/HIL Read Encoder1'
                                        */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S4>/HIL Write Analog'
                                        */
  boolean_T HILWriteAnalog1_Active;    /* Computed Parameter: HILWriteAnalog1_Active
                                        * Referenced by: '<S4>/HIL Write Analog1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_model2 {
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
    real_T odeY[6];
    real_T odeF[3][6];
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
extern Parameters_model2 model2_P;

/* Block signals (auto storage) */
extern BlockIO_model2 model2_B;

/* Continuous states (auto storage) */
extern ContinuousStates_model2 model2_X;

/* Block states (auto storage) */
extern D_Work_model2 model2_DWork;

/* Model entry point functions */
extern void model2_initialize(void);
extern void model2_step(void);
extern void model2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_model2 *const model2_M;

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
 * '<Root>' : 'model2'
 * '<S1>'   : 'model2/MATLAB Function'
 * '<S2>'   : 'model2/MATLAB Function1'
 * '<S3>'   : 'model2/MATLAB Function2'
 * '<S4>'   : 'model2/Subsystem Real'
 * '<S5>'   : 'model2/Subsytem Simulation'
 * '<S6>'   : 'model2/Subsytem Simulation/Animation'
 * '<S7>'   : 'model2/Subsytem Simulation/MATLAB Function'
 * '<S8>'   : 'model2/Subsytem Simulation/StateMachine'
 */
#endif                                 /* RTW_HEADER_model2_h_ */
