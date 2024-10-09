#include "pid.hpp"
#include "odom.hpp"
#include "drive.hpp"

extern Odom odo;

PID::PID( drive*  DT, Odom o, double p, double i, double d, double tp, double ti, double td) :
 dt(DT), position(o), kp(p), ki(i), kd(d), tolerance(4), time(10000), tkp(tp), tki(ti), tkd(td)

    {
        m_error = 0;
        a_error = 0;

        t_m_error = 0;
        t_a_error = 0;

        r_time = 0;
        r_t_time = 0;

        t_time = 500;

    }

int A_CORRECT(double a)
    {

        if (a >= 180)
        {
            a -= 360;
        }

        return a;
    }

void PID::d_point(double des_x, double des_y, int rev)
    {
    
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

                a_error = - A_CORRECT(position.inert.get_heading()) + ((180/3.14) * atan2(x_error, y_error)) - 90;

                double m_speed = ((kp * m_error) + (ki * t_m_error) + (kd * c_m_error));
                double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                
                

                dt->DI(m_speed + a_speed, m_speed - a_speed);

                pros::delay(10);
        


            } while (timeout() && in_tolerance());
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

                a_error = A_CORRECT(position.inert.get_heading()) - ((180/3.14) * atan2(-x_error, -y_error));

                double m_speed = ((kp * m_error) + (ki * t_m_error) + (kd * c_m_error));
                double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                
                

                dt->DI(-m_speed + a_speed, -m_speed - a_speed);

                pros::delay(10);
        


            } while (timeout() && in_tolerance());
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

                        a_error = A_CORRECT(position.inert.get_heading()) - ((180/3.14) * atan2(x_error, y_error));

                        ctlr.clear();
                        ctlr.print(2, 2, "a error  %f", a_error );

                        double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                        dt->DI(-a_speed, a_speed);

                        pros::delay(10);

                    } while (timeout() && in_tolerance());
                    dt->DI(0,0);
                }

            else if (rev)
                {
                    do
                    {
                        

                        x_error = des_x - odo.global_X;
                        y_error = des_y - odo.global_Y;

                        double c_a_error = a_error - p_a_error;

                        

                        a_error = A_CORRECT(position.inert.get_heading()) - ((180/3.14) * atan2(-y_error, -x_error));

                        t_a_error += a_error;
                        p_a_error = a_error;

                        double a_speed = ((tkp * a_error) + (tki * t_a_error) + (tkd * c_a_error));

                        dt->DI(-a_speed, a_speed);

                        pros::delay(10);

                    } while (timeout() && in_tolerance());
                    dt->DI(0,0);
                }
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
        if (m_error < tolerance)
        {
            if (t_time <= r_t_time)
            {
                return 0;
            }

            else
            {
                r_t_time = r_t_time + 10;
                
            }
        }

        else if (m_error > tolerance)
        {
            r_t_time = 0;
            
        }

        return 1;
    }