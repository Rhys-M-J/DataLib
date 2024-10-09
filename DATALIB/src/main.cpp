#include "main.h"
#include "drive.hpp"
#include "subsystem.hpp"
#include "odom.hpp"
#include "pid.hpp"
#include "gui.hpp"

pros::Controller ctlr(pros::E_CONTROLLER_MASTER);

drive drivet (11,12,13,-20,-19,-18, drive::sarc);
drive* drive_p =  &drivet;

Odom odo (17, 16, 0, 0, 0.5);
extern Odom odo;

subsystem intake(15, -14, pros::E_CONTROLLER_DIGITAL_R1, pros::E_CONTROLLER_DIGITAL_R2 );
subsystem intakePis('G', pros::E_CONTROLLER_DIGITAL_Y);

subsystem Hood(9 ,'E', pros::E_CONTROLLER_DIGITAL_B);
subsystem RClamp('H', pros::E_CONTROLLER_DIGITAL_B);

subsystem rush_clamp_dep('F', pros::E_CONTROLLER_DIGITAL_X);
subsystem rush_clamp_use('D', pros::E_CONTROLLER_DIGITAL_RIGHT);

subsystem end_game('Z', 'Y', pros::E_CONTROLLER_DIGITAL_UP);

PID auto_d_right(drive_p, odo,  4.25, 0, 0, 1.7, 0.0, 0);
PID auto_d_GR(drive_p, odo,  4, 0, 0, 1.5, 0.0, 0);

void odocalcwrap()
{
	while(1)
	{
		odo.calc();
		//Hood.CS_P1(guit.Team);
		pros::delay(50);

	}
}


void initialize() {

	guit.guiHome();
	//pros::delay(100);
	//odo.inert.reset();
	//pros::delay(2500);

	
		
	
	
	}

void disabled() {}

void competition_initialize() {}


void autonomous() 
	{
		pros::Task odometry(odocalcwrap);

     ////////////////////////////////////////////////////////////////////////////
		//Testing Auto
	///////////////////////////////////////////////////////////////////////////

		/*RClamp.A_P1();
		Hood.A_P1();Hood.A_P1();
		auto_d_right.d_point(13, -23, 1);
		drivet.DI(-30, -30);
		pros::delay(450);
		drivet.DI(0, 0);
		RClamp.A_P1();
		pros::delay(350);
		Hood.A_P1();
		pros::delay(350);
		//auto_d_right.t_point(-13, -26, 0);
		intake.A_M2(2);
		auto_d_right.d_point(-10, -26, 0);
		auto_d_right.t_point(-15, 0, 0);
		auto_d_right.d_point(-12, -38, 0);
		//auto_d_right.d_point(-8, -38, 0);
		pros::delay(500);
		auto_d_right.d_point(22 , -45, 0);
		Hood.A_P1();
		intake.A_M2(0);*/

	///////////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////////

   // Red = 0
   // Blue = 1

		if(0 == guit.Team) //red
		{
			switch (guit.auto_sel)
				{
					
					case 1:
		RClamp.A_P1();
		Hood.A_P1();Hood.A_P1();
		auto_d_right.d_point(13, -23, 1);
		drivet.DI(-30, -30);
		pros::delay(300);
		drivet.DI(0, 0);
		RClamp.A_P1();
		pros::delay(350);
		Hood.A_P1();
		pros::delay(350);
		auto_d_right.t_point(-13, -26, 0);
		intake.A_M2(2);
		auto_d_right.d_point(-10, -26, 0);
		auto_d_right.t_point(21, -20, 0);
		pros::delay(500);
		intakePis.A_P1();
		auto_d_right.d_point(21 , -15.5, 0);
		drivet.DI(30, 30);
		pros::delay(1000);
		drivet.DI(0, 0);
		drivet.DI(-30, -30);
		pros::delay(1000);
		drivet.DI(0, 0);
		//auto_d_right.t_point(20 , -40, 0);
		auto_d_right.d_point(20 , -40, 0);
		Hood.A_P1();
		intake.A_M2(0);

					case 2:
						RClamp.A_P1();
		Hood.A_P1();Hood.A_P1();
		auto_d_right.d_point(13, -23, 1);
		drivet.DI(-30, -30);
		pros::delay(300);
		drivet.DI(0, 0);
		RClamp.A_P1();
		pros::delay(350);
		Hood.A_P1();
		pros::delay(350);
		auto_d_right.t_point(-13, -26, 0);
		intake.A_M2(2);
		auto_d_right.d_point(-10, -26, 0);
		auto_d_right.t_point(25, -36, 0);
		pros::delay(500);
		auto_d_right.d_point(22 , -45, 0);
		Hood.A_P1();
		intake.A_M2(0);
						break;

					case 3:
		rush_clamp_dep.A_P1();
		//rush_clamp_use.A_P1();
		auto_d_GR.d_point(13.5, 33.5, 0);
		rush_clamp_use.A_P1();
		drivet.DI(-50, -50);
		pros::delay(800);
		drivet.DI(0, 0);
		auto_d_GR.d_point(10, 10, 1);
						break;
					
					default:
						break;
				}

		}

		else if (1 == guit.Team)  // blue
		{
			switch (guit.auto_sel)
				{
					
					case 1:
						RClamp.A_P1();
		Hood.A_P1();Hood.A_P1();
		auto_d_right.d_point(-13, -23, 1);
		drivet.DI(-30, -30);
		pros::delay(300);
		drivet.DI(0, 0);
		RClamp.A_P1();
		pros::delay(350);
		Hood.A_P1();
		pros::delay(350);
		auto_d_right.t_point(13, -26, 0);
		intake.A_M2(2);
		auto_d_right.d_point(10, -26, 0);
		auto_d_right.t_point(-21, -20, 0);
		pros::delay(500);
		intakePis.A_P1();
		auto_d_right.d_point(-21 , -15.5, 0);
		drivet.DI(30, 30);
		pros::delay(1000);
		drivet.DI(0, 0);
		drivet.DI(-30, -30);
		pros::delay(1000);
		drivet.DI(0, 0);
		//auto_d_right.t_point(20 , -40, 0);
		auto_d_right.d_point(-20 , -40, 0);
		Hood.A_P1();
		intake.A_M2(0);
						break;

					case 2:
						RClamp.A_P1();
						Hood.A_P1();Hood.A_P1();
						auto_d_right.d_point(-13, -23, 1);
						drivet.DI(30, -30);
						pros::delay(300);
						drivet.DI(0, 0);
						RClamp.A_P1();
						pros::delay(350);
						Hood.A_P1();
						pros::delay(350);
						auto_d_right.t_point(13, -23, 0);
						intake.A_M2(2);
						auto_d_right.d_point(10, -26, 0);
						auto_d_right.t_point(-25, -36, 0);
						pros::delay(500);
						auto_d_right.d_point(-22 , -45, 0);
						Hood.A_P1();
						intake.A_M2(0);
					
						break;

					case 3:
						rush_clamp_dep.A_P1();
						//rush_clamp_use.A_P1();
						auto_d_GR.d_point(-13.5, 33.5, 0);
						rush_clamp_use.A_P1();
						drivet.DI(-50, -50);
						pros::delay(800);
						drivet.DI(0, 0);
						auto_d_GR.d_point(-10, 10, 1);
						break;
					
					default:
						break;
				}
		}
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
		Hood.CS_P1(guit.Team);
		intakePis.T_B_P11();
		

		pros::delay(20);
	}
}
