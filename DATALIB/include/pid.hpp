#pragma once
#include "main.h" 
#include "odom.hpp"
#include "drive.hpp"

class PID 
{


    private:

    Odom position;
    drive * dt;

    double kp;
    double ki;
    double kd;
    double tkp;
    double tki;
    double tkd;

    double x_error;
    double y_error;
  
    double m_error;
    double a_error;

    double p_m_error;
    double p_a_error;

    double t_m_error;
    double t_a_error;

    int time;
    int r_time;

    int t_time;
    int r_t_time;

    int tolerance;

    int timeout();
    int in_tolerance();

    public:

    PID( drive* , Odom, double, double, double, double, double, double);

    void d_point(double, double, int);
    void d_t_point(double, double, int);

    void t_point(double, double, int);



};