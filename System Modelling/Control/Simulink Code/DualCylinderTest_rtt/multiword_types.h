/*
 * File: multiword_types.h
 *
 * Code generated for Simulink model 'DualCylinderTest'.
 *
 * Model version                  : 1.129
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Fri May 22 11:32:24 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef __MULTIWORD_TYPES_H__
#define __MULTIWORD_TYPES_H__
#include "rtwtypes.h"

/*
 * MultiWord supporting definitions
 */
typedef long int long_T;

/*
 * MultiWord types
 */
typedef struct {
  uint32_T chunks[2];
} int64m_T;

typedef struct {
  int64m_T re;
  int64m_T im;
} cint64m_T;

typedef struct {
  uint32_T chunks[2];
} uint64m_T;

typedef struct {
  uint64m_T re;
  uint64m_T im;
} cuint64m_T;

typedef struct {
  uint32_T chunks[3];
} int96m_T;

typedef struct {
  int96m_T re;
  int96m_T im;
} cint96m_T;

typedef struct {
  uint32_T chunks[3];
} uint96m_T;

typedef struct {
  uint96m_T re;
  uint96m_T im;
} cuint96m_T;

typedef struct {
  uint32_T chunks[4];
} int128m_T;

typedef struct {
  int128m_T re;
  int128m_T im;
} cint128m_T;

typedef struct {
  uint32_T chunks[4];
} uint128m_T;

typedef struct {
  uint128m_T re;
  uint128m_T im;
} cuint128m_T;

typedef struct {
  uint32_T chunks[5];
} int160m_T;

typedef struct {
  int160m_T re;
  int160m_T im;
} cint160m_T;

typedef struct {
  uint32_T chunks[5];
} uint160m_T;

typedef struct {
  uint160m_T re;
  uint160m_T im;
} cuint160m_T;

typedef struct {
  uint32_T chunks[6];
} int192m_T;

typedef struct {
  int192m_T re;
  int192m_T im;
} cint192m_T;

typedef struct {
  uint32_T chunks[6];
} uint192m_T;

typedef struct {
  uint192m_T re;
  uint192m_T im;
} cuint192m_T;

typedef struct {
  uint32_T chunks[7];
} int224m_T;

typedef struct {
  int224m_T re;
  int224m_T im;
} cint224m_T;

typedef struct {
  uint32_T chunks[7];
} uint224m_T;

typedef struct {
  uint224m_T re;
  uint224m_T im;
} cuint224m_T;

typedef struct {
  uint32_T chunks[8];
} int256m_T;

typedef struct {
  int256m_T re;
  int256m_T im;
} cint256m_T;

typedef struct {
  uint32_T chunks[8];
} uint256m_T;

typedef struct {
  uint256m_T re;
  uint256m_T im;
} cuint256m_T;

#endif                                 /* __MULTIWORD_TYPES_H__ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
