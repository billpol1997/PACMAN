

#include "HighScore.h"
using namespace std;


HighScore::HighScore(char *name, int score)
{
   this->Name[10] = *name;
   this->Score = score;
}


HighScore::~HighScore()
{

}




void HighScore::SetName(const char *name)
{
    *Name = *name;
}

void HighScore::SetScore(int sc)
{
    Score = sc;
}



char HighScore::GetName() const
{
    return *Name;
}

int HighScore::GetScore()  const
{
    return Score;
}








