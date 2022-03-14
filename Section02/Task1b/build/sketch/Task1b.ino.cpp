#include <Arduino.h>
#line 1 "d:\\Automatic Control Systems Tasks\\Section02\\Task1b\\Task1b.ino"
#define ldr A0 /* Defining the pin for the LDR */

#line 3 "d:\\Automatic Control Systems Tasks\\Section02\\Task1b\\Task1b.ino"
void setup();
#line 9 "d:\\Automatic Control Systems Tasks\\Section02\\Task1b\\Task1b.ino"
void loop();
#line 3 "d:\\Automatic Control Systems Tasks\\Section02\\Task1b\\Task1b.ino"
void setup()
{
    pinMode(ldr, INPUT); /* Setting the potentiometer as input */
    Serial.begin(9600); /* Beginning the serial with 9600 baud rate */
}

void loop()
{
    int ldrValue = analogRead(ldr); /* Read the LDR value and assign it in a variable */
    Serial.println(ldrValue);       /* Print the LDR value on the serial monitor */
}

