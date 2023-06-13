#ifndef CELL_H
#define CELL_H
#include "piece.h"

class Cell {
    char column;
    int row;
    Piece* piece;

  public:
    Cell();
    Cell(char column, int row);
    void set_piece(Piece* piece);
    Piece* get_piece();
    bool empty();
    void print();
};

#endif