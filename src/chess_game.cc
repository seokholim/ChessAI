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
void ChessGame::create_piece_at(Piece* piece, Position new_pos) {
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
    this->board.create_piece_at(piece, new_pos);
    piece->notify();
    piece->calculate_moves();
}

void ChessGame::initialize_pieces() {
    std::cout << "Creating pieces for white player" << std::endl;
    Rook* white_left_rook = new Rook {PlayerColour::White};
    Rook* white_right_rook = new Rook {PlayerColour::White};
    Knight* white_left_knight = new Knight {PlayerColour::White};
    Knight* white_right_knight = new Knight {PlayerColour::White};
    Bishop* white_left_bishop = new Bishop {PlayerColour::White};
    Bishop* white_right_bishop = new Bishop {PlayerColour::White};
    Queen* white_queen = new Queen {PlayerColour::White};
    King* white_king = new King {PlayerColour::White};

    Pawn* white_pawn_1 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_2 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_3 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_4 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_5 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_6 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_7 = new Pawn {PlayerColour::White};
    Pawn* white_pawn_8 = new Pawn {PlayerColour::White};

    create_piece_at(white_left_rook, {'a', 1});
    create_piece_at(white_right_rook, {'h', 1});
    create_piece_at(white_left_knight, {'b', 1});
    create_piece_at(white_right_knight, {'g', 1});
    create_piece_at(white_left_bishop, {'c', 1});
    create_piece_at(white_right_bishop, {'f', 1});
    create_piece_at(white_queen, {'d', 1});
    create_piece_at(white_king, {'e', 1});
    create_piece_at(white_pawn_1, {'a', 2});
    create_piece_at(white_pawn_2, {'b', 2});
    create_piece_at(white_pawn_3, {'c', 2});
    create_piece_at(white_pawn_4, {'d', 2});
    create_piece_at(white_pawn_5, {'e', 2});
    create_piece_at(white_pawn_6, {'f', 2});
    create_piece_at(white_pawn_7, {'g', 2});
    create_piece_at(white_pawn_8, {'h', 2});

    std::cout << "Creating pieces for black player" << std::endl;
    Rook* black_left_rook = new Rook {PlayerColour::Black};
    Rook* black_right_rook = new Rook {PlayerColour::Black};
    Knight* black_left_knight = new Knight {PlayerColour::Black};
    Knight* black_right_knight = new Knight {PlayerColour::Black};
    Bishop* black_left_bishop = new Bishop {PlayerColour::Black};
    Bishop* black_right_bishop = new Bishop {PlayerColour::Black};
    Queen* black_queen = new Queen {PlayerColour::Black};
    King* black_king = new King {PlayerColour::Black};

    Pawn* black_pawn_1 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_2 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_3 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_4 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_5 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_6 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_7 = new Pawn {PlayerColour::Black};
    Pawn* black_pawn_8 = new Pawn {PlayerColour::Black};

    create_piece_at(black_left_rook, {'h', 8});
    create_piece_at(black_right_rook, {'a', 8});
    create_piece_at(black_left_knight, {'g', 8});
    create_piece_at(black_right_knight, {'b', 8});
    create_piece_at(black_left_bishop, {'f', 8});
    create_piece_at(black_right_bishop, {'c', 8});
    create_piece_at(black_queen, {'d', 8});
    create_piece_at(black_king, {'e', 8});
    create_piece_at(black_pawn_1, {'a', 7});
    create_piece_at(black_pawn_2, {'b', 7});
    create_piece_at(black_pawn_3, {'c', 7});
    create_piece_at(black_pawn_4, {'d', 7});
    create_piece_at(black_pawn_5, {'e', 7});
    create_piece_at(black_pawn_6, {'f', 7});
    create_piece_at(black_pawn_7, {'g', 7});
    create_piece_at(black_pawn_8, {'h', 7});


}

void ChessGame::move_piece(Position current_pos, Position new_pos) { // after checking ownership and nullity of piece. should they be checked here too?
    
}

void ChessGame::run() {
    std::cout << "Game started!" << std::endl;

    bool turn_success = true;
    std::string cmd;  

    while (true) {
        if (turn_success) {
            this->turn_number += 1;
            if (white_player_turn()) {
                std::cout << this->white_player.get_name() << "'s turn!" << std::endl;
            } else {
                std::cout << this->black_player.get_name() << "'s turn!" << std::endl;
            }
            print_board();
        } else {
            std::cout << "please try again" << std::endl;
        }

        std::cin >> cmd;

        if (cmd == "move") {
            std::string current_pos;
            std::cin >> current_pos;
            char current_column = current_pos[0];
            int current_row = current_pos[1] - '0';

            // TODO: check current_pos is valid
            Position current_position {current_column, current_row};

            if (white_player_turn() && board.get_piece_at(current_position)->white()) {
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
                turn_success = true;
            } else if (black_player_turn() && board.get_piece_at(current_position)->black()) {
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
                    turn_success = false;
                }
                turn_success = true;
            } else {
                std::cout << "The selected piece was not yours!" << std::endl;
                turn_success = false;
            }
        } else {
            std::cout << "only 'move' command possible for now, terminating chess..." << std::endl;
            break;
        }
    }
    std::cout << "Game ended!" << std::endl;
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