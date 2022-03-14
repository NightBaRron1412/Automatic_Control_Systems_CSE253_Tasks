# 1 "d:\\Automatic Control Systems Tasks\\Section02\\Task2\\Task2.ino"





void setup()
{
    pinMode(A0 /* Defining the pin for the LDR */, 0x0); /* Setting the LDR as input */
    pinMode(A1 /* Defining the pin for the pot */, 0x0); /* Setting the potentiometer as input */
    pinMode(3 /* Defining the pin for the red LED */, 0x1); /* Setting the red LED as output */
    pinMode(4 /* Defining the pin for the green LED */, 0x1); /* Setting the green LED as output */

    Serial.begin(9600) /* Starting Serial with 9600 baud rate */;
}

void loop()
{
    uint16_t ldrValue = analogRead(A0 /* Defining the pin for the LDR */); /* Read the LDR value and assign it in a variable */
    uint16_t potValue = analogRead(A1 /* Defining the pin for the pot */); /* Read the potentiometer value and assign it in a variable */

    Serial.println((String) "LDR value: " + ldrValue); /* Printing the LDR value */
    Serial.println((String) "Potentiometer value: " + potValue); /* Printing the potentiometer value */

    if (potValue > 1000 && ldrValue < 1000) /* If the pot value is is above 1000 and the LDR value is below 1000 */
    {
        digitalWrite(3 /* Defining the pin for the red LED */, 0x1); /* Turn on the red LED */
        digitalWrite(4 /* Defining the pin for the green LED */, 0x0); /* Turn off the green LED */
        delay(1000); /* Delay 1 second */
    }

    else if (potValue < 1000 && ldrValue > 1000) /* If the pot value is below 1000 and the LDR value is above 1000 */
    {
        digitalWrite(3 /* Defining the pin for the red LED */, 0x0); /* Turn off the red LED */
        digitalWrite(4 /* Defining the pin for the green LED */, 0x1); /* Turn on the green LED */
        delay(2000); /* Delay 2 seconds */
    }

    else if (potValue < 1000 && ldrValue < 1000) /* If the pot value is below 1000 and the LDR value is below 1000 */
    {
        digitalWrite(3 /* Defining the pin for the red LED */, 0x0); /* Turn off the red LED */
        digitalWrite(4 /* Defining the pin for the green LED */, 0x0); /* Turn off the green LED */
        delay(3000); /* Delay 3 second */
    }

    else /* Otherwise */
    {
        digitalWrite(3 /* Defining the pin for the red LED */, 0x1); /* Turn on the red LED */
        digitalWrite(4 /* Defining the pin for the green LED */, 0x1); /* Turn on the green LED */
    }
}
