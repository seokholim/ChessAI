#include "knight.h"

Knight::Knight(PlayerColour colour) : Piece{PieceType::Knight, colour} {}

void Knight::generate_candidate_positions() {
    clear_candidate_positions();
    clear_moves();

    if (board_ == nullptr) {
        std::cout << "Knight::generate_candidate_moves(); this knight is not on board!" << std::endl;
        return;
    }

    if (white()) {
        // Forward Forward Right (FFR)
        Position considered_position = position_;
        considered_position.row += 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // FRR
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BRR
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BBR
        considered_position = position_;
        considered_position.row -= 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BBL
        considered_position = position_;
        considered_position.row -= 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BLL
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // FLL
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // FFl
        considered_position = position_;
        considered_position.row += 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

    } else {
        // Forward Forward Right (FFR)
        Position considered_position = position_;
        considered_position.row -= 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // FRR
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BRR
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BBR
        considered_position = position_;
        considered_position.row += 2;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BBL
        considered_position = position_;
        considered_position.row += 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // BLL
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // FLL
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 2;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }

        // FFl
        considered_position = position_;
        considered_position.row -= 2;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            candidate_positions_.push(considered_position);
        }
    }
}

void Knight::update() {
    generate_candidate_positions();
}