#ifndef MOVING_H
#define MOVING_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>

#include "Engine.h"

using namespace std;

class Moving
{
private:






    int X,Y;
    int H;
    int W ;
    char character;
public:

    Moving(int x,int y);






    void SetX(int x);

    void SetY(int y);

    void SetH(int h);

    void SetW(int w);

    void SetChar(char p);



    int GetX();
    int GetY();
    int GetW();
    int GetH();
    char GetChar();


    void Nomv();
    void Mvup();
    void Mvdown();
    void Mvleft();
    void Mvright();




};

#endif // MOVING_H