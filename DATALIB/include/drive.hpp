#pragma once
#include "main.h"
class drive
{

public:
    enum DT {sarc, arc, tank};

    drive(int,int,int,int,DT);
    drive(int,int,int,int,int,int,DT);
    drive(int,int,int,int,int,int,int,int,DT);
    ~drive();

    

    void SARC();
    void ARC();
    void TANK();

    void UC();

    private:
   pros::Motor LF;
   pros::Motor LM;
   pros::Motor LB;
   pros::Motor RF;
   pros::Motor RM;
   pros::Motor RB;

   pros::Motor_Group R;
   pros::Motor_Group L;

   DT DriveType;
};

