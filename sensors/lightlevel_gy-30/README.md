# Example
Calculate Lux value from GY-30 breakout board, BH1750 sensor

# References
* Breakout Board: GY-30, CJMCU-43
* Chip:           BH1750FVI
* Chip Spec:      http://www.mouser.com/ds/2/348/bh1750fvi-e-186247.pdf

# Usage
1. Wire
2. Flash, restart, and monitor serial

# Libraries
- Wire.h

# Wiring
GND-GND
SDA-SDA(D2)
SCL-SCL(D1)
VCC-3.3V
ADD-NC <-- to asign a different I2C address to the sensor
