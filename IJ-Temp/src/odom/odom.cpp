#include "odom/odom.hpp"
#include "sensors/sensors.hpp"
#include <atomic>
#include <cmath>

static std::atomic<double> x{0}, y{0}, theta{0};
static pros::Task* odom_task = nullptr;

void odom_task_fn(void*) {
    double last_left = 0, last_right = 0;
    while (true) {
        double left = sensors::get_left_encoder();
        double right = sensors::get_right_encoder();
        
        double delta_left = (left - last_left) * (M_PI * constants::WHEEL_DIAMETER) / 360.0;
        double delta_right = (right - last_right) * (M_PI * constants::WHEEL_DIAMETER) / 360.0;
        
        double delta_dist = (delta_left + delta_right) / 2.0;
        double delta_theta = (delta_right - delta_left) / constants::WHEELBASE_WIDTH;
        
        theta.store(theta.load() + delta_theta);
        x.store(x.load() + delta_dist * cos(theta.load()));
        y.store(y.load() + delta_dist * sin(theta.load()));
        
        last_left = left;
        last_right = right;
        pros::delay(10);
    }
}

void odom::start_task() {
    if (!odom_task) {
        odom_task = new pros::Task(odom_task_fn, nullptr, "Odometry");
    }
}

odom::Pose odom::get_pose() {
    return {x.load(), y.load(), theta.load()};
}