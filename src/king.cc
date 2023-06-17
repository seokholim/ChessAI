#include "king.h"

King::King(PlayerColour player_colour) : Piece{PieceType::King, player_colour} {}

void King::evaluate_move(Position move_to) {
    if (board->empty_on(move_to)) {
        Move* new_move = new Move{position, move_to, this};
        moves.push_back(new_move);
    } else if (this->player_colour != board->get_piece_on(move_to)->get_colour()) {
        Move* new_move = new Move{position, move_to, this};
        moves.push_back(new_move);
    }
}

void King::calculate_moves() { // can create moves by evaluate_move(...)
    moves.clear();

    if (white()) { //{Direction::d, PlayerColour::c, i}?
        // Forward
        Position considered_pos = position;
        considered_pos.row += 1;
        evaluate_move(considered_pos);
        // Backward
        considered_pos = position;
        considered_pos.row -= 1;
        evaluate_move(considered_pos);
        // Right
        considered_pos = position;
        considered_pos.column += 1;
        evaluate_move(considered_pos);
        // Left
        considered_pos = position;
        considered_pos.column -= 1;
        evaluate_move(considered_pos);
        // ForwardRight
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column += 1;
        evaluate_move(considered_pos);
        // ForwardLeft
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column -= 1;
        evaluate_move(considered_pos);
        // BackwardRight
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column += 1;
        evaluate_move(considered_pos);
        // BackwardLeft
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column -= 1;
        evaluate_move(considered_pos);
    } else {
        // Forward
        Position considered_pos = position;
        considered_pos.row -= 1;
        evaluate_move(considered_pos);
        // Backward
        considered_pos.row += 1;
        evaluate_move(considered_pos);
        // Right
        considered_pos = position;
        considered_pos.column -= 1;
        evaluate_move(considered_pos);
        // Left
        considered_pos = position;
        considered_pos.column += 1;
        evaluate_move(considered_pos);
        // ForwardRight
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column -= 1;
        evaluate_move(considered_pos);
        // ForwardLeft
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column += 1;
        evaluate_move(considered_pos);
        // BackwardRight
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column -= 1;
        evaluate_move(considered_pos);
        // BackwardLeft
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column += 1;
        evaluate_move(considered_pos);
    }
}

void King::update() {
    calculate_moves();
}