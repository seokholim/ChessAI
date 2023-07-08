#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {

public:
    Pawn(PlayerColour colour);
    bool advanced_three_ranks();
    void generate_candidate_positions() override;
    void update() override;
};

#endif