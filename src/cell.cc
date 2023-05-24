#include "cell.h"

Cell::Cell(int r, char c) {
    this->row = r;
    this->column = c;
}


PieceType Cell::get_piece_type() {
    return this->p->get_piece_type();
}

char Cell::print_piece() {
    
}