#pragma once

class PID {
public:
    PID(double kP, double kI, double kD, double min = -127, double max = 127);
    double compute(double target, double current);
    void reset();
    
private:
    double kP, kI, kD;
    double min, max;
    double integral = 0;
    double prev_error = 0;
};