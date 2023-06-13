#include "info.h"
#include <utility>

bool valid_piece_type(PieceType piece_type) {
    if (piece_type == PieceType::Pawn || piece_type == PieceType::Rook || piece_type == PieceType::Knight ||
        piece_type == PieceType::Queen || piece_type == PieceType::King) {
            return true;
    }
    return false;
}

char convert_to_char(PieceType piece_type) {
    switch(piece_type) {
        case PieceType::King:
            return 'K';
        case PieceType::Queen:
            return 'Q';
        case PieceType::Bishop:
            return 'B';
        case PieceType::Knight:
            return 'N';
        case PieceType::Rook:
            return 'R';
        case PieceType::Pawn:
            return 'o';
        default:
            return ' ';
    }
}

Position::Position() {}

Position::Position(char column, int row) : column{column}, row{row} {}

bool valid_position(Position position) {
    if ((1 <= position.row && position.row <= 8) 
    && ('a' <= position.column && position.column <= 'h')) return true;
    return false;
}

bool valid_player_colour(PlayerColour player_colour) {
    if (player_colour == PlayerColour::White || player_colour == PlayerColour::Black) return true;
    return false;
}

bool valid_direction(Direction direction) {
    if (direction == Direction::Forward || direction == Direction::Backward ||
        direction == Direction::Right || direction == Direction::Left ||
        direction == Direction::ForwardRight || direction == Direction::ForwardLeft ||
        direction == Direction::BackwardRight || direction == Direction::BackwardLeft) {
        return true;
    }
    return false;
}