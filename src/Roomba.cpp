#include "Roomba.h"

int ddPin  = 22; //device detect для UART румбы
int speed = 250;

bool debrisLED;
bool spotLED;
bool dockLED;
bool warningLED;
byte color;
byte intensity;

void wakeUp() { // импульс на device detect
  pinMode(ddPin, OUTPUT);
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
}

void setDirtLED(bool enable)
{
  debrisLED = enable;
  roomba.write(139);
  roomba.write((debrisLED ? 1 : 0) + (spotLED ? 2 : 0) + (dockLED ? 4 : 0) + (warningLED ? 8 : 0));
  roomba.write((byte)color);
  roomba.write((byte)intensity);
}

void startFull() {
  roomba.write(128);
  roomba.write(132);
  delay(1000);
}

void drive(int velocity, int radius)
{
  clamp(velocity, -500, 500); //def max and min velocity in mm/s
  clamp(radius, -2000, 2000); //def max and min radius in mm

  roomba.write(137);
  roomba.write(velocity >> 8);
  roomba.write(velocity);
  roomba.write(radius >> 8);
  roomba.write(radius);
}

void driveDirect(int right, int left)
{
  clamp(right, -500, 500);
  clamp(left, -500, 500);

  roomba.write(145);
  roomba.write(right >> 8);
  roomba.write(right);
  roomba.write(left >> 8);
  roomba.write(left);
}