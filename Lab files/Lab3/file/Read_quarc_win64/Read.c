/*
 * Read.c
 *
 * Code generation for model "Read".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Sep 26 12:25:42 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Read.h"
#include "Read_private.h"
#include "Read_dt.h"

/* Block signals (auto storage) */
BlockIO_Read Read_B;

/* Block states (auto storage) */
D_Work_Read Read_DWork;

/* Real-time model */
RT_MODEL_Read Read_M_;
RT_MODEL_Read *const Read_M = &Read_M_;

/* Model step function */
void Read_step(void)
{
  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Read/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Read_DWork.HILInitialize_Card,
      &Read_P.HILReadEncoder_Channels, 1, &Read_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Read_M, _rt_error_message);
    } else {
      Read_B.HILReadEncoder = Read_DWork.HILReadEncoder_Buffer;
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

  /* S-Function Block: Read/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Read_DWork.HILInitialize_Card,
      &Read_P.HILReadEncoder1_Channels, 1, &Read_DWork.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Read_M, _rt_error_message);
    } else {
      Read_B.HILReadEncoder1 = Read_DWork.HILReadEncoder1_Buffer;
    }
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, Read_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(Read_M)!=-1) &&
        !((rtmGetTFinal(Read_M)-Read_M->Timing.taskTime0) >
          Read_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Read_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Read_M)) {
      rtmSetErrorStatus(Read_M, "Simulation finished");
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
  if (!(++Read_M->Timing.clockTick0)) {
    ++Read_M->Timing.clockTickH0;
  }

  Read_M->Timing.taskTime0 = Read_M->Timing.clockTick0 *
    Read_M->Timing.stepSize0 + Read_M->Timing.clockTickH0 *
    Read_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Read_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Read_M, 0,
                sizeof(RT_MODEL_Read));
  rtmSetTFinal(Read_M, -1);
  Read_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Read_M->Sizes.checksums[0] = (2071695986U);
  Read_M->Sizes.checksums[1] = (3351330442U);
  Read_M->Sizes.checksums[2] = (3235446174U);
  Read_M->Sizes.checksums[3] = (4092912245U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Read_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Read_M->extModeInfo,
      &Read_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Read_M->extModeInfo, Read_M->Sizes.checksums);
    rteiSetTPtr(Read_M->extModeInfo, rtmGetTPtr(Read_M));
  }

  /* block I/O */
  (void) memset(((void *) &Read_B), 0,
                sizeof(BlockIO_Read));

  /* states (dwork) */
  (void) memset((void *)&Read_DWork, 0,
                sizeof(D_Work_Read));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Read_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Read/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8", "0", &Read_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Read_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((Read_P.HILInitialize_CKPStart && !is_switching) ||
        (Read_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(Read_DWork.HILInitialize_Card, (t_clock *)
        Read_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
        Read_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(Read_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Read_M, _rt_error_message);
      return;
    }

    if ((Read_P.HILInitialize_AIPStart && !is_switching) ||
        (Read_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Read_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Read_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Read_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Read_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_AIChannels, 8U,
        &Read_DWork.HILInitialize_AIMinimums[0],
        &Read_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }

    if ((Read_P.HILInitialize_AOPStart && !is_switching) ||
        (Read_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Read_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Read_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Read_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Read_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_AOChannels, 8U,
        &Read_DWork.HILInitialize_AOMinimums[0],
        &Read_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }

    if ((Read_P.HILInitialize_AOStart && !is_switching) ||
        (Read_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Read_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Read_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_AOChannels, 8U,
        &Read_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }

    if (Read_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Read_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Read_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Read_DWork.HILInitialize_Card, Read_P.HILInitialize_AOChannels, 8U,
         &Read_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }

    if ((Read_P.HILInitialize_EIPStart && !is_switching) ||
        (Read_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &Read_DWork.HILInitialize_QuadratureModes
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Read_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &Read_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency = &Read_DWork.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 8; i1++) {
          dw_FilterFrequency[i1] = Read_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_EIChannels, 8U,
        &Read_DWork.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }

    if ((Read_P.HILInitialize_EIStart && !is_switching) ||
        (Read_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &Read_DWork.HILInitialize_InitialEICounts
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Read_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_EIChannels, 8U,
        &Read_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Read_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Read/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Read_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Read_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Read_P.HILInitialize_AOTerminate && !is_switching) ||
        (Read_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Read_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Read_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Read_DWork.HILInitialize_Card,
        Read_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Read_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Read_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Read_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Read_DWork.HILInitialize_Card);
    hil_close(Read_DWork.HILInitialize_Card);
    Read_DWork.HILInitialize_Card = NULL;
  }
}
