/*
 * File: DesignShowModel.c
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
#include "DesignShowModel_private.h"

/* Named constants for Chart: '<S6>/Chart' */
#define DesignShowMo_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DesignShowModel_IN_Forward     ((uint8_T)1U)
#define DesignShowModel_IN_Idle        ((uint8_T)2U)

/* Block signals (auto storage) */
B_DesignShowModel_T DesignShowModel_B;

/* Block states (auto storage) */
DW_DesignShowModel_T DesignShowModel_DW;

/* Real-time model */
RT_MODEL_DesignShowModel_T DesignShowModel_M_;
RT_MODEL_DesignShowModel_T *const DesignShowModel_M = &DesignShowModel_M_;
void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = yk < cb ? 1UL : 0UL;
      u1i *= a0;
      yk += u1i;
      cb += yk < u1i ? 1UL : 0UL;
      u1i = w10 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1UL : 0UL;
      u1i = w01 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1UL : 0UL;
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

real_T uMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  int16_T i;
  int16_T exp_0;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

/* Model output function */
void DesignShowModel_output(void)
{
  static const int8_T b[6] = { 1, 2, 3, 4, 3, 2 };

  real_T rtb_Sum2;
  uint16_T rtb_Product;
  real_T rtb_Abs1_i;
  real_T rtb_Abs;
  real_T rtb_Abs_l;
  int16_T rtb_RetractSaturation;
  uint8_T rtb_DataTypeConversion_p;
  real_T rtb_UnitDelay1;
  uint64m_T rtb_NormalizeFeedback;
  uint8_T tmp[11];
  int16_T tmp_0;
  uint32_T tmp_1;

  /* S-Function (arduinoanaloginput_sfcn): '<S4>/Feedback Voltage' */
  rtb_Product = MW_analogRead(DesignShowModel_P.FeedbackVoltage_p1);

  /* Gain: '<S4>/Normalize Feedback' incorporates:
   *  Gain: '<S4>/Length Compensation'
   *  S-Function (arduinoanaloginput_sfcn): '<S4>/Feedback Voltage'
   */
  tmp_1 = (uint32_T)DesignShowModel_P.LengthCompensation_Gain * rtb_Product;
  uMultiWordMul(&DesignShowModel_P.NormalizeFeedback_Gain, 1, &tmp_1, 1,
                &rtb_NormalizeFeedback.chunks[0U], 2);

  /* UnitDelay: '<S6>/Unit Delay1' */
  rtb_UnitDelay1 = DesignShowModel_DW.UnitDelay1_DSTATE;

  /* S-Function (arduinoserialread_sfcn): '<Root>/Serial Receive' */
  Serial_read(DesignShowModel_P.SerialReceive_p1,
              DesignShowModel_P.SerialReceive_p2, &rtb_DataTypeConversion_p,
              &rtb_RetractSaturation);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/No Request'
   */
  if (rtb_RetractSaturation > DesignShowModel_P.Switch_Threshold_g3) {
    rtb_Sum2 = rtb_DataTypeConversion_p;
  } else {
    rtb_Sum2 = DesignShowModel_P.NoRequest_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Product: '<S5>/Product' incorporates:
   *  Abs: '<S7>/Abs'
   *  Constant: '<S7>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  Sum: '<S7>/Sum'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  rtb_Product = rtb_Sum2 != 0.0 ? (uint16_T)(fabs
    (DesignShowModel_DW.UnitDelay_DSTATE -
     DesignShowModel_DW.UnitDelay1_DSTATE_o) < DesignShowModel_P.Constant_Value)
    : 0U;

  /* Chart: '<S6>/Chart' */
  /* Gateway: High Level System Controller/System Model/State Machine/Chart */
  /* During: High Level System Controller/System Model/State Machine/Chart */
  if (DesignShowModel_DW.is_active_c3_DesignShowModel == 0U) {
    /* Entry: High Level System Controller/System Model/State Machine/Chart */
    DesignShowModel_DW.is_active_c3_DesignShowModel = 1U;

    /* Entry Internal: High Level System Controller/System Model/State Machine/Chart */
    /* Transition: '<S9>:23' */
    DesignShowModel_DW.is_c3_DesignShowModel = DesignShowModel_IN_Idle;

    /* Entry 'Idle': '<S9>:1' */
    DesignShowModel_B.index_out_n = rtb_UnitDelay1;
  } else {
    switch (DesignShowModel_DW.is_c3_DesignShowModel) {
     case DesignShowModel_IN_Forward:
      /* During 'Forward': '<S9>:2' */
      if (rtb_Product != 1U) {
        /* Transition: '<S9>:7' */
        DesignShowModel_DW.is_c3_DesignShowModel = DesignShowModel_IN_Idle;

        /* Entry 'Idle': '<S9>:1' */
        DesignShowModel_B.index_out_n = rtb_UnitDelay1;
      } else {
        DesignShowModel_B.index_out_n = rtb_UnitDelay1 + 1.0;
      }
      break;

     case DesignShowModel_IN_Idle:
      /* During 'Idle': '<S9>:1' */
      if (rtb_Product == 1U) {
        /* Transition: '<S9>:4' */
        DesignShowModel_DW.is_c3_DesignShowModel = DesignShowModel_IN_Forward;

        /* Entry 'Forward': '<S9>:2' */
        DesignShowModel_B.index_out_n = rtb_UnitDelay1 + 1.0;
      }
      break;

     default:
      /* During 'Reverse': '<S9>:3' */
      /* Transition: '<S9>:6' */
      DesignShowModel_DW.is_c3_DesignShowModel = DesignShowModel_IN_Idle;

      /* Entry 'Idle': '<S9>:1' */
      DesignShowModel_B.index_out_n = rtb_UnitDelay1;
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/MATLAB Function': '<S10>:1' */
  /* '<S10>:1:3' */
  DesignShowModel_B.index_out = DesignShowModel_B.index_out_n;
  if (DesignShowModel_B.index_out_n > 6.0) {
    /* '<S10>:1:4' */
    /* '<S10>:1:5' */
    DesignShowModel_B.index_out = 1.0;
  }

  if (DesignShowModel_B.index_out_n < 1.0) {
    /* '<S10>:1:7' */
    /* '<S10>:1:8' */
    DesignShowModel_B.index_out = 6.0;
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* MATLAB Function: '<S8>/MATLAB Function' */
  /* MATLAB Function 'High Level System Controller/System Model/State Machine/Calculate Foot Position/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:3' */
  rtb_UnitDelay1 = DesignShowModel_B.index_out;
  if (DesignShowModel_B.index_out < 1.0) {
    /* '<S11>:1:4' */
    /* '<S11>:1:5' */
    rtb_UnitDelay1 = 1.0;
  } else {
    if (DesignShowModel_B.index_out > 6.0) {
      /* '<S11>:1:6' */
      /* '<S11>:1:7' */
      rtb_UnitDelay1 = 6.0;
    }
  }

  /* '<S11>:1:9' */
  /* divide by 5 to normalize */
  /* '<S11>:1:11' */
  DesignShowModel_B.x = b[(int16_T)rtb_UnitDelay1 - 1];

  /* End of MATLAB Function: '<S8>/MATLAB Function' */

  /* Gain: '<Root>/Normalize' */
  rtb_Sum2 = DesignShowModel_P.Normalize_Gain * DesignShowModel_B.x;

  /* Gain: '<S4>/P' incorporates:
   *  Constant: '<Root>/Shank Offset'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S4>/Sum1'
   */
  rtb_UnitDelay1 = ((DesignShowModel_P.ShankOffset_Value - rtb_Sum2) -
                    uMultiWord2Double(&rtb_NormalizeFeedback.chunks[0U], 2, 0) *
                    1.3877787807814457E-17) * DesignShowModel_P.P_Gain;

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S17>/Constant2'
   */
  if (rtb_UnitDelay1 >= DesignShowModel_P.Switch_Threshold) {
    rtb_Abs1_i = DesignShowModel_P.Constant1_Value_j;
  } else {
    rtb_Abs1_i = DesignShowModel_P.Constant2_Value_d;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Abs: '<S17>/Abs' incorporates:
   *  Product: '<S17>/0 if Negative'
   */
  rtb_Abs = fabs(rtb_UnitDelay1 * rtb_Abs1_i);

  /* Product: '<S17>/0 If Positive' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Sum: '<S17>/Sum'
   */
  rtb_UnitDelay1 *= rtb_Abs1_i - DesignShowModel_P.Constant3_Value;

  /* Abs: '<S17>/Abs1' */
  rtb_UnitDelay1 = fabs(rtb_UnitDelay1);

  /* Sum: '<S4>/Sum2' */
  DesignShowModel_B.Sum2 = rtb_Abs + rtb_UnitDelay1;

  /* S-Function (arduinoanaloginput_sfcn): '<S3>/Feedback Voltage' */
  rtb_Product = MW_analogRead(DesignShowModel_P.FeedbackVoltage_p1_e);

  /* Gain: '<S3>/P' incorporates:
   *  Gain: '<S3>/Normalize Feedback'
   *  S-Function (arduinoanaloginput_sfcn): '<S3>/Feedback Voltage'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Abs1_i = (rtb_Sum2 - (real_T)((uint32_T)
    DesignShowModel_P.NormalizeFeedback_Gain_g * rtb_Product) * 3.0517578125E-5)
    * DesignShowModel_P.P_Gain_b;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   */
  if (rtb_Abs1_i >= DesignShowModel_P.Switch_Threshold_g) {
    rtb_Sum2 = DesignShowModel_P.Constant1_Value;
  } else {
    rtb_Sum2 = DesignShowModel_P.Constant2_Value;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Abs: '<S14>/Abs' incorporates:
   *  Product: '<S14>/0 if Negative'
   */
  rtb_Abs_l = fabs(rtb_Abs1_i * rtb_Sum2);

  /* Product: '<S14>/0 If Positive' incorporates:
   *  Constant: '<S14>/Constant3'
   *  Sum: '<S14>/Sum'
   */
  rtb_Abs1_i *= rtb_Sum2 - DesignShowModel_P.Constant3_Value_i;

  /* Abs: '<S14>/Abs1' */
  rtb_Abs1_i = fabs(rtb_Abs1_i);

  /* Sum: '<S3>/Sum2' */
  rtb_Sum2 = rtb_Abs_l + rtb_Abs1_i;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<S2>/Footer 1'
   *  Constant: '<S2>/Footer 2'
   *  Constant: '<S2>/Header'
   */
  if (DesignShowModel_P.Header_Value < 256.0) {
    if (DesignShowModel_P.Header_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[0] = (uint8_T)DesignShowModel_P.Header_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[0] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[0] = MAX_uint8_T;
  }

  if (DesignShowModel_B.Sum2 < 256.0) {
    if (DesignShowModel_B.Sum2 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[1] = (uint8_T)DesignShowModel_B.Sum2;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[1] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[1] = MAX_uint8_T;
  }

  if (DesignShowModel_B.Sum2 < 256.0) {
    if (DesignShowModel_B.Sum2 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[2] = (uint8_T)DesignShowModel_B.Sum2;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[2] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[2] = MAX_uint8_T;
  }

  if (DesignShowModel_B.Sum2 < 256.0) {
    if (DesignShowModel_B.Sum2 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[3] = (uint8_T)DesignShowModel_B.Sum2;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[3] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[3] = MAX_uint8_T;
  }

  if (DesignShowModel_B.Sum2 < 256.0) {
    if (DesignShowModel_B.Sum2 >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[4] = (uint8_T)DesignShowModel_B.Sum2;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[4] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[4] = MAX_uint8_T;
  }

  if (rtb_Sum2 < 256.0) {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[5] = (uint8_T)rtb_Sum2;
    tmp[6] = (uint8_T)rtb_Sum2;
    tmp[7] = (uint8_T)rtb_Sum2;
    tmp[8] = (uint8_T)rtb_Sum2;
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[5] = MAX_uint8_T;
    tmp[6] = MAX_uint8_T;
    tmp[7] = MAX_uint8_T;
    tmp[8] = MAX_uint8_T;
  }

  if (DesignShowModel_P.Footer1_Value < 256.0) {
    if (DesignShowModel_P.Footer1_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[9] = (uint8_T)DesignShowModel_P.Footer1_Value;
    } else {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[9] = 0U;
    }
  } else {
    /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
    tmp[9] = MAX_uint8_T;
  }

  if (DesignShowModel_P.Footer2_Value < 256.0) {
    if (DesignShowModel_P.Footer2_Value >= 0.0) {
      /* S-Function (arduinoserialwrite_sfcn): '<S2>/Serial Transmit' */
      tmp[10] = (uint8_T)DesignShowModel_P.Footer2_Value;
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
  Serial_write(DesignShowModel_P.SerialTransmit_portNumber, tmp, 11UL);

  /* MinMax: '<S3>/Extend Saturation' */
  rtb_Sum2 = floor(rtb_Abs_l);
  if (rtb_Sum2 < 32768.0) {
    rtb_RetractSaturation = (int16_T)rtb_Sum2;
  } else {
    rtb_RetractSaturation = MAX_int16_T;
  }

  /* End of MinMax: '<S3>/Extend Saturation' */

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  tmp_0 = rtb_RetractSaturation;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  } else {
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }
  }

  rtb_DataTypeConversion_p = (uint8_T)tmp_0;

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_analogWrite(DesignShowModel_P.PWM_pinNumber, rtb_DataTypeConversion_p);

  /* MinMax: '<S3>/Retract Saturation' */
  rtb_Sum2 = floor(rtb_Abs1_i);
  if (rtb_Sum2 < 32768.0) {
    rtb_RetractSaturation = (int16_T)rtb_Sum2;
  } else {
    rtb_RetractSaturation = MAX_int16_T;
  }

  /* End of MinMax: '<S3>/Retract Saturation' */

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  tmp_0 = rtb_RetractSaturation;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  } else {
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }
  }

  rtb_DataTypeConversion_p = (uint8_T)tmp_0;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_analogWrite(DesignShowModel_P.PWM_pinNumber_n, rtb_DataTypeConversion_p);

  /* MinMax: '<S4>/Extend Saturation' */
  rtb_Sum2 = floor(rtb_Abs);
  if (rtb_Sum2 < 32768.0) {
    rtb_RetractSaturation = (int16_T)rtb_Sum2;
  } else {
    rtb_RetractSaturation = MAX_int16_T;
  }

  /* End of MinMax: '<S4>/Extend Saturation' */

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  tmp_0 = rtb_RetractSaturation;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  } else {
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }
  }

  rtb_DataTypeConversion_p = (uint8_T)tmp_0;

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_analogWrite(DesignShowModel_P.PWM_pinNumber_p, rtb_DataTypeConversion_p);

  /* MinMax: '<S4>/Retract Saturation' */
  rtb_Sum2 = floor(rtb_UnitDelay1);
  if (rtb_Sum2 < 32768.0) {
    rtb_RetractSaturation = (int16_T)rtb_Sum2;
  } else {
    rtb_RetractSaturation = MAX_int16_T;
  }

  /* End of MinMax: '<S4>/Retract Saturation' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  tmp_0 = rtb_RetractSaturation;
  if (tmp_0 < 0) {
    tmp_0 = 0;
  } else {
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }
  }

  rtb_DataTypeConversion_p = (uint8_T)tmp_0;

  /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S16>/PWM' */
  MW_analogWrite(DesignShowModel_P.PWM_pinNumber_g, rtb_DataTypeConversion_p);
}

/* Model update function */
void DesignShowModel_update(void)
{
  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  DesignShowModel_DW.UnitDelay1_DSTATE = DesignShowModel_B.index_out;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  DesignShowModel_DW.UnitDelay_DSTATE = DesignShowModel_B.Sum2;

  /* Update for UnitDelay: '<S5>/Unit Delay1' */
  DesignShowModel_DW.UnitDelay1_DSTATE_o = DesignShowModel_B.x;
}

/* Model initialize function */
void DesignShowModel_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(DesignShowModel_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &DesignShowModel_B), 0,
                sizeof(B_DesignShowModel_T));

  /* states (dwork) */
  (void) memset((void *)&DesignShowModel_DW, 0,
                sizeof(DW_DesignShowModel_T));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S4>/Feedback Voltage' */
  MW_pinModeAnalogInput(DesignShowModel_P.FeedbackVoltage_p1);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S3>/Feedback Voltage' */
  MW_pinModeAnalogInput(DesignShowModel_P.FeedbackVoltage_p1_e);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_pinModeOutput(DesignShowModel_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_pinModeOutput(DesignShowModel_P.PWM_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_pinModeOutput(DesignShowModel_P.PWM_pinNumber_p);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S16>/PWM' */
  MW_pinModeOutput(DesignShowModel_P.PWM_pinNumber_g);

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
  DesignShowModel_DW.UnitDelay1_DSTATE =
    DesignShowModel_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  DesignShowModel_DW.UnitDelay_DSTATE =
    DesignShowModel_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  DesignShowModel_DW.UnitDelay1_DSTATE_o =
    DesignShowModel_P.UnitDelay1_InitialCondition_f;

  /* InitializeConditions for Chart: '<S6>/Chart' */
  DesignShowModel_DW.is_active_c3_DesignShowModel = 0U;
  DesignShowModel_DW.is_c3_DesignShowModel = DesignShowMo_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void DesignShowModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
