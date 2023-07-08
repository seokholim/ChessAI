#include "engine.h"

bool engine_evaluation_debug = false;

Engine::Engine() {}

Engine::Engine(Board* board, std::vector<std::shared_ptr<Piece>> pieces) : board_{board}, pieces_{pieces} {}

Engine::~Engine() {}

void Engine::run_scenario(std::shared_ptr<Move>& move, int level) {
    if (move == nullptr || move->moving_piece() == nullptr) { // TODO: check valid move
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
        std::cout << "-- Parent Scenario for a move from " << move->move_from().column << move->move_from().row << " to " << move->move_to().column << move->move_to().row << " by ";
        move->moving_piece()->print();
        std::cout << " has value: " << s.value() << std::endl;
    }
    move->value(s.value());
}

void Engine::evaluate_move(std::shared_ptr<Move>& move, int level) {
    if (move == nullptr || move->moving_piece() == nullptr) { // TODO: check valid move
        std::cout << "Engine::evaluate_move(...); nullptr" << std::endl;
        return;
    }

    // if not a Defending move, run scenario TODO: include castling
    if (!move->occupied() || move->moving_piece()->colour() != move->occupying_piece()->colour()) {
        run_scenario(move, level);
    } // TODO
}

void Engine::generate_moves_for(std::shared_ptr<ChessPiece>& piece, bool use_engine) {
    if (piece == nullptr || piece->data_ == nullptr) {
        std::cout<< "Engine::evaluate_moves_for(...); piece is nullptr" << std::endl;
        return;
    }
    int engine_level = 2;
    if (!use_engine) {
        engine_level = 0;
    }
    std::shared_ptr<Piece> piece_data = piece->data_;
    piece_data->clear_moves();
    std::queue<Position> candidate_positions = piece_data->candidate_positions();
    while (!candidate_positions.empty()) {
        Position candidate_position = candidate_positions.front();
        std::shared_ptr<Move> candidate_move;
        std::shared_ptr<ChessPiece> occupying_piece = board_->get_piece_on(candidate_position);
        if (occupying_piece != nullptr) {
            candidate_move = std::make_shared<Move>(piece->position(), candidate_position, piece, board_->get_piece_on(candidate_position));
        } else {
            candidate_move = std::make_shared<Move>(piece->position(), candidate_position, piece, nullptr);
        }
        evaluate_move(candidate_move, engine_level);
        if (valid_chess_move_type(candidate_move->move_type())) {
            if (is_move_t1(candidate_move->move_type())) {
                piece_data->add_move_t1(candidate_move);
            } else {
                piece_data->add_move_t2(candidate_move);
            }
        }
        candidate_positions.pop();
    }
}

void Engine::generate_moves_for(std::vector<std::shared_ptr<ChessPiece>> pieces, bool use_engine) {
    for (auto& piece : pieces) {
        generate_moves_for(piece, use_engine);
    }
}