#ifndef INFO_H
#define INFO_H

enum class PlayerColour {
    White, Black
};

bool valid_player_colour(PlayerColour player_colour);

enum class PieceType {
    Pawn, Rook, Knight, Bishop, Queen, King
};

bool valid_piece_type(PieceType piece_type);

char convert_to_char(PieceType piece_type);

struct Position {
    char column;
    int row;
    Position();
    Position(char col, int row);  
};

bool valid_position(Position position);

enum class Direction {
    Forward, Backward, Right, Left,
    ForwardRight, ForwardLeft, BackwardRight, BackwardLeft
};

bool valid_direction(Direction direction);

#endif