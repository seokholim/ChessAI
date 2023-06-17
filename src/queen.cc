#include "queen.h"

Queen::Queen(PlayerColour player_colour) : Piece{PieceType::Queen, player_colour} {}

void Queen::evaluate_move(Position move_to) {

}

void Queen::calculate_moves() {
    this->moves.clear();

    if (this->player_colour == PlayerColour::White) { //{Direction::d, PlayerColour::c, i}?
        // Forward
        Position considered_pos = this->position;
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

        // ForwardRight
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
        // Forward
        Position considered_pos = this->position;
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

        // Backward
        considered_pos = this->position;
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

        // Right
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

        // Left
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

        // ForwardRight
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

void Queen::update() {
    calculate_moves();
}