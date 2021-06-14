

#include "Moving.h"

using namespace std;


Moving::Moving(int x, int y) : X(x),Y(y)
{

}



Moving::~Moving()
{

}







void Moving::SetX(int x)
{
    X = x;
}

void Moving::SetY(int y)
{
    Y = y;
}

void Moving::SetH(int h)
{
    H = h;
}

void Moving::SetW(int w)
{
    W = w;
}

void Moving::SetChar(char p)
{
    character = p;
}




int Moving::GetX()
{
    return X;
}

int Moving::GetY()
{
    return Y;
}

int Moving::GetW()
{
    return W;
}

int Moving::GetH()
{
    return H;
}


char Moving::GetChar()
{
    return character;
}


//Object moves

void Moving::Nomv()
{
  X;
  Y;




}



void Moving::Mvup()
{

    Y--;
    if(Y<1)
        Y=1;
}

void Moving::Mvdown()
{

    Y++;
    if(Y>H-1)
    {
        Y = H-1;
    }

}

void Moving::Mvleft()
{

    X--;
    if(X<1)
        X=1;

}

void Moving::Mvright()
{

    X++;
    if(X>W)
        X = W;
}









