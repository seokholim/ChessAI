#include "pawn.h"
#include <iostream>

Pawn::Pawn(PlayerColour player_colour) : Piece{PieceType::Pawn, player_colour}, first_move{true} {}

void Pawn::calculate_moves() { // TODO: only double forward and foward
    this->moves.clear(); // TODO: improve by not always clearing out moves

    if (this->player_colour == PlayerColour::White) {
        // Double Forward
        if (first_move) {
            Position current_position = get_position();
            current_position.row += 2;
            if (this->board->empty_at(current_position)) {
                Move* new_move = new Move{this->position, current_position, this};
                this->moves.push_back(new_move);
            }
            first_move = false;
        }

        // Forward
        Position current_position = get_position();
        current_position.row += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Forward Right Capture
        current_position = get_position();
        current_position.row += 1;
        current_position.column += 1;
        // if (this->board->empty_at(current_position)) {
        //     Move* new_move = new Move{this->position, current_position, this};
        //     this->moves.push_back(new_move);
        // }

    } else {
        // Double Forward
        if (first_move) {
            Position current_position = get_position();
            current_position.row -= 2;
            if (this->board->empty_at(current_position)) {
                Move* new_move = new Move{this->position, current_position, this};
                this->moves.push_back(new_move);
            }
            first_move = false;
        }

        // Forward
        Position current_position = get_position();
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    }
}

void Pawn::update() {
    calculate_moves();
}