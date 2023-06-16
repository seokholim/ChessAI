#include "cell.h"
#include <iostream>

Cell::Cell() {}

Cell::Cell(char column, int row) {
    this->column = column;
    this->row = row;
    this->piece = nullptr;
}

void Cell::set_piece(Piece* piece) {
    if (piece != nullptr) {
        Position new_pos {this->column, this->row};
        piece->set_position(new_pos);
        this->piece = piece;
    }
}

void Cell::remove_piece() {
    this->piece = nullptr;
}

Piece* Cell::get_piece() {
    return this->piece;
}

bool Cell::empty() {
    return this->piece == nullptr;
}

void Cell::print() {
    if (this->piece != nullptr) {
        this->piece->print();
    } else {
        std::cout << ' ';
    }
}