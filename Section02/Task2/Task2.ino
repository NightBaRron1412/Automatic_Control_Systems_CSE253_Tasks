#define ldr A0     /* Defining the pin for the LDR */
#define pot A1     /* Defining the pin for the pot */
#define redLED 3   /* Defining the pin for the red LED */
#define greenLED 4 /* Defining the pin for the green LED */

void setup()
{
    pinMode(ldr, INPUT);       /* Setting the LDR as input */
    pinMode(pot, INPUT);       /* Setting the potentiometer as input */
    pinMode(redLED, OUTPUT);   /* Setting the red LED as output */
    pinMode(greenLED, OUTPUT); /* Setting the green LED as output */

    Serial.begin(9600); /* Starting Serial with 9600 baud rate */
}

void loop()
{
    uint16_t ldrValue = analogRead(ldr); /* Read the LDR value and assign it in a variable */
    uint16_t potValue = analogRead(pot); /* Read the potentiometer value and assign it in a variable */

    Serial.println((String) "LDR value: " + ldrValue);           /* Printing the LDR value */
    Serial.println((String) "Potentiometer value: " + potValue); /* Printing the potentiometer value */

    if (potValue > 1000 && ldrValue < 1000) /* If the pot value is is above 1000 and the LDR value is below 1000 */
    {
        digitalWrite(redLED, HIGH);  /* Turn on the red LED */
        digitalWrite(greenLED, LOW); /* Turn off the green LED */
        delay(1000);                 /* Delay 1 second */
    }

    else if (potValue < 1000 && ldrValue > 1000) /* If the pot value is below 1000 and the LDR value is above 1000 */
    {
        digitalWrite(redLED, LOW);    /* Turn off the red LED */
        digitalWrite(greenLED, HIGH); /* Turn on the green LED */
        delay(2000);                  /* Delay 2 seconds */
    }

    else if (potValue < 1000 && ldrValue < 1000) /* If the pot value is below 1000 and the LDR value is below 1000 */
    {
        digitalWrite(redLED, LOW);   /* Turn off the red LED */
        digitalWrite(greenLED, LOW); /* Turn off the green LED */
        delay(3000);                 /* Delay 3 second */
    }

    else /* Otherwise */
    {
        digitalWrite(redLED, HIGH);   /* Turn on the red LED */
        digitalWrite(greenLED, HIGH); /* Turn on the green LED */
    }
}
