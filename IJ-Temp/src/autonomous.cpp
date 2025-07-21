#include "main.h"

void autonomous() {
    chassis::initialize();
    sensors::initialize();
    odom::start_task();
    
    // Test routine
    chassis::move_distance(24);
    chassis::turn_degrees(90);
    
    odom::Pose p = odom::get_pose();
    printf("Final: (%.1f, %.1f) @ %.1f°\n", p.x, p.y, p.theta * 180/M_PI);
}