#define Switch1 8 /* Defining Switch1 pin number */
#define Switch2 9 /* Defining Switch2 pin number */
#define LED1 10   /* Defining LED1 pin number */
#define LED2 11   /* Defining LED2 pin number */

void setup()
{
    pinMode(Switch1, INPUT_PULLUP); /* Defining Switch1 pin as input with pullup */
    pinMode(Switch2, INPUT_PULLUP); /* Defining Switch2 pin as input with pullup */
    pinMode(LED1, OUTPUT);          /* Defining LED1 pin as output */
    pinMode(LED2, OUTPUT);          /* Defining LED2 pin as output */
}

void loop()
{
    uint8_t Switch1_State = digitalRead(Switch1); /* Reading Switch1 state */
    uint8_t Switch2_State = digitalRead(Switch2); /* Reading Switch2 state */

    if ((Switch1_State == HIGH) && (Switch2_State == HIGH)) /* If Switch1 and Switch2 are both pressed */
    {
        digitalWrite(LED1, LOW); /* Turn off LED1 */
        digitalWrite(LED2, LOW); /* Turn off LED2 */
    }

    else if ((Switch1_State == HIGH) && (Switch2_State == LOW)) /* If Switch1 is only pressed */
    {
        digitalWrite(LED1, LOW);  /* Turn off LED1 */
        digitalWrite(LED2, HIGH); /* Turn on LED2 */
    }

    else if ((Switch1_State == LOW) && (Switch2_State == HIGH)) /* If Switch2 is only pressed */
    {
        digitalWrite(LED1, HIGH); /* Turn on LED1 */
        digitalWrite(LED2, LOW);  /* Turn off LED2 */
    }

    else if ((Switch1_State == LOW) && (Switch2_State == LOW)) /* If Switch1 and Switch2 are not pressed*/
    {
        digitalWrite(LED1, HIGH); /* Turn on LED1 */
        digitalWrite(LED2, HIGH); /* Turn on LED2 */
    }
}
