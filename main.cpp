#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include "Engine.h"
#include "Moving.h"
int main(int argc,char **argv)
{
    //default init
    Player bibis = Player('c',0,0);
    Gnome monster1 = Gnome('o',0,0);
    Traal monster2 = Traal('w',0,0);
    ScoreBoard scoreboard = ScoreBoard();
    Engine eng(bibis,monster1,monster2,scoreboard);

    eng.StartEngine(argv[1],argv[2]);








    return 0;
}
