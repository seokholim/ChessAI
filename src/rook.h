#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include "board.h"

class Rook : public Piece {

public:
    Rook(Player* owner); // position and board to be set
    Rook(Player* owner, Position position, Board* board);
    void update(Subject &by) override;
};

#endif