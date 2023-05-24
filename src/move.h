#ifndef MOVE_H
#define MOVE_H
#include "info.h"
#include "piece.h"

class Move {
    int turn;
    Position prev;
    Position next;
    Piece *p;
  public:
    Move(int turn, Position prev, Position next, Piece *p);
    
};

#endif