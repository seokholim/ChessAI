#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {

public:
    Queen(PlayerColour colour);
    void generate_candidate_positions() override;
    void update() override;
};

#endif