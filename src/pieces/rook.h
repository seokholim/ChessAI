#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece {
public:
    Rook(PlayerColour colour);
    void generate_candidate_positions() override;
    void update() override;
};

#endif