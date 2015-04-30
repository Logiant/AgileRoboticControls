/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'StepResponseTest'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 19:20:04 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "StepResponseTest.h"
#include "Arduino.h"
#define STEP_SIZE                      (unsigned long) (10000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  StepResponseTest_initialize();

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
  while (rtmGetErrorStatus(StepResponseTest_M) == (NULL)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      StepResponseTest_output();

      /* Get model outputs here */
      StepResponseTest_update();
    }
  }

  StepResponseTest_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
