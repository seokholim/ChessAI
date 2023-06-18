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
    print(true);
}

Board::~Board() {
    // for (auto piece : pieces) {
    //     delete piece;
    // }
    // std::cout << "were all pieces deleted?" << std::endl;
}

void Board::create_piece_on(Piece* piece, Position new_pos) {
    if (piece == nullptr) {
        std::cout << "Board::create_piece_on failed; piece is nullptr" << std::endl;
    } else if (!valid_position(new_pos)) {
        std::cout << "Board::create_piece_on failed; new_pos is not valid" << std::endl;
    } else if (!empty_on(new_pos)) {
        std::cout << "Board::create_piece_on failed; new_pos is not empty" << std::endl;
    } else {
        piece->set_board(this);
        this->pieces.push_back(piece);
        this->grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
    }
}

void Board::set_piece_on(Piece* piece, Position new_pos) { // TODO: check if piece is on board
    if (piece == nullptr) {
        std::cout << "Board::set_piece_on failed; piece is nullptr" << std::endl;
    } else if (!valid_position(new_pos)) {
        std::cout << "Board::set_piece_on failed; new_pos is not valid" << std::endl;
    } else if (!empty_on(new_pos)) {
        std::cout << "Board::set_piece_on failed; new_pos is not empty" << std::endl;
    } else {
        this->grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
    }
}

Piece* Board::get_piece_on(Position pos) {
    if (valid_position(pos)) {
        return this->grid[pos.row - 1][pos.column - 'a'].get_piece();
    }
    return nullptr;
}

void Board::remove_piece_on(Position pos) {
    this->grid[pos.row - 1][pos.column - 'a'].remove_piece();
}

void Board::delete_piece_on(Position pos) {
    this->grid[pos.row - 1][pos.column - 'a'].delete_piece();
}

std::vector<Piece*> Board::get_pieces() {
    return this->pieces;
}

void Board::move_piece(Position current_pos, Position new_pos) {
    if (valid_position(current_pos) && valid_position(new_pos)) {
        Piece* moving_piece = this->grid[current_pos.row - 1][current_pos.column - 'a'].get_piece();
        this->grid[current_pos.row - 1][current_pos.column - 'a'].remove_piece();
        this->grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(moving_piece);
    }
}

bool Board::empty_on(Position pos) {
    if (valid_position(pos)) {
        return this->grid[pos.row - 1][pos.column - 'a'].empty();
    }
    return false;
}

void Board::print(bool white_perspective) {
    if (white_perspective) {
        std::cout << " --------" << std::endl;
        for (int i = 0; i < 8; ++i) { // row 8-1
            std::cout << 8 - i;
            for (int j = 0; j < 8; ++j) { // col a-h
                grid[7 - i][j].print();
            }
            std::cout << std::endl;
            }
        std::cout << " abcdefgh" << std::endl;
        std::cout << "=========" << std::endl;
    } else {
        std::cout << " --------" << std::endl;
        for (int i = 0; i < 8; ++i) { // row 1-8
            std::cout << i + 1;
            for (int j = 0; j < 8; ++j) { // col h-a
                grid[i][7 - j].print();
            }
            std::cout << std::endl;
        }
        std::cout << " hgfedcba" << std::endl;
        std::cout << "=========" << std::endl;
    }
}