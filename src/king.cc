#include "king.h"

King::King(PlayerColour colour) : Piece{PieceType::King, colour} {}

void King::generate_candidate_positions() {
    clear_candidate_positions();
    clear_moves();

    if (board_ == nullptr) {
        std::cout << "King::generate_candidate_positions(); this king is not on board!" << std::endl;
        return;
    }

    if (white()) { //{Direction::d, PlayerColour::c, i}?
        // Forward
        Position considered_position = position_;
        considered_position.row += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // Backward
        considered_position = position_;
        considered_position.row -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // Right
        considered_position = position_;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // Left
        considered_position = position_;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // ForwardRight
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // ForwardLeft
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BackwardRight
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BackwardLeft
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

    } else {
        // Forward
        Position considered_position = position_;
        considered_position.row -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // Backward
        considered_position = position_;
        considered_position.row += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // Right
        considered_position = position_;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // Left
        considered_position = position_;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // ForwardRight
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // ForwardLeft
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BackwardRight
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BackwardLeft
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }
    }
}

void King::update() {
    generate_candidate_positions();
}