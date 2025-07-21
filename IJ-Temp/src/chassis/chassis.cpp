#include "chassis/chassis.hpp"
#include "chassis/constants.hpp"
#include "pid/pid.hpp"

pros::MotorGroup left_motors({LEFT_MOTOR_PORT});
pros::MotorGroup right_motors({-RIGHT_MOTOR_PORT}); // Negative = reversed

PID move_pid(constants::MOVE_KP, constants::MOVE_KI, constants::MOVE_KD);
PID turn_pid(constants::TURN_KP, constants::TURN_KI, constants::TURN_KD);

void chassis::initialize() {
    left_motors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
    right_motors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
}

void chassis::move_distance(double inches, int timeout_ms) {
    double target = inches * constants::TICKS_PER_INCH;
    left_motors.tare_position();
    right_motors.tare_position();
    
    uint32_t start = pros::millis();
    while (pros::millis() - start < timeout_ms) {
        double avg_pos = (left_motors.get_positions()[0] + 
                         right_motors.get_positions()[0]) / 2.0;
        double power = move_pid.compute(target, avg_pos);
        
        left_motors.move_voltage(power * 12000 / 127);
        right_motors.move_voltage(power * 12000 / 127);
        pros::delay(10);
    }
    left_motors.brake();
    right_motors.brake();
}