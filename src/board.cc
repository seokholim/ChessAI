#include "board.h"
#include <vector>
#include <iostream>
#include "info.h"

Board::Board() : grid(8) {
    // TODO: test that grid size is fixed to 8 x 8
    for (int i = 0; i < 8; ++i) { // row 1-8
        std::vector<Cell> row(8);
        for (int j = 0; j < 8; ++j) { // column a-h
            Cell cell{'a' + j, 1 + i};
            row[j] = cell;
        }
        grid[i] = row;
    }
}

Piece* Board::get_piece_at(Position pos) {
    std::pair colrow = convert_to_column_row(pos);
    return this->grid[colrow.second - 1][colrow.first - 'a'].get_piece();
}


std::string Board::get_piece_type_string_at(Position pos) {

}

// PieceType Board::get_piece_type_at(Position pos) {
//     // convert Position to row/col
//     std::pair colrow = convert_to_column_row(pos);
//     return this->grid[colrow.second][colrow.first - 'a'].get_piece_type();
// }

void Board::set_piece_at(Piece *p, Position pos) {

}

bool Board::empty_at(Position pos) {
    std::pair<int, char> colrow = convert_to_column_row(pos);
    return this->grid[colrow.second - 1][colrow.first - 'a'].empty();
}


void Board::print() {
    std::cout << "--------" << std::endl;
    for (int i = 0; i < 8; ++i) { // row 1-8
        for (int j = 0; j < 8; ++j) { // col a-h
            grid[i][j].print_piece();
        }
    }
    std::cout << "--------" << std::endl;
}