/*
 * File: SimpleLegTest.c
 *
 * Code generated for Simulink model 'SimpleLegTest'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 13:26:11 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SimpleLegTest.h"
#include "SimpleLegTest_private.h"

/* Block signals (auto storage) */
B_SimpleLegTest_T SimpleLegTest_B;

/* Block states (auto storage) */
DW_SimpleLegTest_T SimpleLegTest_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_SimpleLegTest_T SimpleLegTest_Y;

/* Real-time model */
RT_MODEL_SimpleLegTest_T SimpleLegTest_M_;
RT_MODEL_SimpleLegTest_T *const SimpleLegTest_M = &SimpleLegTest_M_;

/* Model output function */
void SimpleLegTest_output(void)
{
  real_T rtb_Sum1;
  real_T rtb_Abs1;
  real_T rtb_Switch;
  real_T rtb_Abs;
  int16_T rtb_RetractSaturation;
  uint8_T rtb_DataTypeConversion_h;
  uint8_T tmp[11];
  int16_T tmp_0;

  /* S-Function (arduinoserialread_sfcn): '<Root>/Serial Receive' */
  Serial_read(SimpleLegTest_P.SerialReceive_p1, SimpleLegTest_P.SerialReceive_p2,
              &rtb_DataTypeConversion_h, &rtb_RetractSaturation);

  /* Switch: '<Root>/Switch' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (rtb_RetractSaturation > SimpleLegTest_P.Switch_Threshold_i) {
    SimpleLegTest_B.Switch = rtb_DataTypeConversion_h;
  } else {
    SimpleLegTest_B.Switch = SimpleLegTest_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Sum1 = (real_T)SimpleLegTest_B.Switch - SimpleLegTest_P.Constant1_Value_n;

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_Abs1 = SimpleLegTest_P.Constant2_Value_i * rtb_Sum1;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */
  if (rtb_Abs1 >= SimpleLegTest_P.Switch_Threshold) {
    rtb_Switch = SimpleLegTest_P.Constant1_Value;
  } else {
    rtb_Switch = SimpleLegTest_P.Constant2_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Abs: '<S5>/Abs' incorporates:
   *  Product: '<S5>/0 if Negative'
   */
  rtb_Abs = fabs(rtb_Abs1 * rtb_Switch);

  /* Product: '<S5>/0 If Positive' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Sum: '<S5>/Sum'
   */
  rtb_Abs1 *= rtb_Switch - SimpleLegTest_P.Constant3_Value;

  /* Abs: '<S5>/Abs1' */
  rtb_Abs1 = fabs(rtb_Abs1);

  /* Outport: '<Root>/Final Voltage (0, 1)' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  SimpleLegTest_Y.FinalVoltage01 = rtb_Abs + rtb_Abs1;

  /* MinMax: '<Root>/Extend Saturation' */
  rtb_Switch = floor(rtb_Abs);
  if (rtb_Switch < 32768.0) {
    rtb_RetractSaturation = (int16_T)rtb_Switch;
  } else {
    rtb_RetractSaturation = MAX_int16_T;
  }

  /* End of MinMax: '<Root>/Extend Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  tmp_0 = rtb_RetractSaturation;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  } else {
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }
  }

  rtb_DataTypeConversion_h = (uint8_T)tmp_0;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(SimpleLegTest_P.PWM_pinNumber, rtb_DataTypeConversion_h);

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      rtb_DataTypeConversion_h = (uint8_T)rtb_Sum1;
    } else {
      rtb_DataTypeConversion_h = 0U;
    }
  } else {
    rtb_DataTypeConversion_h = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(SimpleLegTest_P.PWM_pinNumber_p, rtb_DataTypeConversion_h);

  /* MinMax: '<Root>/Retract Saturation' */
  rtb_Switch = floor(rtb_Abs1);
  if (rtb_Switch < 32768.0) {
    rtb_RetractSaturation = (int16_T)rtb_Switch;
  } else {
    rtb_RetractSaturation = MAX_int16_T;
  }

  /* End of MinMax: '<Root>/Retract Saturation' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  tmp_0 = rtb_RetractSaturation;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  } else {
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }
  }

  rtb_DataTypeConversion_h = (uint8_T)tmp_0;

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_analogWrite(SimpleLegTest_P.PWM_pinNumber_l, rtb_DataTypeConversion_h);

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<S4>/Footer 1'
   *  Constant: '<S4>/Footer 2'
   *  Constant: '<S4>/Header'
   */
  if (SimpleLegTest_P.Header_Value < 256.0) {
    if (SimpleLegTest_P.Header_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[0] = (uint8_T)SimpleLegTest_P.Header_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[0] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[0] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[1] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[1] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[1] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[2] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[2] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[2] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[3] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[3] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[3] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[4] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[4] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[4] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[5] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[5] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[5] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[6] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[6] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[6] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[7] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[7] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[7] = MAX_uint8_T;
  }

  if (rtb_Sum1 < 256.0) {
    if (rtb_Sum1 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[8] = (uint8_T)rtb_Sum1;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[8] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[8] = MAX_uint8_T;
  }

  if (SimpleLegTest_P.Footer1_Value < 256.0) {
    if (SimpleLegTest_P.Footer1_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[9] = (uint8_T)SimpleLegTest_P.Footer1_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[9] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[9] = MAX_uint8_T;
  }

  if (SimpleLegTest_P.Footer2_Value < 256.0) {
    if (SimpleLegTest_P.Footer2_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[10] = (uint8_T)SimpleLegTest_P.Footer2_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
      tmp[10] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
    tmp[10] = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoserialwrite_sfcn): '<S4>/Serial Transmit' */
  Serial_write(SimpleLegTest_P.SerialTransmit_portNumber, tmp, 11UL);
}

/* Model update function */
void SimpleLegTest_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  SimpleLegTest_DW.UnitDelay_DSTATE = SimpleLegTest_B.Switch;
}

/* Model initialize function */
void SimpleLegTest_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SimpleLegTest_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &SimpleLegTest_B), 0,
                sizeof(B_SimpleLegTest_T));

  /* states (dwork) */
  (void) memset((void *)&SimpleLegTest_DW, 0,
                sizeof(DW_SimpleLegTest_T));

  /* external outputs */
  SimpleLegTest_Y.FinalVoltage01 = 0.0;

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(SimpleLegTest_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(SimpleLegTest_P.PWM_pinNumber_p);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_pinModeOutput(SimpleLegTest_P.PWM_pinNumber_l);

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  SimpleLegTest_DW.UnitDelay_DSTATE = SimpleLegTest_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void SimpleLegTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
