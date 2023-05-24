#include <iostream>
#include <string>
#include "chess_game.h"

ChessGame::ChessGame() : turn_number{0} {}

void ChessGame::init() {
    std::cout << "initializing" << std::endl;
    
    std::string white_player_name, black_player_name;
    std::cout << "White player's name: " << std::endl;
    std::getline(std::cin, white_player_name);
    this->white_player = Player(white_player_name, PlayerColour::White);

    std::cout << "Black player's name: " << std::endl;
    std::getline(std::cin, black_player_name);
    this->black_player = Player(black_player_name, PlayerColour::Black);

    std::cout << "Setting up board" << std::endl;
    this->board = Board(); // empty board
    initialize_pieces();
    this->board.print();
}

void ChessGame::initialize_pieces() {
    
}

void ChessGame::play() {
    std::cout << "Game started!" << std::endl;
    this->turn_number += 1;

    std::string cmd;
    while (true) {
        if (turn_number % 2 == 1) { // white player's turn
            std::cout << this->white_player.get_name() << "'s turn!" << std::endl;
        } else {
            std::cout << this->black_player.get_name() << "'s turn!" << std::endl;
        }
        std::cin >> cmd;

        if (cmd == "move") {
            std::string current_pos;
            std::cin >> current_pos;

            char current_column = current_pos[0];
            int current_row = current_pos[1] - '0'; // TO DO: check input

            Position current_position = convert_to_position(current_column, current_row);
            std::cout << this->board.get_piece_type_string_at(current_position) << " selected" << std::endl;
            
        }
    }

}

int ChessGame::get_turn() {
    return this->turn_number;
}