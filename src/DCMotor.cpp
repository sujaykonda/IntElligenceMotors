#include "DCMotor.h"

DCMotor::DCMotor(int pinPWM, int pinH1, int pinH2) {
  pinMode(pinH1, OUTPUT);
  pinMode(pinH2, OUTPUT);
   
  this->pinPWM = pinPWM;
  this->pinH1 = pinH1;
  this->pinH2 = pinH2;
  this->acc = 300;
  this->dir = 1;
}

void DCMotor::setMaxAcc(double acc) {
  this->acc = acc;
}

void DCMotor::setRawSpeed(int pwm) {
  pwm = constrain(pwm, -255, 255);
  if (pwm < 0)
  {
    digitalWrite(pinH1, LOW);
    delayMicroseconds(5);
    digitalWrite(pinH2, HIGH);
    analogWrite(pinPWM, abs(pwm));
  }
  else
  {
    digitalWrite(pinH1, HIGH);
    delayMicroseconds(5);
    digitalWrite(pinH2, LOW);
    analogWrite(pinPWM, abs(pwm));
  }
  curPWM = pwm;
}

void DCMotor::setSpeed(int pwm) {
  this->tarPWM = pwm * dir;
}
int DCMotor::getSpeed() {
  return this->curPWM;
}

void DCMotor::flip() {
  dir *= -1;
}

void DCMotor::loop() {
  int newLoopMs = millis();
  int maxChange = newLoopMs - this->prevLoopMs;
  int change = tarPWM - curPWM;
  int newPWM = curPWM + constrain(change, -maxChange, maxChange);
  setRawSpeed(newPWM);
  this->prevLoopMs = newLoopMs;
}
