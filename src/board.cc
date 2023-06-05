#include "board.h"
#include <vector>
#include <iostream>
#include "info.h"

Board::Board() : grid(8) {
    // TODO: test that grid size is fixed to 8 x 8
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row(8);
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{'a' + j, 1 + i};
            row[j] = cell;
        }
        grid[i] = row;
    }
}

Piece* Board::get_piece_at(Position pos) {
    return this->grid[pos.row - 1][pos.column - 'a'].get_piece();
}

void Board::set_piece_at(Piece *p, Position pos) {
    this->grid[pos.row - 1][pos.column - 'a'].set_piece(p);
}

bool Board::empty_at(Position pos) {
    return this->grid[pos.row - 1][pos.column - 'a'].empty();
}


void Board::print() {
    std::cout << "--------" << std::endl;
    for (int i = 0; i < 8; ++i) { // row 1-8
        for (int j = 0; j < 8; ++j) { // col a-h
            grid[i][j].print_piece();
        }
    }
    std::cout << "--------" << std::endl;
}