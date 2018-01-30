/*
 * untitled.c
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Sep 12 10:57:59 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (auto storage) */
BlockIO_untitled untitled_B;

/* Continuous states */
ContinuousStates_untitled untitled_X;

/* Block states (auto storage) */
D_Work_untitled untitled_DWork;

/* Real-time model */
RT_MODEL_untitled untitled_M_;
RT_MODEL_untitled *const untitled_M = &untitled_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  untitled_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  real_T rtb_D;
  real_T rtb_HILReadEncoder;
  real_T rtb_gain;
  real_T rtb_pi;
  real_T rtb_Sum;
  real_T rtb_P;
  real_T rtb_Integrator;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    if (!(untitled_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTickH0 + 1) *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTick0 + 1) *
        untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: untitled/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(untitled_DWork.HILInitialize_Card,
        &untitled_P.HILReadEncoder_Channels, 1,
        &untitled_DWork.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = untitled_DWork.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/To radius' */
    untitled_B.Toradius = untitled_P.Toradius_Gain * rtb_HILReadEncoder;

    /* Gain: '<Root>/To degree1' */
    untitled_B.Todegree1 = untitled_P.Todegree1_Gain * untitled_B.Toradius;
  }

  /* Gain: '<Root>/2pi' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  rtb_pi = (sin(untitled_P.SineWave_Freq * untitled_M->Timing.t[0] +
                untitled_P.SineWave_Phase) * untitled_P.SineWave_Amp +
            untitled_P.SineWave_Bias) * untitled_P.pi_Gain;

  /* Gain: '<Root>/To degree2' */
  untitled_B.Todegree2 = untitled_P.Todegree2_Gain * rtb_pi;

  /* Sum: '<Root>/Sum' */
  rtb_Sum = rtb_pi - untitled_B.Toradius;

  /* Gain: '<Root>/P' */
  rtb_P = untitled_P.P_Gain * rtb_Sum;

  /* Integrator: '<Root>/Integrator' */
  rtb_Integrator = untitled_X.Integrator_CSTATE;

  /* Gain: '<Root>/D' */
  rtb_D = untitled_P.D_Gain * rtb_Sum;

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = untitled_M->Timing.t[0];
    real_T timeStampA = untitled_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = untitled_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &untitled_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_gain = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &untitled_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &untitled_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_gain = (rtb_D - *lastU++) / deltaT;
    }
  }

  /* Gain: '<Root>/gain ' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  rtb_gain = ((rtb_P + rtb_Integrator) + rtb_gain) * untitled_P.gain_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_gain >= untitled_P.Saturation_UpperSat) {
    untitled_B.Saturation = untitled_P.Saturation_UpperSat;
  } else if (rtb_gain <= untitled_P.Saturation_LowerSat) {
    untitled_B.Saturation = untitled_P.Saturation_LowerSat;
  } else {
    untitled_B.Saturation = rtb_gain;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/To degree3' */
  untitled_B.Todegree3 = untitled_P.Todegree3_Gain * untitled_B.Saturation;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: untitled/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(untitled_DWork.HILInitialize_Card,
        &untitled_P.HILWriteAnalog_Channels, 1, &untitled_B.Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<Root>/To degree' */
  untitled_B.Todegree[0] = untitled_P.Todegree_Gain * rtb_pi;
  untitled_B.Todegree[1] = untitled_P.Todegree_Gain * untitled_B.Toradius;
  if (rtmIsMajorTimeStep(untitled_M)) {
  }

  /* Gain: '<Root>/I' */
  untitled_B.I = untitled_P.I_Gain * rtb_Sum;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Update for Derivative: '<Root>/Derivative' */
    {
      real_T timeStampA = untitled_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = untitled_DWork.Derivative_RWORK.TimeStampB;
      real_T* lastTime = &untitled_DWork.Derivative_RWORK.TimeStampA;
      real_T* lastU = &untitled_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &untitled_DWork.Derivative_RWORK.TimeStampB;
          lastU = &untitled_DWork.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &untitled_DWork.Derivative_RWORK.TimeStampB;
          lastU = &untitled_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = untitled_M->Timing.t[0];
      *lastU++ = rtb_D;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, untitled_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(untitled_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((untitled_M->Timing.clockTick1+
                            untitled_M->Timing.clockTickH1* 4294967296.0)) *
                          0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(untitled_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(untitled_M)!=-1) &&
          !((rtmGetTFinal(untitled_M)-(((untitled_M->Timing.clockTick1+
               untitled_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((untitled_M->Timing.clockTick1+untitled_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(untitled_M, "Simulation finished");
      }

      if (rtmGetStopRequested(untitled_M)) {
        rtmSetErrorStatus(untitled_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++untitled_M->Timing.clockTick0)) {
      ++untitled_M->Timing.clockTickH0;
    }

    untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

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
      untitled_M->Timing.clockTick1++;
      if (!untitled_M->Timing.clockTick1) {
        untitled_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  ((StateDerivatives_untitled *) untitled_M->ModelData.derivs)
    ->Integrator_CSTATE = untitled_B.I;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->ModelData.derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo,
                         &untitled_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  untitled_M->ModelData.intgData.f[0] = untitled_M->ModelData.odeF[0];
  untitled_M->ModelData.contStates = ((real_T *) &untitled_X);
  rtsiSetSolverData(&untitled_M->solverInfo, (void *)
                    &untitled_M->ModelData.intgData);
  rtsiSetSolverName(&untitled_M->solverInfo,"ode1");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1107019700U);
  untitled_M->Sizes.checksums[1] = (2536230614U);
  untitled_M->Sizes.checksums[2] = (1144082337U);
  untitled_M->Sizes.checksums[3] = (4273290195U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(BlockIO_untitled));

  /* states (continuous) */
  {
    (void) memset((void *)&untitled_X, 0,
                  sizeof(ContinuousStates_untitled));
  }

  /* states (dwork) */
  (void) memset((void *)&untitled_DWork, 0,
                sizeof(D_Work_untitled));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &untitled_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(untitled_DWork.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(untitled_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    if ((untitled_P.HILInitialize_AIPStart && !is_switching) ||
        (untitled_P.HILInitialize_AIPEnter && is_switching)) {
      untitled_DWork.HILInitialize_AIMinimums[0] =
        untitled_P.HILInitialize_AILow;
      untitled_DWork.HILInitialize_AIMinimums[1] =
        untitled_P.HILInitialize_AILow;
      untitled_DWork.HILInitialize_AIMaximums[0] =
        untitled_P.HILInitialize_AIHigh;
      untitled_DWork.HILInitialize_AIMaximums[1] =
        untitled_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(untitled_DWork.HILInitialize_Card,
        untitled_P.HILInitialize_AIChannels, 2U,
        &untitled_DWork.HILInitialize_AIMinimums[0],
        &untitled_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_AOPStart && !is_switching) ||
        (untitled_P.HILInitialize_AOPEnter && is_switching)) {
      untitled_DWork.HILInitialize_AOMinimums[0] =
        untitled_P.HILInitialize_AOLow;
      untitled_DWork.HILInitialize_AOMinimums[1] =
        untitled_P.HILInitialize_AOLow;
      untitled_DWork.HILInitialize_AOMaximums[0] =
        untitled_P.HILInitialize_AOHigh;
      untitled_DWork.HILInitialize_AOMaximums[1] =
        untitled_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(untitled_DWork.HILInitialize_Card,
        untitled_P.HILInitialize_AOChannels, 2U,
        &untitled_DWork.HILInitialize_AOMinimums[0],
        &untitled_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_AOStart && !is_switching) ||
        (untitled_P.HILInitialize_AOEnter && is_switching)) {
      untitled_DWork.HILInitialize_AOVoltages[0] =
        untitled_P.HILInitialize_AOInitial;
      untitled_DWork.HILInitialize_AOVoltages[1] =
        untitled_P.HILInitialize_AOInitial;
      result = hil_write_analog(untitled_DWork.HILInitialize_Card,
        untitled_P.HILInitialize_AOChannels, 2U,
        &untitled_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if (untitled_P.HILInitialize_AOReset) {
      untitled_DWork.HILInitialize_AOVoltages[0] =
        untitled_P.HILInitialize_AOWatchdog;
      untitled_DWork.HILInitialize_AOVoltages[1] =
        untitled_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (untitled_DWork.HILInitialize_Card, untitled_P.HILInitialize_AOChannels,
         2U, &untitled_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_EIPStart && !is_switching) ||
        (untitled_P.HILInitialize_EIPEnter && is_switching)) {
      untitled_DWork.HILInitialize_QuadratureModes[0] =
        untitled_P.HILInitialize_EIQuadrature;
      untitled_DWork.HILInitialize_QuadratureModes[1] =
        untitled_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(untitled_DWork.HILInitialize_Card,
        untitled_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &untitled_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_EIStart && !is_switching) ||
        (untitled_P.HILInitialize_EIEnter && is_switching)) {
      untitled_DWork.HILInitialize_InitialEICounts[0] =
        untitled_P.HILInitialize_EIInitial;
      untitled_DWork.HILInitialize_InitialEICounts[1] =
        untitled_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(untitled_DWork.HILInitialize_Card,
        untitled_P.HILInitialize_EIChannels, 2U,
        &untitled_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  untitled_X.Integrator_CSTATE = untitled_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  untitled_DWork.Derivative_RWORK.TimeStampA = rtInf;
  untitled_DWork.Derivative_RWORK.TimeStampB = rtInf;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(untitled_DWork.HILInitialize_Card);
    hil_monitor_stop_all(untitled_DWork.HILInitialize_Card);
    is_switching = false;
    if ((untitled_P.HILInitialize_AOTerminate && !is_switching) ||
        (untitled_P.HILInitialize_AOExit && is_switching)) {
      untitled_DWork.HILInitialize_AOVoltages[0] =
        untitled_P.HILInitialize_AOFinal;
      untitled_DWork.HILInitialize_AOVoltages[1] =
        untitled_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(untitled_DWork.HILInitialize_Card,
        untitled_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &untitled_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      }
    }

    hil_task_delete_all(untitled_DWork.HILInitialize_Card);
    hil_monitor_delete_all(untitled_DWork.HILInitialize_Card);
    hil_close(untitled_DWork.HILInitialize_Card);
    untitled_DWork.HILInitialize_Card = NULL;
  }
}
