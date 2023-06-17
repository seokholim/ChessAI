#include "bishop.h"

Bishop::Bishop(PlayerColour player_colour) : Piece{PieceType::Bishop, player_colour} {}

void Bishop::evaluate_move(Position move_to) {

}

void Bishop::calculate_moves() {
    this->moves.clear();

    if (white()) { //{Direction::d, PlayerColour::c, i}?
        // ForwardRight
        Position considered_pos = this->position;
        considered_pos.row += 1;
        considered_pos.column += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row += 1;
                considered_pos.column += 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // ForwardLeft
        considered_pos = this->position;
        considered_pos.row += 1;
        considered_pos.column -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row += 1;
                considered_pos.column -= 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardRight
        considered_pos = this->position;
        considered_pos.row -= 1;
        considered_pos.column += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row -= 1;
                considered_pos.column += 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardLeft
        considered_pos = this->position;
        considered_pos.row -= 1;
        considered_pos.column -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row -= 1;
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
        // ForwardRight
        Position considered_pos = this->position;
        considered_pos.row -= 1;
        considered_pos.column -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row -= 1;
                considered_pos.column -= 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // ForwardLeft
        considered_pos = this->position;
        considered_pos.row -= 1;
        considered_pos.column += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row -= 1;
                considered_pos.column += 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardRight
        considered_pos = this->position;
        considered_pos.row += 1;
        considered_pos.column -= 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row += 1;
                considered_pos.column -= 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardLeft
        considered_pos = this->position;
        considered_pos.row += 1;
        considered_pos.column += 1;
        while (valid_position(considered_pos)) {
            if (this->board->empty_on(considered_pos)) { // empty
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                considered_pos.row += 1;
                considered_pos.column += 1;
            } else if (this->board->get_piece_on(considered_pos)->black()) { // capture
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
                break;
            } else { // same coloured piece
                break;
            }
        }
    }
}

void Bishop::update() {
    calculate_moves();
}