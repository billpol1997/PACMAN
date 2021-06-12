

#ifndef PACMAN_GNOME_H
#define PACMAN_GNOME_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include "Moving.h"



using namespace std;
class Gnome:public Moving {
private:
    char ch_symb;
public:
    Gnome(char ch_symb,int x,int y);

    void Setchsymb(char ch);
    char Getchsymb();


    void Mv(int playery, int playerx,bool check);


};


#endif
