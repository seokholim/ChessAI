#include "pawn.h"
#include <iostream>

Pawn::Pawn(PlayerColour player_colour) : Piece{PieceType::Pawn, player_colour}, first_move{true} {}

void Pawn::calculate_moves() { // TODO: fix double forward
    this->moves.clear(); // TODO: improve by not always clearing out moves

    if (white()) {
        // Double Forward
        if (first_move) {
            Position considered_position = position;
            considered_position.row += 2;
            if (valid_position(considered_position)) {
                if (this->board->empty_on(considered_position)) {
                    Move* new_move = new Move{position, considered_position, this, nullptr};
                    if (!chess_engine->king_checked(new_move)) {
                        chess_engine->evaluate_move(new_move, 1);
                        this->moves.push_back(new_move);
                    }
                }
            }
        }

        // Forward
        Position considered_position = position;
        considered_position.row += 1;
        if (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    this->moves.push_back(new_move);
                }
            }
        }

        // Forward Right Capture
        considered_position = position;
        considered_position.row += 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (!this->board->empty_on(considered_position) && board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    this->moves.push_back(new_move);
                }
            }
        }

        // Forward Left Capture
        considered_position = position;
        considered_position.row += 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (!this->board->empty_on(considered_position) && board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    this->moves.push_back(new_move);
                }
            }
        }

    } else {
        // Double Forward
        if (first_move) {
            Position considered_position = position;
            considered_position.row -= 2;
            if (valid_position(considered_position)) {
                if (this->board->empty_on(considered_position)) {
                    Move* new_move = new Move{position, considered_position, this, nullptr};
                    if (!chess_engine->king_checked(new_move)) {
                        chess_engine->evaluate_move(new_move, 1);
                        this->moves.push_back(new_move);
                    }
                }
            }
        }

        // Forward
        Position considered_position = position;
        considered_position.row -= 1;
        if (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    this->moves.push_back(new_move);
                }
            }
        }

        // Forward Right Capture
        considered_position = position;
        considered_position.row -= 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (!this->board->empty_on(considered_position) && board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    this->moves.push_back(new_move);
                }
            }
        }

        // Forward Left Capture
        considered_position = position;
        considered_position.row -= 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (!this->board->empty_on(considered_position) && board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    this->moves.push_back(new_move);
                }
            }
        }
    }
}

void Pawn::update() {
    calculate_moves();
}