#include "move.h"

Move::Move(Position move_from, Position move_to, std::shared_ptr<Piece> moving_piece, std::shared_ptr<Piece> occupying_piece) 
    : move_from_{move_from}, move_to_{move_to}, moving_piece_{moving_piece}, occupying_piece_{occupying_piece}, move_type_{MoveType::Unevaluated}, value_{} {}

Move::~Move() {}

Position Move::move_from() const {
    return move_from_;
}

Position Move::move_to() const {
    return move_to_;
}

std::shared_ptr<Piece> Move::moving_piece() const {
    return moving_piece_;
}

std::shared_ptr<Piece> Move::occupying_piece() const {
    return occupying_piece_;
}

MoveType Move::move_type() const {
    return move_type_;
}

int Move::value() const {
    return value_;
}