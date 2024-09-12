#include "main.h"
#include "drive.hpp"


drive::drive(int LeftF, int LeftB, int RightF, int RightB, DT drvtp) :
    LF(LeftF), LB(LeftB), RF(RightF), RB(RightB), LM(0), RM(0),
    L({LF, LM, LB}), R({RF, RM, RB}),
    DriveType(drvtp)
    {
        
    }

drive::drive(int LeftF, int LeftM, int LeftB, int RightF, int RightM, int RightB, DT drvtp) : 
    LF(LeftF), LM(LeftM), LB(LeftB), RF(RightF), RM(RightM), RB(RightB), 
    L({LF,LM,LB}), R({RF,RM,RB}),
    DriveType(drvtp)
    {

    }

void drive::SARC()
    {
        L.move(ctlr.get_analog(ANALOG_LEFT_Y) - ctlr.get_analog(ANALOG_RIGHT_X));
        R.move(ctlr.get_analog(ANALOG_LEFT_Y) + ctlr.get_analog(ANALOG_RIGHT_X)); 
    }

void drive::ARC()
    {
        L.move(ctlr.get_analog(ANALOG_LEFT_Y) - ctlr.get_analog(ANALOG_LEFT_X));
        R.move(ctlr.get_analog(ANALOG_LEFT_Y) + ctlr.get_analog(ANALOG_LEFT_X)); 
    }

void drive::TANK()
    {
        L.move(ctlr.get_analog(ANALOG_LEFT_Y));
        R.move(ctlr.get_analog(ANALOG_RIGHT_Y)); 
    }


void drive::UC()
{
    switch (DriveType)
    {
    case sarc :
        SARC();
        break;

    case arc :
        ARC();
        break;

    case tank :
        TANK();
        break;
    
    default:
        break;
    }
}

void drive::DI(double l, double r)
    {
        L.move(l);
        R.move(r);
    }