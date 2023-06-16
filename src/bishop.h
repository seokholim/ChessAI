#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include "board.h"

class Player;

class Bishop : public Piece {
private:

public:
    Bishop(PlayerColour player_colour);
    Bishop(Player* owner); // position and board to be set
    Bishop(Player* owner, Position position, Board* board);
    void calculate_moves() override;
    void update() override;
};

#endif