#include <Arduino.h>
#include <U8g2lib.h>

#define PIN_DISPLAY_CLOCK D2
#define PIN_DISPLAY_DATA D1

// U8g2 Contructor list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, PIN_DISPLAY_CLOCK, PIN_DISPLAY_DATA, U8X8_PIN_NONE);


void setup(void) {
    u8g2.begin();
}

// Lots more examples here: https://platformio.org/lib/show/942/U8g2
void drawText(void) {
    u8g2.setFontMode(1);	// Transparent
    u8g2.setFontDirection(0);
    u8g2.setFont(u8g2_font_inb24_mf);
    u8g2.drawStr(0, 30, "Test");
}

void loop(void) {
    u8g2.clearBuffer();
    drawText();
    u8g2.sendBuffer();
    delay(1000);
}

