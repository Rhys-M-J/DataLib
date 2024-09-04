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
    

    int toggle;
    
    public:

    subsystem(int, pros::controller_digital_e_t, pros::controller_digital_e_t);
    subsystem(char, pros::controller_digital_e_t);
    subsystem(char, char, pros::controller_digital_e_t);
        
    void P_B_M12();

    void T_B_P21();
    void T_B_P11();

};

