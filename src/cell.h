#ifndef CELL_H
#define CELL_H
#include "piece.h"
#include "info.h"

class Cell {
    int row;
    char column;
    Piece* p;

  public:
    Cell(int r, char c);
    PieceType get_piece_type();
    char print_piece();
};

#endif