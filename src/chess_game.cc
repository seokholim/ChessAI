#include <iostream>
#include <string>
#include "chess_game.h"
#include "rook.h"


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

    std::cout << "Creating pieces" << std::endl;
    Rook* r1 = new Rook {&(this->white_player)};
    this->board.set_piece_at(r1, {'a', 1});

    Rook* r2 = new Rook {&(this->black_player)};
    this->board.set_piece_at(r2, {'h', 8});
}

void ChessGame::start() {
    std::cout << "Game started!" << std::endl;

    std::string cmd;
    while (true) {
        this->turn_number += 1;
        if (white_player_turn()) {
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

            Piece* selected_piece = this->board.get_piece_at(current_position);
            if (selected_piece != nullptr) {
                std::cout << selected_piece->print() << " selected" << std::endl;
                std::vector<Move*> possible_moves = selected_piece->get_moves();
                std::cout << "You have the following moves:";
                for (int i = 0; i < possible_moves.size(); ++i) {
                    Position res = possible_moves[i]->get_move_to();
                    std::cout << res.column << res.row << ' ';
                }
                std::cout << std::endl;
            } else {
                std::cout << "no piece found in that position!" << std::endl;
            }
            
            break; // testing turn 1
        }
    }

}

int ChessGame::get_turn() {
    return this->turn_number;
}

bool ChessGame::white_player_turn() {
    return (this->turn_number % 2) == 1; 
}

bool ChessGame::black_player_turn() {
    return (this->turn_number % 2) == 0; 
}