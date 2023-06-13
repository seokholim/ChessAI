#include <iostream>
#include <string>
#include "chess_game.h"

ChessGame::ChessGame() : turn_number{0}, white_player{PlayerColour::White}, black_player{PlayerColour::Black}, board{} {}

void ChessGame::initialize_players() {    
    std::string white_player_name, black_player_name;
    std::cout << "White player's name: " << std::endl;
    std::getline(std::cin, white_player_name);
    this->white_player.set_name(white_player_name);

    std::cout << "Black player's name: " << std::endl;
    std::getline(std::cin, black_player_name);
    this->black_player.set_name(black_player_name);
}

// set_piece_at(...) calls Board::set_piece_at(...) with observer method
void ChessGame::set_piece_at(Piece* piece, Position new_pos) {
    std::cout << "ChessGame::set_piece_at called" << std::endl;
    // TODO: try catch
    // try {
    //     this->board.set_piece_at(piece, new_pos);
    // } catch (const std::exception& e) {
    //     std::cout << " a standard exception was caught, with message '"
    //               << e.what() << "'\n";
    // }
    // std::cout << "after catch block" << std::endl;
    std::vector <Piece*> pieces_on_board = board.get_pieces(); // use a pointer to vec?
    for (auto it = pieces_on_board.begin(); it != pieces_on_board.end(); ++it) {
        (*it)->attach(piece);
        piece->attach(*it);
    }
    this->board.set_piece_at(piece, new_pos);
    piece->notify();
    piece->calculate_moves();
}

void ChessGame::initialize_pieces() {
    std::cout << "Creating pieces" << std::endl;
    Rook* r1 = new Rook {PlayerColour::White};
    std::cout << "r1 made" << std::endl;
    set_piece_at(r1, {'a', 1});
    std::cout << "r1 set on board" << std::endl;

    Rook* r2 = new Rook {PlayerColour::Black};
    std::cout << "r2 made" << std::endl;
    set_piece_at(r2, {'b', 1});
    std::cout << "r2 set on board" << std::endl;
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
        print_board();

        // TODO: white can only move white pieces
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
                selected_piece->print(); 
                std::cout << " selected" << std::endl;
                std::vector<Move*> possible_moves = selected_piece->get_moves();
                std::cout << "You have " << possible_moves.size() << " moves:";
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

void ChessGame::print_board() {
    this->board.print();
}