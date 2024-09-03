#include "main.h"

class gui
{
private:

    
    
public:

    gui();
    gui(int);

    enum team {Red, Blue};
    team Team;

    void guiHome();
    void autoS();

    static lv_res_t TSet(lv_obj_t *);
    lv_action_t TSel();
    
    void TSetR();
    void TSetB();


    team getTeam();
    
    
};

    static lv_res_t TSetRW(lv_obj_t *);
    static lv_res_t TSetBW(lv_obj_t *);

    extern gui guit;
