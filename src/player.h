#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "piece.h"
#include "info.h"

class Player {
    std::string name;
    PlayerColour player_colour;
    std::vector<Piece> pieces;
    
  public:  
    Player(PlayerColour player_colour);
    Player(std::string name, PlayerColour player_colour);
    void set_name(std::string name);
    std::string get_name();
    PlayerColour get_player_colour();
    
};

#endif