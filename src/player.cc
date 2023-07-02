#include "player.h"

Player::Player(PlayerColour colour) : name_{}, colour_{colour}, pieces_{}, moves_{}, AI_{} {}

void Player::name(std::string name) {
    name_ = name;
}

std::string Player::name() const {
    return name_;
}

PlayerColour Player::colour() const {
    return colour_;
}

void Player::add_piece(std::shared_ptr<ChessPiece> piece) {
    if (piece == nullptr) {
        return;
    }
    pieces_.push_back(piece);
}

void Player::add_pieces(std::vector<std::shared_ptr<ChessPiece>> pieces) {
    pieces_.insert(pieces_.end(), pieces.begin(), pieces.end());
}

std::vector<std::shared_ptr<ChessPiece>> Player::get_pieces() const {
    return pieces_;
}

void Player::clear_moves() {
    while(!moves_.empty()) {
        moves_.pop();
    }
}

void Player::generate_moves() { // TODO
    clear_moves();
}

void Player::remove_best_move() {
    if (moves_.empty()) {
        return;
    }
    moves_.pop();
}

std::shared_ptr<Move> Player::get_best_move() {
    if (moves_.empty()) {
        return nullptr;
    }
    return moves_.top();
}

void Player::AI(bool AI) {
    AI_ = AI;
}

bool Player::AI() {
    return AI_;
}