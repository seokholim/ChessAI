#ifndef INFO_H
#define INFO_H

enum class PieceType {
    Pawn, Rook, Knight, Queen, King
};

enum class PlayerColour {
    White, Black
};

struct Position {
    char column;
    int row;
    Position();
    Position(char col, int row);  
};

char convert_to_char(PieceType piece_type);

enum class Direction {
    Forward, Backward, Right, Left,
    ForwardRight, ForwardLeft, BackwardRight, BackwardLeft
};

bool valid_piece_type(PieceType piece_type) {
    if (piece_type == PieceType::Pawn || piece_type == PieceType::Rook || piece_type == PieceType::Knight ||
        piece_type == PieceType::Queen || piece_type == PieceType::King) {
            return true;
    }
    return false;
}

bool valid_position(Position position) {}

bool valid_direction(Direction direction) {
    if (direction == Direction::Forward || direction == Direction::Backward ||
        direction == Direction::Right || direction == Direction::Left ||
        direction == Direction::ForwardRight || direction == Direction::ForwardLeft ||
        direction == Direction::BackwardRight || direction == Direction::BackwardLeft) {
        return true;
    }
    return false;
}

#endif