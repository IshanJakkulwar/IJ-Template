#include "pid/pid.hpp"
#include <algorithm>

PID::PID(double kP, double kI, double kD, double min, double max) :
    kP(kP), kI(kI), kD(kD), min(min), max(max) {}

double PID::compute(double target, double current) {
    double error = target - current;
    integral += error;
    double derivative = error - prev_error;
    
    double output = (kP * error) + (kI * integral) + (kD * derivative);
    output = std::clamp(output, min, max);
    
    prev_error = error;
    return output;
}