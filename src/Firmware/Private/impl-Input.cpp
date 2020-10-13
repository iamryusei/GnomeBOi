#include "../../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include "../../Firmware/Private/defines.h"
#include "../../Firmware/Private/impl.h"

#include <Arduino.h>

namespace {
    uint8_t current_input_mask = 0B00000000; // stores the current input
    // uint8_t debounce_input_mask   = 0B00000000; // stores input changes of the previous update to avoid debouncing
}

bool GnomeBOI::Input::isButtonPressed(GnomeBOI::Input::InputButton button) {
  return button & current_input_mask;
}

void GnomeBOI_Internals::Input::updateInputs() {

    // read all input pins
    int sensorValue0 = digitalRead(A0);
    int sensorValue1 = digitalRead(A1);
    int sensorValue2 = analogRead(A2);
    int sensorValue3 = analogRead(A3);
    int sensorValue4 = digitalRead(4);
    int sensorValue5 = digitalRead(5);
    int sensorValue6 = digitalRead(6);
    int sensorValue7 = digitalRead(7);
    
    uint8_t new_input_mask = 0B00000000;
    
    Serial.print("RED (A2)");
    Serial.print(sensorValue2);
    Serial.print(", BLUE (A3)");
    Serial.print(sensorValue3);


    if(sensorValue0)
      new_input_mask |= GnomeBOI::Input::BUTTON_L;
    if(sensorValue1)
      new_input_mask |= GnomeBOI::Input::BUTTON_R;
     if(sensorValue2)
      new_input_mask |= GnomeBOI::Input::BUTTON_B;
     if (sensorValue3 > 512)
        new_input_mask |= GnomeBOI::Input::BUTTON_A;
     if(sensorValue4)
      new_input_mask |= GnomeBOI::Input::ARROW_DOWN;
    if(sensorValue5)
      new_input_mask |= GnomeBOI::Input::ARROW_RIGHT;
     if(sensorValue6)
      new_input_mask |= GnomeBOI::Input::ARROW_UP;
     if(sensorValue7)
      new_input_mask |= GnomeBOI::Input::ARROW_LEFT;

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