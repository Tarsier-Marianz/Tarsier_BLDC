#include "Tarsier_BLDC.h"

Tarsier_BLDC::Tarsier_BLDC(){
    setPins(5, 6, 7);
    setDelay(_delay);
}

Tarsier_BLDC::Tarsier_BLDC(byte pin1, byte pin2, byte pin3){
    setPins(pin1, pin2, pin3);
    setDelay(_delay);
}

void Tarsier_BLDC::setPins(byte pin1, byte pin2, byte pin3) {
    _motorPin1 = pin1;
    _motorPin2 = pin2;
    _motorPin3 = pin3;

    pinMode(_motorPin1, OUTPUT);
    pinMode(_motorPin2, OUTPUT);
    pinMode(_motorPin3, OUTPUT);
}

void Tarsier_BLDC::setDelay(int delay) {
    _delay = delay;
}

void Tarsier_BLDC::forward() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(_motorPin1, _sequence[i][0]);
    digitalWrite(_motorPin2, _sequence[i][1]);
    digitalWrite(_motorPin3, _sequence[i][2]);
    delay(_delay);
  }
}

void Tarsier_BLDC::backward() {
  for (int i = 6; i > 0; i--) {
    digitalWrite(_motorPin1, _sequence[i][0]);
    digitalWrite(_motorPin2, _sequence[i][1]);
    digitalWrite(_motorPin3, _sequence[i][2]);
    delay(_delay);
  }
}

