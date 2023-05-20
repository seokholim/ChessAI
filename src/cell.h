#ifndef CELL_H
#define CELL_H
#include "piece.h"

class Cell {
    int row;
    char column;
    Piece *p;

  public:
    Cell(int r, char c);
    char print_piece();
};

#endif