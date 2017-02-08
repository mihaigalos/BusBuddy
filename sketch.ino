#include "Adafruit_mfGFX.h"    // Core graphics library
#include "Adafruit_ST7735.h" // Hardware-specific library

#ifdef __AVR__
const byte D2 = 2;

#endif

#define cs   A0
#define rst  A1
#define dc   A3

#define sda 2 // PD2
#define scl 3

// following text has attribute progmem, otherwise it would use a lot of ram
static const char demoText[] = "Qu'est-ce que tu fais ce WE? ;)";


void setup() {
    
    Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, sda,scl, rst); 
    tft.initR(INITR_BLACKTAB);

    tft.setRotation(2);
    tft.fillScreen(ST7735_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(ST7735_WHITE);
    tft.setTextWrap(true);
    tft.print(demoText);

    tft.drawLine(0, 0, tft.width()-1, tft.height()-1, ST7735_YELLOW);
    tft.drawLine(tft.width()-1, 0, 0, tft.height()-1, ST7735_YELLOW);

    tft.drawPixel(0, tft.height()/2, ST7735_GREEN);

}

void loop() {

}
