#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
public:
    King(PlayerColour colour);
    void generate_candidate_positions() override;
    void update() override;
};

#endif