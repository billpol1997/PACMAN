#include "Engine.h"
using namespace std;

Engine::Engine(string filename,Player bibis,Gnome monster1,Traal monster2,ScoreBoard scoreboard):bibis(bibis), monster1(monster1),monster2(monster2),scoreBoard(scoreboard)
{
  CreateWindow();
  LoadMap(filename);

  GemSpawn();
  Spawn();
  while(running)
  {
      refresh();
      wrefresh(playwin);
      getch();

      Update();


  }







    getch();
    endwin();
}



void Engine::CreateWindow()
{
    initscr();
    cbreak();
    noecho();
    curs_set(false);
    keypad(stdscr,true);
    getmaxyx(stdscr,winh,winw);
    playwin = newwin(col+10,rows+10,0,0);

    refresh();
    wrefresh(playwin);
    getch();







}



void Engine::LoadMap(string filename) //initialize map
{

    ifstream file(filename);
    char l;
    int i=0;
    int j=0;


    try
    {

        if(file.is_open())
        {
            while(file>>l)
            {
                Map[i][j] =l;
                i++;
                j++;


            }
        }
        file.close();
    }
    catch(ifstream::failure e)
    {

        printw("Error\n");
    }
    col=i;
    rows=j;




    for(i=0;i<col;i++)
    {
        for(j=0;j<rows;j++)
        {
            wprintw(playwin,(const char *)Map[i][j]);
        }
    }




}


int  Engine::RandomPos(int *randij) //finds random positions
{

    do
    {
        randij[0] = rand() %col;
        randij[1] = rand() %rows;
    }while(Map[randij[0]][randij[1]] == '*' && Map[randij[0]][randij[1]] == '@');

   return *randij;
}


void Engine::GemSpawn() //initialize pos for gems
{
    int *randij;
    int i;

    for(i=0;i<10;i++)
    {
        RandomPos(randij);
        mvwaddch(playwin,randij[0],randij[1],'@');

    }



}





void Engine::Spawn() //initialize pos for objects
{
     int *randij;


    RandomPos(randij);

   bibis.SetY(randij[0]);
   bibis.SetX(randij[1]);
   mvwaddch(playwin,randij[0],randij[1],bibis.Getchsymb());



    RandomPos(randij);
    if(randij[0] == bibis.GetY() && randij[1] == bibis.GetX())
    {
        RandomPos(randij);
    }

    monster1.SetY(randij[0]);
    monster1.SetX(randij[1]);
    mvwaddch(playwin,randij[0],randij[1],monster1.Getchsymb());



    RandomPos(randij);


    if(randij[0] == bibis.GetY() && randij[1] ==bibis.GetX() || randij[0] == monster1.GetY() && randij[1] == monster1.GetX())
    {
        RandomPos(randij);
    }


    monster2.SetY(randij[0]);
    monster2.SetX(randij[1]);
    mvwaddch(playwin,randij[0],randij[1],monster2.Getchsymb());






}





int Engine::Takechoice() //takes input from user
{

    int chc = wgetch(playwin);

    return chc;
}




void Engine::Step(int y, int x) //print space character in previous pos
{
    mvwaddch(playwin,y,x,' ');
}


void Engine::Esc() //if user press esc
{

    wprintw(playwin,"Goodbye");

    running = false;
    getch();
    endwin();
}



void Engine::Display(int y, int x,char c)
{
    mvaddch(y,x,c);
}




bool Engine::WallCheck(int yloc, int xloc) //checks for collision with wall
{
    if(Map[bibis.GetY()][bibis.GetX()] == '*')
    {
        bibis.SetY(yloc);
        bibis.SetX(xloc);

        return true;
    }


    return false;
}


bool Engine::WallMon1Check(int y, int x)
{
    if(Map[y][x] == '*'|| Map[y][x] == '@'|| Map[y][x] != Map[monster2.GetY()][monster2.GetX()])
    {
        return true;
    }

    return false;
}

bool Engine::WallMon2Check(int y, int x)
{
    if(Map[y][x] == '*'|| Map[y][x] == '@'|| Map[y][x] != Map[monster1.GetY()][monster1.GetX()])
    {
        return true;
    }

    return false;
}


void Engine::Playmove()
{
    int choice = Takechoice();

    if (choice == KEY_EXIT)
    {
        Esc();
    } else if (choice != (int) ' ')
    {

        Step(bibis.GetY(), bibis.GetX());

        bibis.Getmv(choice);

    } else
    {
        bibis.Getmv(choice);

    }

}


void Engine::ColCheck() //checks if any of the monsters,gems or parchment and the player collide
{
    if(Map[bibis.GetY()][bibis.GetX()] == '@')
    {
        Display(bibis.GetY(),bibis.GetX(),bibis.Getchsymb());


    }




    if(bibis.GetY() == monster1.GetY() && bibis.GetY() == monster1.GetX())
    {
        wprintw(playwin,"You Lost");

        running = false;
        getch();
        endwin();
    }
    if(bibis.GetY() == monster2.GetY() && bibis.GetY() == monster2.GetX())
    {
        wprintw(playwin,"You Lost");

        running = false;
        getch();
        endwin();
    }


}



void Engine::Update() //updating map and objects
{
    int tmpy; // temporary lock positions for wall check
    int tmpx;
    bool wall;
    bool check= true;

    tmpy = bibis.GetY();
    tmpx = bibis.GetX();

    Playmove();

    wall = WallCheck(tmpy, tmpx);

    while(wall)
    {
        Playmove();
        tmpy = bibis.GetY();
        tmpx = bibis.GetX();
        wall = WallCheck(tmpy, tmpx);
    }

    Display(bibis.GetY(), bibis.GetX(), bibis.Getchsymb());

    while(check)
    {
        monster1.Mv(bibis.GetY(), bibis.GetX(),check);
        check = WallMon1Check(monster1.GetY(),monster1.GetX());

    }

    check= true;

    while(check)
    {
        monster2.Mv(bibis.GetY(), bibis.GetX(),check);
        check = WallMon2Check(monster2.GetY(),monster2.GetX());

    }


    Display(monster1.GetY(),monster1.GetX(), monster1.Getchsymb());
    Display(monster2.GetY(),monster2.GetX(), monster2.Getchsymb());

    ColCheck();

















  refresh();
  wrefresh(playwin);
  getch();






}


