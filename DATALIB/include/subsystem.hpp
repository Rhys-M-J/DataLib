#pragma once 

#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"



class subsystem 
{
    private:

    pros::controller_digital_e_t button;
    pros::controller_digital_e_t button2;

    pros::Motor M1;
    pros::Motor M2;

    pros::ADIDigitalOut PIS1;
    pros::ADIDigitalOut PIS2;

    pros::Optical CS1;
    

    int toggle;
    
    public:

    subsystem(int, pros::controller_digital_e_t, pros::controller_digital_e_t);
    subsystem(int, int, pros::controller_digital_e_t, pros::controller_digital_e_t);
    subsystem(int, int, int, pros::controller_digital_e_t, pros::controller_digital_e_t);
    subsystem(char, pros::controller_digital_e_t);
    subsystem(char, char, pros::controller_digital_e_t);
        
    void P_B_M12();
    void P_B_M22();

    void A_M1(int);
    void A_M2(int);

    void T_B_P21();
    void T_B_P11();

    void A_P1();

    void CS_P1(int);

};

