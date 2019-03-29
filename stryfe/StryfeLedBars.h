#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include <math.h>

class StryfeLedBars {
    public:
        StryfeLedBars(int pin, int interval);
        void step();
        void setDebugMode(bool debugMode);
    
    private:
        int _pin;
        Adafruit_NeoPixel _pixels;
        float _twoPi;
        int _x = 0;
        int _previousMillis;
        int _interval;

        bool _debugMode = false;
        void _debug(char* message);
};