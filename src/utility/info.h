#ifndef INFO_H
#define INFO_H
#include <string>
#include <limits>

enum class PlayerColour {
    Null, White, Black
};

bool valid_player_colour(PlayerColour player_colour);

enum class PieceType {
    Null, Pawn, Rook, Knight, Bishop, Queen, King
};

bool valid_piece_type(PieceType piece_type);

bool unbalanced_trade(PieceType trading, PieceType with);

std::string convert_to_char(PlayerColour player_colour, PieceType piece_type);

struct Position {
    char column;
    int row;
    Position();
    Position(char col, int row);  
    bool operator==(const Position& other_pos) const;	
};

bool valid_position(Position position);

bool increasing_column(Position pos1, Position pos2);

enum class Direction {
    Null, Forward, Backward, Right, Left,
    ForwardRight, ForwardLeft, BackwardRight, BackwardLeft
};

bool valid_direction(Direction direction);

enum class MoveType {
    Null, Unevaluated, Capturing, CapturingForFree, Defending, Dangerous, Evading, Neutral, SafeNeutral, Castling, EnPassant, Upgrade, KingUnsafe, Checkmate
};

bool valid_chess_move_type(MoveType move_type);

bool is_move_t1(MoveType MoveType);

int safe_division(int a, int b);

// Capture Move base values

const int pawn_capturing_pawn = 20;
const int pawn_capturing_rook = 70;
const int pawn_capturing_knight = 70;
const int pawn_capturing_bishop = 70;
const int pawn_capturing_queen = 300;
const int pawn_capturing_king = 1000;

const int rook_capturing_pawn = 10;
const int rook_capturing_rook = 50;
const int rook_capturing_knight = 50;
const int rook_capturing_bishop = 50;
const int rook_capturing_queen = 300;
const int rook_capturing_king = 1000;

const int knight_capturing_pawn = 10;
const int knight_capturing_rook = 50;
const int knight_capturing_knight = 50;
const int knight_capturing_bishop = 50;
const int knight_capturing_queen = 300;
const int knight_capturing_king = 1000;

const int bishop_capturing_pawn = 10;
const int bishop_capturing_rook = 50;
const int bishop_capturing_knight = 50;
const int bishop_capturing_bishop = 50;
const int bishop_capturing_queen = 300;
const int bishop_capturing_king = 1000;

const int queen_capturing_pawn = 10;
const int queen_capturing_rook = 50;
const int queen_capturing_knight = 50;
const int queen_capturing_bishop = 50;
const int queen_capturing_queen = 300;
const int queen_capturing_king = 1000;

const int king_capturing_pawn = 5;
const int king_capturing_rook = 5;
const int king_capturing_knight = 5;
const int king_capturing_bishop = 5;
const int king_capturing_queen = 10;
const int king_capturing_king = 5;

#endif