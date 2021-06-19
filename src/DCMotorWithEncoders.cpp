#include "DCMotorWithEncoder.h"

DCMotorWithEncoder::DCMotorWithEncoder(DCMotor motor, MotorEncoder encoder, double maxEPS) : motor(motor), encoder(encoder)
{
    this->maxEPS = maxEPS;
}

void DCMotorWithEncoder::setEPS(double encsPerSec)
{
    this->mode = ENCODER;
    tarEPS = encsPerSec;
}

void DCMotorWithEncoder::setPWM(int pwm) 
{
    this->mode = PWM;
    motor.setSpeed(pwm);
}

void DCMotorWithEncoder::setAcc(double acc)
{
    motor.setMaxAcc(acc);
}

void DCMotorWithEncoder::loop() 
{
    int newLoopMs = millis();
    if(this->mode == ENCODER)
    {
        this->curEPS = (encoder.getEnc() - prevEnc) / ((newLoopMs - prevLoopMs) / 1000.0);
        double error = (tarEPS - curEPS)/maxEPS;
        int pwm = motor.getSpeed();
        
        motor.setSpeed(pwm);
    }
    motor.loop();
    this->prevLoopMs = newLoopMs;
    this->prevEnc = encoder.getEnc();
}

