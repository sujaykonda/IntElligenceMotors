#include "MotorEncoder.h"

MotorEncoder::MotorEncoder(int channelA, int channelB) {
    
    pinMode(channelA, INPUT_PULLUP);
    pinMode(channelB, INPUT_PULLUP);
    this->channelA = channelA;
    this->channelB = channelB;
    this->enc = 0;
    this->dir = 1;
}

void ecount(MotorEncoder* encoder) {
  if(digitalRead(encoder->channelB) == HIGH) {
    encoder->enc += 1;
  } else {
    encoder->enc -= 1;
  }
}

int MotorEncoder::getEnc() {
  return this->enc * dir;
}

void MotorEncoder::flip() {
  this->dir *= -1;
}

void MotorEncoder::resetEnc() {
  this->enc = 0;
}
