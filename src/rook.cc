#include "rook.h"

Rook::Rook(PlayerColour colour) : Piece{PieceType::Rook, colour} {}

void Rook::generate_candidate_positions() {
    clear_candidate_positions();
    clear_moves();

    if (board_ == nullptr) {
        std::cout << "Rook::generate_candidate_positions(); this rook is not on board!" << std::endl;
        return;
    }
    
    if (white()) { // TODO: refactor to account for colour
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
    }
}

void Rook::update() {
    generate_candidate_positions();
}