#include "WDT.h"

hw_timer_t *timer = NULL; // wdt

const int wdtTimeout = 3000;  //time in ms to trigger the watchdog

void IRAM_ATTR resetModule() { // reset при сробатывании wdt 
  // ets_printf("reboot ;ets;\n");
  esp_restart();
}

void WDT_init(){
    timer = timerBegin(0, 80, true);                  //timer 0, div 80
    timerAttachInterrupt(timer, &resetModule, true);  //attach callback
    timerAlarmWrite(timer, wdtTimeout * 1000, false); //set time in us
    timerAlarmEnable(timer);    //enable interrupt
}                     

void WDT_rst(){
    timerWrite(timer, 0); //reset timer (feed watchdog)
}