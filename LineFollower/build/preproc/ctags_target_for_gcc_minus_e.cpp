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
/* Defining Senors pins */






/* Defining Motor driver pins */





/*--------------------------SPEED control Section-------------------*/

void SpeedLogic(int spdL, int spdR) /* A function

{

    spdR = -spdR;



    if (spdL < 0)

    {

        analogWrite(c2, 0);

        analogWrite(c1, -spdL);

    }

    else

    {

        analogWrite(c2, spdL);

        analogWrite(c1, 0);

    }



    if (spdR < 0)

    {

        analogWrite(c3, 0);

        analogWrite(c4, -spdR);

    }

    else

    {

        analogWrite(c3, spdR);

        analogWrite(c4, 0);

    }

}



// /* Error Generation Section */
# 59 "d:\\Automatic Control Systems Tasks\\LineFollower\\main.ino"
/* =============================================================================== */

int Error = 0;
int outlineCnt = 0;

void sensLogic(int X)
{
    switch (X)
    {
    case 0:
        outlineCnt = 0;
        Error = Error;
        break;

    case 31:
        outlineCnt = 0;
        Error = 0;
        break;

    case 2:
    case 6:
        outlineCnt = 0;
        Error = 1;
        break;

    case 1:
    case 3:
    case 7:
        outlineCnt = 0;
        Error = 2;
        break;

    case 4:
        outlineCnt = 0;
        Error = 0;
        break;

    case 8:
    case 12:
        outlineCnt = 0;
        Error = -1;
        break;

    case 16:
    case 24:
    case 28:
        outlineCnt = 0;
        Error = -2;
        break;

    default:
        outlineCnt = 0;
        Error = Error;
        break;
    }

    if (outlineCnt > 2)
    {
        SpeedLogic(0, 0);
    }
    else
    {

        float ctrl = calcPid(Error);
        SpeedLogic(85 - ctrl, 85 + ctrl);
    }
}

/*=========================================================================================== */
/* PID Contorl */
float Kp = 40;
float Ki = 0.45;
float Kd = 1000;
float error, errorLast, erroInt;

float calcPid(float input)
{
    float errorDiff;
    float output;
    error = error * 0.7 + input * 0.3; // filter
    // error = input;
    errorDiff = error - errorLast;
    erroInt = ((erroInt + error)<(-50)?(-50):((erroInt + error)>(50)?(50):(erroInt + error)));
    output = Kp * error + Ki * erroInt + Kd * errorDiff;

    errorLast = error;

    return output;
}

/* Track data ===========================================================================*/
int sensTrack()
{
    int ret = 0;
    int a[5] = {digitalRead(4),
                digitalRead(8),
                digitalRead(10),
                digitalRead(11),
                digitalRead(7)};

    for (int i = 0; i < 5; i++)
    {
        if (a[i] == 0x1)
            ret += (0x1 << i);
    }

    return ret;
}

/* ======================================================================================== */

void setup()
{

    pinMode(4, 0x0);
    pinMode(8, 0x0);
    pinMode(10, 0x0);
    pinMode(11, 0x0);
    pinMode(7, 0x0);
    pinMode(3, 0x1);
    pinMode(5, 0x1);
    pinMode(6, 0x1);
    pinMode(9, 0x1);
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
}

/* ==========================================================================================*/

int pos;
void loop()
{
    delay(4);
    pos = sensTrack();
    sensLogic(pos);
}
