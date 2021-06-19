#include "DCMotor.h"

DCMotor::DCMotor(int pinPWM, int pinA, int pinB) {
  this->pinPWM = pinPWM;
  this->pinA = pinA;
  this->pinB = pinB;
  this->acc = 300;
}

void DCMotor::setMaxAcc(double acc) {
  this->acc = acc;
}

void DCMotor::setRawSpeed(int pwm) {
  if (pwm < 0)
  {
    digitalWrite(pinA, LOW);
    delayMicroseconds(5);
    digitalWrite(pinB, HIGH);
    analogWrite(pinPWM, abs(pwm));
  }
  else
  {
    digitalWrite(pinA, HIGH);
    delayMicroseconds(5);
    digitalWrite(pinB, LOW);
    analogWrite(pinPWM, abs(pwm));
  }
  curPWM = pwm;
}

void DCMotor::setSpeed(int pwm) {
  this->tarPWM = pwm;
}
int DCMotor::getSpeed() {
  return this->curPWM;
}

void DCMotor::loop() {
  int newLoopMs = millis();
  int maxChange = newLoopMs - this->prevLoopMs;
  int change = tarPWM - curPWM;
  int newPWM = curPWM + constrain(change, -maxChange, maxChange);
  setRawSpeed(newPWM);
  this->prevLoopMs = newLoopMs;
}