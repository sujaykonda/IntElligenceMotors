#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PIDControl {
    public:
        PIDControl(double kp, double ki, double kd);
        void setConstants(double kp, double ki, double kd);
        double loop(double error);
        void reset();

    private:
        double kp; 
        double ki;
        double kd;

        double prev;

        double proportional;
        double differencial;
        double integral;

        long prev_time;
};

#endif
