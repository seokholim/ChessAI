#include "cell.h"

Cell::Cell() : column{}, row{}, piece{} {}

Cell::Cell(char column, int row) : column{column}, row{row}, piece{} {}

void Cell::set_piece(Piece* piece) {
    if (piece == nullptr) {
        std::cout << "Cell:set_piece; piece is nullptr!" << std::endl;
    } else {
        this->piece = piece;
    }
}

Piece* Cell::get_piece() {
    return piece;
}

void Cell::remove_piece() {
    piece = nullptr;
}

void Cell::delete_piece() {

}

bool Cell::empty() {
    return piece == nullptr;
}