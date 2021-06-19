#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <Arduino.h>

class DCMotor {
  public:
    DCMotor(int pinPWM, int pinH1, int pinH2);
    void setMaxAcc(double acc);
    void setRawSpeed(int speed);
    void setSpeed(int speed);
    void flip();
    int getSpeed();
    void loop();
  private:
    int pinPWM;
    int pinH1;
    int pinH2;

    double acc;
    int dir;

    int tarPWM;
    int curPWM;

    int prevLoopMs;
};
#endif
