#include "Tarsier_BLDC.h"

#define MOTOR_PIN1 5
#define MOTOR_PIN2 6
#define MOTOR_PIN3 7
#define TOGGLE_PIN 2

int wait_time = 10;

Tarsier_BLDC _bldc;

void setup(){
	pinMode(TOGGLE_PIN, INPUT);
  _bldc.setPins(MOTOR_PIN1, MOTOR_PIN2, MOTOR_PIN3);
  _bldc.setDelay(wait_time);
  
}

void loop(){
  int state = digitalRead(TOGGLE_PIN);
  if (state == HIGH)  {
    _bldc.forward();
  }
  else {
    _bldc.backward();
  }
}