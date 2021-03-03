#pragma once
#include "Arduino.h"

#define clamp(value, min, max) (value < min ? min : value > max ? max : value)

#define roomba Serial1 // 

void wakeUp();
void setDirtLED(bool enable);
void startFull();
void drive(int velocity, int radius);
void driveDirect(int right, int left);