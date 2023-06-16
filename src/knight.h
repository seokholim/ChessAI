#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include "board.h"

class Player;

class Knight : public Piece {
private:

public:
    Knight(PlayerColour player_colour);
    Knight(Player* owner); // position and board to be set
    Knight(Player* owner, Position position, Board* board);
    void calculate_moves() override;
    void update() override;
};

#endif