#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "cell.h"

class Board {
    std::vector<std::vector<Cell>> grid; // 8 x 8

  public:
    Board();
    void set_pieces();
    void print();
};

#endif