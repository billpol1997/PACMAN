#include "ScoreBoard.h"

using namespace std;
string* Split(const string &str, char delim) //splits string in 2
{
    string tokens[2];
    size_t prev = 0,pos=0;
    int count=0;
    do {
        pos = str.find(delim,prev);
        if(pos == string::npos) pos = str.length();
        string token = str.substr(prev,pos-prev);
        if(!token.empty()) tokens[count]=token;
        prev = pos + 1;
        count++;
    } while (pos<str.length() && prev<str.length());





    return tokens;

}
HighScore & ScoreBoard::operator[](int idx) //for easier use of object array
{
    return Board[idx];
}



ScoreBoard::ScoreBoard()
{
    Board ={HighScore(" ",0), //default board
            HighScore(" ",0),
            HighScore(" ",0),
            HighScore(" ",0),
            HighScore(" ",0)};



}


ScoreBoard::~ScoreBoard()
{

}




void ScoreBoard::LoadScoreBoard(const string &bfilename) //reads from file
{
    string brd[5];

    ifstream rf(bfilename,ios::out | ios::binary);
    if(!rf)
    {
        cout<<"Error opening file!"<<endl;
        exit(1);
    }

    int i;
    for(int i=0;i<5;i++)
    {
        rf.read((char *)&brd[i],5);
    }
    rf.close();
    if(!rf.good())
    {
        cout<<"Error reading file"<<endl;
        exit(1);
    }

    for(int i=0;i<5;i++)
    {
        string *content;
        content = Split(brd[i],' ');
        Board[i].SetName(content[0].c_str());
        Board[i].SetScore(atoi(content[1].c_str()));


    }
}


void ScoreBoard::WriteScore(const string &bfilename) //writes to file
{
    string brd[5];
    for(int i=0;i<5;i++)
    {
        brd[i] = Board[i].GetName() + (to_string(Board[i].GetScore()));
    }
    ofstream wf(bfilename, ios::out | ios::binary);
    if(!wf)
    {
        cout<<"Error opening file!"<<endl;
        exit(1);
    }
    int i;
    for(i=0;i<5;i++)
    {
        wf.write((char *)&brd[i],5);
    }
    wf.close();
    if(!wf.good())
    {
        cout<<"Error writing file"<<endl;
        exit(1);
    }

}




void ScoreBoard::ScoreBoardSort() //sorting board
{
    sort(Board.begin(),Board.end(),[](const HighScore &h1,const HighScore &h2){
        return h1.GetScore()>h2.GetScore();
    });

}



