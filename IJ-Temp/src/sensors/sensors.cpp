#include "sensors/sensors.hpp"

pros::Imu sensors::imu(IMU_PORT);
pros::Rotation sensors::left_encoder(LEFT_ENCODER_PORT);
pros::Rotation sensors::right_encoder(RIGHT_ENCODER_PORT);

void sensors::initialize() {
    imu.reset();
    while (imu.is_calibrating()) pros::delay(10);
    left_encoder.reset_position();
    right_encoder.reset_position();
}

double sensors::get_left_encoder() {
    return left_encoder.get_position() / 100.0; // Convert to degrees
}