/*
 * File: XbeeSerialRead.c
 *
 * Code generated for Simulink model 'XbeeSerialRead'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 15 02:40:34 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "XbeeSerialRead.h"
#include "XbeeSerialRead_private.h"

/* Block signals (auto storage) */
B_XbeeSerialRead_T XbeeSerialRead_B;

/* Block states (auto storage) */
DW_XbeeSerialRead_T XbeeSerialRead_DW;

/* Real-time model */
RT_MODEL_XbeeSerialRead_T XbeeSerialRead_M_;
RT_MODEL_XbeeSerialRead_T *const XbeeSerialRead_M = &XbeeSerialRead_M_;

/* Model output function */
void XbeeSerialRead_output(void)
{
  uint8_T rtb_DataTypeConversion_j;
  int16_T rtb_SerialReceive_o2;
  uint8_T tmp[11];

  /* S-Function (arduinoserialread_sfcn): '<Root>/Serial Receive' */
  Serial_read(XbeeSerialRead_P.SerialReceive_p1,
              XbeeSerialRead_P.SerialReceive_p2, &rtb_DataTypeConversion_j,
              &rtb_SerialReceive_o2);

  /* Switch: '<Root>/Switch' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (rtb_SerialReceive_o2 > XbeeSerialRead_P.Switch_Threshold) {
    XbeeSerialRead_B.Switch = rtb_DataTypeConversion_j;
  } else {
    XbeeSerialRead_B.Switch = XbeeSerialRead_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      rtb_DataTypeConversion_j = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      rtb_DataTypeConversion_j = 0U;
    }
  } else {
    rtb_DataTypeConversion_j = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(XbeeSerialRead_P.PWM_pinNumber, rtb_DataTypeConversion_j);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Footer 1'
   *  Constant: '<S2>/Footer 2'
   *  Constant: '<S2>/Header'
   */
  if (XbeeSerialRead_P.Header_Value < 256.0) {
    if (XbeeSerialRead_P.Header_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[0] = (uint8_T)XbeeSerialRead_P.Header_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[0] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[0] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[1] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[1] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[1] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[2] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[2] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[2] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[3] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[3] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[3] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[4] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[4] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[4] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[5] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[5] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[5] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[6] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[6] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[6] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[7] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[7] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[7] = MAX_uint8_T;
  }

  if (XbeeSerialRead_B.Switch < 256.0) {
    if (XbeeSerialRead_B.Switch >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[8] = (uint8_T)XbeeSerialRead_B.Switch;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[8] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[8] = MAX_uint8_T;
  }

  if (XbeeSerialRead_P.Footer1_Value < 256.0) {
    if (XbeeSerialRead_P.Footer1_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[9] = (uint8_T)XbeeSerialRead_P.Footer1_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[9] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[9] = MAX_uint8_T;
  }

  if (XbeeSerialRead_P.Footer2_Value < 256.0) {
    if (XbeeSerialRead_P.Footer2_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[10] = (uint8_T)XbeeSerialRead_P.Footer2_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[10] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[10] = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
  Serial_write(XbeeSerialRead_P.SerialTransmit_portNumber, tmp, 11UL);
}

/* Model update function */
void XbeeSerialRead_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  XbeeSerialRead_DW.UnitDelay_DSTATE = XbeeSerialRead_B.Switch;
}

/* Model initialize function */
void XbeeSerialRead_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(XbeeSerialRead_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &XbeeSerialRead_B), 0,
                sizeof(B_XbeeSerialRead_T));

  /* states (dwork) */
  (void) memset((void *)&XbeeSerialRead_DW, 0,
                sizeof(DW_XbeeSerialRead_T));

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(XbeeSerialRead_P.PWM_pinNumber);

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  XbeeSerialRead_DW.UnitDelay_DSTATE =
    XbeeSerialRead_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void XbeeSerialRead_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
