#include "board.h"
#include <vector>
#include <iostream>

Board::Board() {
    std::vector<Cell> r;
    for (int i = 0; i < 8; ++i) { // row 1-8
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{i, 'a' + j};
            r.push_back(cell);
        }
    }
}

void Board::set_pieces() {

}

void Board::print() {
    std::cout << "--------" << std::endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            grid[i][j].print_piece();
        }
    }
    std::cout << "--------" << std::endl;
}
