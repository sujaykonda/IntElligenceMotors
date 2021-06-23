#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <Arduino.h>

class DCMotor {
  public:
    DCMotor(int pinPWM, int pinH1, int pinH2);
    void setPWM(int speed);
    int getPWM();
  private:
    int pinPWM;
    int pinH1;
    int pinH2;

    int curPWM;
};
#endif
