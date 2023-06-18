#include "king.h"

King::King(PlayerColour player_colour) : Piece{PieceType::King, player_colour} {}

void King::evaluate_move(Position move_to) {
    
}

void King::calculate_moves() {
    moves.clear();

    if (white()) { //{Direction::d, PlayerColour::c, i}?
        // Forward
        Position considered_pos = position;
        considered_pos.row += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // Backward
        considered_pos = position;
        considered_pos.row -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // Right
        considered_pos = position;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // Left
        considered_pos = position;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // ForwardRight
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // ForwardLeft
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // BackwardRight
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // BackwardLeft
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

    } else {
        // Forward
        Position considered_pos = position;
        considered_pos.row -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // Backward
        considered_pos = position;
        considered_pos.row += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // Right
        considered_pos = position;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // Left
        considered_pos = position;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // ForwardRight
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // ForwardLeft
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // BackwardRight
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }

        // BackwardLeft
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos)) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            } else if (board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{position, considered_pos, this};
                moves.push_back(new_move);
            }
        }
    }
}

void King::update() {
    calculate_moves();
}