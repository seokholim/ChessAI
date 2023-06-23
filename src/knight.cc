#include "knight.h"

Knight::Knight(PlayerColour player_colour) : Piece{PieceType::Knight, player_colour} {}

void Knight::calculate_moves() { // TODO: clean
    moves.clear();

    if (white()) {
        // Forward Forward Right (FFR)
        Position considered_position = position;
        considered_position.row += 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // FRR
        considered_position = position;
        considered_position.row += 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BRR
        considered_position = position;
        considered_position.row -= 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BBR
        considered_position = position;
        considered_position.row -= 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BBL
        considered_position = position;
        considered_position.row -= 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BLL
        considered_position = position;
        considered_position.row -= 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // FLL
        considered_position = position;
        considered_position.row += 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // FFl
        considered_position = position;
        considered_position.row += 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->black()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

    } else {
        // Forward Forward Right (FFR)
        Position considered_position = position;
        considered_position.row -= 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // FRR
        considered_position = position;
        considered_position.row -= 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BRR
        considered_position = position;
        considered_position.row += 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BBR
        considered_position = position;
        considered_position.row += 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BBL
        considered_position = position;
        considered_position.row += 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // BLL
        considered_position = position;
        considered_position.row += 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // FLL
        considered_position = position;
        considered_position.row -= 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }

        // FFl
        considered_position = position;
        considered_position.row -= 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (board->empty_on(considered_position)) {
                Move* new_move = new Move{position, considered_position, this, nullptr};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            } else if (board->get_piece_on(considered_position)->white()) {
                Move* new_move = new Move{position, considered_position, this, board->get_piece_on(considered_position)};
                if (!chess_engine->king_checked(new_move)) {
                    chess_engine->evaluate_move(new_move, 1);
                    moves.push_back(new_move);
                }
            }
        }
    }

}

void Knight::update() {
    calculate_moves();
}