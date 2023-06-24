#include "board.h"

Board::Board() : grid{8}, pieces{} {
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row(8);
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{static_cast<char>('a' + j), 1 + i};
            row[j] = cell;
        }
        grid[i] = row;
    }
}

Board::~Board() {}

void Board::create_piece_on(Piece* piece, Position new_pos) {
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
    pieces.push_back(piece);
    grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
}

void Board::set_piece_on(Piece* piece, Position new_pos) { // Note: piece is in Board::pieces
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
    grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(piece);
}

Piece* Board::get_piece_on(Position pos) {
    if (!valid_position(pos)) {
        return nullptr;
    }
    return grid[pos.row - 1][pos.column - 'a'].get_piece();
}

void Board::remove_piece_on(Position pos) {
    if (!valid_position(pos)) {
        return;
    }
    grid[pos.row - 1][pos.column - 'a'].remove_piece();
}

void Board::delete_piece_on(Position pos) { // TODO: Cell::delete_piece() is not implemented
    if (!valid_position(pos)) {
        return;
    }
    grid[pos.row - 1][pos.column - 'a'].delete_piece();
}

std::vector<Piece*> Board::get_pieces() {
    return pieces;
}

void Board::move_piece(Position current_pos, Position new_pos) {
    if (!valid_position(current_pos) || !valid_position(new_pos)) {
        return;
    }
    Piece* moving_piece = grid[current_pos.row - 1][current_pos.column - 'a'].get_piece();
    grid[current_pos.row - 1][current_pos.column - 'a'].remove_piece();
    grid[new_pos.row - 1][new_pos.column - 'a'].set_piece(moving_piece);
}

bool Board::empty_on(Position pos) {
    if (!valid_position(pos)) {
        return false;
    }
    return grid[pos.row - 1][pos.column - 'a'].empty();
}