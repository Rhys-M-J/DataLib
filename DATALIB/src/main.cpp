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
subsystem extend_mag('G', pros::E_CONTROLLER_DIGITAL_UP);
//subsystem redirect('E', 'z', pros::E_CONTROLLER_DIGITAL_Y);
subsystem redirect(21 ,'E', pros::E_CONTROLLER_DIGITAL_Y);
subsystem RClamp('H', pros::E_CONTROLLER_DIGITAL_B);
subsystem highstake('F', pros::E_CONTROLLER_DIGITAL_X);


PID auto_d_right(drive_p, odo,  1, 0.0, 0.0, 1, 0.0, 0.0, 2, 5, 5000, 4.5, 3, 13);
PID auto_d_GR(drive_p, odo,  1, 0.0, 0.0, 1, 0.0, 0.0, 2, 5, 5000, 4.5, 3, 13);


void odocalcwrap()
{
	while(1)
	{
		odo.calc();
		redirect.CS_P1(guit.Team);
		pros::delay(50);

	}
}


void initialize() {

	guit.guiHome();
	pros::delay(100);
	redirect.A_P1();
	RClamp.A_P1();
	//odo.inert.reset();
	//pros::delay(2500);

	
		
	
	
	}

void disabled() {}

void competition_initialize() {}


void autonomous() 
	{
		pros::Task odometry(odocalcwrap);
		extend_mag.A_P1();
		pros::delay(100);
		highstake.A_P1();
		
     ////////////////////////////////////////////////////////////////////////////
		//Testing Auto
	///////////////////////////////////////////////////////////////////////////

		//auto_d_right.t_point(-30, -26, 1);
	
	

	///////////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////////


		if(1 == guit.Team) //blue
		{
			switch (guit.auto_sel)
				{
					
					case 1: //ring long

						auto_d_right.d_point(13, -23, 1);

						pros::delay(300);
						drivet.DI(-30, -30);
						pros::delay(300);
						drivet.DI(0, 0);

						RClamp.A_P1();
						pros::delay(350);

						auto_d_right.t_point(-13, -26, 0);

						intake.A_M2(2);

						auto_d_right.d_point(0, -26, 0);
						auto_d_right.t_point(0, -50, 0);

						auto_d_right.d_point(0, -39, 0);
						auto_d_right.d_point(0, -15, 1);

					case 2:  // ring short
						auto_d_right.d_point(13, -23, 1);

						pros::delay(300);
						drivet.DI(-30, -30);
						pros::delay(300);
						drivet.DI(0, 0);

						RClamp.A_P1();

						pros::delay(350);

						auto_d_right.t_point(-13, -26, 0);

						intake.A_M2(2);

						auto_d_right.d_point(0, -26, 0);

						pros::delay(500);
						intake.A_M2(0);
						break;

					case 3:  // goal rush
						auto_d_right.d_point(-13, -23, 1);
						pros::delay(300);
						drivet.DI(-30, -30);
						pros::delay(300);
						drivet.DI(0, 0);
						RClamp.A_P1();
						pros::delay(350);
						intake.A_M2(2);
						pros::delay(1500);
						RClamp.A_P1();
						auto_d_right.t_point(7, -40, 1);
						auto_d_right.d_point(0, -42, 1);
						pros::delay(500);
						RClamp.A_P1();
						auto_d_right.t_point(3, -20, 0);
						auto_d_right.d_point(3, -20, 0);
						
						break;
					
						default:
						break;
				}

		}

		else if (0 == guit.Team)  // red
		{
			switch (guit.auto_sel)
				{
					
					case 1:  // ring long

						auto_d_right.d_point(-13, -23, 1);

						pros::delay(300);
						drivet.DI(-30, -30);
						pros::delay(300);
						drivet.DI(0, 0);

						RClamp.A_P1();

						pros::delay(350);

						auto_d_right.t_point(13, -26, 0);

						intake.A_M2(2);

						auto_d_right.d_point(0, -26, 0);
						auto_d_right.t_point(0, -50, 0);

						auto_d_right.d_point(0, -39, 0);
						auto_d_right.d_point(0, -15, 1);

						break;

					case 2:  // ring short		

						auto_d_right.d_point(-13, -23, 1);

						pros::delay(300);
						drivet.DI(-30, -30);
						pros::delay(300);
						drivet.DI(0, 0);

						RClamp.A_P1();

						pros::delay(350);

						auto_d_right.t_point(13, -26, 0);

						intake.A_M2(2);

						auto_d_right.d_point(0, -26, 0);

						break;

					case 3:  // goal rush

						auto_d_right.d_point(13, -23, 1);

						pros::delay(300);
						drivet.DI(-30, -30);
						pros::delay(300);
						drivet.DI(0, 0);

						RClamp.A_P1();
						pros::delay(350);
						intake.A_M2(2);
						pros::delay(1500);
						RClamp.A_P1();

						auto_d_right.t_point(-7, -40, 1);
						auto_d_right.d_point(0, -42, 1);

						pros::delay(500);
						RClamp.A_P1();

						auto_d_right.t_point(-3, -20, 0);
						auto_d_right.d_point(-3, -20, 0);

						break;

					default:
						break;
				}
		}

		else if (2 == guit.Team)
		{

		}
	}


void opcontrol() {
	

	while (true)
	{

		drivet.UC();
		intake.P_B_M22();
		RClamp.T_B_P11();
		highstake.T_B_P11();
		redirect.T_B_P11();
		extend_mag.T_B_P11();
		
		//Hood.CS_P1(guit.Team);
		pros::delay(20);
	}
}
