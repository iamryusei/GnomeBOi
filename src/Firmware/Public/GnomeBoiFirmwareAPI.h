/** 
 * [SUMMARY]
 *   This header declares the functions provided by the GnomeBOI firmware's API,
 *   which shall be used from a Client application to implement its interactive
 *   behaviour with the user. In fact, the Client application, whatever it is
 *   a videogame or any other kind of interactive application, shall use the
 *   GnomeBOI  firmware's  API  to  access  the  Input/Output  functionalities
 *   of GnomeBOI's hardware: namely the input buttons, output speaker and display,
 *   trough which it can interact with the user.
 *   
 *  
 * [DESCRIPTION]
 *   GnomeBOI's firmware takes care of the low-level, hardware-dependent routines
 *   such as detecting input buttons, updating audio buffers, monitoring timers 
 *   and executing the code of the Client application trough the definition of
 *   external functions that the Client application itself shall implemented.
 *   
 *   In order to avoid the implementation of the Client application to be dependent
 *   from GnomeBOI's hardware (which may differ in future versions of the device),
 *   the GnomeBOI's firmware exposes an high-level API that provides a layer of
 *   abstraction  between  the  Client  application  and  its  hardware. Therefore,
 *   the  Client  application  shall  use  the  GnomeBOI  firmware's  API  to  access
 *   the  abstract  Input/Ouptut  functionalities  of  the  GnomeBOI  device (buttons
 *   for Input, speaker and display for Output) regardless of the actual hardware
 *   implementation.
 *
 *   A  Client  application  that  is  not  hardware-dependent,  but  instead  uses
 *   only the functions provided by the GnomeBOI firmware's API, is also guaranteed
 *   to be compatible with future versions of GnomeBOI devices. It is NOT RECOMMENDED
 *   for a Client application to make direct calls to  low-level, hardware-dependent
 *   functions (like Arduino.h).
 *
 * 
 * [ADDITIONAL INFO]
 *   The GnomeBOI fiwarmre's API is organized into the different namespaces listed below,
 *   where each namespace corresponds to the abstraction of a different Input or Output interface.
 *   Check the comments of each namespace inside this header for more detailed documentation.
 * 
 *      GnomeBOI          -> Constexpr definitions for Version, Info and HW/SW Capabilities
 *      GnomeBOI::Runtime -> Abstract functions to be implement with the behaviour of the Client application
 *      GnomeBOI::Input   -> Functions to read button strokes (INPUT)
 *      GnomeBOI::Display -> Functions to draw on display     (OUTPUT)
 *      GnomeBOI::Sound   -> Functions to reproduce sound     (OUTPUT)
 *
 */

#ifndef __GNOMEBOI_FIRMWARE_API_H_
#define __GNOMEBOI_FIRMWARE_API_H_

#include <stdint.h> // required for data types (uint8_t, uint16_t)

/**
 *  TO-DO: API documentation
 */
namespace GnomeBOI {

    constexpr unsigned short FIRMWARE_VERSION_MAJ = 1;
    constexpr unsigned short FIRMWARE_VERSION_MIN = 0;
    constexpr unsigned short FIRMWARE_VERSION_REV = 0;
    // global constexpr must be defined here...


    /**
     *  TO-DO: API documentation
     */
    namespace Runtime {

        /**
         *  Function that must be implemented by the Client application.
         *  Will be called from the GnomeBOI firmware's API at regular
         *  time intervals.
         * 
         *  TO-DO: Better documentation
         */
        void onClientApplicationUpdate();


        // TO-DO: API Runtime Interval

    }//end-namespace "GnomeBOI::Runtime"


    /**
     * the GnomeBoi::Input namespace collects the functions relative to the
     * reading of player's input.
     */
    namespace Input {


        /**
         *  Enumeration that identifies the different input buttons
         *  avabile on the GnomeBoi device.
         */
        typedef enum InputButton : uint8_t
        {
            BUTTON_A    = 0b00000001,
            BUTTON_B    = 0b00000010,
            BUTTON_L    = 0b00000100,
            BUTTON_R    = 0b00001000,
            ARROW_LEFT  = 0b00010000,
            ARROW_DOWN  = 0b00100000,
            ARROW_UP    = 0b01000000,
            ARROW_RIGHT = 0b10000000,
        };


        /**
         *  Function that returns true only when the specified
         *  InputButton is pressed in the current frame.
         */
        bool isButtonPressed(InputButton b);

        // TO-DO: bool areAllButtonsPressed(InputButton mask);

    }//end-namespace "GnomeBoi::Input"


    /**
     *  TO-DO: API documentation
     */
    namespace Display {

        constexpr uint8_t DISPLAY_WIDTH_PX =  96;
        constexpr uint8_t DISPLAY_HEIGHT_PX = 64;

        /**
         *  TO-DO: API documentation
         */
        void clean(uint16_t color);

        /**
         *  TO-DO: API documentation
         */
        void drawRect(uint8_t originX, uint8_t originY, uint8_t width, uint8_t height, uint16_t color);
        
        /**
         *  TO-DO: API documentation
         */
        void fillRect(uint8_t originX, uint8_t originY, uint8_t width, uint8_t height, uint16_t color);
        
        /**
         *  TO-DO: API documentation
         */
        void drawBitmap(uint8_t originX, uint8_t originY, const uint8_t* bitmap, uint8_t width, uint8_t height, uint16_t color);
        
        /**
         *  TO-DO: API documentation
         */
        void drawText(uint8_t cursorX, uint8_t cursorY, uint8_t fontSize, uint16_t color, bool wrap, const char* string);

    }//end-namespace "GnomeBoi::Display"

    /**
     *  TO-DO: API documentation
     */
    namespace Sound
    {

        /**
         *  TO-DO: API documentation
         */
        typedef enum Note : uint16_t
        {
            PAUSE = 0,

            NOTE_B0 = 31,
            NOTE_C1 = 33,
            NOTE_CS1 = 35,
            NOTE_D1 = 37,
            NOTE_DS1 = 39,
            NOTE_E1 = 41,
            NOTE_F1 = 44,
            NOTE_FS1 = 46,
            NOTE_G1 = 49,
            NOTE_GS1 = 52,
            NOTE_A1 = 55,
            NOTE_AS1 = 58,
            NOTE_B1 = 62,
            NOTE_C2 = 65,
            NOTE_CS2 = 69,
            NOTE_D2 = 73,
            NOTE_DS2 = 78,
            NOTE_E2 = 82,
            NOTE_F2 = 87,
            NOTE_FS2 = 93,
            NOTE_G2 = 98,
            NOTE_GS2 = 104,
            NOTE_A2 = 110,
            NOTE_AS2 = 117,
            NOTE_B2 = 123,
            NOTE_C3 = 131,
            NOTE_CS3 = 139,
            NOTE_D3 = 147,
            NOTE_DS3 = 156,
            NOTE_E3 = 165,
            NOTE_F3 = 175,
            NOTE_FS3 = 185,
            NOTE_G3 = 196,
            NOTE_GS3 = 208,
            NOTE_A3 = 220,
            NOTE_AS3 = 233,
            NOTE_B3 = 247,
            NOTE_C4 = 262,
            NOTE_CS4 = 277,
            NOTE_D4 = 294,
            NOTE_DS4 = 311,
            NOTE_E4 = 330,
            NOTE_F4 = 349,
            NOTE_FS4 = 370,
            NOTE_G4 = 392,
            NOTE_GS4 = 415,
            NOTE_A4 = 440,
            NOTE_AS4 = 466,
            NOTE_B4 = 494,
            NOTE_C5 = 523,
            NOTE_CS5 = 554,
            NOTE_D5 = 587,
            NOTE_DS5 = 622,
            NOTE_E5 = 659,
            NOTE_F5 = 698,
            NOTE_FS5 = 740,
            NOTE_G5 = 784,
            NOTE_GS5 = 831,
            NOTE_A5 = 880,
            NOTE_AS5 = 932,
            NOTE_B5 = 988,
            NOTE_C6 = 1047,
            NOTE_CS6 = 1109,
            NOTE_D6 = 1175,
            NOTE_DS6 = 1245,
            NOTE_E6 = 1319,
            NOTE_F6 = 1397,
            NOTE_FS6 = 1480,
            NOTE_G6 = 1568,
            NOTE_GS6 = 1661,
            NOTE_A6 = 1760,
            NOTE_AS6 = 1865,
            NOTE_B6 = 1976,
            NOTE_C7 = 2093,
            NOTE_CS7 = 2217,
            NOTE_D7 = 2349,
            NOTE_DS7 = 2489,
            NOTE_E7 = 2637,
            NOTE_F7 = 2794,
            NOTE_FS7 = 2960,
            NOTE_G7 = 3136,
            NOTE_GS7 = 3322,
            NOTE_A7 = 3520,
            NOTE_AS7 = 3729,
            NOTE_B7 = 3951,
            NOTE_C8 = 4186,
            NOTE_CS8 = 4435,
            NOTE_D8 = 4699,
            NOTE_DS8 = 4978
        };


        /**
         *  TO-DO: API documentation
         */
        void playSound(Note note, uint8_t durationUnits);


        // TO-DO: void playMusic(const Note* notesArray, const uint8_t* durationUnitsArray, uint16_t startIndex, uint16_t notesCount, bool playLoop);

    }//end-namespace "GnomeBoi::Sound"

}
#endif