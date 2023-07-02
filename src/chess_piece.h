#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "piece.h"

class ChessPiece {
public:
    ChessPiece(std::shared_ptr<Piece> data);
    ~ChessPiece();
    
    PieceType type() const;
    
    PlayerColour colour() const;
    bool white() const;
    bool black() const;

    Position position() const;
    bool in_range(const std::shared_ptr<ChessPiece> other) const;

    bool first_move() const;

    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves() const;
    std::shared_ptr<Move> best_move() const;

    void print() const;
private:
    std::shared_ptr<Piece> data_;
    friend class ChessGame; // TESTING
};

#endif