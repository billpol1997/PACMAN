

#include "Player.h"

Player::Player( char ch_symb,int x,int y) : Moving(y,x)
{
     this->ch_symb = ch_symb;




}



void Player::Setchsymb(char ch)
{
    ch_symb = ch;
}


char Player::Getchsymb()
{

    return ch_symb;
}



int Player::Getmv(int choice)
{


    switch (choice)
    {
        case KEY_UP:
            Mvup();
            break;
        case KEY_DOWN:
            Mvdown();
            break;
        case KEY_LEFT:
            Mvleft();
            break;
        case KEY_RIGHT:
            Mvright();
            break;
        case (int)' ':
            Nomv();
            break;
        default:
            break;

    }
    return choice;


}