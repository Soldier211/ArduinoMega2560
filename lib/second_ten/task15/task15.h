#ifndef TASK15_H
#define TASK15_H

#include "LedControl.h"

extern int dataPin;
extern int csPin;
extern int clkPin;
extern int maxInUse;
extern LedControl lc;

extern unsigned long delaytime1;
extern unsigned long delaytime2;

void writeArduinoOnMatrix();
void rows();
void columns();
void single();
void setuptask15();
void looptask15();

#endif // TASK15_H
