#include "display/lv_core/lv_style.h"
#include "main.h"
#include "gui.hpp"

gui::gui(){};
gui::gui(int test){};

gui guit(10);
bool Passthrough;


void gui::guiHome()
    {
        
        lv_style_init();
        lv_obj_t * scrHome = lv_obj_create(NULL,NULL);
        lv_scr_load(scrHome);


        lv_obj_t * StartM = lv_btn_create(scrHome, NULL);
        lv_obj_set_size(StartM, 200, 200);
        lv_btn_set_action(StartM, LV_BTN_ACTION_PR, TSet);

        

        lv_obj_t * StartML = lv_label_create(StartM, NULL);
    	lv_label_set_text(StartML, "Start Setup");

        lv_style_t * StartMStl;
        //lv_style_copy(StartMStl,  &lv_style_plain);
        //StartMStl->body.main_color = LV_COLOR_GREEN;

        //lv_btn_set_style(StartM, 1, StartMStl);
    }



    lv_res_t gui::TSet(lv_obj_t * btn)
    {
        Passthrough = 1;

        lv_obj_del(lv_scr_act());


        lv_obj_t * scrTSel = lv_obj_create(NULL,NULL);
        lv_scr_load(scrTSel);

        lv_obj_t * SelRed = lv_btn_create(scrTSel, NULL);
        lv_obj_set_pos(SelRed, 20,100);
        lv_btn_set_action(SelRed, LV_BTN_ACTION_CLICK, TSetRW);

        lv_obj_t * SelRedL = lv_label_create(SelRed, NULL);
        lv_label_set_text(SelRedL, "Red");


        lv_obj_t * SelBlue = lv_btn_create(scrTSel, NULL);
        lv_obj_set_pos(SelBlue, 300,100);
        lv_btn_set_action(SelBlue, LV_BTN_ACTION_CLICK, TSetBW);

        lv_obj_t * SelBlueL = lv_label_create(SelBlue, NULL);
        lv_label_set_text(SelBlueL, "Blue");


        return LV_RES_OK;

    }

    void gui::TSetR()
        {
            Team = Red;
            autoS();
        }

    lv_res_t TSetRW(lv_obj_t * btn)
        {
            guit.TSetR();
            return 0;
        }

    void gui::TSetB()
        {
            Team = Blue;
            autoS();
        }

    lv_res_t TSetBW(lv_obj_t * btn)
        {
            guit.TSetB();
            return 0;
        }

        lv_res_t A1(lv_obj_t * btn)
        {
            guit.auto_sel = 1;
            lv_obj_del(lv_scr_act());
            return 0;
        }

        lv_res_t A2(lv_obj_t * btn)
        {
            guit.auto_sel = 2;
            lv_obj_del(lv_scr_act());
            return 0;
        }

        lv_res_t A3(lv_obj_t * btn)
        {
            guit.auto_sel = 3;
            lv_obj_del(lv_scr_act());
            return 0;
        }




    lv_res_t gui::autoS()
    {
        lv_obj_del(lv_scr_act());


        lv_obj_t * scrASel = lv_obj_create(NULL,NULL);
        lv_scr_load(scrASel);

        //static lv_style_t * ButtonS;
        //lv_style_copy(ButtonS, &lv_style_plain);

        lv_obj_t * Auto1 = lv_btn_create(scrASel, NULL);
        lv_obj_set_pos(Auto1, 0,120);
        lv_btn_set_action(Auto1, LV_BTN_ACTION_CLICK, A1);

        lv_obj_t * Auto1L = lv_label_create(Auto1, NULL);
        //lv_obj_set_style(Auto1, ButtonS);
        lv_label_set_text(Auto1L, "- corner full");


        lv_obj_t * Auto2 = lv_btn_create(scrASel, NULL);
        lv_obj_set_pos(Auto2, 150,120);
        lv_btn_set_action(Auto2, LV_BTN_ACTION_CLICK, A2);

        lv_obj_t * Auto2L = lv_label_create(Auto2, NULL);
        lv_label_set_text(Auto2L, "- corner short");

        lv_obj_t * Auto3 = lv_btn_create(scrASel, NULL);
        lv_obj_set_pos(Auto3, 300,120);
        lv_btn_set_action(Auto3, LV_BTN_ACTION_CLICK, A3);

        lv_obj_t * Auto3L = lv_label_create(Auto3, NULL);
        lv_label_set_text(Auto3L, "GR");


        return LV_RES_OK;
    };



