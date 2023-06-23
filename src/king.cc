#include "king.h"

King::King(PlayerColour player_colour) : Piece{PieceType::King, player_colour} {}

void King::calculate_moves() {
    moves.clear();

    if (white()) { //{Direction::d, PlayerColour::c, i}?
        // Forward
        Position considered_position = position;
        considered_position.row += 1;
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

        // Backward
        considered_position = position;
        considered_position.row -= 1;
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

        // Right
        considered_position = position;
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

        // Left
        considered_position = position;
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

        // ForwardRight
        considered_position = position;
        considered_position.row += 1;
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

        // ForwardLeft
        considered_position = position;
        considered_position.row += 1;
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

        // BackwardRight
        considered_position = position;
        considered_position.row -= 1;
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

        // BackwardLeft
        considered_position = position;
        considered_position.row -= 1;
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
        // Forward
        Position considered_position = position;
        considered_position.row -= 1;
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

        // Backward
        considered_position = position;
        considered_position.row += 1;
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

        // Right
        considered_position = position;
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

        // Left
        considered_position = position;
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

        // ForwardRight
        considered_position = position;
        considered_position.row -= 1;
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

        // ForwardLeft
        considered_position = position;
        considered_position.row -= 1;
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

        // BackwardRight
        considered_position = position;
        considered_position.row += 1;
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

        // BackwardLeft
        considered_position = position;
        considered_position.row += 1;
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

void King::update() {
    calculate_moves();
}