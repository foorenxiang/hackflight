/*
 * This file is part of baseflight
 * Licensed under GPL V3 or modified DCL - see https://github.com/multiwii/baseflight/blob/master/README.md
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "printf.h"

#define RC_CHANS    (18)

#ifndef abs
#define abs(x) ((x) > 0 ? (x) : -(x))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif


enum {
    ROLL = 0,
    PITCH,
    YAW,
    THROTTLE,
    AUX1,
    AUX2,
    AUX3,
    AUX4
};

typedef enum {
    X = 0,
    Y,
    Z
} sensor_axis_e;

#ifndef  EXTERN
#define  EXTERN  extern
#endif

// Board =======================================================

void     board_checkReboot(bool pendReboot);
void     board_delayMilliseconds(uint32_t msec);
uint16_t board_getI2cErrorCounter(void);
uint32_t board_getMicros();
void     board_imuInit(uint16_t *acc1G, float * gyroScale);
void     board_imuRead(int16_t accADC[3], int16_t gyroADC[3]);
void     board_init(void);
void     board_led0Off(void);
void     board_led0On(void);
void     board_led0Toggle(void);
void     board_led1Off(void);
void     board_led1On(void);
void     board_led1Toggle(void);
uint16_t board_pwmRead(uint8_t chan);
void     board_reboot(void);
uint8_t  board_serialAvailable(void);
uint8_t  board_serialRead(void);
void     board_serialWrite(uint8_t c);
void     board_writeMotor(uint8_t index, uint16_t value);

// Utilities

int constrainer(int amt, int low, int high);

// Config =====================================================

static const uint8_t CONFIG_LEVEL_P  = 90;
static const uint8_t CONFIG_LEVEL_I  = 10;
static const uint8_t CONFIG_LEVEL_D  = 100;

// roll, pitch, yaw
static const uint8_t CONFIG_AXIS_P[3] = {40, 40, 85};
static const uint8_t CONFIG_AXIS_I[3] = {30, 30, 45};
static const uint8_t CONFIG_AXIS_D[3] = {23, 23, 0};

#define CONFIG_MAGNETIC_DECLINATION                 0
#define CONFIG_HORIZON_MODE                         true
#define CONFIG_CALIBRATING_GYRO_CYCLES              1000
#define CONFIG_CALIBRATING_ACC_CYCLES               400
#define CONFIG_MIDRC                                1490
#define CONFIG_MINCOMMAND                           1000
#define CONFIG_GYRO_CMPF_FACTOR                     600    
#define CONFIG_GYRO_CMPFM_FACTOR                    250  
#define CONFIG_MINTHROTTLE                          990
#define CONFIG_MAXTHROTTLE                          2010
#define CONFIG_MINCHECK                             1100
#define CONFIG_MAXCHECK                             1900
#define CONFIG_YAW_CONTROL_DIRECTION                1   /* 1 or -1 */
#define CONFIG_MAX_ANGLE_INCLINATION                500 /* 50 degrees */

#define CONFIG_IMU_LOOPTIME_USEC                    3500
#define CONFIG_RC_LOOPTIME_USEC                     20000
#define CONFIG_CALIBRATE_ACCTIME_USEC               500000

#define CONFIG_MORON_THRESHOLD                      32
#define CONFIG_REBOOT_CHARACTER                     'R'
#define CONFIG_RC_EXPO_8                            65
#define CONFIG_RC_RATE_8                            90
#define CONFIG_THR_MID_8                            50
#define CONFIG_THR_EXPO_8                           0
#define CONFIG_YAW_DIRECTION                        1

#define CONFIG_ACC_LPF_FACTOR                       4
#define CONFIG_ACCZ_DEADBAND                        40
#define CONFIG_ACCXY_DEADBAND                       40
#define CONFIG_ACCZ_LPF_CUTOFF                      5.0F
#define CONFIG_SMALL_ANGLE                          250 // tenths of a degree
#define CONFIG_BARO_TAB_SIZE                        21

static const int16_t CONFIG_ANGLE_TRIM[2]      = {-50, -25};
static const uint8_t CONFIG_RCMAP[8]           = {0, 1, 3, 2, 4, 5, 6, 7};