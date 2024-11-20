const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;

void setuptask13()
{
    pinMode(SW_pin,INPUT);
    digitalWrite(SW_pin,HIGH);
    Serial.begin(9600);
}

void looptask13()
{
    Serial.print("Switch: ");
    Serial.print(digitalRead(SW_pin));
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(analogRead(Y_pin));
    Serial.print("\n\n");
    delay(500);
}