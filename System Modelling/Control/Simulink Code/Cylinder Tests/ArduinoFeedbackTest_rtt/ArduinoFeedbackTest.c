/*
 * File: ArduinoFeedbackTest.c
 *
 * Code generated for Simulink model 'ArduinoFeedbackTest'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Mon Mar 16 16:55:36 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoFeedbackTest.h"
#include "ArduinoFeedbackTest_private.h"

/* Block signals (auto storage) */
B_ArduinoFeedbackTest_T ArduinoFeedbackTest_B;

/* Continuous states */
X_ArduinoFeedbackTest_T ArduinoFeedbackTest_X;

/* Real-time model */
RT_MODEL_ArduinoFeedbackTest_T ArduinoFeedbackTest_M_;
RT_MODEL_ArduinoFeedbackTest_T *const ArduinoFeedbackTest_M =
  &ArduinoFeedbackTest_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ArduinoFeedbackTest_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ArduinoFeedbackTest_output();
  ArduinoFeedbackTest_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ArduinoFeedbackTest_output();
  ArduinoFeedbackTest_derivatives();

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

/* Model output function */
void ArduinoFeedbackTest_output(void)
{
  uint16_T rtb_AnalogInput_0;
  real_T rtb_ScaletoMaxInput;
  real_T tmp;
  if (rtmIsMajorTimeStep(ArduinoFeedbackTest_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ArduinoFeedbackTest_M->solverInfo,
                          ((ArduinoFeedbackTest_M->Timing.clockTick0+1)*
      ArduinoFeedbackTest_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ArduinoFeedbackTest_M)) {
    ArduinoFeedbackTest_M->Timing.t[0] = rtsiGetT
      (&ArduinoFeedbackTest_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ArduinoFeedbackTest_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Desired Percent Max Position'
     *  Sin: '<Root>/Sine Wave'
     */
    if (ArduinoFeedbackTest_P.ManualSwitch_CurrentSetting == 1) {
      tmp = sin(ArduinoFeedbackTest_P.SineWave_Freq * 0.0 +
                ArduinoFeedbackTest_P.SineWave_Phase) *
        ArduinoFeedbackTest_P.SineWave_Amp + ArduinoFeedbackTest_P.SineWave_Bias;
    } else {
      tmp = ArduinoFeedbackTest_P.DesiredPercentMaxPosition_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* Gain: '<Root>/Scale to Max Input' */
    rtb_ScaletoMaxInput = ArduinoFeedbackTest_P.ScaletoMaxInput_Gain * tmp;

    /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
    rtb_AnalogInput_0 = MW_analogRead(ArduinoFeedbackTest_P.AnalogInput_p1);

    /* Gain: '<Root>/Gain' incorporates:
     *  S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input'
     *  Sum: '<Root>/Sum'
     */
    rtb_ScaletoMaxInput = (rtb_ScaletoMaxInput - (real_T)rtb_AnalogInput_0) *
      ArduinoFeedbackTest_P.Gain_Gain;

    /* Gain: '<S1>/Proportional Gain' */
    ArduinoFeedbackTest_B.ProportionalGain =
      ArduinoFeedbackTest_P.PIDController_P * rtb_ScaletoMaxInput;

    /* Gain: '<S1>/Derivative Gain' */
    ArduinoFeedbackTest_B.DerivativeGain = ArduinoFeedbackTest_P.PIDController_D
      * rtb_ScaletoMaxInput;
  }

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  ArduinoFeedbackTest_B.FilterCoefficient =
    (ArduinoFeedbackTest_B.DerivativeGain - ArduinoFeedbackTest_X.Filter_CSTATE)
    * ArduinoFeedbackTest_P.PIDController_N;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Sum: '<S1>/Sum'
   */
  tmp = (ArduinoFeedbackTest_B.ProportionalGain +
         ArduinoFeedbackTest_X.Integrator_CSTATE) +
    ArduinoFeedbackTest_B.FilterCoefficient;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      ArduinoFeedbackTest_B.DataTypeConversion = (uint8_T)tmp;
    } else {
      ArduinoFeedbackTest_B.DataTypeConversion = 0U;
    }
  } else {
    ArduinoFeedbackTest_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(ArduinoFeedbackTest_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
    MW_analogWrite(ArduinoFeedbackTest_P.PWM_pinNumber,
                   ArduinoFeedbackTest_B.DataTypeConversion);

    /* Gain: '<S1>/Integral Gain' */
    ArduinoFeedbackTest_B.IntegralGain = ArduinoFeedbackTest_P.PIDController_I *
      rtb_ScaletoMaxInput;
  }
}

/* Model update function */
void ArduinoFeedbackTest_update(void)
{
  if (rtmIsMajorTimeStep(ArduinoFeedbackTest_M)) {
    rt_ertODEUpdateContinuousStates(&ArduinoFeedbackTest_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++ArduinoFeedbackTest_M->Timing.clockTick0;
  ArduinoFeedbackTest_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ArduinoFeedbackTest_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ArduinoFeedbackTest_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void ArduinoFeedbackTest_derivatives(void)
{
  XDot_ArduinoFeedbackTest_T *_rtXdot;
  _rtXdot = ((XDot_ArduinoFeedbackTest_T *)
             ArduinoFeedbackTest_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = ArduinoFeedbackTest_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = ArduinoFeedbackTest_B.FilterCoefficient;
}

/* Model initialize function */
void ArduinoFeedbackTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ArduinoFeedbackTest_M, 0,
                sizeof(RT_MODEL_ArduinoFeedbackTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ArduinoFeedbackTest_M->solverInfo,
                          &ArduinoFeedbackTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&ArduinoFeedbackTest_M->solverInfo, &rtmGetTPtr
                (ArduinoFeedbackTest_M));
    rtsiSetStepSizePtr(&ArduinoFeedbackTest_M->solverInfo,
                       &ArduinoFeedbackTest_M->Timing.stepSize0);
    rtsiSetdXPtr(&ArduinoFeedbackTest_M->solverInfo,
                 &ArduinoFeedbackTest_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ArduinoFeedbackTest_M->solverInfo, (real_T **)
                         &ArduinoFeedbackTest_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ArduinoFeedbackTest_M->solverInfo,
      &ArduinoFeedbackTest_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ArduinoFeedbackTest_M->solverInfo,
                          (&rtmGetErrorStatus(ArduinoFeedbackTest_M)));
    rtsiSetRTModelPtr(&ArduinoFeedbackTest_M->solverInfo, ArduinoFeedbackTest_M);
  }

  rtsiSetSimTimeStep(&ArduinoFeedbackTest_M->solverInfo, MAJOR_TIME_STEP);
  ArduinoFeedbackTest_M->ModelData.intgData.y =
    ArduinoFeedbackTest_M->ModelData.odeY;
  ArduinoFeedbackTest_M->ModelData.intgData.f[0] =
    ArduinoFeedbackTest_M->ModelData.odeF[0];
  ArduinoFeedbackTest_M->ModelData.intgData.f[1] =
    ArduinoFeedbackTest_M->ModelData.odeF[1];
  ArduinoFeedbackTest_M->ModelData.intgData.f[2] =
    ArduinoFeedbackTest_M->ModelData.odeF[2];
  ArduinoFeedbackTest_M->ModelData.contStates = ((X_ArduinoFeedbackTest_T *)
    &ArduinoFeedbackTest_X);
  rtsiSetSolverData(&ArduinoFeedbackTest_M->solverInfo, (void *)
                    &ArduinoFeedbackTest_M->ModelData.intgData);
  rtsiSetSolverName(&ArduinoFeedbackTest_M->solverInfo,"ode3");
  rtmSetTPtr(ArduinoFeedbackTest_M, &ArduinoFeedbackTest_M->Timing.tArray[0]);
  ArduinoFeedbackTest_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &ArduinoFeedbackTest_B), 0,
                sizeof(B_ArduinoFeedbackTest_T));

  /* states (continuous) */
  {
    (void) memset((void *)&ArduinoFeedbackTest_X, 0,
                  sizeof(X_ArduinoFeedbackTest_T));
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  MW_pinModeAnalogInput(ArduinoFeedbackTest_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(ArduinoFeedbackTest_P.PWM_pinNumber);

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  ArduinoFeedbackTest_X.Integrator_CSTATE = ArduinoFeedbackTest_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  ArduinoFeedbackTest_X.Filter_CSTATE = ArduinoFeedbackTest_P.Filter_IC;
}

/* Model terminate function */
void ArduinoFeedbackTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
