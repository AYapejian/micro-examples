#include <Arduino.h>
#include <Button.h>        //https://github.com/JChristensen/Button

#define BUTTON_PIN D2
#define PULLUP true        //To keep things simple, we use the Arduino's internal pullup resistor.
#define INVERT true        //Since the pullup resistor will keep the pin high unless the
                          //switch is closed, this is negative logic, i.e. a high state
                          //means the button is NOT pressed. (Assuming a normally open switch.)
#define DEBOUNCE_MS 20     //A debounce time of 20 milliseconds usually works well for tactile button switches.
#define LED_PIN 13         //The standard Arduino "Pin 13" LED
#define LONG_PRESS 1000

Button myBtn(BUTTON_PIN, PULLUP, INVERT, DEBOUNCE_MS);    //Declare the button
bool longPress = false;
void setup(void) {
    Serial.begin(115200);
}


void loop(void) {
    myBtn.read();

    if (myBtn.wasReleased()) {
        if (longPress) {
            Serial.println("button released, long press");
            longPress = false;
        } else {
            Serial.println("button released");
        }
    }
    if (!longPress && myBtn.pressedFor(LONG_PRESS)) {
        Serial.println("long press");
        longPress = true;
    }
}
