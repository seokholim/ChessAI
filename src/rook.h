#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include "board.h"

class Player;

class Rook : public Piece {

public:
    Rook(PlayerColour player_colour);
    Rook(Player* owner); // position and board to be set
    Rook(Player* owner, Position position, Board* board);
    void calculate_moves() override;
    void update() override;
};

#endif