#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "piece.h"

class ChessPiece {
public:
    ChessPiece(Piece* data);
    ~ChessPiece();
    
    PieceType type() const;
    
    PlayerColour colour() const;
    bool white() const;
    bool black() const;

    Position position() const;
    bool in_range(const ChessPiece* other_piece) const;

    bool first_move() const;

    std::priority_queue<Move*, std::vector<Move*>, CompareMove> moves() const;
    Move* best_move() const;

    void print() const;
private:
    Piece* data_;
};

#endif