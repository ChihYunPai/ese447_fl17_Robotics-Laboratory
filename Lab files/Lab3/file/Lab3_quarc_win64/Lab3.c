/*
 * Lab3.c
 *
 * Code generation for model "Lab3".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Sep 26 11:47:51 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Lab3.h"
#include "Lab3_private.h"
#include "Lab3_dt.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define Lab3_CALL_EVENT                (-1)

/* Block signals (auto storage) */
BlockIO_Lab3 Lab3_B;

/* Block states (auto storage) */
D_Work_Lab3 Lab3_DWork;

/* Real-time model */
RT_MODEL_Lab3 Lab3_M_;
RT_MODEL_Lab3 *const Lab3_M = &Lab3_M_;

/* Model step function */
void Lab3_step(void)
{
  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Lab3/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Lab3_DWork.HILInitialize_Card,
      &Lab3_P.HILReadEncoder_Channels, 1, &Lab3_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab3_M, _rt_error_message);
    } else {
      Lab3_B.HILReadEncoder = Lab3_DWork.HILReadEncoder_Buffer;
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

  /* S-Function Block: Lab3/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Lab3_DWork.HILInitialize_Card,
      &Lab3_P.HILReadEncoder1_Channels, 1, &Lab3_DWork.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab3_M, _rt_error_message);
    } else {
      Lab3_B.HILReadEncoder1 = Lab3_DWork.HILReadEncoder1_Buffer;
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  Lab3_DWork.sfEvent = Lab3_CALL_EVENT;

  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:4' */
  /*  [x,y,z] = sphere */
  /*  r = sqrt(12^2 + 8^2); */
  /*  x = x(1:end,:); */
  /*  y = y(1:end,:); */
  /*  z = z(1:end,:); */
  /*  surf(r.*x, r.*y, r.*z); */
  /*  axis equal */
  /* % Spherical coordinate: */
  /*  title('Task-6: Robot work space plot - compare');  */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, Lab3_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(Lab3_M)!=-1) &&
        !((rtmGetTFinal(Lab3_M)-Lab3_M->Timing.taskTime0) >
          Lab3_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Lab3_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Lab3_M)) {
      rtmSetErrorStatus(Lab3_M, "Simulation finished");
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
  if (!(++Lab3_M->Timing.clockTick0)) {
    ++Lab3_M->Timing.clockTickH0;
  }

  Lab3_M->Timing.taskTime0 = Lab3_M->Timing.clockTick0 *
    Lab3_M->Timing.stepSize0 + Lab3_M->Timing.clockTickH0 *
    Lab3_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Lab3_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Lab3_M, 0,
                sizeof(RT_MODEL_Lab3));
  rtmSetTFinal(Lab3_M, -1);
  Lab3_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Lab3_M->Sizes.checksums[0] = (1598216112U);
  Lab3_M->Sizes.checksums[1] = (2037959162U);
  Lab3_M->Sizes.checksums[2] = (1527321212U);
  Lab3_M->Sizes.checksums[3] = (341368522U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Lab3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lab3_M->extModeInfo,
      &Lab3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lab3_M->extModeInfo, Lab3_M->Sizes.checksums);
    rteiSetTPtr(Lab3_M->extModeInfo, rtmGetTPtr(Lab3_M));
  }

  /* block I/O */
  (void) memset(((void *) &Lab3_B), 0,
                sizeof(BlockIO_Lab3));

  /* states (dwork) */
  (void) memset((void *)&Lab3_DWork, 0,
                sizeof(D_Work_Lab3));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lab3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab3/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8", "0", &Lab3_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((Lab3_P.HILInitialize_CKPStart && !is_switching) ||
        (Lab3_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(Lab3_DWork.HILInitialize_Card, (t_clock *)
        Lab3_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
        Lab3_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(Lab3_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab3_M, _rt_error_message);
      return;
    }

    if ((Lab3_P.HILInitialize_AIPStart && !is_switching) ||
        (Lab3_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Lab3_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Lab3_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Lab3_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Lab3_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_AIChannels, 8U,
        &Lab3_DWork.HILInitialize_AIMinimums[0],
        &Lab3_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }

    if ((Lab3_P.HILInitialize_AOPStart && !is_switching) ||
        (Lab3_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Lab3_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Lab3_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Lab3_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Lab3_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_AOChannels, 8U,
        &Lab3_DWork.HILInitialize_AOMinimums[0],
        &Lab3_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }

    if ((Lab3_P.HILInitialize_AOStart && !is_switching) ||
        (Lab3_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab3_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab3_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_AOChannels, 8U,
        &Lab3_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }

    if (Lab3_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab3_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab3_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Lab3_DWork.HILInitialize_Card, Lab3_P.HILInitialize_AOChannels, 8U,
         &Lab3_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }

    if ((Lab3_P.HILInitialize_EIPStart && !is_switching) ||
        (Lab3_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &Lab3_DWork.HILInitialize_QuadratureModes
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Lab3_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &Lab3_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency = &Lab3_DWork.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 8; i1++) {
          dw_FilterFrequency[i1] = Lab3_P.HILInitialize_EIFrequency;
        }
      }

      result = hil_set_encoder_filter_frequency(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_EIChannels, 8U,
        &Lab3_DWork.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }

    if ((Lab3_P.HILInitialize_EIStart && !is_switching) ||
        (Lab3_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &Lab3_DWork.HILInitialize_InitialEICounts
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Lab3_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_EIChannels, 8U,
        &Lab3_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function' */
  Lab3_DWork.sfEvent = Lab3_CALL_EVENT;
  Lab3_DWork.is_active_c2_Lab3 = 0U;
}

/* Model terminate function */
void Lab3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab3/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Lab3_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Lab3_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Lab3_P.HILInitialize_AOTerminate && !is_switching) ||
        (Lab3_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab3_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab3_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Lab3_DWork.HILInitialize_Card,
        Lab3_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Lab3_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab3_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Lab3_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Lab3_DWork.HILInitialize_Card);
    hil_close(Lab3_DWork.HILInitialize_Card);
    Lab3_DWork.HILInitialize_Card = NULL;
  }
}
