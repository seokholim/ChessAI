#include "board.h"

Board::Board() : grid_{8}, pieces_{} {
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row;
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{static_cast<char>('a' + j), 1 + i};
            row.push_back(cell); // TODO: cell assignment operator
        }
        grid_[i] = row;
    }
}

Board::~Board() {}

void Board::create_piece_on(ChessPiece* piece, Position new_pos) { // piece is in pieces_
    if (piece == nullptr) {
        std::cout << "Board::create_piece_on; piece is nullptr" << std::endl;
        return;
    } else if (!valid_position(new_pos)) {
        std::cout << "Board::create_piece_on; new_pos is not valid" << std::endl;
        return;
    } else if (!empty_on(new_pos)) {
        std::cout << "Board::create_piece_on; new_pos is not empty" << std::endl;
        return;
    }
    pieces_.push_back(piece);
    grid_[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
}

void Board::set_piece_on(ChessPiece* piece, Position new_pos) { // Note:
    if (piece == nullptr) {
        std::cout << "Board::set_piece_on; piece is nullptr" << std::endl;
        return;
    } else if (!valid_position(new_pos)) {
        std::cout << "Board::set_piece_on; new_pos is not valid" << std::endl;
        return;
    } else if (!empty_on(new_pos)) {
        std::cout << "Board::set_piece_on; new_pos is not empty" << std::endl;
        return;
    }
    grid_[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
}

ChessPiece* Board::get_piece_on(Position pos) const {
    if (!valid_position(pos)) {
        return nullptr;
    }
    return grid_[pos.row - 1][pos.column - 'a'].get_piece();
}

void Board::remove_piece_on(Position pos) {
    if (!valid_position(pos)) {
        return;
    }
    grid_[pos.row - 1][pos.column - 'a'].remove_piece();
}

void Board::delete_piece_on(Position pos) { // TODO: Cell::delete_piece() is not implemented
    if (!valid_position(pos)) {
        return;
    }
    grid_[pos.row - 1][pos.column - 'a'].delete_piece();
}

std::vector<ChessPiece*> Board::get_pieces() const {
    return pieces_;
}

void Board::move(Position current_pos, Position new_pos) {
    if (!valid_position(current_pos) || !valid_position(new_pos)) {
        return;
    }
    ChessPiece* moving_piece = grid_[current_pos.row - 1][current_pos.column - 'a'].get_piece();
    grid_[current_pos.row - 1][current_pos.column - 'a'].remove_piece();
    grid_[new_pos.row - 1][new_pos.column - 'a'].set_piece(moving_piece);
}

bool Board::empty_on(Position pos) const {
    if (!valid_position(pos)) {
        return false;
    }
    return grid_[pos.row - 1][pos.column - 'a'].empty();
}