#include <Arduino.h>
#include <Wire.h> //BH1750 IIC Mode
#include <math.h>

#define ADDRESS_BH1750 0x23
#define PIN_SDA D2
#define PIN_SCL D1

byte buff[2];
void setup() {
    Serial.begin(115200);
    Wire.begin(PIN_SDA, PIN_SCL);
}

int readSensor(int address) {
   int i=0;
   int readQuantity = 2;
   Wire.beginTransmission(address);
   Wire.requestFrom(address, readQuantity);

   while(Wire.available()) {
      buff[i] = Wire.read();
      i++;
   }
   Wire.endTransmission();
   return i;
}

void initSensor(int address) {
   Wire.beginTransmission(address);
   Wire.write(0x10);            //1lx reolution 120ms
   Wire.endTransmission();
}

void loop() {
   int i;
   uint16_t val=0;
   initSensor(ADDRESS_BH1750);

   if(2 == readSensor(ADDRESS_BH1750)) {
     val = ((buff[0]<<8) | buff[1]) / 1.2;
     Serial.print(val);
     Serial.println("[lx]");
   }

   delay(150);
}
