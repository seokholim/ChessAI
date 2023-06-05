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
    Position(char col, int row);  
};

char convert_to_char(PieceType piece_type);

enum class Direction {
    Forward, Backward, Right, Left,
    ForwardRight, ForwardLeft, BackwardRight, BackwardLeft
};

#endif