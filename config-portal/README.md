Example: Starts a WiFi Access Point to allow for initial configuration

# Usage
1. On boot, if no credentials exist, starts AP
2. Connect to SSID `micro-example` with password `micro-example-password`
3. Should be redirected to allow selecting / entering WiFi credentials
4. After connection is successful LED status goes green

NOTE: To reset after entering credentials hold down button (Default Pin 4) while powering/reseting the chip

# Libraries
* [WiFiManager](https://github.com/tzapu/WiFiManager/)

# Wiring
Button:    Pin 4
RG(b) LED: Pins 15 & 12

I frequently use the "Witty Cloud Dev boards" which include wired button, rgb led, and ldr sensor, pins here match that board.
