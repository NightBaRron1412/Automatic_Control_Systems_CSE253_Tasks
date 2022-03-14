#define Button 10 /* Defining button pin to use */
#define LED 11    /* Defining LED pin to use */

void setup()
{
    pinMode(Button, INPUT); /* Defining button pin as input */
    pinMode(LED, OUTPUT);   /* Defining LED pin as output */
}

void loop()
{
    if (digitalRead(Button) == HIGH) /* If button is pressed */
    {
        digitalWrite(LED, HIGH); /* Turn on LED */
    }
    else
    {
        digitalWrite(LED, LOW); /* Turn off LED */
    }
}