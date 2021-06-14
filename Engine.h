#ifndef PACMAN_ENGINE_H
#define PACMAN_ENGINE_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <algorithm>
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
    int col,rows; //columns and rows of map
    int winh,winw; // dimensions of console in case they're needed
    bool running = true; //for starting and ending the game

public:
    char Map[100][100]; //game map
    WINDOW * playwin;
    Player bibis;
    Gnome monster1;
    Traal monster2;
    HighScore *tmpscore;
    ScoreBoard scoreboard;



    Engine(string filename,string bfilename,Player bibis,Gnome monster1,Traal monster2,ScoreBoard scoreboard);


    void CreateWindow();

    void InitTempscore();

    void LoadMap(string filename);

    int RandomPos(int *randij);

    void GemSpawn();

    void ParchmentSpawn();

    void Spawn();

    int Takechoice();

    void Step(int y, int x);

    void Esc();

    void Display(int y, int x,char c);

    bool WallCheck(int yloc, int xloc);

    bool WallMon1Check(int y, int x);

    bool WallMon2Check(int y, int x);

    void LostGame();

    void ColCheck();

    void Playmove();

    void TempScore_to_ScoreBoard();

    void DisplayScore();

    void WinGame();

    void Update();

    void StartGame();

    void EndGame();








};
#endif
