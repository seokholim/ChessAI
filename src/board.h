#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "position.h"

class Board {
    std::vector<std::vector<Position>> grid; // 8 x 8
    
  public:
    Board();  
};

#endif