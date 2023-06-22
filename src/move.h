#ifndef MOVE_H
#define MOVE_H
#include "info.h"

class Piece;

class Move {
    Position move_from;
    Position move_to;
    Piece* moving_piece;
    Piece* captured_piece;
    int value;
  public:
    Move(Position move_from, Position move_to, Piece* moving_piece, Piece* captured_piece);
    Position get_move_from();
    Position get_move_to();
    
    void set_captured(Piece* captured_piece);
    Piece* get_captured();

    void set_value(int value);
    int get_value();
};

class CompareMove {
  public:
    bool operator() (Move* m1, Move* m2) {
        return m1->get_value() < m2->get_value();
    }
};

#endif