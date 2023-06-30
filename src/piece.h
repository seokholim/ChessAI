#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <queue>
#include "chess_board.h"
#include "subject.h"
#include "info.h"

class Move;

class CompareMove;

class Piece : public Subject, public Observer {
public:
    Piece(PieceType type, PlayerColour colour);
    ~Piece();
    
    void starting_position(const Position& starting_position);
    void position(const Position& position);

    void set_board(ChessBoard* board);
    bool has_board();
    void print() const;

    virtual void generate_candidate_positions() = 0;
    void clear_candidate_positions();
    void clear_moves();

    // Piece can call 
    PieceType type() const;

    PlayerColour colour() const;
    bool white() const;
    bool black() const;

    Position position() const;
    bool in_range(const Piece* other_piece) const; // TODO

    bool first_move() const;

    std::priority_queue<Move*, std::vector<Move*>, CompareMove> moves() const;
    Move* best_move() const;
protected:
    const PieceType type_;
    const PlayerColour colour_;
    Position starting_position_; // TODO: check if const works
    Position position_;
    ChessBoard* board_;

    std::queue<Position> candidate_positions_;
    std::priority_queue<Move*, std::vector<Move*>, CompareMove> moves_; // set by ChessEngine

    std::vector<Move*> move_history_;
};

#endif