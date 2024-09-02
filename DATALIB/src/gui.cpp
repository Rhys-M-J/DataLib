#include "main.h"
#include "gui.hpp"

gui::gui(){};
gui::gui(int test){};


void gui::guiHome()
    {

        lv_obj_t * scrHome = lv_obj_create(NULL,NULL);
        lv_scr_load(scrHome);


        lv_obj_t * StartM = lv_btn_create(scrHome, NULL);
        lv_obj_set_size(StartM, 200, 200);
        lv_btn_set_action(StartM, LV_BTN_ACTION_PR, MatchSet());

        

        lv_obj_t * StartML = lv_label_create(StartM, NULL);
    	lv_label_set_text(StartML, "Start Setup");

        lv_style_t * StartMStl;
        //lv_style_copy(StartMStl,  &lv_style_plain);
        //StartMStl->body.main_color = LV_COLOR_GREEN;

        //lv_btn_set_style(StartM, 1, StartMStl);





        

        
    }


lv_action_t gui::MatchSet()
    {
        bool Passthrough = 0;

        lv_obj_del(lv_scr_act());


        lv_obj_t * scrTSel = lv_obj_create(NULL,NULL);
        lv_scr_load(scrTSel);


        lv_obj_t * SelRed = lv_btn_create(scrTSel, NULL);
        lv_obj_set_pos(SelRed, 0,0);
        //lv_btn_set_action(SelRed, LV_BTN_ACTION_CLICK, TSet(Red));

        lv_obj_t * SelRedL = lv_label_create(SelRed, NULL);


        lv_obj_t * SelBlue = lv_btn_create(scrTSel, NULL);
        lv_obj_set_pos(SelBlue, 50,50);
        //lv_btn_set_action(SelBlue, LV_BTN_ACTION_CLICK, TSet(Blue));

        lv_obj_t * SelBlueL = lv_label_create(SelBlue, NULL);




        return 0;
    }

lv_action_t gui::TSet(gui::team T)
    {
        Team = T;
        return 0;
    }

gui::team gui::getTeam()
    {
        return Team;
    }