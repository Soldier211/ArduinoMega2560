#include <Servo.h>

Servo myservo;
void setuptask9()
{
    myservo.attach(9); // dolaczamy przewod sygnalowy (zolty)
    myservo.write(90); // ustawiamy serwo na srodkowa pozycje
}
void looptask9(){
  myservo.write(90);// move servos to center position -> 90°
  delay(500);
  myservo.write(30);// move servos to center position -> 60°
  delay(500);
  myservo.write(90);// move servos to center position -> 90°
  delay(500);
  myservo.write(150);// move servos to center position -> 120°
  delay(500);
}