/*
 * collect_data.c
 *
 * Code generation for model "collect_data".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Nov 02 11:40:15 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "collect_data.h"
#include "collect_data_private.h"
#include "collect_data_dt.h"

/* Named constants for MATLAB Function: '<Root>/Animation' */
#define collect_data_CALL_EVENT        (-1)

/* Block signals (auto storage) */
BlockIO_collect_data collect_data_B;

/* Continuous states */
ContinuousStates_collect_data collect_data_X;

/* Block states (auto storage) */
D_Work_collect_data collect_data_DWork;

/* Real-time model */
RT_MODEL_collect_data collect_data_M_;
RT_MODEL_collect_data *const collect_data_M = &collect_data_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  collect_data_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  collect_data_step();
  collect_data_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  collect_data_step();
  collect_data_derivatives();

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
void collect_data_step(void)
{
  real_T M[4];
  real_T B[2];
  int32_T r;
  int32_T r_0;
  real_T a;
  if (rtmIsMajorTimeStep(collect_data_M)) {
    /* set solver stop time */
    if (!(collect_data_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&collect_data_M->solverInfo,
                            ((collect_data_M->Timing.clockTickH0 + 1) *
        collect_data_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&collect_data_M->solverInfo,
                            ((collect_data_M->Timing.clockTick0 + 1) *
        collect_data_M->Timing.stepSize0 + collect_data_M->Timing.clockTickH0 *
        collect_data_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(collect_data_M)) {
    collect_data_M->Timing.t[0] = rtsiGetT(&collect_data_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(collect_data_M)) {
    /* Gain: '<Root>/degree to radius' incorporates:
     *  Constant: '<Root>/q1'
     *  Constant: '<Root>/q1dot'
     *  Constant: '<Root>/q2'
     *  Constant: '<Root>/q2dot'
     */
    collect_data_B.degreetoradius[0] = collect_data_P.degreetoradius_Gain *
      collect_data_P.q1_Value;
    collect_data_B.degreetoradius[1] = collect_data_P.degreetoradius_Gain *
      collect_data_P.q1dot_Value;
    collect_data_B.degreetoradius[2] = collect_data_P.degreetoradius_Gain *
      collect_data_P.q2_Value;
    collect_data_B.degreetoradius[3] = collect_data_P.degreetoradius_Gain *
      collect_data_P.q2dot_Value;
  }

  /* Integrator: '<Root>/Integrator' */
  if (collect_data_DWork.Integrator_IWORK.IcNeedsLoading) {
    collect_data_X.Integrator_CSTATE[0] = collect_data_B.degreetoradius[0];
    collect_data_X.Integrator_CSTATE[1] = collect_data_B.degreetoradius[1];
    collect_data_X.Integrator_CSTATE[2] = collect_data_B.degreetoradius[2];
    collect_data_X.Integrator_CSTATE[3] = collect_data_B.degreetoradius[3];
  }

  collect_data_B.Integrator[0] = collect_data_X.Integrator_CSTATE[0];
  collect_data_B.Integrator[1] = collect_data_X.Integrator_CSTATE[1];
  collect_data_B.Integrator[2] = collect_data_X.Integrator_CSTATE[2];
  collect_data_B.Integrator[3] = collect_data_X.Integrator_CSTATE[3];

  /* MATLAB Function: '<Root>/Animation' */
  collect_data_DWork.sfEvent_m = collect_data_CALL_EVENT;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Sin: '<Root>/Sine Wave 2'
   *  Sin: '<Root>/Sine Wave1'
   */
  collect_data_B.Sum1 = (sin(collect_data_P.SineWave1_Freq *
    collect_data_M->Timing.t[0] + collect_data_P.SineWave1_Phase) *
    collect_data_P.SineWave1_Amp + collect_data_P.SineWave1_Bias) + (sin
    (collect_data_P.SineWave2_Freq * collect_data_M->Timing.t[0] +
     collect_data_P.SineWave2_Phase) * collect_data_P.SineWave2_Amp +
    collect_data_P.SineWave2_Bias);
  if (rtmIsMajorTimeStep(collect_data_M)) {
    /* Constant: '<Root>/voltage2' */
    collect_data_B.voltage2 = collect_data_P.voltage2_Value;
  }

  /* MATLAB Function: '<Root>/StateMachine' incorporates:
   *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport1'
   */
  collect_data_DWork.sfEvent = collect_data_CALL_EVENT;

  /* MATLAB Function 'StateMachine': '<S2>:1' */
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
  /* '<S2>:1:24' */
  /* '<S2>:1:25' */
  /* '<S2>:1:26' */
  /* '<S2>:1:28' */
  /* '<S2>:1:29' */
  /* '<S2>:1:35' */
  /* '<S2>:1:36' */
  /* '<S2>:1:37' */
  /* '<S2>:1:39' */
  /* '<S2>:1:40' */
  /* '<S2>:1:41' */
  /* '<S2>:1:42' */
  /* '<S2>:1:43' */
  /* '<S2>:1:44' */
  /* '<S2>:1:46' */
  /* '<S2>:1:47' */
  /* '<S2>:1:49' */
  M[0] = 0.018426339285714 * rt_powd_snf(sin(collect_data_B.Integrator[2]), 2.0)
    + 0.030372023809524;
  M[2] = 0.018426339285714 * cos(collect_data_B.Integrator[2]);
  M[1] = 0.018426339285714 * cos(collect_data_B.Integrator[2]);
  M[3] = 0.018426339285714;

  /* '<S2>:1:50' */
  /* '<S2>:1:51' */
  /* '<S2>:1:52' */
  /* '<S2>:1:53' */
  /* '<S2>:1:55' */
  B[0] = (collect_data_B.Sum1 - (0.036852678571428 * sin
           (collect_data_B.Integrator[2]) * cos(collect_data_B.Integrator[2]) *
           collect_data_B.Integrator[3] * collect_data_B.Integrator[1] +
           -0.018426339285714 * sin(collect_data_B.Integrator[2]) *
           collect_data_B.Integrator[3] * collect_data_B.Integrator[3])) -
    0.610144642857143 * collect_data_B.Integrator[1];
  B[1] = ((collect_data_B.voltage2 - (-0.018426339285714 * sin
            (collect_data_B.Integrator[2]) * cos(collect_data_B.Integrator[2]) *
            collect_data_B.Integrator[1] * collect_data_B.Integrator[1] + 0.0 *
            collect_data_B.Integrator[3])) - 0.009672619047619 *
          collect_data_B.Integrator[3]) - -0.90289062499999584 * sin
    (collect_data_B.Integrator[2]);
  if (fabs(M[1]) > fabs(M[0])) {
    r = 1;
    r_0 = 0;
  } else {
    r = 0;
    r_0 = 1;
  }

  a = M[r_0] / M[r];
  a = (B[r_0] - B[r] * a) / (M[2 + r_0] - M[2 + r] * a);

  /* '<S2>:1:56' */
  collect_data_B.Xdot[0] = collect_data_B.Integrator[1];
  collect_data_B.Xdot[1] = (B[r] - M[2 + r] * a) / M[r];
  collect_data_B.Xdot[2] = collect_data_B.Integrator[3];
  collect_data_B.Xdot[3] = a;

  /* End of MATLAB Function: '<Root>/StateMachine' */
  if (rtmIsMajorTimeStep(collect_data_M)) {
    /* Update for Integrator: '<Root>/Integrator' */
    collect_data_DWork.Integrator_IWORK.IcNeedsLoading = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, collect_data_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(collect_data_M)) {/* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (((collect_data_M->Timing.clockTick1+
                            collect_data_M->Timing.clockTickH1* 4294967296.0)) *
                          0.001));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(collect_data_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(collect_data_M)!=-1) &&
          !((rtmGetTFinal(collect_data_M)-(((collect_data_M->Timing.clockTick1+
               collect_data_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((collect_data_M->Timing.clockTick1+
               collect_data_M->Timing.clockTickH1* 4294967296.0)) * 0.001) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(collect_data_M, "Simulation finished");
      }

      if (rtmGetStopRequested(collect_data_M)) {
        rtmSetErrorStatus(collect_data_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&collect_data_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++collect_data_M->Timing.clockTick0)) {
      ++collect_data_M->Timing.clockTickH0;
    }

    collect_data_M->Timing.t[0] = rtsiGetSolverStopTime
      (&collect_data_M->solverInfo);

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
      collect_data_M->Timing.clockTick1++;
      if (!collect_data_M->Timing.clockTick1) {
        collect_data_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void collect_data_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((StateDerivatives_collect_data *) collect_data_M->ModelData.derivs)
      ->Integrator_CSTATE[0] = collect_data_B.Xdot[0];
    ((StateDerivatives_collect_data *) collect_data_M->ModelData.derivs)
      ->Integrator_CSTATE[1] = collect_data_B.Xdot[1];
    ((StateDerivatives_collect_data *) collect_data_M->ModelData.derivs)
      ->Integrator_CSTATE[2] = collect_data_B.Xdot[2];
    ((StateDerivatives_collect_data *) collect_data_M->ModelData.derivs)
      ->Integrator_CSTATE[3] = collect_data_B.Xdot[3];
  }
}

/* Model initialize function */
void collect_data_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)collect_data_M, 0,
                sizeof(RT_MODEL_collect_data));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&collect_data_M->solverInfo,
                          &collect_data_M->Timing.simTimeStep);
    rtsiSetTPtr(&collect_data_M->solverInfo, &rtmGetTPtr(collect_data_M));
    rtsiSetStepSizePtr(&collect_data_M->solverInfo,
                       &collect_data_M->Timing.stepSize0);
    rtsiSetdXPtr(&collect_data_M->solverInfo, &collect_data_M->ModelData.derivs);
    rtsiSetContStatesPtr(&collect_data_M->solverInfo,
                         &collect_data_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&collect_data_M->solverInfo,
      &collect_data_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&collect_data_M->solverInfo, (&rtmGetErrorStatus
      (collect_data_M)));
    rtsiSetRTModelPtr(&collect_data_M->solverInfo, collect_data_M);
  }

  rtsiSetSimTimeStep(&collect_data_M->solverInfo, MAJOR_TIME_STEP);
  collect_data_M->ModelData.intgData.y = collect_data_M->ModelData.odeY;
  collect_data_M->ModelData.intgData.f[0] = collect_data_M->ModelData.odeF[0];
  collect_data_M->ModelData.intgData.f[1] = collect_data_M->ModelData.odeF[1];
  collect_data_M->ModelData.intgData.f[2] = collect_data_M->ModelData.odeF[2];
  collect_data_M->ModelData.contStates = ((real_T *) &collect_data_X);
  rtsiSetSolverData(&collect_data_M->solverInfo, (void *)
                    &collect_data_M->ModelData.intgData);
  rtsiSetSolverName(&collect_data_M->solverInfo,"ode3");
  rtmSetTPtr(collect_data_M, &collect_data_M->Timing.tArray[0]);
  rtmSetTFinal(collect_data_M, -1);
  collect_data_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(collect_data_M, 1);

  /* External mode info */
  collect_data_M->Sizes.checksums[0] = (2361450825U);
  collect_data_M->Sizes.checksums[1] = (816511276U);
  collect_data_M->Sizes.checksums[2] = (611984264U);
  collect_data_M->Sizes.checksums[3] = (1226089026U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    collect_data_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(collect_data_M->extModeInfo,
      &collect_data_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(collect_data_M->extModeInfo,
                        collect_data_M->Sizes.checksums);
    rteiSetTPtr(collect_data_M->extModeInfo, rtmGetTPtr(collect_data_M));
  }

  /* block I/O */
  (void) memset(((void *) &collect_data_B), 0,
                sizeof(BlockIO_collect_data));

  /* states (continuous) */
  {
    (void) memset((void *)&collect_data_X, 0,
                  sizeof(ContinuousStates_collect_data));
  }

  /* states (dwork) */
  (void) memset((void *)&collect_data_DWork, 0,
                sizeof(D_Work_collect_data));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    collect_data_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  if (rtmIsFirstInitCond(collect_data_M)) {
    collect_data_X.Integrator_CSTATE[0] = 0.0;
    collect_data_X.Integrator_CSTATE[1] = 0.0;
    collect_data_X.Integrator_CSTATE[2] = 0.0;
    collect_data_X.Integrator_CSTATE[3] = 0.0;
  }

  collect_data_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for MATLAB Function: '<Root>/Animation' */
  collect_data_DWork.sfEvent_m = collect_data_CALL_EVENT;
  collect_data_DWork.is_active_c1_collect_data = 0U;

  /* InitializeConditions for MATLAB Function: '<Root>/StateMachine' */
  collect_data_DWork.sfEvent = collect_data_CALL_EVENT;
  collect_data_DWork.is_active_c2_collect_data = 0U;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(collect_data_M)) {
    rtmSetFirstInitCond(collect_data_M, 0);
  }
}

/* Model terminate function */
void collect_data_terminate(void)
{
}
