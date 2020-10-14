#include "../../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include "../../Firmware/Private/config.h"
#include "../../Firmware/Private/impl.h"

#include <Arduino.h>


namespace {
    constexpr unsigned int ANALOG_TO_DIGITAL_THRESHOLD = 512;

    uint8_t current_input_mask = 0B00000000; // stores the current input
    // uint8_t debounce_input_mask   = 0B00000000; // stores input changes of the previous update to avoid debouncing
}

bool GnomeBOI::Input::isButtonPressed(GnomeBOI::Input::InputButton button) {
  return button & current_input_mask;
}

void GnomeBOI_Internals::Input::updateInputs() {

    uint8_t new_input_mask = 0B00000000;
    
    /*
    Serial.print("RED (A2)");
    Serial.print(sensorValue2);
    Serial.print(", BLUE (A3)");
    Serial.print(sensorValue3);
    /**/

    if( analogRead(PINOUT_ARROW_UP) > ANALOG_TO_DIGITAL_THRESHOLD)
        new_input_mask |= GnomeBOI::Input::ARROW_UP;

    if( analogRead(PINOUT_ARROW_LEFT) > ANALOG_TO_DIGITAL_THRESHOLD)
        new_input_mask |= GnomeBOI::Input::ARROW_LEFT;

    if( analogRead(PINOUT_ARROW_RIGHT) > ANALOG_TO_DIGITAL_THRESHOLD)
        new_input_mask |= GnomeBOI::Input::ARROW_RIGHT;

    if( analogRead(PINOUT_ARROW_DOWN) > ANALOG_TO_DIGITAL_THRESHOLD)
        new_input_mask |= GnomeBOI::Input::ARROW_DOWN;
     
    if(digitalRead(PINOUT_BUTTON_A))
        new_input_mask |= GnomeBOI::Input::BUTTON_A;

    if(digitalRead(PINOUT_BUTTON_B))
        new_input_mask |= GnomeBOI::Input::BUTTON_B;

    if(digitalRead(PINOUT_BUTTON_START))
        new_input_mask |= GnomeBOI::Input::BUTTON_START;

    if(digitalRead(PINOUT_BUTTON_RESERVED))
        new_input_mask |= GnomeBOI::Input::BUTTON_RESERVED;


    current_input_mask = new_input_mask;
 

    #if false
      //DEBOUNCE INPUT
      //
      // if a bit of new_input_mask is different from the previous state current_input_mask, it must be
      // confirmed in the next sensor read to avoid debouncing. Typicvall debounce time is about 20ms, so is two
      // consecutive reads are 32 ms apart are the same, the signal is to be considered stable.
      uint8_t same_read_mask = ~(debounce_input_mask ^ new_input_mask); // a XNOR check if last two reads are same

      // wheres ame_read_mask is 1, the input must be overwritten with the one from debounce_mask.
      // wheres same_read_mask is 0, the input must be the one from previously stable current_input_mask.

      //                    where same_read_mask is 1, debounce_mask is written. 0 otherwise     where ame_read_mask is 1, input_mask is written
      current_input_mask = (same_read_mask & debounce_input_mask) | (~same_read_mask & current_input_mask); // simple logic

      
      debounce_input_mask = new_input_mask;
   #endif
}