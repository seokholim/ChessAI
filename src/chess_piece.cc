#include "chess_piece.h"

ChessPiece::ChessPiece(std::shared_ptr<Piece> data) : data_{data} {}

ChessPiece::~ChessPiece() {}

PieceType ChessPiece::type() const {
    if (data_ == nullptr) {
        return PieceType::Null;
    }
    return data_->type();
}

PlayerColour ChessPiece::colour() const {
    if (data_ == nullptr) {
        return PlayerColour::Null;
    }
    return data_->colour();
}

bool ChessPiece::white() const {
    if (data_ == nullptr) {
        return false;
    }
    return data_->white();
}

bool ChessPiece::black() const {
    if (data_ == nullptr) {
        return false;
    }
    return data_->black();
}

Position ChessPiece::position() const {
    if (data_ == nullptr) {
        return Position {};
    }
    return data_->position();
}

bool ChessPiece::in_range(const std::shared_ptr<ChessPiece> other) const { // TODO
    return false;
}

bool ChessPiece::first_move() const {
    if (data_ == nullptr) {
        return false;
    }
    return data_->first_move();
}

std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> ChessPiece::moves() const {
    if (data_ == nullptr) {
        return {};
    }
    return data_->moves();
}

std::shared_ptr<Move> ChessPiece::best_move() const {
    if (data_ == nullptr) {
        return nullptr;
    }
    return data_->best_move();
}

void ChessPiece::print() const {
    if (data_ == nullptr) {
        return;
    }
    return data_->print();
}