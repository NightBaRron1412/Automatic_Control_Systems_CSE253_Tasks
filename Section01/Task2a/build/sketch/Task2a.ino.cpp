#include <Arduino.h>
#line 1 "d:\\Control Systems Tasks\\Section1\\Task2a\\Task2a.ino"
#define LED 10 /* Defining LED pin to use */

#line 3 "d:\\Control Systems Tasks\\Section1\\Task2a\\Task2a.ino"
void setup();
#line 8 "d:\\Control Systems Tasks\\Section1\\Task2a\\Task2a.ino"
void loop();
#line 3 "d:\\Control Systems Tasks\\Section1\\Task2a\\Task2a.ino"
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
