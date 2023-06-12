#ifndef MOVE_H
#define MOVE_H
#include "info.h"

class Piece;

class Move {
    Position move_from;
    Position move_to;
    Piece* move_piece;
  public:
    Move(Position move_from, Position move_to, Piece* p);
    Position get_move_to();
};

#endif