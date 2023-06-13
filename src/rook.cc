#include "rook.h"
#include <iostream>

Rook::Rook(PlayerColour player_colour) : Piece{PieceType::Rook, player_colour} {}

// Rook::Rook(Player* owner) : Piece{PieceType::Rook, owner} {}

// Rook::Rook(Player* owner, Position position, Board* board) : Piece{PieceType::Rook, owner, position, board} {}

void Rook::calculate_moves() {
    this->moves.clear(); // TODO: improve by not always clearing out moves

    if (this->player_colour == PlayerColour::White) {
        std::cout << "white player's Rook!" << std::endl;
        // Forward
        Position current_position = this->get_position();
        std::cout << "This rook's current position is " << current_position.column << current_position.row << std::endl;
        current_position.row += 1;
        std::cout << "This rook's current position was changed to " << current_position.column << current_position.row << std::endl;
        if (this->board->empty_at(current_position)) {
            std::cout << "Forward move made by White Rook!" << std::endl;
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Backward
        current_position = this->get_position();
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            std::cout << "Backward move made by White Rook!" << std::endl;
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        
        // Right
        current_position = this->get_position();
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Left
        current_position = this->get_position();
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    } else {
        std::cout << "Black player's Rook!" << std::endl;

        // Forward
        Position current_position = this->get_position();
        current_position.row -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Backward
        current_position = this->get_position();
        current_position.row += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
        
        // Right
        current_position = this->get_position();
        current_position.column -= 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }

        // Left
        current_position = this->get_position();
        current_position.column += 1;
        if (this->board->empty_at(current_position)) {
            Move* new_move = new Move{this->position, current_position, this};
            this->moves.push_back(new_move);
        }
    }
}

void Rook::update() {
    std::cout << "rook update called" << std::endl;
    calculate_moves();
}