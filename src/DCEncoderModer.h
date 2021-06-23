#ifndef DC_ENCODER_MOTOR_H
#define DC_ENCODER_MOTOR_H

#include "DCMotor.h"
#include "DCEncoder.h"
#include "PID.h"

enum MotorMode
{
    SET_SPEED,
    GO_TO_POS
};

class DCEncoderMotor {
    public:
        DCEncoderMotor(int pinPWM, int pinH1, int pinH2, int channelA, int channelB);

        void setTarEPS(double eps);
        void setTarPos(int pos);

        void loop();

        void setPWM(int pwm);

    private:
        MotorMode mode;

        DCMotor motor;
        DCEncoder encoder;

        double tarEPS;
        double prevPos;
        double prevTime;

        double tarPos;

        PIDControl pid;
};

#endif