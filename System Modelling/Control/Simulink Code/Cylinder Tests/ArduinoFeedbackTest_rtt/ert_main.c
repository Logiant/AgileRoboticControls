/*
 * File: ert_main.c
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
#include "Arduino.h"
#define STEP_SIZE                      (unsigned long) (1000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  ArduinoFeedbackTest_initialize();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 9600);

#endif

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 9600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 9600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 9600);

#endif

  /* The main step loop */
  while ((rtmGetErrorStatus(ArduinoFeedbackTest_M) == (NULL)) &&
         !rtmGetStopRequested(ArduinoFeedbackTest_M)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      ArduinoFeedbackTest_output();

      /* Get model outputs here */
      ArduinoFeedbackTest_update();
    }
  }

  ArduinoFeedbackTest_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
