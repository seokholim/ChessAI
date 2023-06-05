#include <iostream>
#include <string>
#include "chess_game.h"

ChessGame::ChessGame() : turn_number{0} {}

void ChessGame::initialize_players() {    
    std::string white_player_name, black_player_name;
    std::cout << "White player's name: " << std::endl;
    std::getline(std::cin, white_player_name);
    this->white_player = Player(white_player_name, PlayerColour::White);

    std::cout << "Black player's name: " << std::endl;
    std::getline(std::cin, black_player_name);
    this->black_player = Player(black_player_name, PlayerColour::Black);
}

void ChessGame::initialize_board() {
    std::cout << "Setting up board" << std::endl;
    this->board = Board();



}

void ChessGame::start() {
    std::cout << "Game started!" << std::endl;

    if (this->turn_number != 0) {
        std::cout << "TURN NUMBER NOT ZERO WHEN GAME STARTING" << std::endl;
    }

    std::string cmd;
    while (true) {
        this->turn_number += 1;
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
            int current_row = current_pos[1] - '0';

            // TODO: check current_pos is valid

            Position current_position {current_column, current_row};
            std::cout << this->board.get_piece_type_string_at(current_position) << " selected" << std::endl;
            
            std::vector<Move*> possible_moves = this->board.get_piece_at(current_position)->get_moves();
            std::cout << "You have the following moves:";
            for (int i = 0; i < possible_moves.size(); ++i) {
                Position res = possible_moves[i]->get_move_to();
                std::cout << res.column << res.row;
            }
            std::cout << std::endl;

            break;
        }
    }

}

int ChessGame::get_turn() {
    return this->turn_number;
}