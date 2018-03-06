#include <Arduino.h>

#define PIN_LIGHT_SENSOR A0

void setup() {
    Serial.begin(115200);
    Serial.println("TEMT6000 Test");

    pinMode(PIN_LIGHT_SENSOR,  INPUT);
}

// Not sure on the accuracy here, but seems to be reasonable 0 - 1000 Lux
// https://forum.arduino.cc/index.php?topic=185158.0
float calculateLux() {
    float volts = analogRead(PIN_LIGHT_SENSOR) * 5.0 / 1024.0;
    float amps = volts / 10000.0;       // across 10,000 Ohms
    float microamps = amps * 1000000;
    float lux = microamps * 2.0;
    return lux;
}

void loop() {
    Serial.print("Lux: "); Serial.println(calculateLux());
    delay(1000);
}
