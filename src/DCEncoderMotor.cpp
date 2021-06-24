#include "DCEncoderMotor.h"

DCEncoderMotor::DCEncoderMotor(int pinPWM, int pinH1, int pinH2, int channelA, int channelB, MotorGain GAIN) : motor(pinPWM, pinH1, pinH2), encoder(channelA, channelB), pid(0, 0, 0) {
  this->prevTime = -1;
  this->GAIN = GAIN;
}

void DCEncoderMotor::count() {
  encoder.count();
}

void DCEncoderMotor::setPWM(int pwm) {
  motor.setPWM(pwm);
}

void DCEncoderMotor::setTarEPS(double eps) {
  tarEPS = eps/1000.0;

  mode = SET_SPEED;
  
  pid.setConstants(this->GAIN * 2, this->GAIN * 0, this->GAIN * 2);
  pid.reset();
  
  prevSpeed = 100 * eps/fabs(eps);
  motor.setPWM(prevSpeed);

  prevPos = 0;
}

void DCEncoderMotor::setTarPos(int pos) {
  tarPos = pos;

  mode = GO_TO_POS;
}

void DCEncoderMotor::loop() {
  long curTime = millis();
  double curPos = encoder.get();
  if (curTime - prevTime > 0) {
    if (mode == SET_SPEED) {
      double curEPS = (curPos - prevPos) / (curTime - prevTime);
      double error = tarEPS - curEPS;
      double adjust = pid.loop(error);
      Serial.println(error * 1000.0);
      //Serial.println(curPos);
      prevSpeed -= adjust;
      //Serial.println(prevSpeed);
      motor.setPWM(prevSpeed);
    }
    prevPos = encoder.get();
    prevTime = curTime;
  }
}
