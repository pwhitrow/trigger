/*
  Trigger.h - Library for button triggers.
  Created by Paul Whitrow, 24 July, 2017.
  Released into the public domain.
*/

#ifndef Trigger_h
#define Trigger_h

#include "Arduino.h"

// ----- Callback function types -----

extern "C" {
  typedef void (*callbackFunction)(void);
}

class Trigger
{
  public:
    Trigger(int triggerPin);
    void readTrigger();
    void triggerDown(callbackFunction newFunction);
    void triggerUp(callbackFunction newFunction);
    void triggerLongPress(int trigPressDelay, callbackFunction newFunction);
  private:
    int _triggerPin;
    int _triggered;
	int _trigTimer;
	int _trigPressDelay;
    callbackFunction _trigDown;
    callbackFunction _trigUp;
    callbackFunction _trigLongPress;
};

#endif
