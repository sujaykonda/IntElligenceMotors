#include "DCEncoderModer.h"

DCEncoderMotor::DCEncoderMotor(int pinPWM, int pinH1, int pinH2, int channelA, int channelB) : motor(pinPWM, pinH1, pinH2), encoder(channelA, channelB), pid(0, 0, 0) {}

void DCEncoderMotor::setPWM(int pwm) {
    motor.setPWM(pwm);
}

void DCEncoderMotor::setTarEPS(double eps) {
    tarEPS = eps;

    mode = SET_SPEED;

    pid.setConstants(eps/100.0, eps/100000.0, eps/100.0);
}

void DCEncoderMotor::setTarPos(int pos) {
    tarPos = pos;

    mode = GO_TO_POS;
}

void DCEncoderMotor::loop() {
    double curPos = encoder.get();
    int curTime = millis();
    if(mode == SET_SPEED) {
        double curEPS = (curPos - prevPos) / (curTime - prevTime);
        motor.setPWM(motor.getPWM() + pid.loop(tarEPS - curEPS));
    }
    prevPos = curPos;
    prevTime = curTime;
}


