#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include "Engine.h"
#include "Moving.h"

class Player:public Moving{
 private:
    char ch_symb;


 public:
    Player(char ch_symb,int x,int y);

    void Setchsymb(char ch);
    char Getchsymb();


   int Getmv(int choice);
};


#endif
