#include <iostream>
#include "piece.h"

Piece::Piece(PieceType piece_type, PlayerColour player_colour) {
    if (valid_piece_type(piece_type) && (valid_player_colour(player_colour))) {
        this->piece_type = piece_type;
        this->player_colour = player_colour;
    } else {
        std::cout << "couldn't construct a piece" << std::endl;
    }
}

Piece::Piece(PieceType piece_type, Player* owner) {
    if (valid_piece_type(piece_type) && (owner != nullptr)) {
        this->piece_type = piece_type;
        this->owner = owner;
    } else {
        std::cout << "couldn't construct a piece" << std::endl;
    }
}

Piece::Piece(PieceType piece_type, Player* owner, Position pos, Board* board) {
    if (valid_piece_type(piece_type) && (owner != nullptr) && valid_position(pos) && (board != nullptr)) {
        this->piece_type = piece_type;
        this->owner = owner;
        this->position = pos;
        this->board = board;
    } else {
        std::cout << "couldn't construct a piece" << std::endl;
    }
}

PieceType Piece::get_piece_type() {
    return this->piece_type;
}

void Piece::set_position(Position new_pos) {
    this->position = new_pos;
}

Position Piece::get_position() {
    return this->position;
} 

void Piece::set_board(Board* board) {
    this->board = board;
}

std::vector<Move*> Piece::get_moves() {
    return this->moves;
}

bool Piece::in_range(Piece* other_piece) {

}

void Piece::print() {
    std::cout<< convert_to_char(this->piece_type);
}

Piece::~Piece() {}