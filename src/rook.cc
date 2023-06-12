#include "rook.h"

Rook::Rook(Player* owner) : Piece{PieceType::Rook, owner} {}

Rook::Rook(Player* owner, Position position, Board* board) : Piece{PieceType::Rook, owner, position, board} {}

void Rook::update(Subject &by) {
    this->moves.clear();

    // check Forward, Backward, Right, Left

    if (this->owner->get_player_colour() == PlayerColour::White) {
        // Forward
        Position current_position = this->get_position();
        current_position.row += 1;
        while (this->board->empty_at(current_position)) {

        }

        // Backward
        current_position = this->get_position();
        current_position.row -= 1;

    } else {
        
    }
}