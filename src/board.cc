#include "board.h"
#include <vector>
#include <iostream>
#include "info.h"

Board::Board() {
    std::vector<Cell> r;
    for (int i = 0; i < 8; ++i) { // row 1-8
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{i, 'a' + j};
            r.push_back(cell);
        }
    }
}

PieceType Board::get_piece_type_at(Position pos) {
    // convert Position to row/col
    std::pair colrow = convert_to_column_row(pos);
    return this->grid[colrow.second][colrow.first - 'a'].get_piece_type();
}

void Board::set_piece(Piece *p) {

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