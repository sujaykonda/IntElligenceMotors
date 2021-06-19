#ifndef DC_MOTOR_H
#define DC_MOTOR_H

class DCMotor {
  public:
    DCMotor(int pinPWM, int pinA, int pinB);
    void setMaxAcc(double acc);
    void setRawSpeed(int speed);
    void setSpeed(int speed);
    int getSpeed();
    void loop();
  private:
    int pinPWM;
    int pinA;
    int pinB;

    double acc;

    int tarPWM;
    int curPWM;

    int prevLoopMs;
};
#endif