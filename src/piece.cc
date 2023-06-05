#include "piece.h"

PieceType Piece::get_piece_type() {
    return this->piece_type;
}

Position Piece::get_position() {
    return this->position;
}

std::vector<Move*> Piece::get_moves() {
    return this->moves;
}

char Piece::print() {
    return convert_to_char(this->piece_type);
}