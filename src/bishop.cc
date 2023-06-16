#include "bishop.h"

Bishop::Bishop(PlayerColour player_colour) : Piece{PieceType::Bishop, player_colour} {}

void Bishop::calculate_moves() { // TODO: only one distance
    this->moves.clear();

    if (this->player_colour == PlayerColour::White) { //{Direction::d, PlayerColour::c, i}?
        // ForwardRight
        Position current_position = this->position;
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
        // ForwardRight
        Position current_position = this->position;
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

void Bishop::update() {
    calculate_moves();
}