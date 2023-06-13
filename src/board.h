#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "cell.h"
#include "piece.h"

class Board {
    std::vector<std::vector<Cell> > grid; // 8 x 8
    std::vector<Piece*> pieces;
  public:
    Board();
    void set_piece_at(Piece* piece, Position pos);
    Piece* get_piece_at(Position pos);
    std::vector<Piece*> get_pieces();
    bool empty_at(Position pos);
    void print();
};

#endif