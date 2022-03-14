#define ldr A0 /* Defining the pin for the LDR */

void setup()
{
    pinMode(ldr, INPUT); /* Setting the LDR as input */
    Serial.begin(9600);  /* Beginning the serial with 9600 baud rate */
}

void loop()
{
    int ldrValue = analogRead(ldr); /* Read the LDR value and assign it in a variable */
    Serial.println(ldrValue);       /* Print the LDR value on the serial monitor */
}
