#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "board.h"

class ChessBoard {
public:
    ChessBoard(Board* data);
    ~ChessBoard();

    bool empty_on(const Position& pos) const;
    std::shared_ptr<ChessPiece> get_piece_on(const Position& pos) const;
    std::vector<std::shared_ptr<ChessPiece>> get_pieces() const;
private:
    Board* data_;
    friend class Chess;
    friend class Engine;
    friend class Scenario;
};

#endif