/*
  Trigger - Library for button triggers.
  Created by Paul Whitrow, 24 July, 2017.
  Released into the public domain.
*/

#include <Trigger.h>

//each trigger needs to be declared with it's associated pin
Trigger trigger(2);
Trigger mode(3);

void setup() {
  // declare a ruturn function for the triggers
  trigger.triggerDownFunction(downTrigger);
  trigger.triggerUpFunction(upTrigger);
  mode.triggerDownFunction(modeTrigger);
}

void loop() {
  // poll the triggers
  trigger.readTrigger();
  mode.readTrigger();
}

void downTrigger(){
  Serial.println("TRIGGER DOWN");
}

void upTrigger(){
  Serial.println("TRIGGER UP");
}

void modeTrigger(){
  Serial.println("MODE");
}
