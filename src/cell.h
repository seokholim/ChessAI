#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "info.h"

class Piece;

class Cell {
    char column;
    int row;
    Piece* piece;

  public:
    Cell();
    Cell(char column, int row);

    void set_piece(Piece* piece);
    Piece* get_piece();
    
    void remove_piece();
    void delete_piece();

    bool empty();
};

#endif