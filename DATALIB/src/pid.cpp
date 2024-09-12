#include "pid.hpp"
#include "odom.hpp"
#include "drive.hpp"


PID::PID( drive*  DT, Odom o, double p, double i, double d, double tp, double ti, double td) :
 dt(DT), position(o), kp(p), ki(i), kd(d), tolerance(1), time(20000), tkp(), tki(), tkd()

    {
        m_error = 0;
        a_error = 0;

        t_m_error = 0;
        t_a_error = 0;

        r_time = 0;
        r_t_time = 0;

    }

int A_CORRECT(double a)
    {
        
        //a -= 90;

        if (a >= 180)
        {
            a -= 360;
        }

        return a;
    }

void PID::d_point(double des_x, double des_y)
    {

        do
            {
                p_m_error = m_error;
                p_a_error = a_error;

                x_error = des_x - position.global_X;
                y_error = des_y - position.global_Y;

                double c_m_error = p_m_error - m_error;
                double c_a_error = p_a_error - a_error;

                t_m_error += m_error;
                t_a_error += a_error;

                m_error = sqrt (pow(x_error, 2) + pow(y_error, 2));

                a_error = -A_CORRECT(position.inert.get_heading()) - ((180/3.14) * atan2(x_error, y_error));

                double m_speed = ((kp * m_error) + (ki * t_m_error) + (kd * c_m_error));
                double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                /*ctlr.clear();
                pros::delay(70);
                ctlr.print(1,1,"%f", a_error);
                pros::delay(70);*/

                dt->DI(m_speed - a_speed, m_speed + a_speed);
            } while (timeout() && in_tolerance());

            
            
    }

int PID::timeout()
    {
        if (time <= r_time)
        {
            return 0;
        }
        r_time += 10;
        return 1;
    }

int PID::in_tolerance()
    {
        if( (m_error <= tolerance))
        {
            if (t_time <= r_t_time)
            {
                return 0;
            }

            else
            {
                r_t_time += 10;
            }
        }

        else
        {
            r_t_time = 0;
        }

        return 1;
    }