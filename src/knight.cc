#include "knight.h"

Knight::Knight(PlayerColour player_colour) : Piece{PieceType::Knight, player_colour} {}

void Knight::calculate_moves() { // TODO: can't move
    this->moves.clear();

}

void Knight::update() {
    calculate_moves();
}