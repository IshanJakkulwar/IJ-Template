#pragma once
#include "api.h"

// Hardware ports - UPDATE THESE!
#define LEFT_MOTOR_PORT 1
#define RIGHT_MOTOR_PORT 2
#define IMU_PORT 3
#define LEFT_ENCODER_PORT 'A'
#define RIGHT_ENCODER_PORT 'B'

extern pros::Controller controller;

void autonomous();
void opcontrol();
void initialize();