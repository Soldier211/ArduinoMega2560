#include "LedControl.h"

int dataPin = 12;  // dane
int csPin = 11;    // cs - chip select
int clkPin = 10;   // zegar
int maxInUse = 1;  // liczba używanych modułów MAX7219

LedControl lc = LedControl(dataPin, clkPin, csPin, maxInUse);

unsigned long delaytime1 = 500;  // opóźnienie dla animacji
unsigned long delaytime2 = 50;   // dodatkowe opóźnienie dla animacji

void makeSmile()
{
    byte a[8] = {B00011000, B00010100, B01010010, B00010001, B00010001, B01010010, B00010100, B00011000}; 

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
    delay(delaytime1);
}


/*
  Funkcja do ustawienia zadania
*/
void setupw1() {
  lc.shutdown(0, false);   // Włącz matrycę
  lc.setIntensity(0, 8);    // Ustaw jasność na średnią (0 - najniższa, 15 - najwyższa)
  lc.clearDisplay(0);       // Wyczyść matrycę
}

/*
  Funkcja główna (loop)
*/
void loopw1() {
  makeSmile(); // Wyświetl prostokąt
  delay(delaytime2);  // czekaj przed następnym cyklem animacji
}