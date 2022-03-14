#define pot A0 /* Defining the pin for the potentiometer */

void setup()
{
    pinMode(pot, INPUT); /* Setting the potentiometer as input */
    Serial.begin(9600); /* Beginning the serial with 9600 baud rate */
}

void loop()
{
    int potValue = analogRead(pot); /* Read the potentiometer value and assign it in a variable */
    Serial.println(potValue);       /* Print the potentiometer value on the serial monitor */
}
