/*
 * File: XbeeSerial.c
 *
 * Code generated for Simulink model 'XbeeSerial'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed May 06 22:44:51 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "XbeeSerial.h"
#include "XbeeSerial_private.h"

/* Block signals (auto storage) */
B_XbeeSerial_T XbeeSerial_B;

/* Real-time model */
RT_MODEL_XbeeSerial_T XbeeSerial_M_;
RT_MODEL_XbeeSerial_T *const XbeeSerial_M = &XbeeSerial_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (XbeeSerial_M->Timing.TaskCounters.TID[2])++;
  if ((XbeeSerial_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.1s, 0.0s] */
    XbeeSerial_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function */
void XbeeSerial_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T currentTime;
  uint8_T rtb_MathFunction;
  uint8_T rtb_MathFunction_0;

  /* Step: '<S1>/Step' */
  currentTime = XbeeSerial_M->Timing.t[0];

  /* Clock: '<S1>/Clock' */
  rtb_Clock = XbeeSerial_M->Timing.t[0];

  /* Step: '<S1>/Step' */
  if (currentTime < XbeeSerial_P.Ramp_start) {
    currentTime = XbeeSerial_P.Step_Y0;
  } else {
    currentTime = XbeeSerial_P.Ramp_slope;
  }

  /* Sum: '<S1>/Output' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Sum'
   */
  XbeeSerial_B.Output = (rtb_Clock - XbeeSerial_P.Ramp_start) * currentTime +
    XbeeSerial_P.Ramp_X0;
  if (XbeeSerial_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    currentTime = floor(XbeeSerial_B.Output);
    if (rtIsNaN(currentTime) || rtIsInf(currentTime)) {
      currentTime = 0.0;
    } else {
      currentTime = fmod(currentTime, 256.0);
    }

    XbeeSerial_B.DataTypeConversion = (uint8_T)(currentTime < 0.0 ? (int16_T)
      (uint8_T)-(int8_T)(uint8_T)-currentTime : (int16_T)(uint8_T)currentTime);

    /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
  }

  /* Math: '<Root>/Math Function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (XbeeSerial_P.Constant_Value == 0) {
    rtb_MathFunction = XbeeSerial_B.DataTypeConversion;
  } else {
    rtb_MathFunction = (uint8_T)(XbeeSerial_B.DataTypeConversion %
      XbeeSerial_P.Constant_Value);
  }

  /* End of Math: '<Root>/Math Function' */

  /* S-Function (arduinoserialwrite_sfcn): '<Root>/Serial Transmit' */
  rtb_MathFunction_0 = rtb_MathFunction;
  Serial_write(XbeeSerial_P.SerialTransmit_portNumber, &rtb_MathFunction_0, 1UL);
}

/* Model update function */
void XbeeSerial_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  XbeeSerial_M->Timing.t[0] =
    (++XbeeSerial_M->Timing.clockTick0) * XbeeSerial_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.05, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    XbeeSerial_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void XbeeSerial_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)XbeeSerial_M, 0,
                sizeof(RT_MODEL_XbeeSerial_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&XbeeSerial_M->solverInfo,
                          &XbeeSerial_M->Timing.simTimeStep);
    rtsiSetTPtr(&XbeeSerial_M->solverInfo, &rtmGetTPtr(XbeeSerial_M));
    rtsiSetStepSizePtr(&XbeeSerial_M->solverInfo,
                       &XbeeSerial_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&XbeeSerial_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(XbeeSerial_M))));
    rtsiSetRTModelPtr(&XbeeSerial_M->solverInfo, XbeeSerial_M);
  }

  rtsiSetSimTimeStep(&XbeeSerial_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&XbeeSerial_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(XbeeSerial_M, &XbeeSerial_M->Timing.tArray[0]);
  XbeeSerial_M->Timing.stepSize0 = 0.05;

  /* block I/O */
  (void) memset(((void *) &XbeeSerial_B), 0,
                sizeof(B_XbeeSerial_T));
}

/* Model terminate function */
void XbeeSerial_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
