#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece {

public:
    Bishop(PlayerColour colour);
    void generate_candidate_positions() override;
    void update() override;
};

#endif