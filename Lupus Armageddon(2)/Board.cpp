/*
Lupus Armageddon, A UCI Chess Engine, created by Sebastiano Rebonato-Scott, 2019
*/

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| Useful to remember - BITWISE OPERATORS (binary):
| & (bitwise AND) Takes two numbers as operands and does AND on every bit of two numbers.
| The result of AND is 1 only if both bits are 1.
| | (bitwise OR) Takes two numbers as operands and does OR on every bit of two numbers.
| The result of OR is 1 if any of the two bits is 1.
| ^ (bitwise XOR) Takes two numbers as operands and does XOR on every bit of two numbers.
| The result of XOR is 1 if the two bits are different.
| << (left shift) Takes two numbers, left shifts the bits of the first operand,
| the second operand decides the number of places to shift.
| >> (right shift) Takes two numbers, right shifts the bits of the first operand,
| the second operand decides the number of places to shift.
| ~ (bitwise NOT) Takes one number and inverts all bits of it
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//Pseudo-Legal move generation is much faster because pins are very tricky.

#include <iostream>
using namespace std;

#include "defs.h"

class BoardRep {
    public:

        int SIDE = 0; // 0 is white, 1 is black

void InitialBoard(){
    int fiftyMove = 0; // fifty move rule
    int Castling[4] = { 1 , 1 , 1 , 1}; // White Kingside, White Queenside, Black Kingside, Black Queenside
    int EnPassent = 0; // En passent squares
    int Repetition = 0; // repetition
    int HisPly = 0; // the number of moves played
    int Check = 0;
    int GameStage = 0;
}
//----------------------------------------
//Generate the bitboard for every piece
//----------------------------------------
//----------------------------------------
// Prefix "0x" means it's hexadecimal
// which we will need for hash
//----------------------------------------
void GenBitBoards(){
    U64 whitePawns = 0xFF00;
    U64 whiteKnights = 0x102;
    U64 whiteBishops = 0x84;
    U64 whiteRooks = 0x81;
    U64 whiteQueens = 0x10;
    U64 whiteKing = 0x8;
//111111111111111100000000000000000000000000000000000000000000000 sixty-four zeros
    U64 blackPawns = 0xFF000000000000;
    U64 blackKnights = 0x4080000000000000;
    U64 blackBishops = 0x2100000000000000;
    U64 blackRooks = 0x8040000000000000;
    U64 blackQueens = 0x1000000000000000;
    U64 blackKing = 0x400000000000000;

    //number of white and black pieces
    U64 nWhite = 0xFFFF;
    U64 nBlack = 0x7FFF800000000000;

};

void FilesAndRanks(){
    //bit 0 is a8, bit 63 is h1
    U64 FILE_A = 0x8080808080808000;
    U64 FILE_H = 0x80808101010100;
    //U64 FILE_B = 0x4040404040404000;
    //U64 FILE_G = 0x202020202020200;
    U64 FILES_OTHER = 0xFCFCFCFCFCFD0000;//actually the B- C- D- E- F- and G- FILES
    U64 RANK_1 = 0xFF;
    U64 RANK_8 = 0xFF00000000000000;
};

};







