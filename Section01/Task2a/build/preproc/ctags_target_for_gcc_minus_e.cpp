# 1 "d:\\Control Systems Tasks\\Section1\\Task2a\\Task2a.ino"


void setup()
{
    pinMode(10 /* Defining LED pin to use */, 0x1); /* Defining LED pin as output */
}

void loop()
{
    digitalWrite(10 /* Defining LED pin to use */, 0x1); /* Turn on LED */
    delay(1000); /* Delay 1 second */
    digitalWrite(10 /* Defining LED pin to use */, 0x0); /* Turn off LED */
    delay(1000); /* Delay 1 second */
}
