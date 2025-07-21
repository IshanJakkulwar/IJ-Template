#pragma once
#include "api.h"

namespace odom {
    struct Pose {
        double x;       // inches
        double y;       // inches
        double theta;   // radians
    };

    void initialize();
    void start_task();
    Pose get_pose();
    void reset_pose(double x, double y, double theta);
}