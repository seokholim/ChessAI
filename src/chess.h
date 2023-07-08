#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <algorithm>
#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include "player/player.h"
#include "board/chess_board.h"
#include "engine/engine.h"
#include "pieces/piece.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include "pieces/pawn.h"

class Chess {
public:
    Chess();
    ~Chess();

    void init();
    void initialize_players();
    void create_piece_on(std::shared_ptr<Piece> piece, const Position& pos);
    void initialize_pieces();

    bool valid_move(std::shared_ptr<Move> move);
    void move(std::shared_ptr<Move> move);
    void undo();

    std::shared_ptr<Move> AI_play(bool white_player_turn);

    void run();

    int get_turn();
    bool white_player_turn();
    bool black_player_turn();

    void print_board();

private:
    Player white_player_, black_player_;
    Board board_;
    std::vector<std::shared_ptr<Piece>> pieces_;
    int turn_number_;
    bool play_against_AI_;
    Engine engine_;
    std::vector<std::shared_ptr<Move>> history_;
};

#endif