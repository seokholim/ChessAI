#include "piece.h"

Piece::Piece(PieceType type, PlayerColour colour) 
    : type_{type}, colour_{colour}, starting_position_{}, position_{}, board_{}, candidate_positions_{}, moves_{}, move_history_{} {
    if (!valid_piece_type(type) || !valid_player_colour(colour)) {
        std::cout << "Piece::Piece(...) invalid construction!" << std::endl;
    }
}

Piece::~Piece() {}

void Piece::starting_position(const Position& starting_position) {
    if (!valid_position(starting_position)) {
        return;
    }
    starting_position_ = starting_position;
}

void Piece::position(const Position& position) {
    if (!valid_position(position)) {
        return;
    }
    position_ = position;
}

void Piece::set_board(ChessBoard* board) {
    if (board == nullptr) {
        std::cout << "set_board received nullptr!" << std::endl;
    }
    board_ = board;
}

bool Piece::has_board() {
    if (board_ == nullptr) {
        return false;
    }
    return true;
}

void Piece::print() const {
    std::cout<< convert_to_char(colour_, type_);
}

PieceType Piece::type() const {
    return type_;
}

PlayerColour Piece::colour() const {
    return colour_;
}

bool Piece::white() const {
    return colour_ == PlayerColour::White;
}

bool Piece::black() const {
    return colour_ == PlayerColour::Black;
}

Position Piece::position() const {
    return position_;
} 

bool Piece::in_range(const Piece* other_Piece) const { // TODO
    return false;
}

bool Piece::first_move() const {
    return move_history_.empty();
}

std::priority_queue<Move*, std::vector<Move*>, CompareMove> Piece::moves() const {
    return moves_;
}

Move* Piece::best_move() const {
    if (moves_.empty()) {
        return nullptr;
    }
    return moves_.top();
}
