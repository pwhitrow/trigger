/*
  Trigger.cpp - Library for button triggers.
  Created by Paul Whitrow, 24 July, 2017.
  Released into the public domain.
  ********************************
  Example calls:

  trigger.triggerDown(downTrigger);
  trigger.triggerUp(upTrigger);
  trigger.triggerLongPress(300, timedTrigger);
  mode.triggerDown(modeTrigger);

*/

#include "Arduino.h"
#include "Trigger.h"

Trigger::Trigger(int triggerPin)
{
  pinMode(triggerPin, INPUT_PULLUP);
  _triggerPin = triggerPin;
  _triggered = 0;
  _trigTimer = 0;
  _trigDown = NULL;
  _trigUp = NULL;
  _trigLongPress = NULL;
  _trigPressDelay = 0;
}

// function to run when trigger is pressed
void Trigger::triggerDown(callbackFunction newFunction)
{
   _trigDown = newFunction;  
}

// function to run when trigger is released
void Trigger::triggerUp(callbackFunction newFunction)
{
   _trigUp = newFunction;  
}

// function to run when trigger is pressed for a user defined time
void Trigger::triggerLongPress(int trigPressDelay, callbackFunction newFunction)
{
	_trigPressDelay = trigPressDelay;
   _trigLongPress = newFunction;  
}

// poll the trigger button pin
void Trigger::readTrigger()
{
  int trig = digitalRead(_triggerPin);

  if(!trig){			// if trigger pin LOW (trigger button down)
	_trigTimer++;		// increment the long press counter
    if(!_triggered){	// if the triggered flag is not set
      _triggered = 1;	// set trigger flag (so we only get one pulse)
      if(_trigDown) _trigDown();	// run the requested function for trigger down (if function declared)
    }
    delay(1);			// small delay to help timing
	if(_trigTimer == _trigPressDelay){  // if the long press counter matches the required delay
		_trigLongPress();				// trigger the long press function
	}
  }else{				// when trigger button is released
	if(_triggered){		// if trigger flag is set
		if(_trigUp) _trigUp();	// run the requested function for trigger release (if function declared)
	}
    _triggered = 0;		// reset the triggered flag
	_trigTimer = 0;		// reset the trigger timer
  }
}

