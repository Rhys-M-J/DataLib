#include "main.h"
#include "odom.hpp"



Odom::Odom(int IP, int FRP, int LRP, int fr_off, int s_off) :
    inert(IP), forward1(FRP), sideways1(LRP), forward1offset(fr_off), sideways1offset(s_off),
    forward2(0)
{}


void Odom::calc()
    {
        double g_head = inert.get_heading();
        double imu_dif_head = imu_prev_head - g_head;

        imu_dif_head *= (3.14/180);

        const double enc_dif_x = forward1.get_position() - enc_prev_forward;
        const double enc_dif_y = sideways1.get_position() - enc_prev_side;

        double locX;
        double locY;

        if (!imu_dif_head)
        {
            locX = enc_dif_x;
            locY = enc_dif_y;
        }

        else 
        {
            locX = ((2*sin(imu_dif_head / 2)) * ((enc_dif_x / imu_dif_head)));
            locY = ((2*sin(imu_dif_head / 2)) * ((enc_dif_y / imu_dif_head)));
        }

        double p_angle;
        double p_magnitude;

        if (!locX && !locY)
        {
            return;
        }

        else 
        {
            p_angle = atan2(locY, locX);
            p_magnitude = sqrt(pow(locY, 2) + pow(locX, 2));
        }

        double g_p_angle = p_angle - g_head - (imu_dif_head);

        global_X += p_magnitude * cos(g_p_angle);
        global_Y += p_magnitude * cos(g_p_angle);

        enc_prev_forward = enc_dif_x;
        enc_prev_side = enc_dif_y;

        ctlr.clear();
        pros::delay(50);

        ctlr.print(2, 2, "X : %f", global_X);
        ctlr.print(3, 2, "Y : %f", global_Y);

    }