#include "player.h"

Player::Player(PlayerColour player_colour) : player_colour{player_colour} {}

Player::Player(std::string name, PlayerColour player_colour) : name{name}, player_colour{player_colour} {}

void Player::set_name(std::string name) {
    this->name = name;
}

std::string Player::get_name() {
    return this->name;
}

PlayerColour Player::get_player_colour() {
    return this->player_colour;
}