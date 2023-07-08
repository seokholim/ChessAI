#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "info.h"

class ChessPiece;

class Cell {
    char column;
    int row;
    std::shared_ptr<ChessPiece> piece;

public:
    Cell();
    Cell(char column, int row);

    std::shared_ptr<ChessPiece> get_piece() const;
    bool empty() const;

    void set_piece(const std::shared_ptr<ChessPiece>& piece);
    void remove_piece();
    void delete_piece();

};

#endif