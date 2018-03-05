#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

// NOTE: Using the '#development' branch version of WifiManager
#include <WiFiManager.h>

#define PIN_BUTTON_START_PORTAL 4
#define PIN_LED_STATUS_ERROR    15
#define PIN_LED_STATUS_SUCCESS  12

#define ACCESS_POINT_SSID "micro-example"
#define ACCESS_POINT_PASS "micro-example-password"


void ledStatusError() {
    digitalWrite(PIN_LED_STATUS_SUCCESS, LOW);
    digitalWrite(PIN_LED_STATUS_ERROR, HIGH);
}
void ledStatusSuccess() {
    digitalWrite(PIN_LED_STATUS_SUCCESS, HIGH);
    digitalWrite(PIN_LED_STATUS_ERROR, LOW);
}

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(2000);
    while (!Serial) { ; };

    pinMode(PIN_BUTTON_START_PORTAL, INPUT);
    pinMode(PIN_LED_STATUS_SUCCESS, OUTPUT);
    pinMode(PIN_LED_STATUS_ERROR,   OUTPUT);

    // Should have a startup status, use error for simplicity
    ledStatusError();
    WiFiManager wifiManager;

    // If powered on while pressing button reset settings
    if (digitalRead(PIN_BUTTON_START_PORTAL) == LOW) {
        Serial.println("Resetting wifi settings");
        wifiManager.resetSettings();
    }

    wifiManager.setTimeout(180);    // Timeout if not configured or connected within 3 minutes
    if(!wifiManager.autoConnect(ACCESS_POINT_SSID, ACCESS_POINT_PASS)) {
        Serial.println("Failed to connect, timedout, Going into deepsleep for awhile");
        ESP.deepSleep(600e6); // 10 minutes (600 seconds)
        delay(3000);
        Serial.println("Resetting after deepsleep");
        ESP.reset();
    }

    // Disable captive portal if we are connected
    // Doesn't seem to be working, not sure how to disable AP when connected
    wifiManager.setCaptivePortalEnable(false);
    Serial.print("Connected, IP: ");
    Serial.println(WiFi.localIP());
    ledStatusSuccess();
}

void loop() {

}
