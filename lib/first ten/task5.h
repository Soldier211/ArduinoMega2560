#include <Arduino.h>


int ledPin = 5; //zapala sie LED badz nie
int buttonApin = 9; //button z niebieskim kabelkiem
int buttonBpin = 8; //button z zoltym kabelkiem
byte leds = 0;

void setuptask5()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonApin, INPUT_PULLUP);  
    pinMode(buttonBpin, INPUT_PULLUP);
    Serial.begin(9600); //inicjalizacja komunikacji szeregowej
}

void looptask5()
{
    int stateA = digitalRead(buttonApin);//odczyt cyfrowy stanu przycisku
    int stateB = digitalRead(buttonBpin);

    if (stateA == LOW)
    {
        digitalWrite(ledPin, HIGH); //jesli klikne na przycisk a to lapka sie zapali
    }
    if (stateB == LOW)
    {
        digitalWrite(ledPin, LOW); //jesli klikne na przycisk b , lampka zgasnie
    }
    if (stateA == LOW || stateB == LOW)
    {
        delay(500);
        Serial.print("Stan buttonApin: ");
        Serial.println(stateA == LOW ? "LOW" : "HIGH");
        Serial.print("Stan buttonBpin: ");
        Serial.println(stateB == LOW ? "LOW" : "HIGH");
        Serial.println("-------------");
    }
}


