#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include "cell.h"
#include "../utility/info.h"

class ChessPiece;

class Board {
public:
    Board();
    ~Board();

    void create_piece_on(std::shared_ptr<ChessPiece>& chess_piece, Position pos);
    void set_piece_on(std::shared_ptr<ChessPiece>& chess_piece, Position pos);
    void remove_piece(std::shared_ptr<ChessPiece> piece);
    void remove_piece_on(Position pos);
    void delete_piece_on(Position pos);

    void move(Position from, Position to);
    void undo();

    bool empty_on(Position pos) const;
    std::shared_ptr<ChessPiece> get_piece_on(Position pos) const;
    std::vector<std::shared_ptr<ChessPiece>> get_pieces() const;

    Position location_of(std::shared_ptr<ChessPiece> piece) const; // map

    void empty_board();
private:
    std::vector<std::vector<Cell>> grid_; // 8 x 8
    std::vector<std::shared_ptr<ChessPiece>> pieces_;
};

#endif