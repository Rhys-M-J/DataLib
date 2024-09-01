#include "main.h"
#include "drive.hpp"
pros::Controller ctlr(pros::E_CONTROLLER_MASTER);

drive drivet (11,12,13,-20,-19,-18, drive::sarc);

void initialize() {}

void disabled() {}

void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	

	while (true) {
		drivet.UC();
		pros::delay(20);
	}
}
