#define LED 10 /* Defining LED pin to use */

void setup()
{
    pinMode(LED, OUTPUT); /* Defining LED pin as output */
}

void loop()
{
    digitalWrite(LED, HIGH); /* Turn on LED */
    delay(1000);             /* Delay 1 second */
    digitalWrite(LED, LOW);  /* Turn off LED */
    delay(1000);             /* Delay 1 second */
}