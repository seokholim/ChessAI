#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include "info.h"

class ChessPiece;

class Move {
public:
    Move(Position move_from, Position move_to, std::shared_ptr<ChessPiece> moving_piece, std::shared_ptr<ChessPiece> occupying_piece);
    ~Move();

    Position move_from() const;
    Position move_to() const;

    std::shared_ptr<ChessPiece> moving_piece() const;
    std::shared_ptr<ChessPiece> occupying_piece() const;
    bool occupied() const;

    void move_type(MoveType move_type);
    MoveType move_type() const;
    
    void value(int new_value);
    int value() const;
private:
    Position move_from_;
    Position move_to_;
    std::shared_ptr<ChessPiece> moving_piece_;
    std::shared_ptr<ChessPiece> occupying_piece_;
    MoveType move_type_;
    int value_;
};

class CompareMove {
public:
    bool operator() (std::shared_ptr<Move> m1, std::shared_ptr<Move> m2) {
        return m1->value() < m2->value();
    }
};

#endif