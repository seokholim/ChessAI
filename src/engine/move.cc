#include "move.h"

Move::Move(Position move_from, Position move_to, std::shared_ptr<ChessPiece> moving_piece, std::shared_ptr<ChessPiece> occupying_piece) 
    : move_from_{move_from}, move_to_{move_to}, moving_piece_{moving_piece}, occupying_piece_{occupying_piece}, move_type_{MoveType::Unevaluated}, value_{0} {}

Move::~Move() {}

Position Move::move_from() const {
    return move_from_;
}

Position Move::move_to() const {
    return move_to_;
}

std::shared_ptr<ChessPiece> Move::moving_piece() const {
    return moving_piece_;
}

std::shared_ptr<ChessPiece> Move::occupying_piece() const {
    return occupying_piece_;
}

bool Move::occupied() const {
    return occupying_piece_ != nullptr;
}

void Move::move_type(MoveType move_type) {
    move_type_ = move_type;
}

MoveType Move::move_type() const {
    return move_type_;
}

void Move::value(int new_value) {
    value_ = new_value;
}

int Move::value() const {
    return value_;
}