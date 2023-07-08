#include "board.h"

Board::Board() : grid_{8}, pieces_{} {
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row{8};
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{static_cast<char>('a' + j), 1 + i};
            row[j] = cell; // TODO: cell assignment operator
        }
        grid_[i] = row;
    }
    // std:: cout << "Board::Board()" << std::endl; 
}

Board::~Board() { 
    // std:: cout << "Board::~Board() " << std::endl; 
}

void Board::create_piece_on(std::shared_ptr<ChessPiece>& piece, Position pos) {
    if (piece == nullptr) {
        std::cout << "Board::create_piece_on; piece is nullptr" << std::endl;
        return;
    } else if (!valid_position(pos)) {
        std::cout << "Board::create_piece_on; pos is not valid" << std::endl;
        return;
    } else if (!empty_on(pos)) {
        std::cout << "Board::create_piece_on; pos is not empty at " << pos.column << pos.row << std::endl;
        return;
    }
    pieces_.push_back(piece);
    grid_[pos.row - 1][pos.column - 'a'].set_piece(piece);
}

void Board::set_piece_on(std::shared_ptr<ChessPiece>& piece, Position pos) { // Note:
    if (piece == nullptr) {
        std::cout << "Board::set_piece_on; piece is nullptr" << std::endl;
        return;
    } else if (!valid_position(pos)) {
        std::cout << "Board::set_piece_on; pos is not valid" << std::endl;
        return;
    } else if (!empty_on(pos)) {
        std::cout << "Board::set_piece_on; pos is not empty" << std::endl;
        return;
    }
    grid_[pos.row - 1][pos.column - 'a'].set_piece(piece);
}

std::shared_ptr<ChessPiece> Board::get_piece_on(Position pos) const {
    if (!valid_position(pos)) {
        return nullptr;
    }
    return grid_[pos.row - 1][pos.column - 'a'].get_piece();
}

void Board::remove_piece(std::shared_ptr<ChessPiece> piece) {
    auto it = std::find(pieces_.begin(), pieces_.end(), piece);
    if (it == pieces_.end()) {
        std::cout << "Board::remove_piece(...); pieces_ doesn't contain the piece!" << std::endl;
        return;
    }
    pieces_.erase(it);
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

std::vector<std::shared_ptr<ChessPiece>> Board::get_pieces() const {
    return pieces_;
}

void Board::move(Position from, Position to) {
    if (!valid_position(from) || !valid_position(to)) {
        return;
    }
    std::shared_ptr<ChessPiece> moving_piece = grid_[from.row - 1][from.column - 'a'].get_piece();
    grid_[from.row - 1][from.column - 'a'].remove_piece();
    if (!grid_[to.row - 1][to.column - 'a'].empty()) {
        remove_piece(grid_[to.row - 1][to.column - 'a'].get_piece());
    }
    grid_[to.row - 1][to.column - 'a'].set_piece(moving_piece);
}

bool Board::empty_on(Position pos) const {
    if (!valid_position(pos)) {
        return false;
    }
    return grid_[pos.row - 1][pos.column - 'a'].empty();
}

void Board::empty_board() {
    for (int i = 0; i < grid_.size(); ++i) {
        for (int j = 0; j < grid_[i].size(); ++j) {
            grid_[i][j].remove_piece();
        }
    }
}