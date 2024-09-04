#include "main.h"
#include "pros/misc.h"
#include "subsystem.hpp"

subsystem::subsystem(int SP, pros::controller_digital_e_t btn, pros::controller_digital_e_t btn2) : 
    M1(SP), button(btn), button2(btn2),
    toggle(1), M2(0), PIS1('z'), PIS2('z')
    {}

subsystem::subsystem(char TP, char TP2, pros::controller_digital_e_t btn) :
    PIS1(TP), PIS2(TP2), button(btn), 
    toggle(1), M1(0), M2(0)
    {}

subsystem::subsystem(char TP, pros::controller_digital_e_t btn) :
    PIS1(TP), button(btn), 
    toggle(1), M1(0), M2(0), PIS2('z')
    {}

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
