#ifndef CHESS_GAME_H
#define CHESS_GAME_H
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

  public:
    ChessGame();
    void create_piece_at(Piece* piece, Position pos);
    void initialize_pieces();
    void move_piece(Position current_pos, Position new_pos);
    void initialize_players(); // TODO: asks human vs human, then players' names, then sets up board
    void run();
    int get_turn();
    bool white_player_turn();
    bool black_player_turn();
    void print_board(bool white_perspective);

};

#endif