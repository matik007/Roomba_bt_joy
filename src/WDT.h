#pragma once
#include "Arduino.h"
#include "esp_system.h" // для whatchdog timer (wdt)

void IRAM_ATTR resetModule();
void WDT_init();
void WDT_rst();