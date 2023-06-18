#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "cell.h"
#include "piece.h"

class Board {
    std::vector<std::vector<Cell> > grid; // 8 x 8
    std::vector<Piece*> pieces;
  public:
    Board();
    ~Board();
    void create_piece_on(Piece* piece, const Position& pos);
    void set_piece_on(Piece* piece, const Position& pos);
    Piece* get_piece_on(const Position& pos);
    void remove_piece_on(const Position& pos);
    void delete_piece_on(const Position& pos);
    std::vector<Piece*> get_pieces();
    void move_piece(const Position& current_pos, const Position& new_pos);
    bool empty_on(const Position& pos);
    void print(bool white_perspective);
};

#endif