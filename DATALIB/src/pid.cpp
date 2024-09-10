#include "pid.hpp"
#include "odom.hpp"


PID::PID(Odom o, double p, double i, double d) :
position(o), kp(p), ki(i), kd(d)

    {
        
    }



void PID::d_point(double des_x, double des_y)
    {

        x_error = des_x - position.global_X;
        y_error = des_y - position.global_Y;

        m_error = sqrt (pow(x_error, 2) * pow(y_error, 2));

        a_error = position.global_O - ((180/3.14) * atan2(x_error, y_error));

        

        double m_speed = ((kp) + (ki) + (kd));
                
    }