#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include "subject.h"
#include "info.h"
#include "move.h"
#include "player.h"

class Piece : public Subject, public Observer {
  protected:
    PieceType piece_type;
    Player* owner;
    Position position;
    Board* board;
    std::vector<Move*> moves;

  public:
    PieceType get_piece_type();
    Position get_position();    
    std::vector<Move*> get_moves();
    char print();
};

#endif