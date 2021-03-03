#include "SerialBT.h"
#include "Roomba.h"
#include "WDT.h"


#define RX1_pin 19
#define TX1_pin 18

int rst = 4; // кнопка

void RST(){
  roomba.write(7);
}


void setup()  {
  roomba.begin(115200, SERIAL_8N1, RX1_pin, TX1_pin); 
  SerialBT_init();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rst, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(rst), RST, FALLING);
   
  wakeUp();
  startFull();
  driveDirect(0, 0);
  for (int i = 0; i < 4; i++) // blink
  {
    setDirtLED(1);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    setDirtLED(0);
  }
  WDT_init();
}

void loop() {
  WDT_rst();
  BTjoy();
}

