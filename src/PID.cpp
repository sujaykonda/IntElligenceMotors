#include "PID.h"

PIDControl::PIDControl(double kp, double ki, double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;

    reset();
}

void PIDControl::setConstants(double kp, double ki, double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

double PIDControl::loop(double error)
{
    long t = millis();
    if(t == prev_time) {
      prev_time -= 1;
    }
    this->proportional = error;
    this->integral += error * (t - prev_time) / 1000.0;
    this->differencial = (error - prev) / (t - prev_time) * 1000.0;

    prev = error;
    prev_time = t;

    return this->proportional * kp + this->integral * ki + this->differencial * kd;
}

void PIDControl::reset()
{
    prev_time = millis();
    prev = 0;
    
    proportional = 0;
    differencial = 0;
    integral = 0;
}
