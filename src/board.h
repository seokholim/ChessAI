#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include "cell.h"
#include "info.h"

class ChessPiece;

class Board {
public:
    Board();
    ~Board();

    void create_piece_on(ChessPiece* chess_piece, Position pos);
    void set_piece_on(ChessPiece* chess_piece, Position pos);
    void remove_piece_on(Position pos);
    void delete_piece_on(Position pos);

    void move(Position current_pos, Position new_pos);
    void undo();

    bool empty_on(Position pos) const;
    ChessPiece* get_piece_on(Position pos) const;
    std::vector<ChessPiece*> get_pieces() const;

    Position location_of(ChessPiece* piece) const; // map
private:
    std::vector<std::vector<Cell>> grid_; // 8 x 8
    std::vector<ChessPiece*> pieces_;
};

#endif