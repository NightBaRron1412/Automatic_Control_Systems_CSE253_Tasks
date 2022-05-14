/******************************************************************************
 * Copyright (C) 2022 by Amir Shetaia
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 * Amir Shetaia is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file private.h
 * @brief Header file for LineFollower Robot using Arduino as PID controller
 *
 * Header file that contains important functions prototypes,
 * for a LineFollower Robot using Arduino as PID controller.
 *
 * @author Amir Shetaia
 * @date 12 May 2022
 *
 */

#ifndef __PRIVATE_H__
#define __PRIVATE_H__

/* Defining Senors pins */
#define SENSOR_RIGHT1 4
#define SENSOR_RIGHT2 8
#define SENSOR_MIDDLE 10
#define SENSOR_LEFT1 11
#define SENSOR_LEFT2 7

/* Defining Motor driver pins */
#define MOTOR_CONTROL1 3
#define MOTOR_CONTROL2 5
#define MOTOR_CONTROL3 6
#define MOTOR_CONTROL4 9

/*---------------- Function Prototypes -------------------*/

uint8_t u8SensorsReading(void);
/**
 * @brief A function to get the sensors readings
 * and return the position of the robot in binary form
 *
 * @param void
 *
 * @return u8 Local_u8Res
 */

void VidError(uint8_t Copy_u8SensorsReading);
/**
 * @brief A function that generates error values based on current sensors readings
 *
 * @param u8 Copy_u8SensorsReading
 *
 * @return void
 */

float f32CalcPID(uint8_t Copy_TrackError);
/**
 * @brief A function to calculate PID control values based on current error value
 *
 * @param u8 Copy_TrackError
 *
 * @return Local_f32Output
 */

void VidSpeedLogic(uint8_t Copy_SpdL, uint8_t Copy_SpdR);
/**
 * @brief A function that controls the speed and direction of the motors
 * based on the PID error value
 *
 * @param u8 spdL
 * @param u8 spdR
 *
 * @return void
 */

#endif /*__PRIVATE_H__*/
