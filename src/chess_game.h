#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "player.h"
#include "board.h"

class ChessGame {
    Player black_player, white_player;
    Board board;
    int turn_number;

  public:
    ChessGame();
    void set_piece_at(Piece* piece, Position pos);
    void initialize_board();
    void initialize_players(); // TODO: asks human vs human, then players' names, then sets up board
    void start();
    int get_turn();
    bool white_player_turn();
    bool black_player_turn();
    void print_board();

};

#endif