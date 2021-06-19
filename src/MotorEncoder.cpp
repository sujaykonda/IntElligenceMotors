#include "MotorEncoder.h"

MotorEncoder::MotorEncoder(int channelA, int channelB) {
    this->channelA = channelA;
    this->channelB = channelB;
    this->enc = 0;
}

void ecount(MotorEncoder* encoder) {
  if(digitalRead(encoder->channelB) == HIGH) {
    encoder->enc -= 1;
  } else {
    encoder->enc += 1;
  }
}

int MotorEncoder::getEnc() {
  return this->enc;
}

void MotorEncoder::resetEnc() {
  this->enc = 0;
}
