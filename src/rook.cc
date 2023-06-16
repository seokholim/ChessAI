#include "rook.h"
#include <iostream>

Rook::Rook(PlayerColour player_colour) : Piece{PieceType::Rook, player_colour} {}

void Rook::calculate_moves() {
    this->moves.clear(); // TODO: improve by not always clearing out moves

    if (this->player_colour == PlayerColour::White) {
        // Forward
        Position current_position = this->get_position();
        current_position.row += 1;
        while (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
            current_position.row += 1;
        }

        // Backward
        current_position = this->position;
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        
        // Right
        current_position = this->position;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Left
        current_position = this->position;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    } else {
        // Forward
        Position current_position = this->position;
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Backward
        current_position = this->position;
        current_position.row += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        
        // Right
        current_position = this->position;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Left
        current_position = this->position;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    }
}

void Rook::update() {
    calculate_moves();
}