#include "bishop.h"

Bishop::Bishop(PlayerColour player_colour) : Piece{PieceType::Bishop, player_colour} {}

void Bishop::calculate_moves() {
    this->moves.clear();

    if (white()) { //{Direction::d, PlayerColour::c, i}?
        // ForwardRight
        Position considered_position = this->position;
        considered_position.row += 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row += 1;
                    considered_position.column += 1;
                }
            } else if (board->get_piece_on(considered_position)->black()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }

        // ForwardLeft
        considered_position = this->position;
        considered_position.row += 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row += 1;
                    considered_position.column -= 1;
                }
            } else if (board->get_piece_on(considered_position)->black()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardRight
        considered_position = this->position;
        considered_position.row -= 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row -= 1;
                    considered_position.column += 1;
                }
            } else if (board->get_piece_on(considered_position)->black()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardLeft
        considered_position = this->position;
        considered_position.row -= 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row -= 1;
                    considered_position.column -= 1;
                }
            } else if (board->get_piece_on(considered_position)->black()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }
    } else {
        // ForwardRight
        Position considered_position = this->position;
        considered_position.row -= 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row -= 1;
                    considered_position.column -= 1;
                }
            } else if (board->get_piece_on(considered_position)->white()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }

        // ForwardLeft
        considered_position = this->position;
        considered_position.row -= 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row -= 1;
                    considered_position.column += 1;
                }
            } else if (board->get_piece_on(considered_position)->white()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardRight
        considered_position = this->position;
        considered_position.row += 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row += 1;
                    considered_position.column -= 1;
                }
            } else if (board->get_piece_on(considered_position)->white()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
                break;
            } else { // same coloured piece
                break;
            }
        }

        // BackwardLeft
        considered_position = this->position;
        considered_position.row += 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row += 1;
                    considered_position.column += 1;
                }
            } else if (board->get_piece_on(considered_position)->white()) { // capture
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
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