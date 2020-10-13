#include "../../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include "../../Firmware/Private/defines.h"
#include "../../Firmware/Private/impl.h"

#include <Arduino.h>

void GnomeBOI_Internals::Runtime::runStartUpAnimation() {
  
     // clean screen //
     GnomeBOI::Display::clean(0x0000);
  
     // startup animation - white bands //
     for(uint8_t i = 1; i <= 32; i++) {
          delay(9);
          GnomeBOI::Display::fillRect(0, 32-i, 128, 2*i, 0xFFFF);
     }
     delay(100);
     
     // welcome text //
     GnomeBOI::Display::drawText(2, 23, 2, 0x001F, false, "GnomeBoi");
     GnomeBOI::Display::drawText(20, 50, 1, 0x000C, false, "Welcome!");
     
     // startup sound fx //   
     tone(3, 440);
     delay(100);
     tone(3, 880);
     delay(100);
     tone(3, 1760);
     delay(100);
     noTone(3);
     delay(1000);
};