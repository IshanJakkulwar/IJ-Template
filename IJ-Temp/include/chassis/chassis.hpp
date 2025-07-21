#pragma once
#include "api.h"

namespace chassis {
    void initialize();
    void tank(int left, int right);
    void arcade(int power, int turn);
    
    // Autonomous movements
    void move_distance(double inches, int timeout_ms = 4000);
    void turn_degrees(double degrees, int timeout_ms = 3000);
    
    void set_brake_mode(pros::motor_brake_mode_e_t mode);
}