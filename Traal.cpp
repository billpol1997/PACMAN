

#include "Traal.h"




Traal::Traal( char ch_symb,int x,int y) : Moving(y,x)
{
    this->ch_symb = ch_symb;




}



void Traal::Setchsymb(char ch)
{
    ch_symb = ch;
}


char Traal::Getchsymb()
{

    return ch_symb;
}



void Traal::Mv(int playery, int playerx,bool check)
{
    int disty = this->GetY() - playery;
    int distx = this->GetX() - playerx;
    int yloc = this->GetY();
    int xloc = this->GetX();

    if(disty<0 && distx<0)
    {
        Mvleft();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvup();
        }

    }

    if(disty<0 && distx>0)
    {
        Mvright();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvup();
        }
    }
    if(disty<0 && distx==0)
    {
        Mvleft();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvdown();
        }
    }

    if(disty==0 && distx<0)
    {
        Mvup();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvleft();
        }
    }
    if(disty>0 && distx<0)
    {
        Mvdown();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvleft();
        }
    }
    if(disty>0 && distx>0)
    {
        Mvright();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvdown();
        }
    }
    if(disty>0 && distx==0)
    {
        Mvright();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvdown();
        }
    }
    if(disty==0 && distx>0)
    {
        Mvup();
        if(check)
        {
            this->SetY(yloc);
            this->SetX(xloc);
            Mvright();
        }
    }

}