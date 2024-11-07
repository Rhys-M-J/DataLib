#include "pid.hpp"
#include "odom.hpp"
#include "drive.hpp"
#include "pros/screen.h"
#include "pros/screen.hpp"

extern Odom odo;

PID::PID( drive*  DT, Odom o, double p, double i, double d, double tp, double ti, double td, double tol, double ttol, double tout, double t_a, double t_b, double t_c) :
 dt(DT), position(o), kp(p), ki(i), kd(d), tolerance(tol), time(tout), tkp(tp), tki(ti), tkd(td), tune_a(t_a), tune_b(t_b), tune_c(t_c)

    {

        m_error = 0;
        a_error = 0;

        t_m_error = 0;
        t_a_error = 0;

        r_time = 0;
        r_t_time = 0;

        t_time = 250;

    }


int A_180(double a)
    {

        if (a > 180)
        {
            a -= 360;
        }

        else if (a < -180)
        {
            a += 360;
        }

        return a;
    }


int A_360(double a)
    {

        if (a > 360)
        {
            a -= 360;
        }

        else if (a < 0)
        {
            a += 360;
        }

        return a;
    }

double PID::error_correct(double e)
    {

        return ((tune_a * pow(e , 1/tune_b)) + (tune_c * e));

    }


void PID::d_point(double des_x, double des_y, int rev)
    {
        r_t_time = 0;
        r_time = 0;
    if (!rev)
    {
        do
            {
                p_m_error = m_error;
                p_a_error = a_error;

                x_error = des_x - odo.global_X;
                y_error = des_y - odo.global_Y;

                double c_m_error = m_error - p_m_error;
                double c_a_error = a_error - p_a_error;

                t_m_error += m_error;
                t_a_error += a_error;

                m_error = sqrt (pow(x_error, 2) + pow(y_error, 2));

                a_error =  A_180(position.inert.get_heading() - (A_360((180/3.14) * atan2(x_error, y_error))));


                double m_speed = ((kp * m_error) + (ki * t_m_error) + (kd * c_m_error));
                double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                
                

                dt->DI(m_speed + a_speed, m_speed - a_speed);

                pros::delay(10);
        


            } while (timeout() && in_tolerance(m_error));
            dt->DI(0,0);
        }

    else if (rev)
        {
            do
            {
                p_m_error = m_error;
                p_a_error = a_error;

                x_error = des_x - odo.global_X;
                y_error = des_y - odo.global_Y;

                double c_m_error = m_error - p_m_error;
                double c_a_error = a_error - p_a_error;

                t_m_error += m_error;
                t_a_error += a_error;

                m_error = sqrt (pow(x_error, 2) + pow(y_error, 2));

                a_error = A_180(position.inert.get_heading() - A_360((180/3.14) * atan2(-x_error, -y_error)));
                
                double a_speed = 0;

                double m_speed = ((kp * m_error) + (ki * t_m_error) + (kd * c_m_error));

                if (m_error >= 5)
                {
                a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));
                }

                else
                {
                a_speed = (((tkp * a_error * 0.001) + (tki * t_a_error) + (tkd * c_a_error)));
                }
               

                dt->DI(-m_speed + a_speed, -m_speed - a_speed);

                pros::delay(10);
        


            } while (timeout() && in_tolerance(m_error));
            dt->DI(0,0);
        }
                    
        

            
            
    }

    void PID::t_point(double des_x, double des_y, int rev)
        {

            r_t_time = 0;
            r_time = 0;
            if (!rev)
            {
                do
                    {
                        
                        p_a_error = a_error;

                        x_error = des_x - odo.global_X;
                        y_error = des_y - odo.global_Y;

                        double c_a_error = a_error - p_a_error;

                        t_a_error += a_error;

                        a_error = A_180(position.inert.get_heading() - (A_360((180/3.14) * atan2(x_error, y_error))));
                        
                        

                        double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                        dt->DI(a_speed, -a_speed);

                        pros::delay(10);

                pros::screen::erase();
                pros::delay(50);
                pros::screen::print(pros::E_TEXT_LARGE, 1, "a error %f", a_error);

                    } while (timeout() && in_tolerance(a_error));
                    dt->DI(0,0);
                }

            else if (rev)
                {
                    do
                    {
                        

                        x_error = des_x - odo.global_X;
                        y_error = des_y - odo.global_Y;

                        double c_a_error = a_error - p_a_error;

                        

                        a_error = A_180(position.inert.get_heading() - A_360((180/3.14) * atan2(-x_error, -y_error)));
                        t_a_error += a_error;
                        p_a_error = a_error;

                        double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                        dt->DI(a_speed, -a_speed);

                        pros::delay(10);
                        pros::screen::erase();
                pros::delay(50);
                pros::screen::print(pros::E_TEXT_LARGE, 1, "a error %f", a_error);

                    } while (timeout() && in_tolerance(m_error));
                    dt->DI(0,0);
                }

                ctlr.clear();       
                //pros::screen::print(pros::E_TEXT_LARGE, 2, "m error %f", m_error); timeout() && in_tolerance(a_error)
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

int PID::in_tolerance(int E)
    {
        if (E < tolerance)
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

        else if (E > tolerance)
        {
            r_t_time = 0;
            
        }

        return 1;
    }