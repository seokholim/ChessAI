#include "cell.h"

// public:
Cell::Cell() : column{}, row{}, piece{} {}

Cell::Cell(char column, int row) : column{column}, row{row}, piece{} {}

ChessPiece* Cell::get_piece() const {
    return piece;
}

bool Cell::empty() const {
    return piece == nullptr;
}

// private:
void Cell::set_piece(ChessPiece* piece) {
    if (piece == nullptr) {
        std::cout << "Cell:set_piece; piece is nullptr!" << std::endl;
    } else {
        this->piece = piece;
    }
}

void Cell::remove_piece() {
    piece = nullptr;
}

void Cell::delete_piece() {

}