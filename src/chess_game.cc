#include <iostream>
#include <string>
#include "chess_game.h"

ChessGame::ChessGame() {}

void ChessGame::init() {
    std::cout << "initializing" << std::endl;
    
    std::string white_player_name, black_player_name;
    std::cout << "White player's name: " << std::endl;
    std::getline(std::cin, white_player_name);
    this->white_player = Player(white_player_name);

    std::cout << "Black player's name: " << std::endl;
    std::getline(std::cin, black_player_name);
    this->black_player = Player(black_player_name);

    std::cout << "setting up board" << std::endl;
    this->b = Board();
}