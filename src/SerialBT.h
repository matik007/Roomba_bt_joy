#pragma once
#include <Arduino.h>

#define ESP 1


#if ESP
#include "BluetoothSerial.h"      // https://github.com/espressif/arduino-esp32/tree/master/libraries/BluetoothSerial
#else 
#define SerialBT Serial1
#endif
#include "Roomba.h"

extern int joyX;       // obtain the Int from the ASCII representation
extern int joyY;
extern bool flag;

void SerialBT_init();
void getJoystickState(byte data[8]);
void BTget();
void BTjoy();