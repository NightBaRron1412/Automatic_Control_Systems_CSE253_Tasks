# 1 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
/******************************************************************************

 * Copyright (C) 2022 by Amir Shetaia

 *

 * Redistribution, modification or use of this software in source or binary

 * forms is permitted as long as the files maintain this copyright.

 * Amir Shetaia is not liable for any misuse of this material.

 *

 *****************************************************************************/
# 9 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
/**

 * @file main.c

 * @brief LineFollower Robot using Arduino as PID controller

 * @author Amir Shetaia

 * @date 12 May 2022

 */
# 16 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
# 17 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino" 2

uint8_t u8Pos; /* A variable to store the current position of the robot */
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
void setup()
{
    /* Defining Pins Modes */
    pinMode(4, 0x0);
    pinMode(8, 0x0);
    pinMode(10, 0x0);
    pinMode(11, 0x0);
    pinMode(7, 0x0);
    pinMode(3, 0x1);
    pinMode(5, 0x1);
    pinMode(6, 0x1);
    pinMode(9, 0x1);

    /* Initializing motors speed at ZERO */
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
}

/* ------------------------- Loop function ----------------------------- */
void loop()
{
    delay(4); /* Wait for 4 ms */
    u8Pos = u8SensorsReading(); /* Read the current position of the robot */
    VidError(u8Pos); /* Calculate the error value */
}

/*-------------------------- Reading sensors to determine robot postion -------------------*/
uint8_t u8SensorsReading(void)
{
    uint8_t Local_u8Res = 0; /* A variable to store the current position of the robot in a binary form*/
    uint8_t readings[5] = {digitalRead(4),
                           digitalRead(8),
                           digitalRead(10),
                           digitalRead(11),
                           digitalRead(7)}; /* Sensor readings */

    for (uint8_t i = 0; i < 5; i++) /* looping through the sensors readings */
    {
        if (readings[i] == 0x1) /* if the sensor reading is HIGH */
            Local_u8Res += (0x1 << i); /* adding the sensor reading to the binary form */
    }

    return Local_u8Res; /* returning the binary form of the current position of the robot */
}

/*-------------------------- Error Generation Section -------------------*/
void VidError(uint8_t Copy_u8SensorsReading)
{
    switch (Copy_u8SensorsReading) /* Error generation logic */
    {
    case 0:
        u8TrackError = u8TrackError;
        break;

    case 31:
        u8TrackError = 0;
        break;

    case 2:
    case 6:
        u8TrackError = 1;
        break;

    case 1:
    case 3:
    case 7:
        u8TrackError = 2;
        break;

    case 4:
        u8TrackError = 0;
        break;

    case 8:
    case 12:
        u8TrackError = -1;
        break;

    case 16:
    case 24:
    case 28:
        u8TrackError = -2;
        break;

    default:
        u8TrackError = u8TrackError;
        break;
    }

    float Local_f32Ctrl = f32CalcPID(u8TrackError); /* applying PID control */
    VidSpeedLogic(u8MaxSpeed - Local_f32Ctrl, u8MaxSpeed + Local_f32Ctrl); /* controlling the motors based on PID Error */
}

/*-------------------------- PID control Section -------------------*/
float f32CalcPID(uint8_t Copy_u8TrackError)
{
    float Local_f32ErrorDiff;
    float Local_f32Output;
    f32Error = f32Error * 0.7 + Copy_u8TrackError * 0.3; /* Filtering the error value */
    /* error = Copy_u8TrackError; */
    Local_f32ErrorDiff = f32Error - f32ErrorLast; /* Calculating the error difference */
    f32ErrorInt = ((f32ErrorInt + f32Error)<(-50)?(-50):((f32ErrorInt + f32Error)>(50)?(50):(f32ErrorInt + f32Error))); /* Calculating the integral error */
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
        analogWrite(5, 0);
        analogWrite(3, -Copy_u8SpdL);
    }
    else
    {
        analogWrite(5, Copy_u8SpdL);
        analogWrite(3, 0);
    }

    if (Copy_u8SpdR < 0)
    {
        analogWrite(6, 0);
        analogWrite(9, -Copy_u8SpdR);
    }
    else
    {
        analogWrite(6, Copy_u8SpdR);
        analogWrite(9, 0);
    }
}
