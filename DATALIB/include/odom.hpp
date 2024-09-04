#pragma once

#include "main.h"
#include "pros/rotation.hpp"

class Odom
{
    private:

    pros::Rotation forward1;
    pros::Rotation forward2;
    pros::Rotation sideways1;

    pros::IMU inert;

    double forward1offset;
    double forward2offset;
    double sideways1offset;

    double enc_prev_forward;
    double enc_prev_side;
    double imu_prev_head;
    
    
    public:

    Odom(int);

    double global_X;
    double global_Y;
    double global_O;

    void calc();


};