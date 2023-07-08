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

    void set_board(std::shared_ptr<ChessBoard> board);
    std::shared_ptr<ChessBoard> board() const;
    bool has_board();

    virtual void generate_candidate_positions() = 0;
    void clear_candidate_positions();
    std::queue<Position> candidate_positions();

    void clear_moves();
    void add_move_t1(std::shared_ptr<Move> new_move);
    void add_move_t2(std::shared_ptr<Move> new_move);

    // ChessBoard, ChessPiece can also call:
    PieceType type() const;

    PlayerColour colour() const;
    bool white() const;
    bool black() const;

    Position starting_position() const;
    Position position() const;
    bool in_range(const std::shared_ptr<Piece> other_piece) const; // TODO

    bool first_move() const;

    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t1() const;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t2() const;
    std::shared_ptr<Move> best_move() const;

    void add_to_history(std::shared_ptr<Move> move);

    void print() const;
protected:
    const PieceType type_;
    const PlayerColour colour_;
    Position starting_position_;
    Position position_;
    std::shared_ptr<ChessBoard> board_;

    std::queue<Position> candidate_positions_;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t1_;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t2_;

    std::vector<std::shared_ptr<Move>> move_history_;

    friend class Chess; // TESTING
};

#endif