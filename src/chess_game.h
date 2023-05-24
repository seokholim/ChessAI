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
    void initialize_pieces();
    void init(); // asks humnan vs human, then players' names, then sets up board
    void play();
    int get_turn();
    
};

#endif