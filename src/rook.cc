#include "rook.h"
#include <iostream>

Rook::Rook(PlayerColour player_colour) : Piece{PieceType::Rook, player_colour} {}

void Rook::evaluate_move(Position move_to) {

}

void Rook::calculate_moves() {
    this->moves.clear(); // TODO: improve by not always clearing out moves

    if (white()) {
        // Forward
        Position considered_pos = position;
        considered_pos.row += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row += 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // Backward
        considered_pos = this->position;
        considered_pos.row -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row -= 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }
        
        // Right
        considered_pos = this->position;
        considered_pos.column += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.column += 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // Left
        considered_pos = this->position;
        considered_pos.column -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.column -= 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

    } else {
        // Forward
        Position considered_pos = this->position;
        considered_pos.row -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row -= 1;
            } else if (this->board->get_piece_on(considered_pos)->white()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // Backward
        considered_pos = this->position;
        considered_pos.row += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row += 1;
            } else if (this->board->get_piece_on(considered_pos)->white()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }
        
        // Right
        considered_pos = this->position;
        considered_pos.column -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.column -= 1;
            } else if (this->board->get_piece_on(considered_pos)->white()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // Left
        considered_pos = this->position;
        considered_pos.column += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.column += 1;
            } else if (this->board->get_piece_on(considered_pos)->white()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }
    }
}

void Rook::update() {
    calculate_moves();
}