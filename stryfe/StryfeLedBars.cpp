#include "StryfeLedBars.h"

#define NUMPIXELS      16

StryfeLedBars::StryfeLedBars(int pin, int interval) {
    _debug("StryfeLedBars: initialising");
    _pin = pin;
    _interval = interval;

    _debug("StryfeLedBars: Setting neopixel config");
    _pixels = Adafruit_NeoPixel(NUMPIXELS, _pin, NEO_GRB + NEO_KHZ800);

    // Initialize leds to off.
    _debug("StryfeLedBars: Initialising neopixel");
    _pixels.begin();
    _pixels.show(); // Initialize all pixels to 'off'
    _debug("StryfeLedBars: initialised");
}

void StryfeLedBars::step() {
    unsigned long currentMillis = millis();
    if (currentMillis - _previousMillis >= _interval) {
        _previousMillis = currentMillis;
        
        _debug("StryfeLedBars: Animate bars");
        

        for (int ledNumber=0; ledNumber<NUMPIXELS; ledNumber++) {
            _pixels.setPixelColor(ledNumber, 10, 0, 0);
        }
        _x++;
        _x = _x % NUMPIXELS;
        _pixels.setPixelColor(_x, 255, 0, 0);
        _pixels.show();
    }
}

void StryfeLedBars::setDebugMode(bool debugMode) {
    _debugMode = debugMode;
}

void StryfeLedBars::_debug(char* message) {
    if(_debugMode) {
        Serial.println(message);
    }
}