#ifndef TASK12_H
#define TASK12_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11

extern uint32_t delayMS;

void setuptask12();
void looptask12();

#endif //i think the most accurate