/*
 * Lab4.c
 *
 * Code generation for model "Lab4".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Sat Nov 04 17:44:01 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Lab4.h"
#include "Lab4_private.h"
#include "Lab4_dt.h"

/* Named constants for MATLAB Function: '<Root>/Animation' */
#define Lab4_CALL_EVENT                (-1)

/* Block signals (auto storage) */
BlockIO_Lab4 Lab4_B;

/* Continuous states */
ContinuousStates_Lab4 Lab4_X;

/* Block states (auto storage) */
D_Work_Lab4 Lab4_DWork;

/* Real-time model */
RT_MODEL_Lab4 Lab4_M_;
RT_MODEL_Lab4 *const Lab4_M = &Lab4_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Lab4_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

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
void Lab4_step(void)
{
  real_T M[4];
  real_T B[2];
  int32_T r;
  int32_T r_0;
  real_T a;
  if (rtmIsMajorTimeStep(Lab4_M)) {
    /* set solver stop time */
    if (!(Lab4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Lab4_M->solverInfo, ((Lab4_M->Timing.clockTickH0 +
        1) * Lab4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Lab4_M->solverInfo, ((Lab4_M->Timing.clockTick0 + 1)
        * Lab4_M->Timing.stepSize0 + Lab4_M->Timing.clockTickH0 *
        Lab4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab4_M)) {
    Lab4_M->Timing.t[0] = rtsiGetT(&Lab4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab4_M)) {
    /* Gain: '<Root>/degree to radius' incorporates:
     *  Constant: '<Root>/q1'
     *  Constant: '<Root>/q1dot'
     *  Constant: '<Root>/q2'
     *  Constant: '<Root>/q2dot'
     */
    Lab4_B.degreetoradius[0] = Lab4_P.degreetoradius_Gain * Lab4_P.q1_Value;
    Lab4_B.degreetoradius[1] = Lab4_P.degreetoradius_Gain * Lab4_P.q1dot_Value;
    Lab4_B.degreetoradius[2] = Lab4_P.degreetoradius_Gain * Lab4_P.q2_Value;
    Lab4_B.degreetoradius[3] = Lab4_P.degreetoradius_Gain * Lab4_P.q2dot_Value;
  }

  /* Integrator: '<Root>/Integrator' */
  if (Lab4_DWork.Integrator_IWORK.IcNeedsLoading) {
    Lab4_X.Integrator_CSTATE[0] = Lab4_B.degreetoradius[0];
    Lab4_X.Integrator_CSTATE[1] = Lab4_B.degreetoradius[1];
    Lab4_X.Integrator_CSTATE[2] = Lab4_B.degreetoradius[2];
    Lab4_X.Integrator_CSTATE[3] = Lab4_B.degreetoradius[3];
  }

  Lab4_B.Integrator[0] = Lab4_X.Integrator_CSTATE[0];
  Lab4_B.Integrator[1] = Lab4_X.Integrator_CSTATE[1];
  Lab4_B.Integrator[2] = Lab4_X.Integrator_CSTATE[2];
  Lab4_B.Integrator[3] = Lab4_X.Integrator_CSTATE[3];

  /* MATLAB Function: '<Root>/Animation' */
  Lab4_DWork.sfEvent_m = Lab4_CALL_EVENT;
  if (rtmIsMajorTimeStep(Lab4_M)) {
    /* Constant: '<Root>/voltage1' */
    Lab4_B.voltage1 = Lab4_P.voltage1_Value;

    /* Constant: '<Root>/voltage2' */
    Lab4_B.voltage2 = Lab4_P.voltage2_Value;
  }

  /* MATLAB Function: '<Root>/StateMachine' incorporates:
   *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport1'
   */
  Lab4_DWork.sfEvent = Lab4_CALL_EVENT;

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
  /* '<S2>:1:32' */
  /* '<S2>:1:33' */
  /* '<S2>:1:35' */
  /* '<S2>:1:36' */
  /* '<S2>:1:37' */
  /* '<S2>:1:39' */
  /* '<S2>:1:40' */
  /* '<S2>:1:41' */
  /* '<S2>:1:43' */
  /* '<S2>:1:44' */
  /* '<S2>:1:46' */
  /* '<S2>:1:47' */
  /* '<S2>:1:49' */
  M[0] = 0.018426339285714 * rt_powd_snf(sin(Lab4_B.Integrator[2]), 2.0) +
    0.030372023809524;
  M[2] = 0.018426339285714 * cos(Lab4_B.Integrator[2]);
  M[1] = 0.018426339285714 * cos(Lab4_B.Integrator[2]);
  M[3] = 0.018426339285714;

  /* '<S2>:1:50' */
  /* '<S2>:1:51' */
  /* '<S2>:1:52' */
  /* '<S2>:1:53' */
  /* '<S2>:1:55' */
  B[0] = Lab4_B.voltage1 - ((0.036852678571428 * sin(Lab4_B.Integrator[2]) * cos
                             (Lab4_B.Integrator[2]) + 0.610144642857143) *
    Lab4_B.Integrator[1] + -0.018426339285714 * sin(Lab4_B.Integrator[2]) *
    Lab4_B.Integrator[3] * Lab4_B.Integrator[3]);
  B[1] = (Lab4_B.voltage2 - (-0.018426339285714 * sin(Lab4_B.Integrator[2]) *
           cos(Lab4_B.Integrator[2]) * Lab4_B.Integrator[1] * Lab4_B.Integrator
           [1] + 0.009672619047619 * Lab4_B.Integrator[3])) -
    -0.90289062499999584 * sin(Lab4_B.Integrator[2]);
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
  Lab4_B.Xdot[0] = Lab4_B.Integrator[1];
  Lab4_B.Xdot[1] = (B[r] - M[2 + r] * a) / M[r];
  Lab4_B.Xdot[2] = Lab4_B.Integrator[3];
  Lab4_B.Xdot[3] = a;

  /* End of MATLAB Function: '<Root>/StateMachine' */
  if (rtmIsMajorTimeStep(Lab4_M)) {
    /* Update for Integrator: '<Root>/Integrator' */
    Lab4_DWork.Integrator_IWORK.IcNeedsLoading = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, Lab4_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Lab4_M)) {  /* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((Lab4_M->Timing.clockTick1+Lab4_M->Timing.clockTickH1*
                            4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Lab4_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Lab4_M)!=-1) &&
          !((rtmGetTFinal(Lab4_M)-(((Lab4_M->Timing.clockTick1+
               Lab4_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((Lab4_M->Timing.clockTick1+Lab4_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Lab4_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Lab4_M)) {
        rtmSetErrorStatus(Lab4_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Lab4_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Lab4_M->Timing.clockTick0)) {
      ++Lab4_M->Timing.clockTickH0;
    }

    Lab4_M->Timing.t[0] = rtsiGetSolverStopTime(&Lab4_M->solverInfo);

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
      Lab4_M->Timing.clockTick1++;
      if (!Lab4_M->Timing.clockTick1) {
        Lab4_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Lab4_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((StateDerivatives_Lab4 *) Lab4_M->ModelData.derivs)->Integrator_CSTATE[0] =
      Lab4_B.Xdot[0];
    ((StateDerivatives_Lab4 *) Lab4_M->ModelData.derivs)->Integrator_CSTATE[1] =
      Lab4_B.Xdot[1];
    ((StateDerivatives_Lab4 *) Lab4_M->ModelData.derivs)->Integrator_CSTATE[2] =
      Lab4_B.Xdot[2];
    ((StateDerivatives_Lab4 *) Lab4_M->ModelData.derivs)->Integrator_CSTATE[3] =
      Lab4_B.Xdot[3];
  }
}

/* Model initialize function */
void Lab4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab4_M, 0,
                sizeof(RT_MODEL_Lab4));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab4_M->solverInfo, &Lab4_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab4_M->solverInfo, &rtmGetTPtr(Lab4_M));
    rtsiSetStepSizePtr(&Lab4_M->solverInfo, &Lab4_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab4_M->solverInfo, &Lab4_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Lab4_M->solverInfo, &Lab4_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Lab4_M->solverInfo, &Lab4_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Lab4_M->solverInfo, (&rtmGetErrorStatus(Lab4_M)));
    rtsiSetRTModelPtr(&Lab4_M->solverInfo, Lab4_M);
  }

  rtsiSetSimTimeStep(&Lab4_M->solverInfo, MAJOR_TIME_STEP);
  Lab4_M->ModelData.intgData.f[0] = Lab4_M->ModelData.odeF[0];
  Lab4_M->ModelData.contStates = ((real_T *) &Lab4_X);
  rtsiSetSolverData(&Lab4_M->solverInfo, (void *)&Lab4_M->ModelData.intgData);
  rtsiSetSolverName(&Lab4_M->solverInfo,"ode1");
  rtmSetTPtr(Lab4_M, &Lab4_M->Timing.tArray[0]);
  rtmSetTFinal(Lab4_M, -1);
  Lab4_M->Timing.stepSize0 = 0.002;
  rtmSetFirstInitCond(Lab4_M, 1);

  /* External mode info */
  Lab4_M->Sizes.checksums[0] = (61543148U);
  Lab4_M->Sizes.checksums[1] = (1753116754U);
  Lab4_M->Sizes.checksums[2] = (3965072757U);
  Lab4_M->Sizes.checksums[3] = (2511508786U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Lab4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lab4_M->extModeInfo,
      &Lab4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lab4_M->extModeInfo, Lab4_M->Sizes.checksums);
    rteiSetTPtr(Lab4_M->extModeInfo, rtmGetTPtr(Lab4_M));
  }

  /* block I/O */
  (void) memset(((void *) &Lab4_B), 0,
                sizeof(BlockIO_Lab4));

  /* states (continuous) */
  {
    (void) memset((void *)&Lab4_X, 0,
                  sizeof(ContinuousStates_Lab4));
  }

  /* states (dwork) */
  (void) memset((void *)&Lab4_DWork, 0,
                sizeof(D_Work_Lab4));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lab4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  if (rtmIsFirstInitCond(Lab4_M)) {
    Lab4_X.Integrator_CSTATE[0] = 0.0;
    Lab4_X.Integrator_CSTATE[1] = 0.0;
    Lab4_X.Integrator_CSTATE[2] = 0.0;
    Lab4_X.Integrator_CSTATE[3] = 0.0;
  }

  Lab4_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for MATLAB Function: '<Root>/Animation' */
  Lab4_DWork.sfEvent_m = Lab4_CALL_EVENT;
  Lab4_DWork.is_active_c1_Lab4 = 0U;

  /* InitializeConditions for MATLAB Function: '<Root>/StateMachine' */
  Lab4_DWork.sfEvent = Lab4_CALL_EVENT;
  Lab4_DWork.is_active_c2_Lab4 = 0U;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Lab4_M)) {
    rtmSetFirstInitCond(Lab4_M, 0);
  }
}

/* Model terminate function */
void Lab4_terminate(void)
{
}
