#ifndef PACMAN_ENGINE_H
#define PACMAN_ENGINE_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include "Moving.h"
#include "Player.h"
#include "Gnome.h"
#include "Traal.h"
#include "HighScore.h"
#include "ScoreBoard.h"

using namespace std;
class Engine
{
private:
    int col,rows;
    int winh,winw;
    bool running = true;

public:
    char Map[100][100];
    WINDOW * playwin;
    Player bibis;
    Gnome monster1;
    Traal monster2;
    ScoreBoard scoreBoard;



    Engine(string filename,Player bibis,Gnome monster1,Traal monster2,ScoreBoard scoreboard);


    void CreateWindow();

    void LoadMap(string filename);

    int RandomPos(int *randij);

    void GemSpawn();

    void Spawn();

    int Takechoice();

    void Step(int y, int x);

    void Esc();

    void Display(int y, int x,char c);

    bool WallCheck(int yloc, int xloc);

    bool WallMon1Check(int y, int x);

    bool WallMon2Check(int y, int x);

    void ColCheck();

    void Playmove();

    void Update();






};
#endif
