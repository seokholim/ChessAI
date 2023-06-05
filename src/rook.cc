#include "rook.h"

void Rook::update() {
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