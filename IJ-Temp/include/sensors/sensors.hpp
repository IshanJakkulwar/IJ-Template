#pragma once
#include "api.h"

namespace sensors {
    extern pros::Imu imu;
    extern pros::Rotation left_encoder;
    extern pros::Rotation right_encoder;
    
    void initialize();
    double get_left_encoder();
    double get_right_encoder();
    double get_heading(bool radians = false);
}