#include "LedControl.h"

int dataPin = 12; // dane
int csPin = 11;   // cs - chip select
int clkPin = 10;  // zegar
int maxInUse = 1; // liczba używanych modułów MAX7219

LedControl lc = LedControl(dataPin, clkPin, csPin, maxInUse);

unsigned long delaytime1=500; // nie moge byc ujemne
unsigned long delaytime2=50;

/*
  Funkcja wyświetlająca litery na matrycy
*/
void writeArduinoOnMatrix() {
  // Dane dla liter 8x8
  byte a[8] = {B01111110, B10000001, B10000001, B10000001, B11111111, B10000001, B10000001, B10000001}; // Litera A
  byte r[8] = {B11111110, B10000001, B10000001, B11111110, B10010000, B10001000, B10000100, B10000010}; // Litera R (poprawiona)
  byte d[8] = {B11111110, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111110}; // Litera D
  byte u[8] = {B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111}; // Litera U
  byte i[8] = {B11111111, B00010000, B00010000, B00010000, B00010000, B00010000, B00010000, B11111111}; // Litera I
  byte n[8] = {B10000001, B11000001, B10100001, B10010001, B10001001, B10000101, B10000011, B10000001}; // Litera N
  byte o[8] = {B01111110, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B01111110}; // Litera O

  // Teraz wyświetl je jeden po drugim z małym opóźnieniem
  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  lc.setRow(0, 5, a[5]);
  lc.setRow(0, 6, a[6]);
  lc.setRow(0, 7, a[7]);
  delay(delaytime1);

  lc.setRow(0, 0, r[0]);
  lc.setRow(0, 1, r[1]);
  lc.setRow(0, 2, r[2]);
  lc.setRow(0, 3, r[3]);
  lc.setRow(0, 4, r[4]);
  lc.setRow(0, 5, r[5]);
  lc.setRow(0, 6, r[6]);
  lc.setRow(0, 7, r[7]);
  delay(delaytime1);

  lc.setRow(0, 0, d[0]);
  lc.setRow(0, 1, d[1]);
  lc.setRow(0, 2, d[2]);
  lc.setRow(0, 3, d[3]);
  lc.setRow(0, 4, d[4]);
  lc.setRow(0, 5, d[5]);
  lc.setRow(0, 6, d[6]);
  lc.setRow(0, 7, d[7]);
  delay(delaytime1);

  lc.setRow(0, 0, u[0]);
  lc.setRow(0, 1, u[1]);
  lc.setRow(0, 2, u[2]);
  lc.setRow(0, 3, u[3]);
  lc.setRow(0, 4, u[4]);
  lc.setRow(0, 5, u[5]);
  lc.setRow(0, 6, u[6]);
  lc.setRow(0, 7, u[7]);
  delay(delaytime1);

  lc.setRow(0, 0, i[0]);
  lc.setRow(0, 1, i[1]);
  lc.setRow(0, 2, i[2]);
  lc.setRow(0, 3, i[3]);
  lc.setRow(0, 4, i[4]);
  lc.setRow(0, 5, i[5]);
  lc.setRow(0, 6, i[6]);
  lc.setRow(0, 7, i[7]);
  delay(delaytime1);

  lc.setRow(0, 0, n[0]);
  lc.setRow(0, 1, n[1]);
  lc.setRow(0, 2, n[2]);
  lc.setRow(0, 3, n[3]);
  lc.setRow(0, 4, n[4]);
  lc.setRow(0, 5, n[5]);
  lc.setRow(0, 6, n[6]);
  lc.setRow(0, 7, n[7]);
  delay(delaytime1);

  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  lc.setRow(0, 5, o[5]);
  lc.setRow(0, 6, o[6]);
  lc.setRow(0, 7, o[7]);
  delay(delaytime1);

  // Wyczyść matrycę po wyświetleniu
  lc.setRow(0, 0, 0);
  lc.setRow(0, 1, 0);
  lc.setRow(0, 2, 0);
  lc.setRow(0, 3, 0);
  lc.setRow(0, 4, 0);
  lc.setRow(0, 5, 0);
  lc.setRow(0, 6, 0);
  lc.setRow(0, 7, 0);
  delay(delaytime1);
}

void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime2);
    lc.setRow(0,row,B10100000);
    delay(delaytime2);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime2);
      lc.setRow(0,row,B10100000);
      delay(delaytime2);
      lc.setRow(0,row,(byte)0);
    }
  }
}

void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime2);
    lc.setColumn(0,col,B00100000);
    delay(delaytime2);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime2);
      lc.setColumn(0,col,B00100000);
      delay(delaytime2);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime2);
      lc.setLed(0,row,col,true);
      delay(delaytime2);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime2);
        lc.setLed(0,row,col,true);
        delay(delaytime2);
      }
    }
  }
}

/*
  Funkcja do ustawienia zadania 15
*/
void setuptask15() {
  lc.shutdown(0, false); // Włącz matrycę
  lc.setIntensity(0, 8);  // Ustaw jasność na najwyższą (0 - najniższa, 15 - najwyższa)
  lc.clearDisplay(0);     // Wyczyść matrycę
}

/*
  Funkcja główna (loop)
*/
void looptask15() {
    writeArduinoOnMatrix(); // Wyświetlanie słowa "Arduino" na matrycy
    rows();
    columns();
    single();
}
