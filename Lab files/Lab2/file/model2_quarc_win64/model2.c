/*
 * model2.c
 *
 * Code generation for model "model2".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Sep 07 13:11:09 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "model2.h"
#include "model2_private.h"
#include "model2_dt.h"

/* Block signals (auto storage) */
BlockIO_model2 model2_B;

/* Continuous states */
ContinuousStates_model2 model2_X;

/* Block states (auto storage) */
D_Work_model2 model2_DWork;

/* Real-time model */
RT_MODEL_model2 model2_M_;
RT_MODEL_model2 *const model2_M = &model2_M_;

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
  model2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void model2_step(void)
{
  /* local block i/o variables */
  real_T rtb_D;
  real_T rtb_HILReadEncoder;
  real_T rtb_gain;
  real_T rtb_SignalGenerator;
  real_T rtb_Sum1;
  if (rtmIsMajorTimeStep(model2_M)) {
    /* set solver stop time */
    if (!(model2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model2_M->solverInfo,
                            ((model2_M->Timing.clockTickH0 + 1) *
        model2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model2_M->solverInfo, ((model2_M->Timing.clockTick0
        + 1) * model2_M->Timing.stepSize0 + model2_M->Timing.clockTickH0 *
        model2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model2_M)) {
    model2_M->Timing.t[0] = rtsiGetT(&model2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(model2_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: model2/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(model2_DWork.HILInitialize_Card,
        &model2_P.HILReadEncoder_Channels, 1,
        &model2_DWork.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = model2_DWork.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/To radius' */
    model2_B.Toradius = model2_P.Toradius_Gain * rtb_HILReadEncoder;

    /* Gain: '<Root>/To degree1' */
    model2_B.Todegree1 = model2_P.Todegree1_Gain * model2_B.Toradius;
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_SignalGenerator = model2_P.SignalGenerator_Frequency * model2_M->Timing.t
    [0];
  if (rtb_SignalGenerator - floor(rtb_SignalGenerator) >= 0.5) {
    rtb_SignalGenerator = model2_P.SignalGenerator_Amplitude;
  } else {
    rtb_SignalGenerator = -model2_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/To degree2' */
  model2_B.Todegree2 = model2_P.Todegree2_Gain * rtb_SignalGenerator;

  /* Sum: '<Root>/Sum' */
  model2_B.Sum = rtb_SignalGenerator - model2_B.Toradius;

  /* Integrator: '<Root>/Integrator' */
  rtb_gain = model2_X.Integrator_CSTATE;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/P'
   */
  rtb_Sum1 = model2_P.P_Gain * model2_B.Sum + rtb_gain;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_gain = model2_P.TransferFcn_C*model2_X.TransferFcn_CSTATE;

  /* Gain: '<Root>/D' */
  rtb_D = model2_P.D_Gain * rtb_gain;

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = model2_M->Timing.t[0];
    real_T timeStampA = model2_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = model2_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_gain = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_gain = (rtb_D - *lastU++) / deltaT;
    }
  }

  /* Gain: '<Root>/gain ' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  rtb_gain = (rtb_Sum1 + rtb_gain) * model2_P.gain_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_gain >= model2_P.Saturation_UpperSat) {
    model2_B.Saturation = model2_P.Saturation_UpperSat;
  } else if (rtb_gain <= model2_P.Saturation_LowerSat) {
    model2_B.Saturation = model2_P.Saturation_LowerSat;
  } else {
    model2_B.Saturation = rtb_gain;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/To degree3' */
  model2_B.Todegree3 = model2_P.Todegree3_Gain * model2_B.Saturation;
  if (rtmIsMajorTimeStep(model2_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: model2/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(model2_DWork.HILInitialize_Card,
        &model2_P.HILWriteAnalog_Channels, 1, &model2_B.Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<Root>/To degree' */
  model2_B.Todegree[0] = model2_P.Todegree_Gain * rtb_SignalGenerator;
  model2_B.Todegree[1] = model2_P.Todegree_Gain * 0.0;
  model2_B.Todegree[2] = model2_P.Todegree_Gain * model2_B.Toradius;
  if (rtmIsMajorTimeStep(model2_M)) {
  }

  /* Gain: '<Root>/I' */
  model2_B.I = model2_P.I_Gain * model2_B.Sum;
  if (rtmIsMajorTimeStep(model2_M)) {
    /* Update for Derivative: '<Root>/Derivative' */
    {
      real_T timeStampA = model2_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = model2_DWork.Derivative_RWORK.TimeStampB;
      real_T* lastTime = &model2_DWork.Derivative_RWORK.TimeStampA;
      real_T* lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &model2_DWork.Derivative_RWORK.TimeStampB;
          lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &model2_DWork.Derivative_RWORK.TimeStampB;
          lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = model2_M->Timing.t[0];
      *lastU++ = rtb_D;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, model2_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(model2_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((model2_M->Timing.clockTick1+
                            model2_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(model2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(model2_M)!=-1) &&
          !((rtmGetTFinal(model2_M)-(((model2_M->Timing.clockTick1+
               model2_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((model2_M->Timing.clockTick1+model2_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(model2_M, "Simulation finished");
      }

      if (rtmGetStopRequested(model2_M)) {
        rtmSetErrorStatus(model2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&model2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++model2_M->Timing.clockTick0)) {
      ++model2_M->Timing.clockTickH0;
    }

    model2_M->Timing.t[0] = rtsiGetSolverStopTime(&model2_M->solverInfo);

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
      model2_M->Timing.clockTick1++;
      if (!model2_M->Timing.clockTick1) {
        model2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void model2_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->Integrator_CSTATE =
    model2_B.I;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->TransferFcn_CSTATE
      = model2_B.Sum;
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->TransferFcn_CSTATE
      += (model2_P.TransferFcn_A)*model2_X.TransferFcn_CSTATE;
  }
}

/* Model initialize function */
void model2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model2_M, 0,
                sizeof(RT_MODEL_model2));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model2_M->solverInfo, &model2_M->Timing.simTimeStep);
    rtsiSetTPtr(&model2_M->solverInfo, &rtmGetTPtr(model2_M));
    rtsiSetStepSizePtr(&model2_M->solverInfo, &model2_M->Timing.stepSize0);
    rtsiSetdXPtr(&model2_M->solverInfo, &model2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&model2_M->solverInfo, &model2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&model2_M->solverInfo,
      &model2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&model2_M->solverInfo, (&rtmGetErrorStatus(model2_M)));
    rtsiSetRTModelPtr(&model2_M->solverInfo, model2_M);
  }

  rtsiSetSimTimeStep(&model2_M->solverInfo, MAJOR_TIME_STEP);
  model2_M->ModelData.intgData.f[0] = model2_M->ModelData.odeF[0];
  model2_M->ModelData.contStates = ((real_T *) &model2_X);
  rtsiSetSolverData(&model2_M->solverInfo, (void *)&model2_M->ModelData.intgData);
  rtsiSetSolverName(&model2_M->solverInfo,"ode1");
  rtmSetTPtr(model2_M, &model2_M->Timing.tArray[0]);
  rtmSetTFinal(model2_M, -1);
  model2_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  model2_M->Sizes.checksums[0] = (2744334598U);
  model2_M->Sizes.checksums[1] = (2965170420U);
  model2_M->Sizes.checksums[2] = (3371437042U);
  model2_M->Sizes.checksums[3] = (3630979061U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    model2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model2_M->extModeInfo,
      &model2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model2_M->extModeInfo, model2_M->Sizes.checksums);
    rteiSetTPtr(model2_M->extModeInfo, rtmGetTPtr(model2_M));
  }

  /* block I/O */
  (void) memset(((void *) &model2_B), 0,
                sizeof(BlockIO_model2));

  /* states (continuous) */
  {
    (void) memset((void *)&model2_X, 0,
                  sizeof(ContinuousStates_model2));
  }

  /* states (dwork) */
  (void) memset((void *)&model2_DWork, 0,
                sizeof(D_Work_model2));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: model2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &model2_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(model2_DWork.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(model2_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model2_M, _rt_error_message);
      return;
    }

    if ((model2_P.HILInitialize_AIPStart && !is_switching) ||
        (model2_P.HILInitialize_AIPEnter && is_switching)) {
      model2_DWork.HILInitialize_AIMinimums[0] = model2_P.HILInitialize_AILow;
      model2_DWork.HILInitialize_AIMinimums[1] = model2_P.HILInitialize_AILow;
      model2_DWork.HILInitialize_AIMaximums[0] = model2_P.HILInitialize_AIHigh;
      model2_DWork.HILInitialize_AIMaximums[1] = model2_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(model2_DWork.HILInitialize_Card,
        model2_P.HILInitialize_AIChannels, 2U,
        &model2_DWork.HILInitialize_AIMinimums[0],
        &model2_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
        return;
      }
    }

    if ((model2_P.HILInitialize_AOPStart && !is_switching) ||
        (model2_P.HILInitialize_AOPEnter && is_switching)) {
      model2_DWork.HILInitialize_AOMinimums[0] = model2_P.HILInitialize_AOLow;
      model2_DWork.HILInitialize_AOMinimums[1] = model2_P.HILInitialize_AOLow;
      model2_DWork.HILInitialize_AOMaximums[0] = model2_P.HILInitialize_AOHigh;
      model2_DWork.HILInitialize_AOMaximums[1] = model2_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(model2_DWork.HILInitialize_Card,
        model2_P.HILInitialize_AOChannels, 2U,
        &model2_DWork.HILInitialize_AOMinimums[0],
        &model2_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
        return;
      }
    }

    if ((model2_P.HILInitialize_AOStart && !is_switching) ||
        (model2_P.HILInitialize_AOEnter && is_switching)) {
      model2_DWork.HILInitialize_AOVoltages[0] =
        model2_P.HILInitialize_AOInitial;
      model2_DWork.HILInitialize_AOVoltages[1] =
        model2_P.HILInitialize_AOInitial;
      result = hil_write_analog(model2_DWork.HILInitialize_Card,
        model2_P.HILInitialize_AOChannels, 2U,
        &model2_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
        return;
      }
    }

    if (model2_P.HILInitialize_AOReset) {
      model2_DWork.HILInitialize_AOVoltages[0] =
        model2_P.HILInitialize_AOWatchdog;
      model2_DWork.HILInitialize_AOVoltages[1] =
        model2_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (model2_DWork.HILInitialize_Card, model2_P.HILInitialize_AOChannels, 2U,
         &model2_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
        return;
      }
    }

    if ((model2_P.HILInitialize_EIPStart && !is_switching) ||
        (model2_P.HILInitialize_EIPEnter && is_switching)) {
      model2_DWork.HILInitialize_QuadratureModes[0] =
        model2_P.HILInitialize_EIQuadrature;
      model2_DWork.HILInitialize_QuadratureModes[1] =
        model2_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(model2_DWork.HILInitialize_Card,
        model2_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &model2_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
        return;
      }
    }

    if ((model2_P.HILInitialize_EIStart && !is_switching) ||
        (model2_P.HILInitialize_EIEnter && is_switching)) {
      model2_DWork.HILInitialize_InitialEICounts[0] =
        model2_P.HILInitialize_EIInitial;
      model2_DWork.HILInitialize_InitialEICounts[1] =
        model2_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(model2_DWork.HILInitialize_Card,
        model2_P.HILInitialize_EIChannels, 2U,
        &model2_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  model2_X.Integrator_CSTATE = model2_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  model2_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  model2_DWork.Derivative_RWORK.TimeStampA = rtInf;
  model2_DWork.Derivative_RWORK.TimeStampB = rtInf;
}

/* Model terminate function */
void model2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: model2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(model2_DWork.HILInitialize_Card);
    hil_monitor_stop_all(model2_DWork.HILInitialize_Card);
    is_switching = false;
    if ((model2_P.HILInitialize_AOTerminate && !is_switching) ||
        (model2_P.HILInitialize_AOExit && is_switching)) {
      model2_DWork.HILInitialize_AOVoltages[0] = model2_P.HILInitialize_AOFinal;
      model2_DWork.HILInitialize_AOVoltages[1] = model2_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(model2_DWork.HILInitialize_Card,
        model2_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &model2_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
      }
    }

    hil_task_delete_all(model2_DWork.HILInitialize_Card);
    hil_monitor_delete_all(model2_DWork.HILInitialize_Card);
    hil_close(model2_DWork.HILInitialize_Card);
    model2_DWork.HILInitialize_Card = NULL;
  }
}
