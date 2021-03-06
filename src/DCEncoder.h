#ifndef MOTOR_ENCODERS_H
#define MOTOR_ENCODERS_H

#include <Arduino.h>

void encoderChange();

class DCEncoder
{
public:

  DCEncoder(int channelA, int channelB);

  int get();
  void reset();
  void count();

  int channelA;
  int channelB;
  volatile int enc;
  volatile bool state;

private:
};

extern DCEncoder *encoders[100];
extern int enc_s;


#endif
