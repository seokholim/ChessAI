#ifndef KING_H
#define KING_H
#include "piece.h"
#include "board.h"

class Player;

class King : public Piece {
private:

public:
    King(PlayerColour player_colour);
    King(Player* owner); // position and board to be set
    King(Player* owner, Position position, Board* board);
    void calculate_moves() override;
    void update() override;
};

#endif