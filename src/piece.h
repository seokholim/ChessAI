#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include "subject.h"
#include "info.h"
#include "move.h"

class Board;

class Player;

class Piece : public Subject, public Observer {
protected:
    PieceType piece_type;
    PlayerColour player_colour;
    Player* owner;
    Position position;
    Board* board;
    std::vector<Move*> moves;

public:
    Piece(PieceType piece_type, PlayerColour player_colour);
    Piece(PieceType piece_type, Player* owner);
    Piece(PieceType piece_type, Player* owner, Position position, Board* board);
    ~Piece();
    PieceType get_piece_type();
    void set_position(Position new_pos);
    Position get_position();
    void set_board(Board* board);
    virtual void calculate_moves() = 0;
    std::vector<Move*> get_moves();
    bool in_range(Piece* other_piece);
    void print();
};

#endif