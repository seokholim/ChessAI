#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "board.h"

class ChessBoard {
public:
    ChessBoard(Board* data);
    ~ChessBoard();

    bool empty_on(const Position& pos) const;
    ChessPiece* get_piece_on(const Position& pos) const;
    std::vector<ChessPiece*> get_pieces() const;
private:
    Board* data_;
};

#endif