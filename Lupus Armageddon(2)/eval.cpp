/*
Lupus ARMAGEDDON, A UCI Chess Engine by Sebastiano Rebonato-Scott, 2019
*/

#include <iostream>
using namespace std;

#include "Board.cpp"
#include "defs.h"

int drawscore = 0;
int score = 0;
int GameStage = 0; // 0 is Opening, 1 is early middlegame, 2 is lte middlegame, 3 is endgame
int QUEEN = 1000;
int ROOK = 550;
int BISHOP = 360;
int KNIGHT = 320;
int PAWN = 100;

int evaluate(int score){
    return score;
};
