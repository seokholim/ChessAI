#include "pawn.h"

Pawn::Pawn(PlayerColour colour) : Piece{PieceType::Pawn, colour} {}

bool Pawn::advanced_three_ranks() { // TODO: check history and calculate distance
    if ((position_.column == starting_position_.column)
    &&  ((white() && (position_.row - starting_position_.row == 3)) || (black() && (position_.row - starting_position_.row == -3)))) {
        return true;
    }
    return false;
}

void Pawn::generate_candidate_positions() {
    clear_candidate_positions();
    clear_moves();

    if (board_ == nullptr) {
        std::cout << "Pawn::generate_candidate_positions(); this pawn is not on board!" << std::endl;
        return;
    }

    if (white()) {
        // Double Forward
        if (first_move()) {
            Position considered_position = position_;
            considered_position.row += 1;
            if (valid_position(considered_position) && board_->empty_on(considered_position)) {
                considered_position.row += 1;
                if (valid_position(considered_position) && board_->empty_on(considered_position)) {
                    candidate_positions_.push(considered_position);
                }
            }
        }

        // Forward
        Position considered_position = position_;
        considered_position.row += 1;
        if (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
            }
        }

        // Forward Right
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (!board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
            }
        }

        // Forward Left
        considered_position = position_;
        considered_position.row += 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (!board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
            }
        }

        // Left En Passant
        if (advanced_three_ranks()) {
            considered_position = position_;
            considered_position.column -= 1;
            if (valid_position(considered_position)) {
                if (!board_->empty_on(considered_position)) {
                    candidate_positions_.push(considered_position);
                } 
            }
        }

        // Right En Passant
        if (advanced_three_ranks()) {
            considered_position = position_;
            considered_position.column += 1;
            if (valid_position(considered_position)) {
                if (!board_->empty_on(considered_position)) {
                    candidate_positions_.push(considered_position);
                } 
            }
        }

    } else {
        // Double Forward
        if (first_move()) {
            Position considered_position = position_;
            considered_position.row -= 1;
            if (valid_position(considered_position) && board_->empty_on(considered_position)) {
                considered_position.row -= 1;
                if (valid_position(considered_position) && board_->empty_on(considered_position)) {
                    candidate_positions_.push(considered_position);
                }
            }
        }

        // Forward
        Position considered_position = position_;
        considered_position.row -= 1;
        if (valid_position(considered_position)) {
            if (board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
            }
        }

        // Forward Right
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column -= 1;
        if (valid_position(considered_position)) {
            if (!board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
            }
        }

        // Forward Left
        considered_position = position_;
        considered_position.row -= 1;
        considered_position.column += 1;
        if (valid_position(considered_position)) {
            if (!board_->empty_on(considered_position)) {
                candidate_positions_.push(considered_position);
            }
        }

        // Left En Passant
        if (advanced_three_ranks()) {
            considered_position = position_;
            considered_position.column += 1;
            if (valid_position(considered_position)) {
                if (!board_->empty_on(considered_position)) {
                    candidate_positions_.push(considered_position);
                } 
            }
        }

        // Right En Passant
        if (advanced_three_ranks()) {
            considered_position = position_;
            considered_position.column -= 1;
            if (valid_position(considered_position)) {
                if (!board_->empty_on(considered_position)) {
                    candidate_positions_.push(considered_position);
                } 
            }
        }
    }
}

void Pawn::update() {
    generate_candidate_positions();
}