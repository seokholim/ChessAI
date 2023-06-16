#include "queen.h"

Queen::Queen(PlayerColour player_colour) : Piece{PieceType::Queen, player_colour} {}

void Queen::calculate_moves() { // TODO: only one distance
    this->moves.clear();

    if (this->player_colour == PlayerColour::White) { //{Direction::d, PlayerColour::c, i}?
        // Forward
        Position current_position = this->position;
        current_position.row += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // Backward
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // Right
        current_position = this->position;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // Left
        current_position = this->position;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // ForwardRight
        current_position = this->position;
        current_position.row += 1;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // ForwardLeft
        current_position = this->position;
        current_position.row += 1;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // BackwardRight
        current_position = this->position;
        current_position.row -= 1;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // BackwardLeft
        current_position = this->position;
        current_position.row -= 1;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    } else {
        // Forward
        Position current_position = this->position;
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // Backward
        current_position.row += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // Right
        current_position = this->position;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // Left
        current_position = this->position;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // ForwardRight
        current_position = this->position;
        current_position.row -= 1;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // ForwardLeft
        current_position = this->position;
        current_position.row -= 1;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // BackwardRight
        current_position = this->position;
        current_position.row += 1;
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        // BackwardLeft
        current_position = this->position;
        current_position.row += 1;
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    }
}

void Queen::update() {
    calculate_moves();
}