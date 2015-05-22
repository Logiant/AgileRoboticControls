/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'DesignShowModel'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 12:35:13 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DesignShowModel.h"
#include "Arduino.h"
#define STEP_SIZE                      (unsigned long) (20000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  DesignShowModel_initialize();

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
  while (rtmGetErrorStatus(DesignShowModel_M) == (NULL)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      DesignShowModel_output();

      /* Get model outputs here */
      DesignShowModel_update();
    }
  }

  DesignShowModel_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
