#include "StryfeSpeedControl.h"

StryfeSpeedControl::StryfeSpeedControl(int pwmPin, int triggerPin, int toggleSpeedPin) {
    _debug("StryfeSpeedControl: initialising");
    pinMode(pwmPin, OUTPUT); // enable output for speed control by PWM
    pinMode(triggerPin, INPUT); // enable read for triggerPush

    _pwmPin = pwmPin;
    _triggerPin = triggerPin;
    _toggleSpeedPin = toggleSpeedPin;

    _debug("StryfeSpeedControl: initialised");
}

void StryfeSpeedControl::check() {
    checkButtonPress();

    if(digitalRead(_triggerPin) == HIGH) {
        _debug("Motor: on.");
        setSpeed(_speed);
    } else {
        setSpeed(0);
    }
}

void StryfeSpeedControl::toggleSpeed() {
    if(_speed == SPEED_MAX) {
        _speed = SPEED_LOW;
    } else {
        _speed = SPEED_MAX;
    }
}

void StryfeSpeedControl::checkButtonPress() {
    // read the pushbutton input pin:
    _buttonState = digitalRead(_toggleSpeedPin);

    // compare the buttonState to its previous state
    if (_buttonState != _lastButtonState) {
        // if the state has changed, increment the counter
        if (_buttonState == HIGH) {
            _debug("Toggle speed.");
            // if the current state is HIGH then the button went from off to on:
            toggleSpeed();
        } else {
            // if the current state is LOW then the button went from on to off:
        }
        // Delay a little bit to avoid bouncing
        delay(50);
    }
    // save the current state as the last state, for next time through the loop
    _lastButtonState = _buttonState;
}

void StryfeSpeedControl::setSpeed(int speed) {
    analogWrite(_pwmPin, speed);
}

void StryfeSpeedControl::setDebugMode(bool debugMode) {
    _debugMode = debugMode;
}

void StryfeSpeedControl::_debug(char* message) {
    if(_debugMode) {
        _debug(message);
    }
}