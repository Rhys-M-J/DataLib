#include "main.h"
#include "odom.hpp"



Odom::Odom(int IP, int FRP, int LRP, double fr_off, double s_off) :
    inert(IP), forward1(FRP), sideways1(LRP), forward1offset(fr_off), sideways1offset(s_off),
    forward2(0)
{
    enc_prev_forward = 0;
    enc_prev_forward = 0;
    imu_prev_head = 0;

    global_X = 0;
    global_Y = 0;

    forward1.reset_position();
    forward2.reset_position();
    sideways1.reset_position();
}


void Odom::calc()
    {
        double tcutoff = 0.01;
        double scutoff = 30;
        const double g_head = inert.get_heading();


        double imu_dif_head = imu_prev_head - g_head;

        if((imu_dif_head >  -tcutoff) && (imu_dif_head < tcutoff))
        {
            imu_dif_head = 0;
        }
        

        imu_dif_head *= (3.14/180);

        double forward1p = forward1.get_position();
        double forward2p = 0; //sideways1.get_position();

        double enc_dif_x = (forward1p/1000) - enc_prev_forward;
        double enc_dif_y = (forward2p/1000) - enc_prev_side;

        if((enc_dif_x > -scutoff) && (enc_dif_x < scutoff))
            {
                enc_dif_x = 0;
            }

        if((enc_dif_y > -scutoff) && (enc_dif_y < scutoff))
            {
                enc_dif_y = 0;
            }

            

        double locX = 0;
        double locY = 0;

        if (!imu_dif_head)
        {
            locX = enc_dif_x;
            locY = enc_dif_y;
        }

        else 
        {
            locX = ((2*sin(imu_dif_head / 2)) * ((enc_dif_x / imu_dif_head) + forward1offset));
            locY = ((2*sin(imu_dif_head / 2)) * ((enc_dif_y / imu_dif_head)));
        }

        double p_angle = 0;
        double p_magnitude = 0;

        if (!locX && !locY)
        {
           return;
        }

        else 
        {
            p_angle = atan2(locY, locX);
            p_magnitude = sqrt(pow(locY, 2) + pow(locX, 2));
        }

        double g_p_angle = p_angle - ((3.14/180)*g_head) - ((3.14/180)*imu_dif_head);

        global_X += p_magnitude * cos(g_p_angle);
        global_Y += p_magnitude * sin(g_p_angle);
        global_O = g_head;

        
        ctlr.clear();
        pros::delay(70);
        ctlr.print(0, 2, "X : %f", global_Y);
        pros::delay(100);
        ctlr.print(1, 2, "Y : %f", global_X);
        pros::delay(100);
        

        enc_prev_forward = forward1p/1000;
        enc_prev_side = forward2p/1000;



    }