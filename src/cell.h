#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "info.h"

class ChessPiece;

class Cell {
    const char column;
    const int row;
    ChessPiece* piece;

public:
    Cell();
    Cell(char column, int row);

    ChessPiece* get_piece() const;
    bool empty() const;

    void set_piece(ChessPiece* piece);
    void remove_piece();
    void delete_piece();

};

#endif