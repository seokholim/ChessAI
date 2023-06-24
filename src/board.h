#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include "cell.h"
#include "info.h"

class Piece;

class Move;

class Board {
    std::vector<std::vector<Cell>> grid; // 8 x 8
    std::vector<Piece*> pieces;
  public:
    Board();
    ~Board();

    void create_piece_on(Piece* piece, Position pos);
    void set_piece_on(Piece* piece, Position pos);
    Piece* get_piece_on(Position pos);

    void remove_piece_on(Position pos);
    void delete_piece_on(Position pos);

    std::vector<Piece*> get_pieces();
    void move_piece(Position current_pos, Position new_pos);
    void undo();

    bool empty_on(Position pos);
};

#endif