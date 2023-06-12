#include "cell.h"

Cell::Cell() {}

Cell::Cell(char column, int row) {
    this->column = column;
    this->row = row;
}

void Cell::set_piece(Piece* piece) {
    this->piece = piece;
}

Piece* Cell::get_piece() {
    return this->piece;
}

bool Cell::empty() {
    return this->piece == nullptr;
}

char Cell::print() {
    return this->piece->print();
}