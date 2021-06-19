#ifndef MOTOR_ENCODERS_H
#define MOTOR_ENCODERS_H

#include <Arduino.h>

class MotorEncoder {
  public:
    MotorEncoder(int channelA, int channelB);
    
    int getEnc();
    void resetEnc();
    void flip();
        
    int channelA;
    int channelB;
    int enc;
  private:
    int dir;
        
};
void ecount(MotorEncoder* encoder);

#endif
