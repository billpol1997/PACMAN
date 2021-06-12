#ifndef PACMAN_SCOREBOARD_H
#define PACMAN_SCOREBOARD_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "HighScore.h"

using namespace std;

class ScoreBoard {

public:

    array<HighScore,5>Board;


    HighScore& operator [](int idx);

    ScoreBoard();



    void LoadScoreBoard(const string &bfilename);
    void WriteScore(const string &bfilename);
    void ScoreBoardSort();
};


#endif
