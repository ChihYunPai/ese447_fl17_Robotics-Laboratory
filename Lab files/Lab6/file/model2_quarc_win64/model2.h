/*
 * model2.h
 *
 * Code generation for model "model2".
 *
 * Model version              : 1.38
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Nov 07 12:32:38 2017
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
  real_T Toradius;                     /* '<S2>/To radius' */
  real_T Toradius1;                    /* '<S2>/To radius1' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T degreetoradius[4];            /* '<S3>/degree to radius' */
  real_T Integrator[4];                /* '<S3>/Integrator' */
  real_T Memory;                       /* '<Root>/Memory' */
  real_T Saturation;                   /* '<S2>/Saturation' */
  real_T Saturation1;                  /* '<S2>/Saturation1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Saturation_p[2];              /* '<S3>/Saturation' */
  real_T Xdot[4];                      /* '<S3>/StateMachine' */
  real_T q2;                           /* '<S3>/MATLAB Function' */
  real_T q2dot;                        /* '<S3>/MATLAB Function' */
  real_T q1_out;                       /* '<S2>/MATLAB Function' */
  real_T q1dot_out;                    /* '<S2>/MATLAB Function' */
  real_T q2_out;                       /* '<S2>/MATLAB Function' */
  real_T q2dot_out;                    /* '<S2>/MATLAB Function' */
  real_T control;                      /* '<Root>/MATLAB Function' */
} BlockIO_model2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[2];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[2];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[2];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[2];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[2];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<S2>/HIL Initialize' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  t_card HILInitialize_Card;           /* '<S2>/HIL Initialize' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                 /* '<S2>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S2>/Derivative' */

  void *HILReadEncoder_PWORK;          /* '<S2>/HIL Read Encoder' */
  void *HILReadEncoder1_PWORK;         /* '<S2>/HIL Read Encoder1' */
  struct {
    void *LoggedData;
  } X_collect_2_PWORK;                 /* '<S2>/X_collect_2 ' */

  void *HILWriteAnalog_PWORK;          /* '<S2>/HIL Write Analog' */
  void *HILWriteAnalog1_PWORK;         /* '<S2>/HIL Write Analog1' */
  struct {
    void *LoggedData;
  } V_collect_2_PWORK;                 /* '<S2>/V_collect_2' */

  struct {
    void *LoggedData;
  } V_PWORK;                           /* '<S3>/V' */

  struct {
    void *LoggedData;
  } X_PWORK;                           /* '<S3>/X' */

  int32_T HILInitialize_ClockModes;    /* '<S2>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<S2>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<S2>/HIL Initialize' */
  int32_T HILReadEncoder_Buffer;       /* '<S2>/HIL Read Encoder' */
  int32_T HILReadEncoder1_Buffer;      /* '<S2>/HIL Read Encoder1' */
  int32_T sfEvent;                     /* '<S3>/StateMachine' */
  int32_T sfEvent_m;                   /* '<S3>/MATLAB Function' */
  int32_T sfEvent_p;                   /* '<S3>/Animation' */
  int32_T sfEvent_g;                   /* '<S2>/MATLAB Function' */
  int32_T sfEvent_l;                   /* '<Root>/MATLAB Function' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S3>/Integrator' */

  uint8_T is_active_c3_model2;         /* '<S3>/StateMachine' */
  uint8_T is_active_c4_model2;         /* '<S3>/MATLAB Function' */
  uint8_T is_active_c1_model2;         /* '<S3>/Animation' */
  uint8_T is_active_c5_model2;         /* '<S2>/MATLAB Function' */
  uint8_T is_active_c2_model2;         /* '<Root>/MATLAB Function' */
  boolean_T isStable;                  /* '<S3>/StateMachine' */
  boolean_T doneDoubleBufferReInit;    /* '<S3>/StateMachine' */
  boolean_T isStable_c;                /* '<S3>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S3>/MATLAB Function' */
  boolean_T isStable_e;                /* '<S3>/Animation' */
  boolean_T doneDoubleBufferReInit_lo; /* '<S3>/Animation' */
  boolean_T isStable_o;                /* '<S2>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S2>/MATLAB Function' */
  boolean_T isStable_b;                /* '<Root>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_h;  /* '<Root>/MATLAB Function' */
} D_Work_model2;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S2>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<S2>/Transfer Fcn' */
  real_T Integrator_CSTATE[4];         /* '<S3>/Integrator' */
} ContinuousStates_model2;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S2>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<S2>/Transfer Fcn' */
  real_T Integrator_CSTATE[4];         /* '<S3>/Integrator' */
} StateDerivatives_model2;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S2>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE;        /* '<S2>/Transfer Fcn' */
  boolean_T Integrator_CSTATE[4];      /* '<S3>/Integrator' */
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
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T Toradius_Gain;                /* Expression: -2*pi/4096
                                        * Referenced by: '<S2>/To radius'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S2>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S2>/Transfer Fcn1'
                                        */
  real_T Toradius1_Gain;               /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/To radius1'
                                        */
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  real_T q1_Value;                     /* Expression: 0
                                        * Referenced by: '<S3>/q1'
                                        */
  real_T q1dot_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/q1dot'
                                        */
  real_T q3_Value;                     /* Expression: 180
                                        * Referenced by: '<S3>/q3'
                                        */
  real_T q2dot1_Value;                 /* Expression: 0
                                        * Referenced by: '<S3>/q2dot1'
                                        */
  real_T degreetoradius_Gain;          /* Expression: pi/180
                                        * Referenced by: '<S3>/degree to radius'
                                        */
  real_T interval_1indegree_Value;     /* Expression: 25
                                        * Referenced by: '<Root>/interval_1 in degree'
                                        */
  real_T interval_2indegree_Value;     /* Expression: 10
                                        * Referenced by: '<Root>/interval_2 in degree'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T voltage2_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/voltage2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 10
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -10
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T voltage2_Value_p;             /* Expression: 0
                                        * Referenced by: '<S3>/voltage2'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 10
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -10
                                        * Referenced by: '<S3>/Saturation'
                                        */
  int32_T HILInitialize_CKChannels;    /* Computed Parameter: HILInitialize_CKChannels
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  int32_T HILInitialize_POModes;       /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AIChannels[2];/* Computed Parameter: HILInitialize_AIChannels
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[2];/* Computed Parameter: HILInitialize_AOChannels
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[2];/* Computed Parameter: HILInitialize_EIChannels
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  uint32_T HILReadEncoder_Channels;    /* Computed Parameter: HILReadEncoder_Channels
                                        * Referenced by: '<S2>/HIL Read Encoder'
                                        */
  uint32_T HILReadEncoder1_Channels;   /* Computed Parameter: HILReadEncoder1_Channels
                                        * Referenced by: '<S2>/HIL Read Encoder1'
                                        */
  uint32_T HILWriteAnalog_Channels;    /* Computed Parameter: HILWriteAnalog_Channels
                                        * Referenced by: '<S2>/HIL Write Analog'
                                        */
  uint32_T HILWriteAnalog1_Channels;   /* Computed Parameter: HILWriteAnalog1_Channels
                                        * Referenced by: '<S2>/HIL Write Analog1'
                                        */
  uint8_T q2Switch_CurrentSetting;     /* Computed Parameter: q2Switch_CurrentSetting
                                        * Referenced by: '<Root>/q2 Switch'
                                        */
  uint8_T q2dotSwitch_CurrentSetting;  /* Computed Parameter: q2dotSwitch_CurrentSetting
                                        * Referenced by: '<Root>/q2dot Switch'
                                        */
  boolean_T HILInitialize_Active;      /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKStart;     /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKEnter;     /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  boolean_T HILReadEncoder_Active;     /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<S2>/HIL Read Encoder'
                                        */
  boolean_T HILReadEncoder1_Active;    /* Computed Parameter: HILReadEncoder1_Active
                                        * Referenced by: '<S2>/HIL Read Encoder1'
                                        */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S2>/HIL Write Analog'
                                        */
  boolean_T HILWriteAnalog1_Active;    /* Computed Parameter: HILWriteAnalog1_Active
                                        * Referenced by: '<S2>/HIL Write Analog1'
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
 * '<S2>'   : 'model2/Subsystem Real'
 * '<S3>'   : 'model2/Subsytem Simulation'
 * '<S4>'   : 'model2/Subsystem Real/MATLAB Function'
 * '<S5>'   : 'model2/Subsytem Simulation/Animation'
 * '<S6>'   : 'model2/Subsytem Simulation/MATLAB Function'
 * '<S7>'   : 'model2/Subsytem Simulation/StateMachine'
 */
#endif                                 /* RTW_HEADER_model2_h_ */
