/*
 * Tarsier_BLDC.cpp - A simple library for 3 phase brushless DC motor
 * Copyright (c) 2018 Tarsier-Marianz . All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
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

#ifndef Tarsier_BLDC_H
#define Tarsier_BLDC_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else    
    #include "WProgram.h"
#endif

class Tarsier_BLDC{
    private:
        byte _delay = 10;
        byte _motorPin1;
        byte _motorPin2;
        byte _motorPin3;
        //110, 100, 101, 001, 011, 010
        int _sequence [6][3] = {
            {1, 1, 0},
            {1, 0, 0},
            {1, 0, 1},
            {0, 0, 1},
            {0, 1, 1},
            {0, 1, 0},
        };


    public:
        Tarsier_BLDC();
        Tarsier_BLDC(byte pin1, byte pin2, byte pin3);
        void setPins(byte pin1, byte pin2, byte pin3);
        void setDelay(int delay);
        void forward();
        void backward();
        void stop();
};
#endif