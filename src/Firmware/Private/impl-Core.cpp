#include "../../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include "../../Firmware/Private/defines.h"
#include "../../Firmware/Private/impl.h"

#include <Arduino.h>

// static context
namespace {
    static constexpr uint32_t FRAME_DURATION_MILLISEC = 32; //duration of each frame in milliseconds (33.333 ms = 30 FPS)

    static uint32_t last_frame_presentation_timestamp_ms = 0; // timestamp in milliseconds of when the last frame was finished drawing
    static uint32_t current_timestamp_ms = 0;                 // timestamp in milliseconds of the last internal clock reading

    #define next_frame_presentation_timestamp_ms (last_frame_presentation_timestamp_ms + FRAME_DURATION_MILLISEC) // macro for code simplicity
}

// ARDUINO SETUP
// 
void setup() {

    Serial.begin(9600);

  GnomeBOI_Internals::Display::displayBegin();
  GnomeBOI_Internals::Runtime::runStartUpAnimation();
};

// ARDUINO LOOP - Not used.
void loop() {
  
    // UPDATE THE INPUT STATE
    GnomeBOI_Internals::Input::updateInputs();

    // CALL CLIENT APPLICATION
    GnomeBOI::Runtime::onClientApplicationUpdate();

    // LIMIT THE FRAMERATE WITH BUSY WAITING
    //
    // When a frame has finished being drawn, dont draw the next one until
    // at least a FRAME_DURATION_MILLISEC period has passed, to avoid
    // games running too fast when their computational load is too light.
    //
    
    do {
        // UPDATE THE AUDIO BUFFER as frequently as possible
        GnomeBOI_Internals::Sound::updateAudioBuffers();

        // check if the waited time is enough
        //
        current_timestamp_ms = millis();
    } while(current_timestamp_ms < next_frame_presentation_timestamp_ms);


    // DEBUG
        unsigned int T = millis() - last_frame_presentation_timestamp_ms;
        Serial.print("frame drawn! [frane time: ");
        Serial.print(T);
        Serial.print("ms (");
        Serial.print(1000.0/T);
        Serial.println(" FPS)]");

    // UPDATE THE TIMER STATE
    //
    last_frame_presentation_timestamp_ms = millis();


    // CHECK FOR TIMER OVERFLOW
    //
    // A 32 bit timer overflows in approximately 49 days.
    // If that happens, throw an INTERNAL_CLOCK_ERROR and halt the device.
    //
    if(last_frame_presentation_timestamp_ms > next_frame_presentation_timestamp_ms) {
    
        //TO-DO throw fatal error.
        /*display.fillScreen(BLACK);
        display.setCursor(4, 0);
        display.setTextColor(RED);
        display.setTextSize(1);
        display.println("\nINTERNAL ERROR: CLOCK_OVERFLOW!");
        display.println("\nReboot the\ndevice.");*/
        while(1);
    }

}//end-loop()