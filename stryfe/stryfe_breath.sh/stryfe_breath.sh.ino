// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <math.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      2

float maxBrightness = 255;
float minBrightness = 20;
float speedFactor = 0.008; // I don't actually know what would look good
float stepDelay = 5; // ms for a step delay on the lights

float twoPi = 2*PI;

int x = 0;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pixels.begin();
  pixels.setBrightness(minBrightness);  // Lower brightness and save eyeballs!
  pixels.show(); // Initialize all pixels to 'off'
}

float calcIntensity(int x) {
  //return (maxBrightness-minBrightness) /2.0 * (1.0 + sin(speedFactor * i - PI/2)) + minBrightness;
  float relX = speedFactor * x;
  
  return (maxBrightness-minBrightness) /2.0 * (1.0 + sin(relX + sin(relX- PI) - PI/2)) + minBrightness;
}

void loop() {

// Make the lights breathe
  if (speedFactor * x > twoPi) {
    x = 0;
  }
  
  //for (int i = 0; i < 65535; i++) {
    // Intensity will go from 10 - MaximumBrightness in a "breathing" manner
    float intensity = calcIntensity(x);
    pixels.setBrightness(intensity);
    // Now set every LED to that color
    for (int ledNumber=0; ledNumber<NUMPIXELS; ledNumber++) {
      pixels.setPixelColor(ledNumber, 255, 0, 0);
    }
    
    pixels.show();
    x++;
    //Wait a bit before continuing to breathe
    delay(stepDelay);
  
  //}
}
