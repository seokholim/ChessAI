#include "board.h"
#include <vector>
#include <iostream>
#include "info.h"

Board::Board() : grid(8) {
    // TODO: test that grid size is fixed to 8 x 8
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row(8);
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{static_cast<char>('a' + j), 1 + i};
            row[j] = cell;
        }
        grid[i] = row;
    }
}

void Board::set_piece_at(Piece* piece, Position new_pos) {
    if (empty_at(new_pos)) {
        this->grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
        for (auto it = this->pieces.begin(); it != this->pieces.end(); ++it) {
            (*it)->attach(piece);
            piece->attach(*it);
            
        }
        piece->notify();
        this->pieces.push_back(piece);
    } else {
        std::cout << "couldn't set the piece, new pos is not empty" << std::endl;
    }
}

Piece* Board::get_piece_at(Position pos) {
    return this->grid[pos.row - 1][pos.column - 'a'].get_piece();
}

bool Board::empty_at(Position pos) {
    return this->grid[pos.row - 1][pos.column - 'a'].empty();
}

void Board::print() {
    std::cout << "--------" << std::endl;
    for (int i = 0; i < 8; ++i) { // row 1-8
        for (int j = 0; j < 8; ++j) { // col a-h
            grid[i][j].print();
        }
    }
    std::cout << "--------" << std::endl;
}