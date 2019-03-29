#include "StryfeSpeedControl.h">
//#include "StryfeLedBars.h">

#define pwmPin 5
#define speedButton 4
#define triggerButton 2
#define ledBarsPin 7
#define ledDelay 100

//StryfeLedBars* bars;
StryfeSpeedControl* fire;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Starting Stryfe OS...");
  fire = new StryfeSpeedControl(pwmPin, triggerButton, speedButton);
  //bars = new StryfeLedBars(ledBarsPin, ledDelay);
  //bars->setDebugMode(true);
  
}

void loop() {
  fire->check();
  //bars->step();
}
