#pragma once
#include <cmath>

namespace constants {
    // Physical measurements - UPDATE THESE!
    constexpr double WHEEL_DIAMETER = 3.25; // inches
    constexpr double WHEELBASE_WIDTH = 12.0; // inches
    
    // Calculated values
    constexpr double TICKS_PER_INCH = 36000.0 / (WHEEL_DIAMETER * M_PI);
    
    // PID gains - TUNE THESE!
    constexpr double MOVE_KP = 0.5;
    constexpr double MOVE_KI = 0.001;
    constexpr double MOVE_KD = 0.1;
    
    constexpr double TURN_KP = 2.5;
    constexpr double TURN_KI = 0.005;
    constexpr double TURN_KD = 0.3;
}