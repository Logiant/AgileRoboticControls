/*
 * File: FrequencyResponseTest.h
 *
 * Code generated for Simulink model 'FrequencyResponseTest'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Apr 29 20:13:30 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FrequencyResponseTest_h_
#define RTW_HEADER_FrequencyResponseTest_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef FrequencyResponseTest_COMMON_INCLUDES_
# define FrequencyResponseTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* FrequencyResponseTest_COMMON_INCLUDES_ */

#include "FrequencyResponseTest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  uint8_T DataTypeConversion_k;        /* '<S2>/Data Type Conversion' */
  uint8_T DataTypeConversion_l;        /* '<S3>/Data Type Conversion' */
} B_FrequencyResponseTest_T;

/* Parameters (auto storage) */
struct P_FrequencyResponseTest_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  uint32_T PWM_pinNumber_b;            /* Mask Parameter: PWM_pinNumber_b
                                        * Referenced by: '<S2>/PWM'
                                        */
  uint32_T PWM_pinNumber_j;            /* Mask Parameter: PWM_pinNumber_j
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T ReferenceVoltagePercentage_Amp;/* Expression: 1
                                         * Referenced by: '<Root>/Reference Voltage (Percentage)'
                                         */
  real_T ReferenceVoltagePercentage_Bias;/* Expression: 0
                                          * Referenced by: '<Root>/Reference Voltage (Percentage)'
                                          */
  real_T ReferenceVoltagePercentage_Freq;/* Expression: 7
                                          * Referenced by: '<Root>/Reference Voltage (Percentage)'
                                          */
  real_T ReferenceVoltagePercentage_Phas;/* Expression: 0
                                          * Referenced by: '<Root>/Reference Voltage (Percentage)'
                                          */
  real_T ScaleValue_Gain;              /* Expression: 255
                                        * Referenced by: '<Root>/Scale Value'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T ReferenceGain_Gain;           /* Expression: 255
                                        * Referenced by: '<Root>/Reference Gain'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FrequencyResponseTest_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_FrequencyResponseTest_T FrequencyResponseTest_P;

/* Block signals (auto storage) */
extern B_FrequencyResponseTest_T FrequencyResponseTest_B;

/* Model entry point functions */
extern void FrequencyResponseTest_initialize(void);
extern void FrequencyResponseTest_output(void);
extern void FrequencyResponseTest_update(void);
extern void FrequencyResponseTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FrequencyResponseTes_T *const FrequencyResponseTest_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FrequencyResponseTest'
 * '<S1>'   : 'FrequencyResponseTest/Extend Signal'
 * '<S2>'   : 'FrequencyResponseTest/Reference Signal'
 * '<S3>'   : 'FrequencyResponseTest/Retract Signal'
 * '<S4>'   : 'FrequencyResponseTest/Subsystem'
 */
#endif                                 /* RTW_HEADER_FrequencyResponseTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
