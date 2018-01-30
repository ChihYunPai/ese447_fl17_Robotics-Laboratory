/*
 * untitled.c
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Aug 31 12:44:41 2017
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

/* Block states (auto storage) */
D_Work_untitled untitled_DWork;

/* Real-time model */
RT_MODEL_untitled untitled_M_;
RT_MODEL_untitled *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;

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
      rtb_Saturation = untitled_DWork.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  untitled_B.Gain = untitled_P.Gain_Gain * rtb_Saturation;

  /* Sum: '<S5>/Diff' incorporates:
   *  UnitDelay: '<S5>/UD'
   */
  untitled_B.Diff = untitled_B.Gain - untitled_DWork.UD_DSTATE;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  untitled_B.Compare = (untitled_B.Gain != untitled_P.Constant_Value_l);

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  untitled_B.LogicalOperator1 = ((untitled_B.Diff >= untitled_P.Constant_Value) &&
    untitled_B.Compare);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  untitled_B.Compare_c = (untitled_B.Gain != untitled_P.Constant_Value_g);

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  untitled_B.LogicalOperator = ((untitled_B.Diff < untitled_P.Constant_Value_j) &&
    untitled_B.Compare_c);

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   */
  untitled_B.Add = (int8_T)(((untitled_B.LogicalOperator1 ?
    untitled_P.Gain2_Gain : 0) + (untitled_B.LogicalOperator ?
    untitled_P.Gain1_Gain : 0)) >> 1);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  if (untitled_B.Add > untitled_P.Switch_Threshold) {
    rtb_Saturation = untitled_P.Constant3_Value;
  } else {
    rtb_Saturation = untitled_P.Constant4_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation >= untitled_P.Saturation_UpperSat) {
    rtb_Saturation = untitled_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation <= untitled_P.Saturation_LowerSat) {
      rtb_Saturation = untitled_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: untitled/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(untitled_DWork.HILInitialize_Card,
      &untitled_P.HILWriteAnalog_Channels, 1, &rtb_Saturation);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
    }
  }

  /* Update for UnitDelay: '<S5>/UD' */
  untitled_DWork.UD_DSTATE = untitled_B.Gain;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
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
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.taskTime0 = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled));
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (4039783815U);
  untitled_M->Sizes.checksums[1] = (1843785379U);
  untitled_M->Sizes.checksums[2] = (799954715U);
  untitled_M->Sizes.checksums[3] = (3351565520U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(BlockIO_untitled));

  /* states (dwork) */
  (void) memset((void *)&untitled_DWork, 0,
                sizeof(D_Work_untitled));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
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

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  untitled_DWork.UD_DSTATE = untitled_P.UD_InitialCondition;
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
