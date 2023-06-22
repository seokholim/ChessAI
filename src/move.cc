#include "move.h"

Move::Move(Position move_from, Position move_to, Piece* moving_piece, Piece* captured_piece) 
    : move_from{move_from}, move_to{move_to}, moving_piece{moving_piece}, captured_piece{captured_piece}, value{0} {}

Position Move::get_move_from() {
    return move_from;
}

Position Move::get_move_to() {
    return move_to;
}

void Move::set_captured(Piece* captured_piece) {
    this->captured_piece = captured_piece;
}

Piece* Move::get_captured() {
    return captured_piece;
}

void Move::set_value(int value) {
    this->value = value;
}

int Move::get_value() {
    return value;
}