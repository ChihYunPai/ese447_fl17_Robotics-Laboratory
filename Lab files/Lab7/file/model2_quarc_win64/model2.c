/*
 * model2.c
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
#include "model2.h"
#include "model2_private.h"
#include "model2_dt.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define model2_CALL_EVENT              (-1)

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
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  model2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  model2_step();
  model2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  model2_step();
  model2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u;
  int32_T u_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u = 1;
    } else {
      u = -1;
    }

    if (u1 > 0.0) {
      u_0 = 1;
    } else {
      u_0 = -1;
    }

    y = atan2((real_T)u, (real_T)u_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void model2_step(void)
{
  /* local block i/o variables */
  real_T rtb_TransferFcn1;
  real_T rtb_Derivative1;
  real_T rtb_TransferFcn;
  real_T rtb_Derivative;
  real_T rtb_HILReadEncoder1;
  real_T point_c;
  real_T point_d;
  int32_T currentState;
  real_T M[4];
  real_T B[2];
  int32_T r;
  real_T rtb_q2Switch;
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
  }

  /* TransferFcn: '<S4>/Transfer Fcn1' */
  rtb_TransferFcn1 = model2_P.TransferFcn1_C*model2_X.TransferFcn1_CSTATE;

  /* Derivative: '<S4>/Derivative1' */
  {
    real_T t = model2_M->Timing.t[0];
    real_T timeStampA = model2_DWork.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = model2_DWork.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &model2_DWork.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative1 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &model2_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &model2_DWork.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Derivative1 = (rtb_TransferFcn1 - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(model2_M)) {
    /* S-Function (hil_read_encoder_block): '<S4>/HIL Read Encoder' */

    /* S-Function Block: model2/Subsystem Real/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(model2_DWork.HILInitialize_Card,
        &model2_P.HILReadEncoder_Channels, 1,
        &model2_DWork.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder1 = model2_DWork.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<S4>/To radius' */
    model2_B.Toradius = model2_P.Toradius_Gain * rtb_HILReadEncoder1;
  }

  /* TransferFcn: '<S4>/Transfer Fcn' */
  rtb_TransferFcn = model2_P.TransferFcn_C*model2_X.TransferFcn_CSTATE;

  /* Derivative: '<S4>/Derivative' */
  {
    real_T t = model2_M->Timing.t[0];
    real_T timeStampA = model2_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = model2_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &model2_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative = 0.0;
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
      rtb_Derivative = (rtb_TransferFcn - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(model2_M)) {
    /* S-Function (hil_read_encoder_block): '<S4>/HIL Read Encoder1' */

    /* S-Function Block: model2/Subsystem Real/HIL Read Encoder1 (hil_read_encoder_block) */
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

    /* Gain: '<S4>/To radius1' */
    model2_B.Toradius1 = model2_P.Toradius1_Gain * rtb_HILReadEncoder1;

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     */
    model2_B.Sum = model2_B.Toradius1 + model2_P.Constant_Value;

    /* Gain: '<S5>/degree to radius' incorporates:
     *  Constant: '<S5>/q1'
     *  Constant: '<S5>/q1dot'
     *  Constant: '<S5>/q2dot1'
     *  Constant: '<S5>/q3'
     */
    model2_B.degreetoradius[0] = model2_P.degreetoradius_Gain *
      model2_P.q1_Value;
    model2_B.degreetoradius[1] = model2_P.degreetoradius_Gain *
      model2_P.q1dot_Value;
    model2_B.degreetoradius[2] = model2_P.degreetoradius_Gain *
      model2_P.q3_Value;
    model2_B.degreetoradius[3] = model2_P.degreetoradius_Gain *
      model2_P.q2dot1_Value;
  }

  /* Integrator: '<S5>/Integrator' */
  if (model2_DWork.Integrator_IWORK.IcNeedsLoading) {
    model2_X.Integrator_CSTATE[0] = model2_B.degreetoradius[0];
    model2_X.Integrator_CSTATE[1] = model2_B.degreetoradius[1];
    model2_X.Integrator_CSTATE[2] = model2_B.degreetoradius[2];
    model2_X.Integrator_CSTATE[3] = model2_B.degreetoradius[3];
  }

  model2_B.Integrator[0] = model2_X.Integrator_CSTATE[0];
  model2_B.Integrator[1] = model2_X.Integrator_CSTATE[1];
  model2_B.Integrator[2] = model2_X.Integrator_CSTATE[2];
  model2_B.Integrator[3] = model2_X.Integrator_CSTATE[3];

  /* MATLAB Function: '<S5>/MATLAB Function' */
  model2_DWork.sfEvent_m = model2_CALL_EVENT;

  /* MATLAB Function 'Subsytem Simulation/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:3' */
  model2_B.q2 = model2_B.Integrator[2];

  /* '<S7>:1:4' */
  model2_B.q2dot = model2_B.Integrator[3];

  /* ManualSwitch: '<Root>/q2 Switch' */
  if (model2_P.q2Switch_CurrentSetting == 1) {
    rtb_q2Switch = model2_B.q2;
  } else {
    rtb_q2Switch = model2_B.Sum;
  }

  /* End of ManualSwitch: '<Root>/q2 Switch' */

  /* ManualSwitch: '<Root>/q2dot Switch' */
  if (model2_P.q2dotSwitch_CurrentSetting == 1) {
    model2_B.q2dotSwitch = model2_B.q2dot;
  } else {
    model2_B.q2dotSwitch = rtb_Derivative;
  }

  /* End of ManualSwitch: '<Root>/q2dot Switch' */
  if (rtmIsMajorTimeStep(model2_M)) {
    /* Memory: '<Root>/Memory' */
    model2_B.Memory = model2_DWork.Memory_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/interval_1 in degree'
   *  Constant: '<Root>/interval_2 in degree'
   */
  model2_DWork.sfEvent_l = model2_CALL_EVENT;

  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /*  interval_1 = 25; */
  /*  interval_2 = 10; */
  /* '<S1>:1:4' */
  /* '<S1>:1:5' */
  rtb_q2Switch = rt_atan2d_snf(sin(rtb_q2Switch - 3.1415926535897931), cos
    (rtb_q2Switch - 3.1415926535897931));

  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /* '<S1>:1:9' */
  point_c = -model2_P.interval_2indegree_Value * 3.1415926535897931 / 180.0;

  /* '<S1>:1:10' */
  point_d = model2_P.interval_2indegree_Value * 3.1415926535897931 / 180.0;
  if ((rtb_q2Switch > point_c) && (rtb_q2Switch < point_d)) {
    /* '<S1>:1:13' */
    /* '<S1>:1:14' */
    currentState = 1;
  } else if (((rtb_q2Switch > point_d) && (rtb_q2Switch < (180.0 -
                model2_P.interval_1indegree_Value) * 3.1415926535897931 / 180.0))
             || ((rtb_q2Switch > (-180.0 + model2_P.interval_1indegree_Value) *
                  3.1415926535897931 / 180.0) && (rtb_q2Switch < point_c))) {
    /* '<S1>:1:15' */
    /* '<S1>:1:16' */
    currentState = 2;
  } else {
    /* '<S1>:1:18' */
    currentState = 3;
  }

  if ((model2_B.Memory == 1.0) && (currentState == 3)) {
    /* '<S1>:1:21' */
    /* '<S1>:1:22' */
    model2_B.control = 3.0;
  } else if ((model2_B.Memory == 2.0) && (currentState == 1) && (fabs
              (model2_B.q2dotSwitch) < 0.5)) {
    /* '<S1>:1:23' */
    /* '<S1>:1:24' */
    model2_B.control = 1.0;
  } else if ((model2_B.Memory == 3.0) && (currentState == 2)) {
    /* '<S1>:1:25' */
    /* '<S1>:1:26' */
    model2_B.control = 2.0;
  } else {
    /* '<S1>:1:28' */
    model2_B.control = model2_B.Memory;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  if (rtmIsMajorTimeStep(model2_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function1' */
    model2_DWork.sfEvent_f = model2_CALL_EVENT;

    /* MATLAB Function 'MATLAB Function1': '<S2>:1' */
    /* '<S2>:1:2' */
    /* '<S2>:1:3' */
    model2_B.output = rt_atan2d_snf(sin(model2_B.Sum - 3.1415926535897931), cos
      (model2_B.Sum - 3.1415926535897931));

    /* Gain: '<Root>/k1' */
    model2_B.k1 = model2_P.k1_Gain * model2_B.output;
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<Root>/k2'
   */
  model2_B.Sum2 = model2_P.k2_Gain * rtb_Derivative + model2_B.k1;

  /* Saturate: '<Root>/Saturation1' */
  if (model2_B.Sum2 >= model2_P.Saturation1_UpperSat) {
    model2_B.Saturation1 = model2_P.Saturation1_UpperSat;
  } else if (model2_B.Sum2 <= model2_P.Saturation1_LowerSat) {
    model2_B.Saturation1 = model2_P.Saturation1_LowerSat;
  } else {
    model2_B.Saturation1 = model2_B.Sum2;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Kp'
   *  Gain: '<Root>/Kv'
   *  Sum: '<Root>/Sum'
   */
  model2_B.Sum1 = (model2_B.Saturation1 - model2_B.Toradius) * model2_P.Kp_Gain
    - model2_P.Kv_Gain * rtb_Derivative1;

  /* Saturate: '<Root>/Saturation' */
  if (model2_B.Sum1 >= model2_P.Saturation_UpperSat) {
    model2_B.Saturation = model2_P.Saturation_UpperSat;
  } else if (model2_B.Sum1 <= model2_P.Saturation_LowerSat) {
    model2_B.Saturation = model2_P.Saturation_LowerSat;
  } else {
    model2_B.Saturation = model2_B.Sum1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  model2_DWork.sfEvent_g = model2_CALL_EVENT;

  /* MATLAB Function 'MATLAB Function2': '<S3>:1' */
  /* '<S3>:1:2' */
  /* '<S3>:1:4' */
  /* '<S3>:1:5' */
  model2_B.V = 0.0;
  model2_B.V += 0.8285 * model2_B.Toradius;
  model2_B.V += 1.2024 * rtb_Derivative1;
  model2_B.V += 15.0566 * rt_atan2d_snf(sin(model2_B.Sum), cos(model2_B.Sum));
  model2_B.V += 1.9463 * rtb_Derivative;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  switch ((int32_T)model2_B.control) {
   case 1:
    rtb_q2Switch = model2_B.Saturation;
    break;

   case 2:
    rtb_q2Switch = model2_P.Constant_Value_d;
    break;

   default:
    /* Saturate: '<Root>/Saturation2' */
    if (model2_B.V >= model2_P.Saturation2_UpperSat) {
      rtb_q2Switch = model2_P.Saturation2_UpperSat;
    } else if (model2_B.V <= model2_P.Saturation2_LowerSat) {
      rtb_q2Switch = model2_P.Saturation2_LowerSat;
    } else {
      rtb_q2Switch = model2_B.V;
    }

    /* End of Saturate: '<Root>/Saturation2' */
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Gain: '<S4>/gain' */
  model2_B.gain = model2_P.gain_Gain * rtb_q2Switch;
  if (rtmIsMajorTimeStep(model2_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: model2/Subsystem Real/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(model2_DWork.HILInitialize_Card,
        &model2_P.HILWriteAnalog_Channels, 1, &model2_B.gain);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
      }
    }

    /* Constant: '<S4>/voltage2' */
    model2_B.voltage2 = model2_P.voltage2_Value;

    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog1' */

    /* S-Function Block: model2/Subsystem Real/HIL Write Analog1 (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(model2_DWork.HILInitialize_Card,
        &model2_P.HILWriteAnalog1_Channels, 1, &model2_B.voltage2);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model2_M, _rt_error_message);
      }
    }
  }

  /* MATLAB Function: '<S5>/Animation' */
  model2_DWork.sfEvent_p = model2_CALL_EVENT;

  /* Saturate: '<S5>/Saturation' incorporates:
   *  Constant: '<S5>/voltage2'
   */
  if (rtb_q2Switch >= model2_P.Saturation_UpperSat_p) {
    model2_B.Saturation_p[0] = model2_P.Saturation_UpperSat_p;
  } else if (rtb_q2Switch <= model2_P.Saturation_LowerSat_k) {
    model2_B.Saturation_p[0] = model2_P.Saturation_LowerSat_k;
  } else {
    model2_B.Saturation_p[0] = rtb_q2Switch;
  }

  if (model2_P.voltage2_Value_p >= model2_P.Saturation_UpperSat_p) {
    model2_B.Saturation_p[1] = model2_P.Saturation_UpperSat_p;
  } else if (model2_P.voltage2_Value_p <= model2_P.Saturation_LowerSat_k) {
    model2_B.Saturation_p[1] = model2_P.Saturation_LowerSat_k;
  } else {
    model2_B.Saturation_p[1] = model2_P.voltage2_Value_p;
  }

  /* End of Saturate: '<S5>/Saturation' */
  if (rtmIsMajorTimeStep(model2_M)) {
  }

  /* MATLAB Function: '<S5>/StateMachine' */
  model2_DWork.sfEvent = model2_CALL_EVENT;

  /* MATLAB Function 'Subsytem Simulation/StateMachine': '<S8>:1' */
  /*  J1=0.0012; */
  /*  m2=0.127; */
  /*  l1_l2=0.2; */
  /*  l2=0.3; */
  /*  lc2=0.15; */
  /*  beta1=0.015; */
  /*  beta2=0.002; */
  /*  Ra=2.6; */
  /*  kt=0.00768; */
  /*  kv=0.00768; */
  /*  kr=70; */
  /*   */
  /*  theta1=(J1+m2*l1_l2^2)*Ra/(kr*kt); */
  /*  theta2=(m2*l2^2/3)*Ra/(kr*kt); */
  /*  theta3=(m2*l1_l2*l2/2)*Ra/(kr*kt); */
  /*  theta4=(m2*lc2)*Ra/(kr*kt); */
  /*  theta5=beta1*Ra/(kr*kt) + kr*kv; */
  /*  theta6=beta2*Ra/(kr*kt); */
  /* '<S8>:1:24' */
  /* '<S8>:1:25' */
  /* '<S8>:1:26' */
  /* '<S8>:1:28' */
  /* '<S8>:1:29' */
  /* '<S8>:1:35' */
  /* '<S8>:1:36' */
  /* '<S8>:1:37' */
  /* '<S8>:1:39' */
  /* '<S8>:1:40' */
  /* '<S8>:1:41' */
  /* '<S8>:1:42' */
  /* '<S8>:1:43' */
  /* '<S8>:1:44' */
  /* '<S8>:1:46' */
  /* '<S8>:1:47' */
  /* '<S8>:1:49' */
  M[0] = 0.018426339285714 * rt_powd_snf(sin(model2_B.Integrator[2]), 2.0) +
    0.030372023809524;
  M[2] = 0.018426339285714 * cos(model2_B.Integrator[2]);
  M[1] = 0.018426339285714 * cos(model2_B.Integrator[2]);
  M[3] = 0.018426339285714;

  /* '<S8>:1:50' */
  /* '<S8>:1:51' */
  /* '<S8>:1:52' */
  /* '<S8>:1:53' */
  /* '<S8>:1:55' */
  B[0] = (model2_B.Saturation_p[0] - (0.036852678571428 * sin
           (model2_B.Integrator[2]) * cos(model2_B.Integrator[2]) *
           model2_B.Integrator[3] * model2_B.Integrator[1] + -0.018426339285714 *
           sin(model2_B.Integrator[2]) * model2_B.Integrator[3] *
           model2_B.Integrator[3])) - 0.610144642857143 * model2_B.Integrator[1];
  B[1] = ((model2_B.Saturation_p[1] - (-0.018426339285714 * sin
            (model2_B.Integrator[2]) * cos(model2_B.Integrator[2]) *
            model2_B.Integrator[1] * model2_B.Integrator[1] + 0.0 *
            model2_B.Integrator[3])) - 0.009672619047619 * model2_B.Integrator[3])
    - -0.90289062499999584 * sin(model2_B.Integrator[2]);
  if (fabs(M[1]) > fabs(M[0])) {
    currentState = 1;
    r = 0;
  } else {
    currentState = 0;
    r = 1;
  }

  rtb_q2Switch = M[r] / M[currentState];
  rtb_q2Switch = (B[r] - B[currentState] * rtb_q2Switch) / (M[2 + r] - M[2 +
    currentState] * rtb_q2Switch);

  /* '<S8>:1:56' */
  model2_B.Xdot[0] = model2_B.Integrator[1];
  model2_B.Xdot[1] = (B[currentState] - M[2 + currentState] * rtb_q2Switch) /
    M[currentState];
  model2_B.Xdot[2] = model2_B.Integrator[3];
  model2_B.Xdot[3] = rtb_q2Switch;

  /* End of MATLAB Function: '<S5>/StateMachine' */
  if (rtmIsMajorTimeStep(model2_M)) {
    /* Update for Derivative: '<S4>/Derivative1' */
    {
      real_T timeStampA = model2_DWork.Derivative1_RWORK.TimeStampA;
      real_T timeStampB = model2_DWork.Derivative1_RWORK.TimeStampB;
      real_T* lastTime = &model2_DWork.Derivative1_RWORK.TimeStampA;
      real_T* lastU = &model2_DWork.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &model2_DWork.Derivative1_RWORK.TimeStampB;
          lastU = &model2_DWork.Derivative1_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &model2_DWork.Derivative1_RWORK.TimeStampB;
          lastU = &model2_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = model2_M->Timing.t[0];
      *lastU++ = rtb_TransferFcn1;
    }

    /* Update for Derivative: '<S4>/Derivative' */
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
      *lastU++ = rtb_TransferFcn;
    }

    /* Update for Integrator: '<S5>/Integrator' */
    model2_DWork.Integrator_IWORK.IcNeedsLoading = 0;
    if (rtmIsMajorTimeStep(model2_M)) {
      /* Update for Memory: '<Root>/Memory' */
      model2_DWork.Memory_PreviousInput = model2_B.control;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, model2_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(model2_M)) {/* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (((model2_M->Timing.clockTick1+
                            model2_M->Timing.clockTickH1* 4294967296.0)) * 0.001));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(model2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(model2_M)!=-1) &&
          !((rtmGetTFinal(model2_M)-(((model2_M->Timing.clockTick1+
               model2_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((model2_M->Timing.clockTick1+model2_M->Timing.clockTickH1*
               4294967296.0)) * 0.001) * (DBL_EPSILON))) {
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
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
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
  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn1' */
  {
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)
      ->TransferFcn1_CSTATE = model2_B.Toradius;
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)
      ->TransferFcn1_CSTATE += (model2_P.TransferFcn1_A)*
      model2_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  {
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->TransferFcn_CSTATE
      = model2_B.Toradius1;
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->TransferFcn_CSTATE
      += (model2_P.TransferFcn_A)*model2_X.TransferFcn_CSTATE;
  }

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->Integrator_CSTATE
      [0] = model2_B.Xdot[0];
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->Integrator_CSTATE
      [1] = model2_B.Xdot[1];
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->Integrator_CSTATE
      [2] = model2_B.Xdot[2];
    ((StateDerivatives_model2 *) model2_M->ModelData.derivs)->Integrator_CSTATE
      [3] = model2_B.Xdot[3];
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
  model2_M->ModelData.intgData.y = model2_M->ModelData.odeY;
  model2_M->ModelData.intgData.f[0] = model2_M->ModelData.odeF[0];
  model2_M->ModelData.intgData.f[1] = model2_M->ModelData.odeF[1];
  model2_M->ModelData.intgData.f[2] = model2_M->ModelData.odeF[2];
  model2_M->ModelData.contStates = ((real_T *) &model2_X);
  rtsiSetSolverData(&model2_M->solverInfo, (void *)&model2_M->ModelData.intgData);
  rtsiSetSolverName(&model2_M->solverInfo,"ode3");
  rtmSetTPtr(model2_M, &model2_M->Timing.tArray[0]);
  rtmSetTFinal(model2_M, -1);
  model2_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(model2_M, 1);

  /* External mode info */
  model2_M->Sizes.checksums[0] = (1804695245U);
  model2_M->Sizes.checksums[1] = (4162449741U);
  model2_M->Sizes.checksums[2] = (1090694384U);
  model2_M->Sizes.checksums[3] = (3723066648U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    model2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
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

  /* Start for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: model2/Subsystem Real/HIL Initialize (hil_initialize_block) */
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

  /* Start for Constant: '<S4>/voltage2' */
  model2_B.voltage2 = model2_P.voltage2_Value;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn1' */
  model2_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<S4>/Derivative1' */
  model2_DWork.Derivative1_RWORK.TimeStampA = rtInf;
  model2_DWork.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
  model2_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  model2_DWork.Derivative_RWORK.TimeStampA = rtInf;
  model2_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  if (rtmIsFirstInitCond(model2_M)) {
    model2_X.Integrator_CSTATE[0] = 0.0;
    model2_X.Integrator_CSTATE[1] = 0.0;
    model2_X.Integrator_CSTATE[2] = 0.0;
    model2_X.Integrator_CSTATE[3] = 0.0;
  }

  model2_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for MATLAB Function: '<S5>/MATLAB Function' */
  model2_DWork.sfEvent_m = model2_CALL_EVENT;
  model2_DWork.is_active_c4_model2 = 0U;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  model2_DWork.Memory_PreviousInput = model2_P.Memory_X0;

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function' */
  model2_DWork.sfEvent_l = model2_CALL_EVENT;
  model2_DWork.is_active_c2_model2 = 0U;

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function1' */
  model2_DWork.sfEvent_f = model2_CALL_EVENT;
  model2_DWork.is_active_c6_model2 = 0U;

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function2' */
  model2_DWork.sfEvent_g = model2_CALL_EVENT;
  model2_DWork.is_active_c5_model2 = 0U;

  /* InitializeConditions for MATLAB Function: '<S5>/Animation' */
  model2_DWork.sfEvent_p = model2_CALL_EVENT;
  model2_DWork.is_active_c1_model2 = 0U;

  /* InitializeConditions for MATLAB Function: '<S5>/StateMachine' */
  model2_DWork.sfEvent = model2_CALL_EVENT;
  model2_DWork.is_active_c3_model2 = 0U;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(model2_M)) {
    rtmSetFirstInitCond(model2_M, 0);
  }
}

/* Model terminate function */
void model2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: model2/Subsystem Real/HIL Initialize (hil_initialize_block) */
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
