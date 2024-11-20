#include "UltraSonic.h"

Ultrasonic ultrasonic1(12, 11);	// An ultrasonic sensor HC-04

void setuptask10()
{
   Serial.begin(9600);
   delay(1000);
}

void looptask10(){
  Serial.print("Sensor 01: ");
  Serial.print(ultrasonic1.read()); // Prints the distance on the default unit (centimeters)
  Serial.println("cm");
  delay(1000);
}