#include "queen.h"

Queen::Queen(PlayerColour colour) : Piece{PieceType::Queen, colour} {}

void Queen::generate_candidate_positions() {
    clear_candidate_positions();
    clear_moves();

    if (board_ == nullptr) {
        std::cout << "Queen::generate_candidate_positions(); this queen is not on board!" << std::endl;
        return;
    }

    if (white()) { // TODO: iterate over i {Direction::d, PlayerColour::c, i}
        // Forward
        Position considered_position = position_;
        considered_position.row += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // Backward
        considered_position = position_;
        considered_position.row -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) { 
                candidate_positions_.push(considered_position);
                considered_position.row -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // Right
        considered_position = position_;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.column += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // Left
        considered_position = position_;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.column -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // ForwardRight
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
        // Forward
        Position considered_position = position_;
        considered_position.row -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // Backward
        considered_position = position_;
        considered_position.row += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.row += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // Right
        considered_position = position_;
        considered_position.column -= 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.column -= 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // Left
        considered_position = position_;
        considered_position.column += 1;
        while (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
                considered_position.column += 1;
            } else {
                candidate_positions_.push(considered_position);
                break;
            }
        }

        // ForwardRight
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

void Queen::update() {
    generate_candidate_positions();
}