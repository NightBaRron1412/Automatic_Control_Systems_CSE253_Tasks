# 1 "d:\\Control Systems Tasks\\Section1\\Task3\\Task3.ino"





void setup()
{
    pinMode(8 /* Defining Switch1 pin number */, 0x2); /* Defining Switch1 pin as input with pullup */
    pinMode(9 /* Defining Switch2 pin number */, 0x2); /* Defining Switch2 pin as input with pullup */
    pinMode(10 /* Defining LED1 pin number */, 0x1); /* Defining LED1 pin as output */
    pinMode(11 /* Defining LED2 pin number */, 0x1); /* Defining LED2 pin as output */
}

void loop()
{
    uint8_t Switch1_State = digitalRead(8 /* Defining Switch1 pin number */); /* Reading Switch1 state */
    uint8_t Switch2_State = digitalRead(9 /* Defining Switch2 pin number */); /* Reading Switch2 state */

    if ((Switch1_State == 0x1) && (Switch2_State == 0x1)) /* If Switch1 and Switch2 are both pressed */
    {
        digitalWrite(10 /* Defining LED1 pin number */, 0x0); /* Turn off LED1 */
        digitalWrite(11 /* Defining LED2 pin number */, 0x0); /* Turn off LED2 */
    }

    else if ((Switch1_State == 0x1) && (Switch2_State == 0x0)) /* If Switch1 is only pressed */
    {
        digitalWrite(10 /* Defining LED1 pin number */, 0x0); /* Turn off LED1 */
        digitalWrite(11 /* Defining LED2 pin number */, 0x1); /* Turn on LED2 */
    }

    else if ((Switch1_State == 0x0) && (Switch2_State == 0x1)) /* If Switch2 is only pressed */
    {
        digitalWrite(10 /* Defining LED1 pin number */, 0x1); /* Turn on LED1 */
        digitalWrite(11 /* Defining LED2 pin number */, 0x0); /* Turn off LED2 */
    }

    else if ((Switch1_State == 0x0) && (Switch2_State == 0x0)) /* If Switch1 and Switch2 are not pressed*/
    {
        digitalWrite(10 /* Defining LED1 pin number */, 0x1); /* Turn on LED1 */
        digitalWrite(11 /* Defining LED2 pin number */, 0x1); /* Turn on LED2 */
    }
}
