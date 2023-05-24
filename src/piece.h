#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include "subject.h"
#include "info.h"
#include "move.h"
#include "player.h"

class Piece : public Subject, public Observer {
  protected:
    PieceType pieceType;
    Player *owner;
    Position p;
    std::vector<Move*> moves;

  public:
    PieceType get_piece_type();
    virtual char print();
    virtual Position get_position();
    virtual Position get_move();
};

#endif