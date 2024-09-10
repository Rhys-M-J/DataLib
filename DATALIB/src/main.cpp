#include "main.h"
#include "drive.hpp"
#include "subsystem.hpp"
#include "odom.hpp"

pros::Controller ctlr(pros::E_CONTROLLER_MASTER);

drive drivet (11,12,13,-20,-19,-18, drive::sarc);
Odom odo (69, 16, 69, 69, 69);
subsystem intake(15, pros::E_CONTROLLER_DIGITAL_R1, pros::E_CONTROLLER_DIGITAL_R2 );

subsystem GClamp('C', pros::E_CONTROLLER_DIGITAL_A);
subsystem RClamp('A', pros::E_CONTROLLER_DIGITAL_B);

subsystem rush_clamp_dep('E', pros::E_CONTROLLER_DIGITAL_X);
subsystem rush_clamp_use('F', pros::E_CONTROLLER_DIGITAL_Y);

subsystem end_game('G', 'H', pros::E_CONTROLLER_DIGITAL_UP);


void initialize() {}

void disabled() {}

void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	

	while (true)
	{

		drivet.UC();
		intake.P_B_M12();
		RClamp.T_B_P11();

		pros::delay(20);
	}
}
