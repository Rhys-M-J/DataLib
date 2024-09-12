#pragma once
#include "main.h"
class drive
{

public:
    enum DT {sarc, arc, tank};

    drive();
    drive(int,int,int,int,DT);
    drive(int,int,int,int,int,int,DT);
    drive(int,int,int,int,int,int,int,int,DT);


    
    void UC();
    void DI(double, double);

    private:
   pros::Motor LF;
   pros::Motor LM;
   pros::Motor LB;
   pros::Motor RF;
   pros::Motor RM;
   pros::Motor RB;

   pros::Motor_Group R;
   pros::Motor_Group L;

    void SARC();
    void ARC();
    void TANK();

    void DF(int,int);

   DT DriveType;
};

