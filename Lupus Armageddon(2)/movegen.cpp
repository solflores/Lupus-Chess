#include <iostream>
using namespace std;

#include "defs.h"
#include "Board.cpp"

//from and to
//int SQ_FROM;
//int SQ_TO;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| Also useful:
| NORTH -8
| SOUTH 8
| EAST 1
| WEST -1
| SOUTH EAST 9
| SOUTH WEST 7
| NORTH EAST -7
| NORTH WEST -9
|
| Directions for the knight:
|
| NORTH NORTH WEST -17
| NORTH NORTH EAST -15
| EAST EAST NORTH -6
| EAST EAST SOUTH 10
| SOUTH SOUTH EAST 17
| SOUTH SOUTH WEST 15
| WEST WEST SOUTH  6
| WEST WEST NORTH -10
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//----------------------------------
// Generating Moves and
// Attack Boards
//----------------------------------

class MoveGen {
   public:
       void AttackBoards(U64 whitePawns,
                         U64 whiteKnights,
                         U64 whiteBishops,
                         U64 whiteRooks,
                         U64 whiteQueens,
                         U64 whiteKing,

                         U64 blackPawns,
                         U64 blackKnights,
                         U64 blackBishops,
                         U64 blackRooks,
                         U64 blackQueens,
                         U64 blackKing,

                         U64 nWhite,
                         U64 nBlack,

                         U64 FILE_A,
                         U64 FILE_H,
                         U64 FILES_OTHER
                         )
                         {
                             //White Pieces First
           /*-------------------------------
           | PAWNS: first moves, then attacks
           ---------------------------------*/
           U64 whitePawnMoves = ((whitePawns) << 8) | ((whitePawns) << 16);//1 or 2 squares forwards
           // if they're on the A- or H-FILE, do not shift in the wrong direction.
           U64 A_PAWN = ((whitePawns) & (FILE_A)); //AND the A-file and whitePawns to find the A-PAWN
           U64 A_PAWN_ATTACKS = ((A_PAWN) << 7);

           U64 H_PAWN = ((whitePawns) & (FILE_H));
           U64 H_PAWN_ATTACKS = ((H_PAWN) << 9);

           //then shift the pawns on the other files
           U64 OTHER_PAWNS = ((whitePawns) & (FILES_OTHER));
           U64 OTHER_PAWN_ATTACKS = ((OTHER_PAWNS) << 7) | ((OTHER_PAWNS) << 9);

           // and now put it all together
           U64 whitePawnAttacks = (A_PAWN_ATTACKS) | (H_PAWN_ATTACKS) | (OTHER_PAWN_ATTACKS);

           /*--------------------------------------------------------
           | KNIGHTS (dammit): moves and attacks are the same thing
           ----------------------------------------------------------*/
           //first see if we're on the A- or H-file


           U64 whiteKnightMoves;


           /*--------------------------------------------------------
           | BISHOPS - extend diagonal by 1 until we reach the edge
           | of the board.
           ----------------------------------------------------------*/
           int BISHOP1_SQUARE = 58;
           int BISHOP2_SQUARE = 61;

           /**how to see what rank we're on:
           eg. (BISHOP1_SQUARE = 58) / 8 = 7.25
           IF the answer is not a whole number:
           add 0.5 (so that it then rounds)
           otherwise just return the whole number
           */

           int BISHOP1_RANK_OLD = 1;//what rank are we on - shifting too much makes this increase by 2
           int BISHOP1_RANK_NEW = 1;//what rank is the extension on
           //to see what square (index of the 64-bit string) we are on


           int DIAGONAL_LENGTH = 0;
           //North-West First
          // for(BISHOP1_RANK_NEW - BISHOP1_RANK_OLD < 2;){
            //DIAGONAL_LENGTH++;
           //}


           U64 whiteBishopMoves;

           /*--------------------------------------------------------
           | ROOKS - extend by 1 until we reach edge of board
           ----------------------------------------------------------*/
           U64 whiteRookMoves;

           /*--------------------------------------------------------
           | QUEENS - rooks and bishops combined
           ----------------------------------------------------------*/
           U64 whiteQueenMoves;

           /*--------------------------------------------------------
           | KING
           ----------------------------------------------------------*/
           U64 whiteKingMoves = ((whiteKing) << 8) | ((whiteKing) << 7) | (whiteKing) << 9; //etc.

       };
};
