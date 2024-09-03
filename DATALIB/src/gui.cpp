#include "main.h"
#include "gui.hpp"

gui::gui(){};
gui::gui(int test){};

gui guit(10);
bool Passthrough;


void gui::guiHome()
    {
            
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
        lv_obj_set_pos(SelRed, 0,120);
        lv_btn_set_action(SelRed, LV_BTN_ACTION_CLICK, TSetRW);

        lv_obj_t * SelRedL = lv_label_create(SelRed, NULL);


        lv_obj_t * SelBlue = lv_btn_create(scrTSel, NULL);
        lv_obj_set_pos(SelBlue, 300,120);
        lv_btn_set_action(SelBlue, LV_BTN_ACTION_CLICK, TSetBW);

        lv_obj_t * SelBlueL = lv_label_create(SelBlue, NULL);


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
            Team = Red;
            autoS();
        }

    lv_res_t TSetBW(lv_obj_t * btn)
        {
            guit.TSetB();
            return 0;
        }


void gui::autoS(){};



