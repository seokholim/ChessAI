#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece {
public:
    Knight(PlayerColour colour);
    void generate_candidate_positions() override;
    void update() override;
};

#endif