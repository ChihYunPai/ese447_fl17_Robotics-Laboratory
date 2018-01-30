/*
 * connect.c
 *
 * Code generation for model "connect".
 *
 * Model version              : 1.12
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Oct 31 11:51:29 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "connect.h"
#include "connect_private.h"
#include "connect_dt.h"

/* Block signals (auto storage) */
BlockIO_connect connect_B;

/* Continuous states */
ContinuousStates_connect connect_X;

/* Block states (auto storage) */
D_Work_connect connect_DWork;

/* Real-time model */
RT_MODEL_connect connect_M_;
RT_MODEL_connect *const connect_M = &connect_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  connect_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void connect_step(void)
{
  /* local block i/o variables */
  real_T rtb_D;
  real_T rtb_HILReadEncoder;
  real_T rtb_gain;
  real_T rtb_SignalGenerator;
  real_T rtb_Sum1;
  if (rtmIsMajorTimeStep(connect_M)) {
    /* set solver stop time */
    if (!(connect_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&connect_M->solverInfo,
                            ((connect_M->Timing.clockTickH0 + 1) *
        connect_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&connect_M->solverInfo,
                            ((connect_M->Timing.clockTick0 + 1) *
        connect_M->Timing.stepSize0 + connect_M->Timing.clockTickH0 *
        connect_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(connect_M)) {
    connect_M->Timing.t[0] = rtsiGetT(&connect_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(connect_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: connect/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(connect_DWork.HILInitialize_Card,
        &connect_P.HILReadEncoder_Channels, 1,
        &connect_DWork.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = connect_DWork.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/To radius' */
    connect_B.Toradius = connect_P.Toradius_Gain * rtb_HILReadEncoder;

    /* Gain: '<Root>/To degree1' */
    connect_B.Todegree1 = connect_P.Todegree1_Gain * connect_B.Toradius;
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_SignalGenerator = connect_P.SignalGenerator_Frequency *
    connect_M->Timing.t[0];
  if (rtb_SignalGenerator - floor(rtb_SignalGenerator) >= 0.5) {
    rtb_SignalGenerator = connect_P.SignalGenerator_Amplitude;
  } else {
    rtb_SignalGenerator = -connect_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/To degree2' */
  connect_B.Todegree2 = connect_P.Todegree2_Gain * rtb_SignalGenerator;

  /* Sum: '<Root>/Sum' */
  connect_B.Sum = rtb_SignalGenerator - connect_B.Toradius;

  /* Integrator: '<Root>/Integrator' */
  rtb_gain = connect_X.Integrator_CSTATE;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/P'
   */
  rtb_Sum1 = connect_P.P_Gain * connect_B.Sum + rtb_gain;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_gain = connect_P.TransferFcn_C*connect_X.TransferFcn_CSTATE;

  /* Gain: '<Root>/D' */
  rtb_D = connect_P.D_Gain * rtb_gain;

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = connect_M->Timing.t[0];
    real_T timeStampA = connect_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = connect_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &connect_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_gain = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &connect_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &connect_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_gain = (rtb_D - *lastU++) / deltaT;
    }
  }

  /* Gain: '<Root>/gain ' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  rtb_gain = (rtb_Sum1 + rtb_gain) * connect_P.gain_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_gain >= connect_P.Saturation_UpperSat) {
    connect_B.Saturation = connect_P.Saturation_UpperSat;
  } else if (rtb_gain <= connect_P.Saturation_LowerSat) {
    connect_B.Saturation = connect_P.Saturation_LowerSat;
  } else {
    connect_B.Saturation = rtb_gain;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/To degree3' */
  connect_B.Todegree3 = connect_P.Todegree3_Gain * connect_B.Saturation;
  if (rtmIsMajorTimeStep(connect_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: connect/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(connect_DWork.HILInitialize_Card,
        &connect_P.HILWriteAnalog_Channels, 1, &connect_B.Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<Root>/To degree' */
  connect_B.Todegree[0] = connect_P.Todegree_Gain * rtb_SignalGenerator;
  connect_B.Todegree[1] = connect_P.Todegree_Gain * 0.0;
  connect_B.Todegree[2] = connect_P.Todegree_Gain * connect_B.Toradius;
  if (rtmIsMajorTimeStep(connect_M)) {
  }

  /* Gain: '<Root>/I' */
  connect_B.I = connect_P.I_Gain * connect_B.Sum;
  if (rtmIsMajorTimeStep(connect_M)) {
    /* Update for Derivative: '<Root>/Derivative' */
    {
      real_T timeStampA = connect_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = connect_DWork.Derivative_RWORK.TimeStampB;
      real_T* lastTime = &connect_DWork.Derivative_RWORK.TimeStampA;
      real_T* lastU = &connect_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &connect_DWork.Derivative_RWORK.TimeStampB;
          lastU = &connect_DWork.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &connect_DWork.Derivative_RWORK.TimeStampB;
          lastU = &connect_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = connect_M->Timing.t[0];
      *lastU++ = rtb_D;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, connect_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(connect_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((connect_M->Timing.clockTick1+
                            connect_M->Timing.clockTickH1* 4294967296.0)) *
                          0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(connect_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(connect_M)!=-1) &&
          !((rtmGetTFinal(connect_M)-(((connect_M->Timing.clockTick1+
               connect_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((connect_M->Timing.clockTick1+connect_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(connect_M, "Simulation finished");
      }

      if (rtmGetStopRequested(connect_M)) {
        rtmSetErrorStatus(connect_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&connect_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++connect_M->Timing.clockTick0)) {
      ++connect_M->Timing.clockTickH0;
    }

    connect_M->Timing.t[0] = rtsiGetSolverStopTime(&connect_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      connect_M->Timing.clockTick1++;
      if (!connect_M->Timing.clockTick1) {
        connect_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void connect_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  ((StateDerivatives_connect *) connect_M->ModelData.derivs)->Integrator_CSTATE =
    connect_B.I;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives_connect *) connect_M->ModelData.derivs)
      ->TransferFcn_CSTATE = connect_B.Sum;
    ((StateDerivatives_connect *) connect_M->ModelData.derivs)
      ->TransferFcn_CSTATE += (connect_P.TransferFcn_A)*
      connect_X.TransferFcn_CSTATE;
  }
}

/* Model initialize function */
void connect_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)connect_M, 0,
                sizeof(RT_MODEL_connect));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&connect_M->solverInfo, &connect_M->Timing.simTimeStep);
    rtsiSetTPtr(&connect_M->solverInfo, &rtmGetTPtr(connect_M));
    rtsiSetStepSizePtr(&connect_M->solverInfo, &connect_M->Timing.stepSize0);
    rtsiSetdXPtr(&connect_M->solverInfo, &connect_M->ModelData.derivs);
    rtsiSetContStatesPtr(&connect_M->solverInfo,
                         &connect_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&connect_M->solverInfo,
      &connect_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&connect_M->solverInfo, (&rtmGetErrorStatus(connect_M)));
    rtsiSetRTModelPtr(&connect_M->solverInfo, connect_M);
  }

  rtsiSetSimTimeStep(&connect_M->solverInfo, MAJOR_TIME_STEP);
  connect_M->ModelData.intgData.f[0] = connect_M->ModelData.odeF[0];
  connect_M->ModelData.contStates = ((real_T *) &connect_X);
  rtsiSetSolverData(&connect_M->solverInfo, (void *)
                    &connect_M->ModelData.intgData);
  rtsiSetSolverName(&connect_M->solverInfo,"ode1");
  rtmSetTPtr(connect_M, &connect_M->Timing.tArray[0]);
  rtmSetTFinal(connect_M, -1);
  connect_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  connect_M->Sizes.checksums[0] = (3541117751U);
  connect_M->Sizes.checksums[1] = (2883132852U);
  connect_M->Sizes.checksums[2] = (3555833322U);
  connect_M->Sizes.checksums[3] = (3870806889U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    connect_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(connect_M->extModeInfo,
      &connect_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(connect_M->extModeInfo, connect_M->Sizes.checksums);
    rteiSetTPtr(connect_M->extModeInfo, rtmGetTPtr(connect_M));
  }

  /* block I/O */
  (void) memset(((void *) &connect_B), 0,
                sizeof(BlockIO_connect));

  /* states (continuous) */
  {
    (void) memset((void *)&connect_X, 0,
                  sizeof(ContinuousStates_connect));
  }

  /* states (dwork) */
  (void) memset((void *)&connect_DWork, 0,
                sizeof(D_Work_connect));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    connect_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: connect/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &connect_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(connect_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(connect_DWork.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(connect_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(connect_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(connect_M, _rt_error_message);
      return;
    }

    if ((connect_P.HILInitialize_AIPStart && !is_switching) ||
        (connect_P.HILInitialize_AIPEnter && is_switching)) {
      connect_DWork.HILInitialize_AIMinimums[0] = connect_P.HILInitialize_AILow;
      connect_DWork.HILInitialize_AIMinimums[1] = connect_P.HILInitialize_AILow;
      connect_DWork.HILInitialize_AIMaximums[0] = connect_P.HILInitialize_AIHigh;
      connect_DWork.HILInitialize_AIMaximums[1] = connect_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(connect_DWork.HILInitialize_Card,
        connect_P.HILInitialize_AIChannels, 2U,
        &connect_DWork.HILInitialize_AIMinimums[0],
        &connect_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
        return;
      }
    }

    if ((connect_P.HILInitialize_AOPStart && !is_switching) ||
        (connect_P.HILInitialize_AOPEnter && is_switching)) {
      connect_DWork.HILInitialize_AOMinimums[0] = connect_P.HILInitialize_AOLow;
      connect_DWork.HILInitialize_AOMinimums[1] = connect_P.HILInitialize_AOLow;
      connect_DWork.HILInitialize_AOMaximums[0] = connect_P.HILInitialize_AOHigh;
      connect_DWork.HILInitialize_AOMaximums[1] = connect_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(connect_DWork.HILInitialize_Card,
        connect_P.HILInitialize_AOChannels, 2U,
        &connect_DWork.HILInitialize_AOMinimums[0],
        &connect_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
        return;
      }
    }

    if ((connect_P.HILInitialize_AOStart && !is_switching) ||
        (connect_P.HILInitialize_AOEnter && is_switching)) {
      connect_DWork.HILInitialize_AOVoltages[0] =
        connect_P.HILInitialize_AOInitial;
      connect_DWork.HILInitialize_AOVoltages[1] =
        connect_P.HILInitialize_AOInitial;
      result = hil_write_analog(connect_DWork.HILInitialize_Card,
        connect_P.HILInitialize_AOChannels, 2U,
        &connect_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
        return;
      }
    }

    if (connect_P.HILInitialize_AOReset) {
      connect_DWork.HILInitialize_AOVoltages[0] =
        connect_P.HILInitialize_AOWatchdog;
      connect_DWork.HILInitialize_AOVoltages[1] =
        connect_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (connect_DWork.HILInitialize_Card, connect_P.HILInitialize_AOChannels,
         2U, &connect_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
        return;
      }
    }

    if ((connect_P.HILInitialize_EIPStart && !is_switching) ||
        (connect_P.HILInitialize_EIPEnter && is_switching)) {
      connect_DWork.HILInitialize_QuadratureModes[0] =
        connect_P.HILInitialize_EIQuadrature;
      connect_DWork.HILInitialize_QuadratureModes[1] =
        connect_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(connect_DWork.HILInitialize_Card,
        connect_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &connect_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
        return;
      }
    }

    if ((connect_P.HILInitialize_EIStart && !is_switching) ||
        (connect_P.HILInitialize_EIEnter && is_switching)) {
      connect_DWork.HILInitialize_InitialEICounts[0] =
        connect_P.HILInitialize_EIInitial;
      connect_DWork.HILInitialize_InitialEICounts[1] =
        connect_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(connect_DWork.HILInitialize_Card,
        connect_P.HILInitialize_EIChannels, 2U,
        &connect_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  connect_X.Integrator_CSTATE = connect_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  connect_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  connect_DWork.Derivative_RWORK.TimeStampA = rtInf;
  connect_DWork.Derivative_RWORK.TimeStampB = rtInf;
}

/* Model terminate function */
void connect_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: connect/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(connect_DWork.HILInitialize_Card);
    hil_monitor_stop_all(connect_DWork.HILInitialize_Card);
    is_switching = false;
    if ((connect_P.HILInitialize_AOTerminate && !is_switching) ||
        (connect_P.HILInitialize_AOExit && is_switching)) {
      connect_DWork.HILInitialize_AOVoltages[0] =
        connect_P.HILInitialize_AOFinal;
      connect_DWork.HILInitialize_AOVoltages[1] =
        connect_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(connect_DWork.HILInitialize_Card,
        connect_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &connect_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(connect_M, _rt_error_message);
      }
    }

    hil_task_delete_all(connect_DWork.HILInitialize_Card);
    hil_monitor_delete_all(connect_DWork.HILInitialize_Card);
    hil_close(connect_DWork.HILInitialize_Card);
    connect_DWork.HILInitialize_Card = NULL;
  }
}
