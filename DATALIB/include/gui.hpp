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
    lv_action_t MatchSet();
    lv_action_t TSel();
    lv_action_t TSet(team);

    team getTeam();
    
};


//lv_action_t MatchSet();