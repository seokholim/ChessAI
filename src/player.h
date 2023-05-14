#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
    std::string name;
  public:  
    Player(std::string name);
    std::string get_name();
    
};

#endif