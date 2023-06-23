#include "rook.h"
#include <iostream>

Rook::Rook(PlayerColour player_colour) : Piece{PieceType::Rook, player_colour} {}

void Rook::calculate_moves() {
    moves.clear(); // TODO: improve by not always clearing out moves

    if (white()) {
        // Forward
        Position considered_position = position;
        considered_position.row += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row += 1;
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

        // Backward
        considered_position = position;
        considered_position.row -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row -= 1;
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
        
        // Right
        considered_position = position;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
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

        // Left
        considered_position = position;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
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
        // Forward
        Position considered_position = position;
        considered_position.row -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row -= 1;
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

        // Backward
        considered_position = position;
        considered_position.row += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                    considered_position.row += 1;
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
        
        // Right
        considered_position = position;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
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

        // Left
        considered_position = position;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (this->board->empty_on(considered_position)) { // empty
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
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
    }
}

void Rook::update() {
    calculate_moves();
}