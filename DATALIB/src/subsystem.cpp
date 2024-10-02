#include "main.h"
#include "pros/misc.h"
#include "subsystem.hpp"

subsystem::subsystem(int SP, pros::controller_digital_e_t btn, pros::controller_digital_e_t btn2) : 
    M1(SP), button(btn), button2(btn2),
    toggle(1), M2(0), PIS1('z'), PIS2('z'), CS1(0)
    {}

subsystem::subsystem(int SP1, int SP2, pros::controller_digital_e_t btn, pros::controller_digital_e_t btn2) : 
    M1(SP1), M2(SP2), button(btn), button2(btn2),
    toggle(1), PIS1('z'), PIS2('z'), CS1(0)
    {}

subsystem::subsystem(int CS, int SP1, int SP2, pros::controller_digital_e_t btn, pros::controller_digital_e_t btn2) : 
    CS1(CS), M1(SP1), M2(SP2), button(btn), button2(btn2),
    toggle(1), PIS1('z'), PIS2('z')
    {}

subsystem::subsystem( int CS, char TP, char TP2, pros::controller_digital_e_t btn) :
    PIS1(TP), PIS2(TP2), button(btn), 
    toggle(1), M1(0), M2(0), CS1(CS)
    {}

subsystem::subsystem( char TP, char TP2, pros::controller_digital_e_t btn) :
    PIS1(TP), PIS2(TP2), button(btn), 
    toggle(1), M1(0), M2(0), CS1(0)
    {}

subsystem::subsystem(char TP, pros::controller_digital_e_t btn) :
    PIS1(TP), button(btn), 
    toggle(0), M1(0), M2(0), PIS2('z'), CS1(0)
    {}

subsystem::subsystem(int CS, char TP, pros::controller_digital_e_t btn) :
    PIS1(TP), button(btn), 
    toggle(1), M1(0), M2(0), PIS2('z'), CS1(CS)
    {
        CS1.set_led_pwm(100);
    }

void subsystem::P_B_M12()
    {

        if (ctlr.get_digital(button))
            {
                M1.move(127);
            }
        else if (ctlr.get_digital(button2)) 
            {
                M1.move(-127);
            }

        else 
            {
                M1.brake();
            }

    }

void subsystem::P_B_M22()
    {

        if (ctlr.get_digital(button))
            {
                M1.move(127);
                M2.move(127);
            }
        else if (ctlr.get_digital(button2)) 
            {
                M1.move(-127);
                M2.move(-127);
            }
            
        else 
            {
                M1.brake();
                M2.brake();
            }

    }

void subsystem::T_B_P21()
    {
        if (ctlr.get_digital_new_press(button))
        {
            toggle = 1 ^ toggle; 
        }

        PIS1.set_value(toggle);
        PIS2.set_value(toggle);
    }

void subsystem::T_B_P11()
    {
        if (ctlr.get_digital_new_press(button))
        {
            toggle = 1 ^ toggle; 
        }

        PIS1.set_value(toggle);
        
    }


void subsystem::A_M1(int i)
    {
        if (i==1)
        {
            M1.move(127);
            
        }
        else if (i==2)
        {
            M1.move(-127);
           
        }
        else
        {
            M1.brake();
        }
    }

void subsystem::A_M2(int i)
    {
        if (i==1)
        {
            M1.move(127);
            M2.move(127);
        }
        else if (i==2)
        {
            M1.move(-127);
            M2.move(-127);
        }
        else
        {
            M1.brake();
            M2.brake();
        }
    }

void subsystem::A_P1()
    {
        toggle = toggle ^ 1; 

        PIS1.set_value(toggle);
    }

void subsystem::CS_P1(int i)
    {
switch (i)
{
case 0:
    if (CS1.get_hue() < 210 && CS1.get_hue() > 140)
    {PIS1.set_value(1);}
    
    else
    {PIS1.set_value(0);}

    break;

case 1:
    if ((CS1.get_hue() < 40 && CS1.get_hue() >= 0) || (CS1.get_hue() <= 360 && CS1.get_hue() > 345))
    {PIS1.set_value(1);}
    
    else
    {PIS1.set_value(0);}

default:
    break;
}
    }