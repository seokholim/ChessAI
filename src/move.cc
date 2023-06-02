#include "move.h"

Move::Move(Position move_from, Position move_to, Piece* move_piece) : move_from{move_from}, move_to{move_to}, move_piece{move_piece} {}

Position Move::get_move_to() {
    return this->move_to;
}