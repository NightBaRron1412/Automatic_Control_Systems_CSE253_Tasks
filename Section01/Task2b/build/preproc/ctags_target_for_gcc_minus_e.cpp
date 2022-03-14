# 1 "d:\\Control Systems Tasks\\Section1\\Task2b\\Task2b.ino"



void setup()
{
    pinMode(10 /* Defining button pin to use */, 0x0); /* Defining button pin as input */
    pinMode(11 /* Defining LED pin to use */, 0x1); /* Defining LED pin as output */
}

void loop()
{
    if (digitalRead(10 /* Defining button pin to use */) == 0x1) /* If button is pressed */
    {
        digitalWrite(11 /* Defining LED pin to use */, 0x1); /* Turn on LED */
    }
    else
    {
        digitalWrite(11 /* Defining LED pin to use */, 0x0); /* Turn off LED */
    }
}
