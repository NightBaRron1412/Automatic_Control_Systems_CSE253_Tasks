#include <Arduino.h>
#line 1 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
/******************************************************************************
 * Copyright (C) 2022 by Amir Shetaia
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 * Amir Shetaia is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief LineFollower Robot using Arduino as PID controller
 * @author Amir Shetaia
 * @date 12 May 2022
 */

#include "private.h" /* Including private header file */

uint8_t u8Pos;            /* A variable to store the current position of the robot */
uint8_t u8TrackError = 0; /* A variable to store the current error value */

/* PID Contorl gain values */
float f32Kp = 40;
float f32Ki = 0.45;
float f32Kd = 1000;
/* PID error values */
float f32Error, f32ErrorLast, f32ErrorInt;

/* Maximum speed value*/
uint8_t u8MaxSpeed = 85;

/* ------------------------- Setup function ----------------------------- */
#line 32 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
void setup();
#line 53 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
void loop();
#line 61 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
uint8_t u8SensorsReading(void);
#line 80 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
void VidError(uint8_t Copy_u8SensorsReading);
#line 128 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
float f32CalcPID(uint8_t Copy_u8TrackError);
#line 144 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
void VidSpeedLogic(uint8_t Copy_u8SpdL, uint8_t Copy_u8SpdR);
#line 32 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
void setup()
{
    /* Defining Pins Modes */
    pinMode(SENSOR_RIGHT1, INPUT);
    pinMode(SENSOR_RIGHT2, INPUT);
    pinMode(SENSOR_MIDDLE, INPUT);
    pinMode(SENSOR_LEFT1, INPUT);
    pinMode(SENSOR_LEFT2, INPUT);
    pinMode(MOTOR_CONTROL1, OUTPUT);
    pinMode(MOTOR_CONTROL2, OUTPUT);
    pinMode(MOTOR_CONTROL3, OUTPUT);
    pinMode(MOTOR_CONTROL4, OUTPUT);

    /* Initializing motors speed at ZERO */
    analogWrite(MOTOR_CONTROL1, 0);
    analogWrite(MOTOR_CONTROL2, 0);
    analogWrite(MOTOR_CONTROL3, 0);
    analogWrite(MOTOR_CONTROL4, 0);
}

/* ------------------------- Loop function ----------------------------- */
void loop()
{
    delay(4);                   /* Wait for 4 ms */
    u8Pos = u8SensorsReading(); /* Read the current position of the robot */
    VidError(u8Pos);            /* Calculate the error value */
}

/*-------------------------- Reading sensors to determine robot postion -------------------*/
uint8_t u8SensorsReading(void)
{
    uint8_t Local_u8Res = B00000; /* A variable to store the current position of the robot in a binary form*/
    uint8_t readings[5] = {digitalRead(SENSOR_RIGHT1),
                           digitalRead(SENSOR_RIGHT2),
                           digitalRead(SENSOR_MIDDLE),
                           digitalRead(SENSOR_LEFT1),
                           digitalRead(SENSOR_LEFT2)}; /* Sensor readings */

    for (uint8_t i = 0; i < 5; i++) /* looping through the sensors readings */
    {
        if (readings[i] == HIGH)       /* if the sensor reading is HIGH */
            Local_u8Res += (0x1 << i); /* adding the sensor reading to the binary form */
    }

    return Local_u8Res; /* returning the binary form of the current position of the robot */
}

/*-------------------------- Error Generation Section -------------------*/
void VidError(uint8_t Copy_u8SensorsReading)
{
    switch (Copy_u8SensorsReading) /* Error generation logic */
    {
    case B00000:
        u8TrackError = u8TrackError;
        break;

    case B11111:
        u8TrackError = 0;
        break;

    case B00010:
    case B00110:
        u8TrackError = 1;
        break;

    case B00001:
    case B00011:
    case B00111:
        u8TrackError = 2;
        break;

    case B00100:
        u8TrackError = 0;
        break;

    case B01000:
    case B01100:
        u8TrackError = -1;
        break;

    case B10000:
    case B11000:
    case B11100:
        u8TrackError = -2;
        break;

    default:
        u8TrackError = u8TrackError;
        break;
    }

    float Local_f32Ctrl = f32CalcPID(u8TrackError);                        /* applying PID control */
    VidSpeedLogic(u8MaxSpeed - Local_f32Ctrl, u8MaxSpeed + Local_f32Ctrl); /* controlling the motors based on PID Error */
}

/*-------------------------- PID control Section -------------------*/
float f32CalcPID(uint8_t Copy_u8TrackError)
{
    float Local_f32ErrorDiff;
    float Local_f32Output;
    f32Error = f32Error * 0.7 + Copy_u8TrackError * 0.3; /* Filtering the error value */
    /* error = Copy_u8TrackError; */
    Local_f32ErrorDiff = f32Error - f32ErrorLast;                                          /* Calculating the error difference */
    f32ErrorInt = constrain(f32ErrorInt + f32Error, -50, 50);                              /* Calculating the integral error */
    Local_f32Output = f32Kp * f32Error + f32Ki * f32ErrorInt + f32Kd * Local_f32ErrorDiff; /* Calculating the PID output */

    f32ErrorLast = f32Error; /* Saving the current error value */

    return Local_f32Output;
}

/*--------------------------SPEED control Section-------------------*/
void VidSpeedLogic(uint8_t Copy_u8SpdL, uint8_t Copy_u8SpdR)
{
    Copy_u8SpdR = -Copy_u8SpdR;

    if (Copy_u8SpdL < 0)
    {
        analogWrite(MOTOR_CONTROL2, 0);
        analogWrite(MOTOR_CONTROL1, -Copy_u8SpdL);
    }
    else
    {
        analogWrite(MOTOR_CONTROL2, Copy_u8SpdL);
        analogWrite(MOTOR_CONTROL1, 0);
    }

    if (Copy_u8SpdR < 0)
    {
        analogWrite(MOTOR_CONTROL3, 0);
        analogWrite(MOTOR_CONTROL4, -Copy_u8SpdR);
    }
    else
    {
        analogWrite(MOTOR_CONTROL3, Copy_u8SpdR);
        analogWrite(MOTOR_CONTROL4, 0);
    }
}
