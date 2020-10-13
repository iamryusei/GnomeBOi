#include "../../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include "../../Firmware/Private/defines.h"
#include "../../Firmware/Private/impl.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

namespace {
    Adafruit_SSD1331 displayHandle = Adafruit_SSD1331(&SPI, PINOUT_cs, PINOUT_dc, PINOUT_rst);;
}

void GnomeBOI_Internals::Display::displayBegin() {
    displayHandle.begin();
}

void GnomeBOI::Display::clean(uint16_t color) {
   displayHandle.fillScreen(color);
}

void GnomeBOI::Display::drawRect(uint8_t originX, uint8_t originY, uint8_t width, uint8_t height, uint16_t color) {
    displayHandle.drawRect(originX, originY, width, height, color);
}

void GnomeBOI::Display::fillRect(uint8_t originX, uint8_t originY, uint8_t width, uint8_t height, uint16_t color) {
    displayHandle.fillRect(originX, originY, width, height, color);
}
       
void GnomeBOI::Display::drawBitmap(uint8_t originX, uint8_t originY, const uint8_t* bitmap, uint8_t width, uint8_t height, uint16_t color) {
    displayHandle.drawBitmap(originX, originY, bitmap, width, height, color);
}

void GnomeBOI::Display::drawText(uint8_t cursorX, uint8_t cursorY, uint8_t fontSize, uint16_t color, bool wrap, const char* string) {
    displayHandle.setCursor(cursorX, cursorY);
    displayHandle.setTextColor(color);
    displayHandle.setTextSize(fontSize);
    displayHandle.setTextWrap(wrap);
    displayHandle.println(string);
}