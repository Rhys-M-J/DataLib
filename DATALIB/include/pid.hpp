#pragma once
#include "main.h" 
#include "odom.hpp"

class PID 
{


    private:

    Odom position;

    double kp;
    double ki;
    double kd;

    double x_error;
    double y_error;
  
    double m_error;
    double a_error;

    public:

    PID(Odom, double, double, double);

    void d_point(double, double);
    void d_t_point(double, double);

    void t_point();



};