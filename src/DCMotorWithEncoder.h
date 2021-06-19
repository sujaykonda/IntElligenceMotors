#ifndef DC_MOTOR_WITH_ENC_H
#define DC_MOTOR_WITH_ENC_H
#include "DCMotor.h"
#include "MotorEncoder.h"

enum MotorMode { PWM, ENCODER };

class DCMotorWithEncoder {
    public:
        DCMotorWithEncoder(DCMotor motor, MotorEncoder encoder, double maxEPS);
        void setEPS(double encsPerSec);
        void setPWM(int pwm);
        void setAcc(double acc);
        void loop();

    private:
        DCMotor motor;
        MotorEncoder encoder;
        MotorMode mode;
        
        double maxEPS;
        double tarEPS;
        double curEPS;
        
        int prevLoopMs;
        int prevEnc;
};
#endif
