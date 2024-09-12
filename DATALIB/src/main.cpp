#include "main.h"
#include "drive.hpp"
#include "subsystem.hpp"
#include "odom.hpp"
#include "pid.hpp"
pros::Controller ctlr(pros::E_CONTROLLER_MASTER);

drive drivet (11,12,13,-20,-19,-18, drive::sarc);
drive* drive_p =  &drivet;
Odom odo (17, 16, 10, 0, 0.5);
subsystem intake(15, -14, pros::E_CONTROLLER_DIGITAL_R1, pros::E_CONTROLLER_DIGITAL_R2 );
subsystem intakePis('B', pros::E_CONTROLLER_DIGITAL_Y);

subsystem Hood('C', pros::E_CONTROLLER_DIGITAL_B);
subsystem RClamp('A', pros::E_CONTROLLER_DIGITAL_B);

subsystem rush_clamp_dep('E', pros::E_CONTROLLER_DIGITAL_X);
subsystem rush_clamp_use('F', pros::E_CONTROLLER_DIGITAL_Y);

subsystem end_game('G', 'H', pros::E_CONTROLLER_DIGITAL_UP);

PID auto_d(drive_p, odo,  1, 0, 0, 2, 0, 0);

void odocalcwrap()
{
	while(1)
	{
		odo.calc();
	}
}


void initialize() {
	
	odo.inert.reset();
	pros::delay(2500);
	
	pros::Task odometry(odocalcwrap);}

void disabled() {}

void competition_initialize() {}


void autonomous() 
	{
		auto_d.d_point(0, 30);
	}


void opcontrol() {
	

	while (true)
	{

		drivet.UC();
		intake.P_B_M22();
		RClamp.T_B_P11();
		rush_clamp_dep.T_B_P11();
		rush_clamp_use.T_B_P11();
		Hood.T_B_P11();
		intakePis.T_B_P11();
		

		pros::delay(20);
	}
}
