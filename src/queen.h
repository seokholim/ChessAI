#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include "board.h"

class Player;

class Queen : public Piece {
private:
    bool first_move;

public:
    Queen(PlayerColour player_colour);
    Queen(Player* owner); // position and board to be set
    Queen(Player* owner, Position position, Board* board);
    void calculate_moves() override;
    void update() override;
};

#endif