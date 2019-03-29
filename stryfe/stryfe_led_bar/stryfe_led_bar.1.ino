// // NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// // released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

// #include <Adafruit_NeoPixel.h>
// #include <math.h>
// #ifdef __AVR__
// #include <avr/power.h>
// #endif

// // Which pin on the Arduino is connected to the NeoPixels?
// // On a Trinket or Gemma we suggest changing this to 1
// #define PIN            2

// // How many NeoPixels are attached to the Arduino?
// #define NUMPIXELS      16

// int x = 0;

// // When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// // Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// // example for more information on possible values.
// Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// int delayval = 100; // delay for half a second

// void setup() {
//   // initialize serial communication at 9600 bits per second:
//   Serial.begin(9600);

//   pixels.begin();
//   pixels.show(); // Initialize all pixels to 'off'
// }

// void loop() {

//   for (int ledNumber=0; ledNumber<NUMPIXELS; ledNumber++) {
//     pixels.setPixelColor(ledNumber, 10, 0, 0);
//   }
//   x++;
//   x = x % NUMPIXELS;
//   pixels.setPixelColor(x, 255, 0, 0);
//   pixels.show();
//   //Wait a bit before continuing to breathe
//   delay(delayval);
// }
