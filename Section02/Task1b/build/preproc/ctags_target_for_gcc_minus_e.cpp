# 1 "d:\\Automatic Control Systems Tasks\\Section02\\Task1b\\Task1b.ino"


void setup()
{
    pinMode(A0 /* Defining the pin for the LDR */, 0x0); /* Setting the potentiometer as input */
    Serial.begin(9600); /* Beginning the serial with 9600 baud rate */
}

void loop()
{
    int ldrValue = analogRead(A0 /* Defining the pin for the LDR */); /* Read the LDR value and assign it in a variable */
    Serial.println(ldrValue); /* Print the LDR value on the serial monitor */
}
