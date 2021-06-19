#ifndef MOTOR_ENCODERS_H
#define MOTOR_ENCODERS_H

#include <Arduino.h>

class MotorEncoder {
  public:
    MotorEncoder(int channelA, int channelB);
        
    int getEnc();
    void resetEnc();
        
    int channelA;
    int channelB;
    int enc;
        
};
void ecount(MotorEncoder* encoder);

#endif
