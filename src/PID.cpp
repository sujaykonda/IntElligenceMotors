#include "PID.h"

PIDControl::PIDControl(double kp, double ki, double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

void PIDControl::setConstants(double kp, double ki, double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

double PIDControl::loop(double error)
{
    long time = millis();
    this->proportional = error;
    this->integral += error * (time - prev_time) / 1000.0;
    this->differencial += (error - prev) / (time - prev_time) * 1000.0;

    prev = error;
    prev_time = time;

    return this->proportional * kp + this->integral * ki + this->differencial * kd;
}

void PIDControl::reset()
{
    prev = 0;

    proportional = 0;
    differencial = 0;
    integral = 0;
}