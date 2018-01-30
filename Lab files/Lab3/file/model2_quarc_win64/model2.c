/*
 * model2.c
 *
 * Code generation for model "model2".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Sep 26 12:59:57 2017
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

/* Block states (auto storage) */
D_Work_model2 model2_DWork;

/* Real-time model */
RT_MODEL_model2 model2_M_;
RT_MODEL_model2 *const model2_M = &model2_M_;

/* Model step function */
void model2_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder1;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: model2/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(model2_DWork.HILInitialize_Card,
      &model2_P.HILReadEncoder_Channels, 1, &model2_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model2_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = model2_DWork.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  model2_B.Gain = model2_P.Gain_Gain * rtb_HILReadEncoder1;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

  /* S-Function Block: model2/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(model2_DWork.HILInitialize_Card,
      &model2_P.HILReadEncoder1_Channels, 1,
      &model2_DWork.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model2_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = model2_DWork.HILReadEncoder1_Buffer;
    }
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   */
  model2_B.Add = model2_P.Gain2_Gain * rtb_HILReadEncoder1 * model2_P.Gain1_Gain
    + model2_P.Constant_Value;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, model2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(model2_M)!=-1) &&
        !((rtmGetTFinal(model2_M)-model2_M->Timing.taskTime0) >
          model2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(model2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(model2_M)) {
      rtmSetErrorStatus(model2_M, "Simulation finished");
    }
  }

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

  model2_M->Timing.taskTime0 = model2_M->Timing.clockTick0 *
    model2_M->Timing.stepSize0 + model2_M->Timing.clockTickH0 *
    model2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void model2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)model2_M, 0,
                sizeof(RT_MODEL_model2));
  rtmSetTFinal(model2_M, -1);
  model2_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  model2_M->Sizes.checksums[0] = (242253066U);
  model2_M->Sizes.checksums[1] = (1293330689U);
  model2_M->Sizes.checksums[2] = (2329484445U);
  model2_M->Sizes.checksums[3] = (3294570071U);

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
