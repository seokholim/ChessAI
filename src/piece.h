#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <queue>
#include "chess_board.h"
#include "subject.h"
#include "info.h"
#include "move.h"

class Piece : public Subject, public Observer {
public:
    Piece(PieceType type, PlayerColour colour);
    ~Piece();
    
    void starting_position(const Position& starting_position);
    void position(const Position& position);

    void set_board(ChessBoard* board);
    bool has_board();

    virtual void generate_candidate_positions() = 0;
    void clear_candidate_positions();
    std::queue<Position> candidate_positions();

    void clear_moves();
    void add_move(std::shared_ptr<Move> new_move);

    // ChessBoard, ChessPiece can also call:
    PieceType type() const;

    PlayerColour colour() const;
    bool white() const;
    bool black() const;

    Position position() const;
    bool in_range(const std::shared_ptr<Piece> other_piece) const; // TODO

    bool first_move() const;

    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves() const;
    std::shared_ptr<Move> best_move() const;

    void print() const;
protected:
    const PieceType type_;
    const PlayerColour colour_;
    Position starting_position_; // TODO: check if const works
    Position position_;
    ChessBoard* board_;

    std::queue<Position> candidate_positions_;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_; // set by ChessEngine

    std::vector<std::shared_ptr<Move>> move_history_;
};

#endif