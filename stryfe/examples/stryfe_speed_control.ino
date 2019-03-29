#define pwmPin 5
#define speedButton 4
#define triggerButton 2

// Define speed values
#define SPEED_MAX 255
#define SPEED_LOW 100


int val = 255;
// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT); // enable output for speed control by PWM
  pinMode(triggerButton, INPUT); // enable read for triggerPush
}

void toggleSpeed() {
  if(val == SPEED_MAX) {
    val = SPEED_LOW;
  } else {
    val = SPEED_MAX;
  }
}

void checkButtonPress() {
  // read the pushbutton input pin:
  buttonState = digitalRead(speedButton);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      toggleSpeed();
    } else {
      // if the current state is LOW then the button went from on to off:
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
}

void setSpeed(int speed) {
  analogWrite(pwmPin, speed);
}

void loop() {

  checkButtonPress();

  if(digitalRead(triggerButton) == HIGH) {
    setSpeed(val);
  } else {
    setSpeed(0);
  }
}
