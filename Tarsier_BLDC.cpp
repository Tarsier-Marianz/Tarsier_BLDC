
/*
 * Tarsier_BLDC.h - A simple library for 3 phase brushless DC motor
 * Copyright (c) 2018 Tarsier-Marianz . All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * 20180226 Marian'O de Gracia Jr.
 */

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

