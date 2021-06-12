

#ifndef PACMAN_TRAAL_H
#define PACMAN_TRAAL_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include "Moving.h"



using namespace std;
class Traal:public Moving {
private:
    char ch_symb;
public:
    Traal(char ch_symb,int x,int y);

    void Setchsymb(char ch);
    char Getchsymb();

    void Mv(int playery, int playerx,bool check);
};


#endif