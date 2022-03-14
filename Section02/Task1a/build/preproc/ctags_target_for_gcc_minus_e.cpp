# 1 "d:\\Automatic Control Systems Tasks\\Section02\\Task1a\\Task1a.ino"


void setup()
{
    pinMode(A0, 0x0); /* Setting the potentiometer as input */
    Serial.begin(9600); /* Beginning the serial with 9600 baud rate */
}

void loop()
{
    int potValue = analogRead(A0 /* Defining the pin for the potentiometer */); /* Read the potentiometer value and assign it in a variable */
    Serial.println(potValue); /* Print the potentiometer value on the serial monitor */
}
