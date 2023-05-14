#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "player.h"
#include "board.h"

class ChessGame {
    Player black_player, white_player;
    Board b;

  public:
    void init(); // asks humnan vs human, then players' names, then sets up board
    
    
};

#endif