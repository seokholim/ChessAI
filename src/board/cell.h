#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "../utility/info.h"

class ChessPiece;

class Cell {
public:
    Cell();
    Cell(char column, int row);

    std::shared_ptr<ChessPiece> get_piece() const;
    bool empty() const;

    void set_piece(const std::shared_ptr<ChessPiece>& piece);
    void remove_piece();
    void delete_piece();
private:
    char column;
    int row;
    std::shared_ptr<ChessPiece> piece;
};

#endif