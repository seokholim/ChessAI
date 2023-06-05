#ifndef CELL_H
#define CELL_H
#include "piece.h"
#include "info.h"

class Cell {
    char column;
    int row;
    Piece* piece;

  public:
    Cell(char column, int row);
    void set_piece(Piece* piece);
    Piece* get_piece();
    bool empty();
    char print_piece();
};

#endif