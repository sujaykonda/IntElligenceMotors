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

enum MotorGain
{
    MOTOR_5X_GAIN=5,
    MOTOR_10X_GAIN=10,
    MOTOR_20X_GAIN=20,
    MOTOR_30X_GAIN=30,
    MOTOR_69X_GAIN=69
};

class DCEncoderMotor {
    public:
        DCEncoderMotor(int pinPWM, int pinH1, int pinH2, int channelA, int channelB, MotorGain GAIN=MOTOR_10X_GAIN);

        void count();
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
        double prevSpeed;

        double tarPos;

        PIDControl pid;
        MotorGain GAIN;
};

#endif
