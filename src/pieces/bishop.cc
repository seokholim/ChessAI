#include "bishop.h"

Bishop::Bishop(PlayerColour colour) : Piece{PieceType::Bishop, colour} {}

void Bishop::generate_candidate_positions() {
    clear_candidate_positions();
    clear_moves();

    if (board_ == nullptr) {
        std::cout << "Bishop::generate_candidate_positions(); this bishop is not on board!" << std::endl;
        return;
    }

    if (white()) { // TODO: refactor to account for colour
        // ForwardRight
        Position considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row += 1;
                considered_position.column += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // ForwardLeft
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row += 1;
                considered_position.column -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // BackwardRight
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row -= 1;
                considered_position.column += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // BackwardLeft
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row -= 1;
                considered_position.column -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }
    } else {
        // ForwardRight
        Position considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row -= 1;
                considered_position.column -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // ForwardLeft
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row -= 1;
                considered_position.column += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // BackwardRight
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row += 1;
                considered_position.column -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // BackwardLeft
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row += 1;
                considered_position.column += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }
    }
}

void Bishop::update() {
    generate_candidate_positions();
}