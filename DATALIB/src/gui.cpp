#include "display/lv_misc/lv_color.h"
#include "display/lv_objx/lv_btn.h"
#include "main.h"
#include "gui.hpp"

static lv_style_t SMATCH;
static lv_style_t SSKILLS;
static lv_style_t SRED;
static lv_style_t SBLUE;
static lv_style_t SAUTO;






gui::gui(){};

gui::gui(int test)
{Team = White;};

gui guit(1);

void gui::guiHome()
    {

        lv_style_copy(&SMATCH, &lv_style_plain); /*Copy a built-in style to initialize the new style*/
        SMATCH.body.main_color = LV_COLOR_GREEN;
        SMATCH.body.grad_color = LV_COLOR_GREEN;
        SMATCH.body.radius = 0;
        SMATCH.text.color = LV_COLOR_BLACK;

        
        lv_style_copy(&SSKILLS, &lv_style_plain); 
        SSKILLS.body.main_color = LV_COLOR_WHITE;
        SSKILLS.body.grad_color = LV_COLOR_WHITE;
        SSKILLS.body.radius = 0;
        SSKILLS.text.color = LV_COLOR_BLACK;
        
        lv_obj_t * scrHome = lv_obj_create(NULL,NULL);
        lv_scr_load(scrHome);


        lv_obj_t * StartM = lv_btn_create(scrHome, NULL);
        lv_btn_set_style(StartM, LV_BTN_STYLE_REL,&SMATCH);
        lv_btn_set_style(StartM, LV_BTN_STYLE_PR, &SMATCH);
        lv_obj_set_size(StartM, 230, 240);
        lv_btn_set_action(StartM, LV_BTN_ACTION_CLICK, TSet);
        
        lv_obj_t * StartSkills = lv_btn_create(scrHome, NULL);
        lv_obj_set_pos(StartSkills,250, 0);
        lv_btn_set_style(StartSkills, LV_BTN_STYLE_REL,&SSKILLS);
        lv_btn_set_style(StartSkills, LV_BTN_STYLE_PR, &SSKILLS);
        lv_obj_set_size(StartSkills, 230, 240);
        lv_btn_set_action(StartSkills, LV_BTN_ACTION_CLICK, TSet);
        

        lv_obj_t * StartML = lv_label_create(StartM, NULL);
    	lv_label_set_text(StartML, "Match Setup");

    }



    lv_res_t gui::TSet(lv_obj_t * btn)
    {
       
        
        lv_obj_del(lv_scr_act());

        
        lv_obj_t * scrTSel = lv_obj_create(NULL,NULL);
        lv_scr_load(scrTSel);

        lv_style_copy(&SRED, &lv_style_plain); 
        SRED.body.main_color = LV_COLOR_RED;
        SRED.body.grad_color = LV_COLOR_RED;
        SRED.body.radius = 0;
        SRED.text.color = LV_COLOR_BLACK;

        lv_obj_t * SelRed = lv_btn_create(scrTSel, NULL);
        lv_btn_set_style(SelRed,LV_BTN_STYLE_REL, &SRED);
        lv_btn_set_style(SelRed,LV_BTN_STYLE_PR, &SRED);
        lv_obj_set_pos(SelRed, 0,0);
        lv_obj_set_size(SelRed,240,240);
        

        lv_obj_t * SelRedL = lv_label_create(SelRed, NULL);
        lv_label_set_text(SelRedL, "RED");

        lv_style_copy(&SBLUE, &lv_style_plain); 
        SBLUE.body.main_color = LV_COLOR_BLUE;
        SBLUE.body.grad_color = LV_COLOR_BLUE;
        SBLUE.body.radius = 0;
        SBLUE.text.color = LV_COLOR_BLACK;

        lv_obj_t * SelBlue = lv_btn_create(scrTSel, NULL);
        lv_btn_set_style(SelBlue,LV_BTN_STYLE_REL, &SBLUE);
        lv_btn_set_style(SelBlue,LV_BTN_STYLE_PR, &SBLUE);
        lv_obj_set_pos(SelBlue, 240,0);
        lv_obj_set_size(SelBlue,240,240);
        

        lv_obj_t * SelBlueL = lv_label_create(SelBlue, NULL);
        lv_label_set_text(SelBlueL, "BLUE");

        lv_btn_set_action(SelRed, LV_BTN_ACTION_CLICK, TSetRW);
        lv_btn_set_action(SelBlue, LV_BTN_ACTION_CLICK, TSetBW);

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
            lv_obj_del(lv_scr_act());

            lv_obj_t * KirkScreen = lv_obj_create(NULL, NULL);
            lv_obj_t * KirklandBackground = lv_img_create(KirkScreen, NULL);
            //lv_img_set_src(KirklandBackground, &KirklandSignature_map);
            guit.auto_sel = 1;
            return 0;
            
        }

        lv_res_t A2(lv_obj_t * btn)
        {
            lv_obj_del(lv_scr_act());
            guit.auto_sel = 2;
            return 0;
        }

        lv_res_t A3(lv_obj_t * btn)
        {
            lv_obj_del(lv_scr_act());
            guit.auto_sel = 3;
            return 0;
        }




    lv_res_t gui::autoS()
    {

        lv_style_copy(&SAUTO, &lv_style_plain_color);
        SAUTO.body.main_color = LV_COLOR_AQUA;
        SAUTO.text.color = LV_COLOR_BLACK;

        lv_obj_del(lv_scr_act());

        lv_obj_t * scrASel = lv_obj_create(NULL,NULL);
        lv_scr_load(scrASel);

        lv_obj_t * Auto1 = lv_btn_create(scrASel, NULL);
        lv_btn_set_style(Auto1,LV_BTN_STYLE_REL, &SAUTO);
        lv_btn_set_style(Auto1,LV_BTN_STYLE_PR, &SAUTO);
        lv_obj_set_pos(Auto1, 0,60);
        lv_btn_set_action(Auto1, LV_BTN_ACTION_CLICK, A1);

        lv_obj_t * Auto1L = lv_label_create(Auto1, NULL);
        lv_label_set_text(Auto1L, "Ring Long");

        lv_obj_t * Auto2 = lv_btn_create(scrASel, NULL);
        lv_btn_set_style(Auto2,LV_BTN_STYLE_REL, &SAUTO);
        lv_btn_set_style(Auto2,LV_BTN_STYLE_PR, &SAUTO);
        lv_obj_set_pos(Auto2, 160,60);
        lv_btn_set_action(Auto2, LV_BTN_ACTION_CLICK, A2);

        lv_obj_t * Auto2L = lv_label_create(Auto2, NULL);
        lv_label_set_text(Auto2L, "Ring Short");

        lv_obj_t * Auto3 = lv_btn_create(scrASel, NULL);
        lv_btn_set_style(Auto3,LV_BTN_STYLE_REL, &SAUTO);
        lv_btn_set_style(Auto3,LV_BTN_STYLE_PR, &SAUTO);
        lv_obj_set_pos(Auto3, 320,60);
        lv_btn_set_action(Auto3, LV_BTN_ACTION_CLICK, A3);

        lv_obj_t * Auto3L = lv_label_create(Auto3, NULL);
        lv_label_set_text(Auto3L, "Goal Rush");


        return LV_RES_OK;
    };



