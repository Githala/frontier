// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include "../StryfeLedBars.h">

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

int delayval = 100; // delay for half a second

StryfeLedBars bars(PIN, delayval);

void setup() {
}

void loop() {
  bars.step();
}
