#include "main.h"

void opcontrol() {
    chassis::initialize();
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    
    while (true) {
        chassis::arcade(
            master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
            master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)
        );
        pros::delay(20);
    }
}