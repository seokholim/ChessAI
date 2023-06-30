#include "chess_board.h"

ChessBoard::ChessBoard(Board* data) : data_{data} {}

ChessBoard::~ChessBoard() {}

bool ChessBoard::empty_on(const Position& pos) const {
    if (data_ == nullptr) {
        return false;
    }
    return data_->empty_on(pos);
}

ChessPiece* ChessBoard::get_piece_on(const Position& pos) const {
    if (data_ == nullptr) {
        return nullptr;
    }
    return data_->get_piece_on(pos);
}

std::vector<ChessPiece*> ChessBoard::get_pieces() const {
    if (data_ == nullptr) {
        return {};
    }
    return data_->get_pieces();
}