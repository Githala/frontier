#include "Arduino.h"

// Define speed values
#define SPEED_MAX 255
#define SPEED_LOW 100

class StryfeSpeedControl {
    public:
        StryfeSpeedControl(int pwmPin, int triggerPin, int toggleSpeedPin);
        void check();
        void setDebugMode(bool debugMode);
        
    private:
        int _pwmPin;
        int _triggerPin;
        int _toggleSpeedPin;
        
        int _speed = 255;
        int _buttonState = 0;         // current state of the button
        int _lastButtonState = 0;     // previous state of the button

        void toggleSpeed();
        void checkButtonPress();
        void setSpeed(int speed);
        
        bool _debugMode = false;
        void _debug(char* message);
};