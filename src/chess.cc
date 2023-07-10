#include "chess.h"

Chess::Chess() : white_player_{PlayerColour::White}, black_player_{PlayerColour::Black}, board_{}, turn_number_{0}, play_against_White_{false}, play_against_Black_{false}, play_against_Human_{false}, engine_{} {}

Chess::~Chess() {}

void Chess::init() {
    initialize_players();
    initialize_pieces();
}

void Chess::initialize_players() {
    std::cout << "- Please choose the game type." << std::endl <<  "(1) Play against AI" << std::endl << "(2) Play against human" << std::endl << ": ";
    std::string cmd;

    while (true) {
        std::cin >> cmd;
        std::istringstream ss {cmd};
        int game_type;
        ss >> game_type;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (game_type == 1) {
            std::cout << "- You have selected <(1) Play against AI>." << std::endl <<  "- Please choose the player colour." << std::endl;
            std::cout << "(a) Play as White " << std::endl << "(b) Play as Black " << std::endl << ": ";
            while (true) {
                std::cin >> cmd;
                std::istringstream ss {cmd};
                char white_or_black;
                ss >> white_or_black;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (white_or_black == 'a') {
                    play_against_Black_ = true;
                    std::string white_player_name;
                    std::cout << "- White Player's name: ";
                    std::getline(std::cin, white_player_name);
                    white_player_.name(white_player_name);

                    black_player_.name("Black_AI");
                    black_player_.AI(true);
                    std::cout << std::endl;
                    break;
                } else if (white_or_black == 'b') {
                    play_against_White_ = true;
                    std::string black_player_name;
                    std::cout << "- Black Player's name: ";
                    std::getline(std::cin, black_player_name);
                    black_player_.name(black_player_name);

                    white_player_.name("White_AI");
                    white_player_.AI(true);
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "please choose again!" << std::endl;
                }
            }
            if (play_against_White_ || play_against_Black_) break;
        } else if (game_type == 2) {
            play_against_Human_ = true;
            std::string white_player_name, black_player_name;
            std::cout << "- White Player name: ";
            std::getline(std::cin, white_player_name);
            white_player_.name(white_player_name);

            std::cout << "- Black Player name: ";
            std::getline(std::cin, black_player_name);
            black_player_.name(black_player_name);
            break;
        } else {
            std::cout << "please choose again!" << std::endl;
        }
    }
}

void Chess::create_piece_on(std::shared_ptr<Piece> new_piece, const Position& starting_position) {
    if (new_piece == nullptr) {
        return;
    } else if (!new_piece->has_board()) {
        return;
    }

    for (const auto& piece : pieces_) {
        piece->attach(new_piece);
        new_piece->attach(piece);
    }
    pieces_.push_back(new_piece);
    new_piece->starting_position(starting_position);
    new_piece->position(starting_position);
    new_piece->notify();
    new_piece->generate_candidate_positions();

    // add ChessPiece interface to board and player
    std::shared_ptr<ChessPiece> new_chess_piece = std::make_shared<ChessPiece>(new_piece);
    board_.create_piece_on(new_chess_piece, starting_position);
    if (new_chess_piece->white()) {
        white_player_.add_piece(new_chess_piece);
    } else {
        black_player_.add_piece(new_chess_piece);
    }
}

void Chess::initialize_pieces() {
    Board* board = &board_;
    std::shared_ptr<ChessBoard> chess_board = std::make_shared<ChessBoard>(board);

    // Initializing for white_player_
    // White Rooks
    std::shared_ptr<Rook> white_left_rook = std::make_shared<Rook>(PlayerColour::White);
    std::shared_ptr<Rook> white_right_rook = std::make_shared<Rook>(PlayerColour::White);
    white_left_rook->set_board(chess_board);
    white_right_rook->set_board(chess_board);
    create_piece_on(white_left_rook, {'a', 1});
    create_piece_on(white_right_rook, {'h', 1});

    // White Knights
    std::shared_ptr<Knight> white_left_knight = std::make_shared<Knight>(PlayerColour::White);
    std::shared_ptr<Knight> white_right_knight = std::make_shared<Knight>(PlayerColour::White);
    white_left_knight->set_board(chess_board);
    white_right_knight->set_board(chess_board);
    create_piece_on(white_left_knight, {'b', 1});
    create_piece_on(white_right_knight, {'g', 1});

    // White Bishops
    std::shared_ptr<Bishop> white_left_bishop = std::make_shared<Bishop>(PlayerColour::White);
    std::shared_ptr<Bishop> white_right_bishop = std::make_shared<Bishop>(PlayerColour::White);
    white_left_bishop->set_board(chess_board);
    white_right_bishop->set_board(chess_board);
    create_piece_on(white_left_bishop, {'c', 1});
    create_piece_on(white_right_bishop, {'f', 1});

    // White Queen
    std::shared_ptr<Queen> white_queen = std::make_shared<Queen>(PlayerColour::White);
    white_queen->set_board(chess_board);
    create_piece_on(white_queen, {'d', 1});

    // White King
    std::shared_ptr<King> white_king = std::make_shared<King>(PlayerColour::White);
    white_king->set_board(chess_board);
    create_piece_on(white_king, {'e', 1});

    // White Pawns
    std::shared_ptr<Pawn> white_pawn_1 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_2 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_3 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_4 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_5 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_6 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_7 = std::make_shared<Pawn>(PlayerColour::White);
    std::shared_ptr<Pawn> white_pawn_8 = std::make_shared<Pawn>(PlayerColour::White);
    white_pawn_1->set_board(chess_board);
    white_pawn_2->set_board(chess_board);
    white_pawn_3->set_board(chess_board);
    white_pawn_4->set_board(chess_board);
    white_pawn_5->set_board(chess_board);
    white_pawn_6->set_board(chess_board);
    white_pawn_7->set_board(chess_board);
    white_pawn_8->set_board(chess_board);
    create_piece_on(white_pawn_1, {'a', 2});
    create_piece_on(white_pawn_2, {'b', 2});
    create_piece_on(white_pawn_3, {'c', 2});
    create_piece_on(white_pawn_4, {'d', 2});
    create_piece_on(white_pawn_5, {'e', 2});
    create_piece_on(white_pawn_6, {'f', 2});
    create_piece_on(white_pawn_7, {'g', 2});
    create_piece_on(white_pawn_8, {'h', 2});


    // Initializing for black player
    // Black Rooks
    std::shared_ptr<Rook> black_left_rook = std::make_shared<Rook>(PlayerColour::Black);
    std::shared_ptr<Rook> black_right_rook = std::make_shared<Rook>(PlayerColour::Black);
    black_left_rook->set_board(chess_board);
    black_right_rook->set_board(chess_board);
    create_piece_on(black_left_rook, {'h', 8});
    create_piece_on(black_right_rook, {'a', 8});

    // Black Knights
    std::shared_ptr<Knight> black_left_knight = std::make_shared<Knight>(PlayerColour::Black);
    std::shared_ptr<Knight> black_right_knight = std::make_shared<Knight>(PlayerColour::Black);
    black_left_knight->set_board(chess_board);
    black_right_knight->set_board(chess_board);
    create_piece_on(black_left_knight, {'g', 8});
    create_piece_on(black_right_knight, {'b', 8});

    // Black Bishops
    std::shared_ptr<Bishop> black_left_bishop = std::make_shared<Bishop>(PlayerColour::Black);
    std::shared_ptr<Bishop> black_right_bishop = std::make_shared<Bishop>(PlayerColour::Black);
    black_left_bishop->set_board(chess_board);
    black_right_bishop->set_board(chess_board);
    create_piece_on(black_left_bishop, {'f', 8});
    create_piece_on(black_right_bishop, {'c', 8});

    // Black Queen
    std::shared_ptr<Queen> black_queen = std::make_shared<Queen>(PlayerColour::Black);
    black_queen->set_board(chess_board);
    create_piece_on(black_queen, {'d', 8});

    // Black King
    std::shared_ptr<King> black_king = std::make_shared<King>(PlayerColour::Black);
    black_king->set_board(chess_board);
    create_piece_on(black_king, {'e', 8});

    // Black Pawns
    std::shared_ptr<Pawn> black_pawn_1 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_2 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_3 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_4 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_5 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_6 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_7 = std::make_shared<Pawn>(PlayerColour::Black);
    std::shared_ptr<Pawn> black_pawn_8 = std::make_shared<Pawn>(PlayerColour::Black);
    black_pawn_1->set_board(chess_board);
    black_pawn_2->set_board(chess_board);
    black_pawn_3->set_board(chess_board);
    black_pawn_4->set_board(chess_board);
    black_pawn_5->set_board(chess_board);
    black_pawn_6->set_board(chess_board);
    black_pawn_7->set_board(chess_board);
    black_pawn_8->set_board(chess_board);
    create_piece_on(black_pawn_1, {'a', 7});
    create_piece_on(black_pawn_2, {'b', 7});
    create_piece_on(black_pawn_3, {'c', 7});
    create_piece_on(black_pawn_4, {'d', 7});
    create_piece_on(black_pawn_5, {'e', 7});
    create_piece_on(black_pawn_6, {'f', 7});
    create_piece_on(black_pawn_7, {'g', 7});
    create_piece_on(black_pawn_8, {'h', 7});

    // std::cout << "chessboard count " << chess_board.use_count() << std::endl; // 33
}

bool Chess::valid_move(std::shared_ptr<Move> move) {
    if (move == nullptr) {
        return false;
    }
    // Checking ChessPiece interface is valid for new_move
    if (move->moving_piece() == nullptr || move->moving_piece()->data_ == nullptr) {
        return false;
    }
    if (move->occupying_piece() != nullptr && move->occupying_piece()->data_ == nullptr) {
        return false;
    }
    return true;
}

void Chess::move(std::shared_ptr<Move> new_move) {
    if (!valid_move(new_move)) {
        std::cout << "Chess::move(...); move is not valid" << std::endl;
        return;
    }
    history_.push_back(new_move);
    std::shared_ptr<Piece> moving_piece = new_move->moving_piece()->data_;
    if (new_move->occupied()) { // capture logic
        std::shared_ptr<Piece> occupying_piece = new_move->occupying_piece()->data_;
        auto it = std::find(pieces_.begin(), pieces_.end(), occupying_piece);
        if (it == pieces_.end()) {
            std::cout << "Chess::move(...); pieces_ doesn't contain the occupying piece!" << std::endl;
            return;
        }
        for (auto piece : pieces_) {
            piece->detach(*it);
            (*it)->detach(piece);
        }
        pieces_.erase(it);
        if (occupying_piece->white()) {
            white_player_.remove_piece(new_move->occupying_piece());
        } else {
            black_player_.remove_piece(new_move->occupying_piece());
        }
    }
    board_.move(new_move->move_from(), new_move->move_to());
    moving_piece->add_to_history(new_move);
    moving_piece->position(new_move->move_to());
    moving_piece->notify();
    moving_piece->generate_candidate_positions();
}

std::shared_ptr<Move> Chess::AI_play(bool white_player_turn) {
    std::shared_ptr<Move> best_move;
    if (white_player_turn) {
        white_player_.generate_moves();
        best_move = white_player_.get_best_move();
    } else {
        black_player_.generate_moves();
        best_move = black_player_.get_best_move();
    }
    return best_move;
}

void Chess::run() {
    bool turn_success = true;
    bool move_from_selected = false;
    bool move_to_selected = false;
    std::shared_ptr<ChessPiece> selected_piece = nullptr;

    std::string cmd;  
    while (true) {
        if (turn_success) {
            turn_number_ += 1;
            std::cout << "*** Turn: " << turn_number_ << " ***" << std::endl;
            print_board();
            move_from_selected = move_to_selected = turn_success = false;
            if (white_player_turn()) {
                std::cout << "- " << white_player_.name() << "'s turn!" << std::endl;
                engine_.generate_moves_for_pieces(white_player_.get_pieces(), play_against_White_);
                if (play_against_White_) {
                    std::shared_ptr<Move> AI_move = AI_play(white_player_turn());
                    if (AI_move == nullptr) { // No move to play for AI;
                        std::cout << "- White has no move to play! Black wins!" << std::endl;
                        break;
                    }
                    move(AI_move);
                    turn_success = true;
                    continue;
                }
            } else {
                std::cout << "- " << black_player_.name() << "'s turn!" << std::endl;
                engine_.generate_moves_for_pieces(black_player_.get_pieces(), play_against_Black_);
                if (play_against_Black_) {
                    std::shared_ptr<Move> AI_move = AI_play(white_player_turn());
                    if (AI_move == nullptr) { // No move to play for AI;
                        std::cout << "- Black has no move to play! White wins!" << std::endl;
                        break;
                    }
                    move(AI_move);
                    turn_success = true;
                    continue;
                }
            }
        }

        if (!move_from_selected) {
            std::cout << "- Please choose a piece to move : ";
        } else if (!move_to_selected) {
            std::cout << "- Where do you want to move it? : ";
        }

        std::cin >> cmd;
        if (cmd == "quit" || cmd == "exit") {
            std::cout << "- Terminating......" << std::endl;
            break;
        } else {
            if (!move_from_selected) {
                char current_column = cmd[0];
                int current_row = cmd[1] - '0';
                Position current_position {current_column, current_row};
                if (!valid_position(current_position)) {
                    std::cout << "- You can't select a piece there! " << std::endl;
                    continue;
                }
                selected_piece = board_.get_piece_on(current_position);
                if (selected_piece == nullptr) {
                    std::cout << "- There is no piece to move! " << std::endl;
                    continue;
                } 
                if ((white_player_turn() && selected_piece->white())
                ||  (black_player_turn() && selected_piece->black())) {
                    print_board();
                    std::cout << "- ";
                    selected_piece->print(); 
                    std::cout << " was selected. The piece has the following moves: " << std::endl;
                    std::cout << "[ ";
                    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> candidate_moves_t1 = selected_piece->data_->moves_t1();
                    int total_candidate_size = 0;
                    int candidate_moves_t1_size = candidate_moves_t1.size();
                    total_candidate_size += candidate_moves_t1_size;
                    for (int i = 0; i < candidate_moves_t1_size; ++i) {
                        std::shared_ptr<Move> res = candidate_moves_t1.top();
                        std::cout << res->move_to().column << res->move_to().row << ' ';
                        candidate_moves_t1.pop();
                    }
                    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> candidate_moves_t2 = selected_piece->data_->moves_t2();
                    int candidate_moves_t2_size = candidate_moves_t2.size();
                    total_candidate_size += candidate_moves_t2_size;
                    for (int i = 0; i < candidate_moves_t2_size; ++i) {
                        std::shared_ptr<Move> res = candidate_moves_t2.top();
                        std::cout << res->move_to().column << res->move_to().row << ' ';
                        candidate_moves_t2.pop();
                    }
                    std::cout << "]" << std::endl;
                    if (total_candidate_size == 0) {
                        std::cout << "- The piece has no moves!" << std::endl;
                        continue;
                    }
                    move_from_selected = true;
                } else {
                    std::cout << "- It is not your piece!" << std::endl;
                }
            } else if (!move_to_selected) {
                char new_column = cmd[0];
                int new_row = cmd[1] - '0';
                Position new_position {new_column, new_row};
                if (!valid_position(new_position)) {
                    std::cout << "- You can't move there! " << std::endl;
                    continue;
                } 
                std::shared_ptr<Move> desired_move;
                std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t1 = selected_piece->moves_t1();
                int moves_size = moves_t1.size();
                bool move_found = false;
                for (int i = 0; i < moves_size; ++i) {
                    std::shared_ptr<Move> move = moves_t1.top();
                    if (move->move_to() == new_position) {
                        desired_move = move;
                        move_found = true;
                        break;
                    }
                    moves_t1.pop();
                }
                std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t2 = selected_piece->moves_t2();
                moves_size = moves_t2.size();
                for (int i = 0; i < moves_size; ++i) {
                    std::shared_ptr<Move> move = moves_t2.top();
                    if (move->move_to() == new_position) {
                        desired_move = move;
                        move_found = true;
                        break;
                    }
                    moves_t2.pop();
                }
                if (move_found) {
                    move(desired_move);
                    turn_success = true;
                } else {
                    std::cout << "- You can't move there! " << std::endl;
                    move_from_selected = false;
                }
            } else {
                std::cout << "- It is not your piece! " << std::endl;
            }
        }
    }
}

int Chess::get_turn() const {
    return turn_number_;
}

bool Chess::white_player_turn() const {
    return (turn_number_ % 2) == 1; 
}

bool Chess::black_player_turn() const {
    return (turn_number_ % 2) == 0; 
}

void Chess::print_board() const {
    if (white_player_turn()) {
        if (play_against_Human_ || play_against_Black_) {
            std::cout << " ================" << std::endl;
            for (int i = 0; i < 8; ++i) { // row 8-1
                std::cout << 8 - i;
                for (int j = 0; j < 8; ++j) { // col a-h
                    if (board_.get_piece_on({static_cast<char>('a' + j), 8 - i}) == nullptr) {
                        std::cout << " ";
                    } else {
                        board_.get_piece_on({static_cast<char>('a' + j), 8 - i})->print();
                    }
                    std::cout << "|";
                }
                std::cout << std::endl;
            }
            std::cout << " a b c d e f g h" << std::endl;
            std::cout << " ================" << std::endl;
        } else {
            std::cout << " ================" << std::endl;
            for (int i = 0; i < 8; ++i) { // row 1-8
                std::cout << i + 1;
                for (int j = 0; j < 8; ++j) { // col h-a
                    if (board_.get_piece_on({static_cast<char>('h' - j), i + 1}) == nullptr) {
                        std::cout << " ";
                    } else {
                        board_.get_piece_on({static_cast<char>('h' - j), i + 1})->print();
                    }
                    std::cout << "|";
                }
                std::cout << std::endl;
            }
            std::cout << " h g f e d c b a" << std::endl;
            std::cout << " ================" << std::endl;
        }
    } else {
        if (play_against_Human_ || play_against_White_) {
            std::cout << " ================" << std::endl;
            for (int i = 0; i < 8; ++i) { // row 1-8
                std::cout << i + 1;
                for (int j = 0; j < 8; ++j) { // col h-a
                    if (board_.get_piece_on({static_cast<char>('h' - j), i + 1}) == nullptr) {
                        std::cout << " ";
                    } else {
                        board_.get_piece_on({static_cast<char>('h' - j), i + 1})->print();
                    }
                    std::cout << "|";
                }
                std::cout << std::endl;
            }
            std::cout << " h g f e d c b a" << std::endl;
            std::cout << " ================" << std::endl;
        } else {
            std::cout << " ================" << std::endl;
            for (int i = 0; i < 8; ++i) { // row 8-1
                std::cout << 8 - i;
                for (int j = 0; j < 8; ++j) { // col a-h
                    if (board_.get_piece_on({static_cast<char>('a' + j), 8 - i}) == nullptr) {
                        std::cout << " ";
                    } else {
                        board_.get_piece_on({static_cast<char>('a' + j), 8 - i})->print();
                    }
                    std::cout << "|";
                }
                std::cout << std::endl;
                }
            std::cout << " a b c d e f g h" << std::endl;
            std::cout << " ================" << std::endl;
        }
    }
}