#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H
#include "board.h"
#include "move.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

class ChessEngine {
    Board* board;

public:
    ChessEngine(Board* board);
    void evaluate_move(Move* move, int level);
    bool king_checked(Move* move);
};


#endif