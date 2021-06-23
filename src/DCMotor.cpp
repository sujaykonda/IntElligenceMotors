#include "DCMotor.h"

DCMotor::DCMotor(int pinPWM, int pinH1, int pinH2) {
  pinMode(pinH1, OUTPUT);
  pinMode(pinH2, OUTPUT);
   
  this->pinPWM = pinPWM;
  this->pinH1 = pinH1;
  this->pinH2 = pinH2;
}

void DCMotor::setPWM(int pwm) {
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

int DCMotor::getPWM()
{
  return curPWM;
}