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
};
#endif