#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "board.h"

class Player;

class Pawn : public Piece {
private:
    bool first_move;
    Position original_position;

public:
    Pawn(PlayerColour player_colour);
    Pawn(Player* owner); // position and board to be set
    Pawn(Player* owner, Position position, Board* board);
    void calculate_moves() override;
    void update() override;
};

#endif