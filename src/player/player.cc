#include "player.h"

Player::Player(PlayerColour colour) : name_{}, colour_{colour}, pieces_{}, moves_t1_{}, moves_t2_{}, AI_{} {}

void Player::name(std::string name) {
    name_ = name;
}

std::string Player::name() const {
    return name_;
}

PlayerColour Player::colour() const {
    return colour_;
}

void Player::remove_piece(std::shared_ptr<ChessPiece> piece) {
    auto it = std::find(pieces_.begin(), pieces_.end(), piece);
    if (it == pieces_.end()) {
        std::cout << "Player::remove_piece(...); couldn't delete piece" << std::endl;
        return;
    }
    pieces_.erase(it);
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
    while(!moves_t1_.empty()) {
        moves_t1_.pop();
    }

    while(!moves_t2_.empty()) {
        moves_t2_.pop();
    }
}

void Player::generate_moves() {
    clear_moves();
    for (const auto& piece : pieces_) {
        std::shared_ptr<Move> best_move = piece->best_move();
        if (best_move != nullptr) {
            if (is_move_t1(best_move->move_type())) {
                moves_t1_.push(best_move);
            } else {
                moves_t2_.push(best_move);
            }
        }
    }
}

std::shared_ptr<Move> Player::get_best_move() const {
    if (moves_t1_.empty()) {
        if (moves_t2_.empty()) {
            return nullptr;
        }
        return moves_t2_.top();
    }
    return moves_t1_.top();
}

void Player::AI(bool AI) {
    AI_ = AI;
}

bool Player::AI() const {
    return AI_;
}