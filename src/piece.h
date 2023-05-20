#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "subject.h"
#include "position.h"

class Piece : public Subject, public Observer {
    Position p;
    std::vector<Position> moves;

  public:
    virtual char print();
    virtual Position get_position();
    virtual Position get_move(); 
};

#endif