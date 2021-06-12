

#ifndef PACMAN_HIGHSCORE_H
#define PACMAN_HIGHSCORE_H
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
class HighScore {
private:
    char Name[10];
    int Score;

public:

    HighScore() = default;
    HighScore(char *name,int score);

    void SetName(const char *name);
    void SetScore(int sc);


    char GetName() const;
    int GetScore() const;






};


#endif
