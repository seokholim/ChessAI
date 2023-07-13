#include "engine.h"

bool engine_evaluation_debug = false;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run_scenario(std::shared_ptr<Move>& move, int level) {
    if (move == nullptr || move->moving_piece() == nullptr) {
        return;
    }

    if (level < 0) {
        return;
    }
    Scenario s = Scenario(move, level);
    s.move();
    s.generate_next_scenarios();
    s.evaluate();
    if (engine_evaluation_debug) {
        std::cout << "-- Scenario for a move from " << move->move_from().column << move->move_from().row << " to " << move->move_to().column << move->move_to().row << " by ";
        move->moving_piece()->print();
        std::cout << " has value: " << s.value() << std::endl;
    }
    move->value(s.value());
}

void Engine::evaluate_move(std::shared_ptr<Move>& move, int level) {
    if (move == nullptr || move->moving_piece() == nullptr) {
        std::cout << "Engine::evaluate_move(...); nullptr" << std::endl;
        return;
    }

    // if not a Defending move, run scenario
    if (!move->occupied() || move->moving_piece()->colour() != move->occupying_piece()->colour()) {
        run_scenario(move, level);
    }
}

void Engine::generate_moves_for_piece(std::shared_ptr<ChessPiece>& piece, bool use_engine) {
    if (piece == nullptr || piece->data_ == nullptr) {
        std::cout<< "Engine::evaluate_moves_for(...); piece is nullptr" << std::endl;
        return;
    }
    int engine_level = 3;
    if (!use_engine) {
        engine_level = 0;
    }
    std::shared_ptr<Piece> piece_data = piece->data_;
    piece_data->clear_moves();
    std::queue<Position> candidate_positions = piece_data->candidate_positions();
    std::vector<std::shared_ptr<Move>> candidate_moves;
    std::shared_ptr<Move> candidate_move;
    while (!candidate_positions.empty()) {
        Position candidate_position = candidate_positions.front();
        std::shared_ptr<ChessPiece> occupying_piece = piece_data->board()->get_piece_on(candidate_position);
        if (occupying_piece != nullptr) {
            candidate_move = std::make_shared<Move>(piece->position(), candidate_position, piece, piece_data->board()->get_piece_on(candidate_position));
        } else {
            candidate_move = std::make_shared<Move>(piece->position(), candidate_position, piece, nullptr);
        }
        candidate_moves.push_back(candidate_move);
        candidate_positions.pop();
    }

    // multithreading
    std::thread threads[candidate_moves.size()];
    for (int i = 0; i < candidate_moves.size(); ++i) {
        threads[i] = std::thread(&Engine::evaluate_move, std::ref(candidate_moves[i]), engine_level);
    }
    for (std::thread& t : threads) {
        t.join();
    }
    for (auto& move : candidate_moves) {
        if (valid_chess_move_type(move->move_type())) {
            if (is_move_t1(move->move_type())) {
                piece_data->add_move_t1(move);
            } else {
                piece_data->add_move_t2(move);
            }
        }
    }
}

void Engine::generate_moves_for_pieces(std::vector<std::shared_ptr<ChessPiece>> pieces, bool use_engine) {
    // multithreading
    std::thread threads[pieces.size()];
    for (int i = 0; i < pieces.size(); ++i) {
        threads[i] = std::thread(&Engine::generate_moves_for_piece, std::ref(pieces[i]), use_engine);
    }

    for (std::thread& t : threads) {
        t.join();
    }
}