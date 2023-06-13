#include "board.h"
#include <vector>
#include <iostream>
#include "info.h"

Board::Board() : grid{8} {
    // TODO: test that grid size is fixed to 8 x 8
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row(8);
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{static_cast<char>('a' + j), 1 + i};
            row[j] = cell;
        }
        grid[i] = row;
    }
    print();
}

void Board::set_piece_at(Piece* piece, Position new_pos) {
    if (valid_position(new_pos)) {
        if (piece != nullptr) {
            if (empty_at(new_pos)) {
                piece->set_board(this);
                this->grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
                this->pieces.push_back(piece);
            } else {
                std::cout << "couldn't set the piece, requested position is not empty" << std::endl;
            }
        } else {
            std::cout << "couldn't set the piece, piece is nullptr" << std::endl;
        }
    } else {
        std::cout << "couldn't set the piece, requested position is out of range" << std::endl;
    }
}

Piece* Board::get_piece_at(Position pos) {
    return this->grid[pos.row - 1][pos.column - 'a'].get_piece();
}

std::vector<Piece*> Board::get_pieces() {
    return this->pieces;
}

bool Board::empty_at(Position pos) {
    if (valid_position(pos)) {
        return this->grid[pos.row - 1][pos.column - 'a'].empty();
    }
    return false;
}

void Board::print() {
    std::cout << "--------" << std::endl;
    for (int i = 0; i < 8; ++i) { // row 8-1
        for (int j = 0; j < 8; ++j) { // col a-h
            grid[7 - i][j].print();
        }
        std::cout << std::endl;
    }
    std::cout << "--------" << std::endl;
}