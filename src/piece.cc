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

void Piece::clear_candidate_positions() {
    while (!candidate_positions_.empty()) {
        candidate_positions_.pop();
    }
}

std::queue<Position> Piece::candidate_positions() {
    return candidate_positions_;
}

void Piece::clear_moves() {
    while (!moves_.empty()) {
        moves_.pop();
    }
}

void Piece::add_move(std::shared_ptr<Move> new_move) {
    moves_.push(new_move);
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

bool Piece::in_range(const std::shared_ptr<Piece> other_Piece) const { // TODO
    return false;
}

bool Piece::first_move() const {
    return move_history_.empty();
}

std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> Piece::moves() const {
    return moves_;
}

std::shared_ptr<Move> Piece::best_move() const {
    if (moves_.empty()) {
        return nullptr;
    }
    return moves_.top();
}

void Piece::print() const {
    std::cout<< convert_to_char(colour_, type_);
}