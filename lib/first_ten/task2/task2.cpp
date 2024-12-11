#include "task2.h"
void setuptask2()
{
    pinMode(LED_BUILTIN,OUTPUT);
}

void looptask2()
{
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
}