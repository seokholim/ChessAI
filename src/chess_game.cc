#include <iostream>
#include <sstream>
#include <string>
#include "chess_game.h"

ChessGame::ChessGame() : white_player{PlayerColour::White}, black_player{PlayerColour::Black}, board{}, turn_number{0} {} // TODO: players setup

void ChessGame::initialize_players() {
    std::cout << "Choose game type! 1 - play against AI 2 - play against human" << std::endl;
    std::string cmd;

    while (true) {
        std::cin >> cmd;
        std::istringstream ss {cmd};
        int game_type;
        ss >> game_type;
        if (game_type == 1) {
            this->play_against_AI = true;
            std::string white_player_name;
            std::cout << "- 백색 플레이어의 이름을 입력하세요: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, white_player_name);
            this->white_player.set_name(white_player_name);

            this->black_player.set_name("AI Level 1");
            break;
        } else if (game_type == 2) {
            this->play_against_AI = false;
            std::string white_player_name, black_player_name;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "- 백색 플레이어의 이름을 입력하세요: ";
            std::getline(std::cin, white_player_name);
            this->white_player.set_name(white_player_name);

            std::cout << "- 흑색 플레이어의 이름을 입력하세요: ";
            std::getline(std::cin, black_player_name);
            this->black_player.set_name(black_player_name);
            break;
        } else {
            std::cout << "please choose again!" << std::endl;
        }
    }
}

void ChessGame::create_piece_on(Piece* piece, Position new_pos) {
    std::vector <Piece*> pieces_on_board = board.get_pieces();
    for (auto it = pieces_on_board.begin(); it != pieces_on_board.end(); ++it) {
        (*it)->attach(piece);
        piece->attach(*it);
    }
    this->board.create_piece_on(piece, new_pos);
    piece->notify();
    piece->calculate_moves();
}

void ChessGame::initialize_pieces() {  // TODO: use smart pointers
    // Initializing for white player
    Rook* white_left_rook = new Rook {PlayerColour::White};
    white_player.add_piece(white_left_rook);
    Rook* white_right_rook = new Rook {PlayerColour::White};
    white_player.add_piece(white_right_rook);
    Knight* white_left_knight = new Knight {PlayerColour::White};
    white_player.add_piece(white_left_knight);
    Knight* white_right_knight = new Knight {PlayerColour::White};
    white_player.add_piece(white_right_knight);
    Bishop* white_left_bishop = new Bishop {PlayerColour::White};
    white_player.add_piece(white_left_bishop);
    Bishop* white_right_bishop = new Bishop {PlayerColour::White};
    white_player.add_piece(white_right_bishop);
    Queen* white_queen = new Queen {PlayerColour::White};
    white_player.add_piece(white_queen);
    King* white_king = new King {PlayerColour::White};
    white_player.add_piece(white_king);

    Pawn* white_pawn_1 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_1);
    Pawn* white_pawn_2 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_2);
    Pawn* white_pawn_3 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_3);
    Pawn* white_pawn_4 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_4);
    Pawn* white_pawn_5 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_5);
    Pawn* white_pawn_6 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_6);
    Pawn* white_pawn_7 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_7);
    Pawn* white_pawn_8 = new Pawn {PlayerColour::White};
    white_player.add_piece(white_pawn_8);

    create_piece_on(white_left_rook, {'a', 1});
    create_piece_on(white_right_rook, {'h', 1});
    create_piece_on(white_left_knight, {'b', 1});
    create_piece_on(white_right_knight, {'g', 1});
    create_piece_on(white_left_bishop, {'c', 1});
    create_piece_on(white_right_bishop, {'f', 1});
    create_piece_on(white_queen, {'d', 1});
    create_piece_on(white_king, {'e', 1});
    create_piece_on(white_pawn_1, {'a', 2});
    create_piece_on(white_pawn_2, {'b', 2});
    create_piece_on(white_pawn_3, {'c', 2});
    create_piece_on(white_pawn_4, {'d', 2});
    create_piece_on(white_pawn_5, {'e', 2});
    create_piece_on(white_pawn_6, {'f', 2});
    create_piece_on(white_pawn_7, {'g', 2});
    create_piece_on(white_pawn_8, {'h', 2});    
    
    // Initializing for black player
    Rook* black_left_rook = new Rook {PlayerColour::Black};
    black_player.add_piece(black_left_rook);
    Rook* black_right_rook = new Rook {PlayerColour::Black};
    black_player.add_piece(black_right_rook);
    Knight* black_left_knight = new Knight {PlayerColour::Black};
    black_player.add_piece(black_left_knight);
    Knight* black_right_knight = new Knight {PlayerColour::Black};
    black_player.add_piece(black_right_knight);
    Bishop* black_left_bishop = new Bishop {PlayerColour::Black};
    black_player.add_piece(black_left_bishop);
    Bishop* black_right_bishop = new Bishop {PlayerColour::Black};
    black_player.add_piece(black_right_bishop);
    Queen* black_queen = new Queen {PlayerColour::Black};
    black_player.add_piece(black_queen);
    King* black_king = new King {PlayerColour::Black};
    black_player.add_piece(black_king);

    Pawn* black_pawn_1 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_1);
    Pawn* black_pawn_2 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_2);
    Pawn* black_pawn_3 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_3);
    Pawn* black_pawn_4 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_4);
    Pawn* black_pawn_5 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_5);
    Pawn* black_pawn_6 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_6);
    Pawn* black_pawn_7 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_7);
    Pawn* black_pawn_8 = new Pawn {PlayerColour::Black};
    black_player.add_piece(black_pawn_8);

    create_piece_on(black_left_rook, {'h', 8});
    create_piece_on(black_right_rook, {'a', 8});
    create_piece_on(black_left_knight, {'g', 8});
    create_piece_on(black_right_knight, {'b', 8});
    create_piece_on(black_left_bishop, {'f', 8});
    create_piece_on(black_right_bishop, {'c', 8});
    create_piece_on(black_queen, {'d', 8});
    create_piece_on(black_king, {'e', 8});
    create_piece_on(black_pawn_1, {'a', 7});
    create_piece_on(black_pawn_2, {'b', 7});
    create_piece_on(black_pawn_3, {'c', 7});
    create_piece_on(black_pawn_4, {'d', 7});
    create_piece_on(black_pawn_5, {'e', 7});
    create_piece_on(black_pawn_6, {'f', 7});
    create_piece_on(black_pawn_7, {'g', 7});
    create_piece_on(black_pawn_8, {'h', 7});
}

void ChessGame::move_piece(Position current_pos, Position new_pos) { // after checking ownership and nullity of piece. should they be checked here too?
    board.move_piece(current_pos, new_pos);
    board.get_piece_on(new_pos)->notify();
    board.get_piece_on(new_pos)->calculate_moves();
}

void ChessGame::select_move_from(Position pos) {


}

void ChessGame::select_move_to(Position pos) {
    
}

void ChessGame::AI_play() {
    black_player.generate_moves();
    Move* best_move = black_player.get_best_move();
    board.move_piece(best_move->get_move_from(), best_move->get_move_to());
    board.get_piece_on(best_move->get_move_to())->notify();
    board.get_piece_on(best_move->get_move_to())->calculate_moves();
    
    int n_best_moves = 5;
    for (int i = 0; i < n_best_moves; ++i) {
        if (black_player.get_best_move() == nullptr) {
            std::cout << "no more best moves" << std::endl;
            break;
        }
        best_move = black_player.get_best_move();
        std::cout << i <<  " - best move was: move from " << best_move->get_move_from().column << best_move->get_move_from().row;
        std::cout << " to " << best_move->get_move_to().column << best_move->get_move_to().row << std::endl;
        black_player.remove_best_move();
    }
}

void ChessGame::run() {
    bool turn_success = true;
    bool move_from_selected = false;
    bool move_to_selected = false;
    Piece* selected_piece = nullptr;

    std::string cmd;  
    while (true) {
        if (turn_success) {
            this->turn_number += 1;
            move_from_selected = move_to_selected = turn_success = false;
            if (white_player_turn()) {
                std::cout << "- " << this->white_player.get_name() << "의 차례!" << std::endl;
            } else {
                if (play_against_AI) {
                    AI_play();
                    turn_success = true;
                    continue;

                } else {
                    std::cout << "- " << this->black_player.get_name() << "의 차례!" << std::endl;
                }
            }
            print_board();
        }

        if (!move_from_selected) {
            std::cout << "- 체스말을 선택하거나 옮겨주세요 : ";
        } else if (!move_to_selected) {
            std::cout << "- 어디로 옮기시겠습니까? : ";
        }

        std::cin >> cmd;
        if (cmd == "quit" || cmd == "exit") {
            std::cout << "- 게임을 종료합니다......" << std::endl;
            break;
        } else {
            if (!move_from_selected) {
                char current_column = cmd[0];
                int current_row = cmd[1] - '0';
                Position current_position {current_column, current_row};
                if (!valid_position(current_position)) {
                    std::cout << "- 체스말을 선택할 수 없는 장소입니다! ";
                    continue;
                } 
                selected_piece = this->board.get_piece_on(current_position);
                if (selected_piece == nullptr) {
                    std::cout << "- 움직일 수 있는 체스말이 없습니다! ";
                    continue;
                } 
                if ((white_player_turn() && selected_piece->white())
                ||  (black_player_turn() && selected_piece->black())) {
                    print_board();
                    std::cout << "- ";
                    selected_piece->print(); 
                    std::cout << " 를 고르셨습니다. 움직일 수 있는 장소는 다음과 같습니다." << std::endl;
                    std::cout << "[ ";
                    std::vector<Move*> possible_moves = selected_piece->get_moves();
                    for (int i = 0; i < possible_moves.size(); ++i) {
                        Position res = possible_moves[i]->get_move_to();
                        std::cout << res.column << res.row << ' ';
                    }
                    std::cout << "]" << std::endl;
                    move_from_selected = true;
                } else {
                    std::cout << "- 자신의 체스말이 아닙니다!" << std::endl;
                }
            } else if (!move_to_selected) {
                char new_column = cmd[0];
                int new_row = cmd[1] - '0';
                Position new_position {new_column, new_row};
                if (!valid_position(new_position)) {
                    std::cout << "- 움직일 수 없는 장소입니다! ";
                    continue;
                } 
                std::vector<Move*> possible_moves = selected_piece->get_moves();
                bool move_found = false;
                for (auto move : possible_moves) {
                    if (move->get_move_to() == new_position) {
                        move_found = true;
                        Piece* piece_on_new_position = board.get_piece_on(new_position);
                        if (piece_on_new_position != nullptr) { // TODO: improve
                            piece_on_new_position->empty_moves();
                            for (auto ob : board.get_pieces()) {
                                ob->detach(piece_on_new_position);
                            }
                        }
                        move_piece(selected_piece->get_position(), new_position);
                        break;
                    }
                }
                if (move_found) {
                    turn_success = true;
                } else {
                    std::cout << "- 움직일 수 없는 장소입니다! ";
                }
            } else {
                std::cout << "- 자신의 체스말이 아닙니다! " << std::endl;
            }
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
    this->board.print(white_player_turn());
}