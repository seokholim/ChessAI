#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <algorithm>
#include "player.h"
#include "board.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"

class ChessGame {
    Player white_player, black_player; // always there til game ends
    Board board; // always there til game ends
    int turn_number;
    std::vector<Move*> history;
    bool play_against_AI;

  public:
    ChessGame();

    void initialize_players();

    void create_piece_on(Piece* piece, Position pos);
    void initialize_pieces();

    void move_piece(Position current_pos, Position new_pos);
    void undo();

    void AI_play();

    void select_move_from(Position pos);
    void select_move_to(Position pos);
    void run();

    int get_turn();
    bool white_player_turn();
    bool black_player_turn();

    void print_board();

};

#endif