#include "scenario.h"

bool scenario_memory_debug = false;
bool scenario_evaluation_debug = false;

std::shared_ptr<Piece> Scenario::copy_piece(std::shared_ptr<Piece> piece) {
    if (piece == nullptr) {
        return piece;
    }
    std::shared_ptr<Piece> copy_data;
    if (piece->type() == PieceType::Rook) {
        copy_data = std::make_shared<Rook>(piece->colour());
    } else if (piece->type() == PieceType::Knight) {
        copy_data = std::make_shared<Knight>(piece->colour());
    } else if (piece->type() == PieceType::Bishop) {
        copy_data = std::make_shared<Bishop>(piece->colour());
    } else if (piece->type() == PieceType::Queen) {
        copy_data = std::make_shared<Queen>(piece->colour());
    } else if (piece->type() == PieceType::King) {
        copy_data = std::make_shared<King>(piece->colour());
    } else if (piece->type() == PieceType::Pawn) {
        copy_data = std::make_shared<Pawn>(piece->colour());
    }
    copy_data->position(piece->position());
    copy_data->starting_position(piece->starting_position());
    return copy_data;
}

void Scenario::set_move_type(std::shared_ptr<Move> move) { // TODO
    if (move == nullptr || move->moving_piece() == nullptr || move->move_type() != MoveType::Unevaluated) {
        return;
    }

    if (move->occupied()) {
        if (move->moving_piece()->colour() == move->occupying_piece()->colour()) {
            if ((move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::King) 
            ||  (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::Rook)) { // Castling
                move->move_type(MoveType::Castling);
            } else { // Defending
                move->move_type(MoveType::Defending);
            }
        } else { // Capturing or EnPassant
            move->move_type(MoveType::Capturing);
        }
    } else { // moving to empty spot or Evading or Upgrade
        move->move_type(MoveType::Neutral);
    }
}

void Scenario::evaluate_move_type(std::shared_ptr<Move> move) { // TODO
    if (move->move_type() == MoveType::Unevaluated || move->move_type() == MoveType::Null) {
        return;
    } else if (move->move_type() == MoveType::Capturing) {
        // moving piece is Pawn
        if (move->moving_piece()->type() == PieceType::Pawn && move->occupying_piece()->type() == PieceType::Pawn) {
            move->value(pawn_capturing_pawn);
        } else if (move->moving_piece()->type() == PieceType::Pawn && move->occupying_piece()->type() == PieceType::Rook) {
            move->value(pawn_capturing_rook);
        } else if (move->moving_piece()->type() == PieceType::Pawn && move->occupying_piece()->type() == PieceType::Knight) {
            move->value(pawn_capturing_knight);
        } else if (move->moving_piece()->type() == PieceType::Pawn && move->occupying_piece()->type() == PieceType::Bishop) {
            move->value(pawn_capturing_bishop);
        } else if (move->moving_piece()->type() == PieceType::Pawn && move->occupying_piece()->type() == PieceType::Queen) {
            move->value(pawn_capturing_queen);
        } else if (move->moving_piece()->type() == PieceType::Pawn && move->occupying_piece()->type() == PieceType::King) {
            move->value(pawn_capturing_king);
        } 

        // moving piece is Rook
        if (move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::Pawn) {
            move->value(rook_capturing_pawn);
        } else if (move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::Rook) {
            move->value(rook_capturing_rook);
        } else if (move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::Knight) {
            move->value(rook_capturing_knight);
        } else if (move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::Bishop) {
            move->value(rook_capturing_bishop);
        } else if (move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::Queen) {
            move->value(rook_capturing_queen);
        } else if (move->moving_piece()->type() == PieceType::Rook && move->occupying_piece()->type() == PieceType::King) {
            move->value(rook_capturing_king);
        } 

        // moving piece is Bishop
        if (move->moving_piece()->type() == PieceType::Bishop && move->occupying_piece()->type() == PieceType::Pawn) {
            move->value(bishop_capturing_pawn);
        } else if (move->moving_piece()->type() == PieceType::Bishop && move->occupying_piece()->type() == PieceType::Rook) {
            move->value(bishop_capturing_rook);
        } else if (move->moving_piece()->type() == PieceType::Bishop && move->occupying_piece()->type() == PieceType::Knight) {
            move->value(bishop_capturing_knight);
        } else if (move->moving_piece()->type() == PieceType::Bishop && move->occupying_piece()->type() == PieceType::Bishop) {
            move->value(bishop_capturing_bishop);
        } else if (move->moving_piece()->type() == PieceType::Bishop && move->occupying_piece()->type() == PieceType::Queen) {
            move->value(bishop_capturing_queen);
        } else if (move->moving_piece()->type() == PieceType::Bishop && move->occupying_piece()->type() == PieceType::King) {
            move->value(bishop_capturing_king);
        }

        // moving piece is Knight
        if (move->moving_piece()->type() == PieceType::Knight && move->occupying_piece()->type() == PieceType::Pawn) {
            move->value(knight_capturing_pawn);
        } else if (move->moving_piece()->type() == PieceType::Knight && move->occupying_piece()->type() == PieceType::Rook) {
            move->value(knight_capturing_rook);
        } else if (move->moving_piece()->type() == PieceType::Knight && move->occupying_piece()->type() == PieceType::Knight) {
            move->value(knight_capturing_knight);
        } else if (move->moving_piece()->type() == PieceType::Knight && move->occupying_piece()->type() == PieceType::Bishop) {
            move->value(knight_capturing_bishop);
        } else if (move->moving_piece()->type() == PieceType::Knight && move->occupying_piece()->type() == PieceType::Queen) {
            move->value(knight_capturing_queen);
        } else if (move->moving_piece()->type() == PieceType::Knight && move->occupying_piece()->type() == PieceType::King) {
            move->value(knight_capturing_king);
        } 

        // moving piece is Queen
        if (move->moving_piece()->type() == PieceType::Queen && move->occupying_piece()->type() == PieceType::Pawn) {
            move->value(queen_capturing_pawn);
        } else if (move->moving_piece()->type() == PieceType::Queen && move->occupying_piece()->type() == PieceType::Rook) {
            move->value(queen_capturing_rook);
        } else if (move->moving_piece()->type() == PieceType::Queen && move->occupying_piece()->type() == PieceType::Knight) {
            move->value(queen_capturing_knight);
        } else if (move->moving_piece()->type() == PieceType::Queen && move->occupying_piece()->type() == PieceType::Bishop) {
            move->value(queen_capturing_bishop);
        } else if (move->moving_piece()->type() == PieceType::Queen && move->occupying_piece()->type() == PieceType::Queen) {
            move->value(queen_capturing_queen);
        } else if (move->moving_piece()->type() == PieceType::Queen && move->occupying_piece()->type() == PieceType::King) {
            move->value(queen_capturing_king);
        }

        // moving piece is King
        if (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::Pawn) {
            move->value(king_capturing_pawn);
        } else if (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::Rook) {
            move->value(king_capturing_rook);
        } else if (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::Knight) {
            move->value(king_capturing_knight);
        } else if (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::Bishop) {
            move->value(king_capturing_bishop);
        } else if (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::Queen) {
            move->value(king_capturing_queen);
        } else if (move->moving_piece()->type() == PieceType::King && move->occupying_piece()->type() == PieceType::King) {
            move->value(king_capturing_king);
        } 
    } else if (move->move_type() == MoveType::CapturingForFree) {
        move->value(1000);
    } else if (move->move_type() == MoveType::SafeNeutral) {
        if (move->moving_piece()->type() == PieceType::Pawn) {
            move->value(7);
        } else if (move->moving_piece()->type() == PieceType::King) {
            move->value(-10);
        } else {
            move->value(5);
        }
    } else if (move->move_type() == MoveType::Dangerous) {
        move->value(-50);
    } else if (move->move_type() == MoveType::Defending) {
        move->value(50);
    } else if (move->move_type() == MoveType::Evading) {
        move->value(30);
    } else if (move->move_type() == MoveType::Neutral) {
        if (move->moving_piece()->type() == PieceType::Pawn) {
            move->value(5);
        } else if (move->moving_piece()->type() == PieceType::King) {
            move->value(-10);
        } else {
            move->value(3);
        }
    } else if (move->move_type() == MoveType::Castling) {
        move->value(200);
    } else if (move->move_type() == MoveType::EnPassant) {
        move->value(30);
    } else if (move->move_type() == MoveType::Upgrade) {
        move->value(100);
    } else if (move->move_type() == MoveType::Checkmate) {
        move->value(10000);
    }

}

Scenario::Scenario() : m_original_move{nullptr}, m_scenario_level{0}, m_move_copy{nullptr}, m_new_board{}, m_pieces_data_copy{}, m_scenario_colour{PlayerColour::Null}, m_number_of_next_scenarios{0}, m_scenario_value{0} {}

Scenario::Scenario(std::shared_ptr<Move> move, int level) : m_original_move{move}, m_scenario_level{level}, m_move_copy{nullptr}, m_new_board{}, m_pieces_data_copy{}, m_scenario_colour{PlayerColour::Null}, m_number_of_next_scenarios{0}, m_scenario_value{0} {
    // TODO: check valid move
    m_scenario_colour = m_original_move->moving_piece()->colour();

    std::shared_ptr<ChessBoard> new_chess_board = std::make_shared<ChessBoard>(&m_new_board);
    std::shared_ptr<Piece> original_moving_piece_data = m_original_move->moving_piece()->data_;

    std::shared_ptr<ChessPiece> moving_piece_copy, occupying_piece_copy = nullptr;
    std::vector<std::shared_ptr<ChessPiece>> pieces_to_copy = original_moving_piece_data->board()->get_pieces();
    for (auto& piece : pieces_to_copy) {
        std::shared_ptr<Piece> copy_data = copy_piece(piece->data_);
        std::shared_ptr<ChessPiece> copy = std::make_shared<ChessPiece>(copy_data);
        if (piece == m_original_move->moving_piece()) {
            moving_piece_copy = copy;
        } else if (m_original_move->occupied() && piece == m_original_move->occupying_piece()) {
            occupying_piece_copy = copy;
        }
        copy_data->set_board(new_chess_board);
        m_new_board.create_piece_on(copy, copy->position());
        for (auto& copied : m_pieces_data_copy) {
            copied->attach(copy_data);
            copy_data->attach(copied);
        }
        m_pieces_data_copy.push_back(copy_data);
    }
    m_move_copy = std::make_shared<Move>(m_original_move->move_from(), m_original_move->move_to(), moving_piece_copy, occupying_piece_copy);
}

Scenario::~Scenario() {
    for (int i = 0; i < m_pieces_data_copy.size(); ++i) {
        m_pieces_data_copy[i]->clear_candidate_positions();
        m_pieces_data_copy[i]->clear_moves();
        for (int j = i + 1; j < m_pieces_data_copy.size(); ++j) {
            m_pieces_data_copy[j]->detach(m_pieces_data_copy[i]);
            m_pieces_data_copy[i]->detach(m_pieces_data_copy[j]);
        }
    }
    m_new_board.empty_board();
}

void Scenario::move() {
    if (m_move_copy == nullptr) { // TODO: check valid m_move_copy
        std::cout << "Scenario::move(); m_move_copy is nullptr" << std::endl;
        return;
    }
    if (m_move_copy->occupied()) { // capture logic
        auto it = std::find(m_pieces_data_copy.begin(), m_pieces_data_copy.end(), m_move_copy->occupying_piece()->data_);
        if (it == m_pieces_data_copy.end()) {
            std::cout << "Scenario::move(); can't erase the occupying piece data" << std::endl;
            return;
        }
        for (auto& piece : m_pieces_data_copy) {
            piece->detach((*it));
            (*it)->detach(piece);
        }
        m_pieces_data_copy.erase(it);
    }
    m_new_board.move(m_move_copy->move_from(), m_move_copy->move_to());
    m_move_copy->moving_piece()->data_->position(m_move_copy->move_to());
    m_move_copy->moving_piece()->data_->notify();
    m_move_copy->moving_piece()->data_->generate_candidate_positions();
}

void Scenario::generate_next_scenarios() { // dependent on Scenario::move() because it needs candidate_positions
    bool original_move_king_unsafe = false; // to check if m_original_move is king safe
    if (m_scenario_level == 0) { // base case
        for (auto piece: m_pieces_data_copy) {
            if (piece->colour() != m_scenario_colour) { // consider opponent pieces' candidate positions
                std::queue<Position> candidate_positions = piece->candidate_positions();
                while (!candidate_positions.empty()) {
                    Position candidate_position = candidate_positions.front();
                    if (m_new_board.get_piece_on(candidate_position) != nullptr) {
                        if (m_new_board.get_piece_on(candidate_position)->colour() == piece->colour()) { // opponent piece can't capture their piece
                            candidate_positions.pop();
                            continue;
                        } else if (m_new_board.get_piece_on(candidate_position)->type() == PieceType::King) {
                            original_move_king_unsafe = true;
                            break;
                        }
                    }
                    candidate_positions.pop();
                }
                if (original_move_king_unsafe) break;
            }
        }
        if (original_move_king_unsafe) {
            m_original_move->move_type(MoveType::KingUnsafe);
            return;
        }
        set_move_type(m_original_move);
        evaluate_move_type(m_original_move);
        return;
    }

    // recursive case
    int support = 0; // number of ally pieces that can move to piece after move
    int opponent_attack = 0; // number of opponent pieces that can capture piece after move
    int critical_opponent_attack = 0; // number of weaker opponent pieces that can capture piece after move
    bool original_move_checkmate_candidate = true; // every move is a candidate for checkmate, until opponent's next valid move is found
    for (auto piece: m_pieces_data_copy) {
        if (piece->colour() != m_scenario_colour) { // consider opponent pieces' candidate positions
            std::queue<Position> candidate_positions = piece->candidate_positions();
            std::vector<std::shared_ptr<Move>> candidate_moves; // TODO: multithreading
            std::shared_ptr<Move> candidate_move;
            while (!candidate_positions.empty()) {
                Position candidate_position = candidate_positions.front();
                if (candidate_position == m_move_copy->move_to()) { // piece could attack moving piece; check scenario
                    if (m_move_copy->moving_piece()->type() == PieceType::King) {
                        original_move_king_unsafe = true;
                        break;
                    }
                    candidate_move = std::make_shared<Move>(piece->position(), candidate_position, m_new_board.get_piece_on(piece->position()), m_new_board.get_piece_on(candidate_position));
                    candidate_moves.push_back(candidate_move);
                    candidate_positions.pop();
                    continue;
                }

                if (m_new_board.get_piece_on(candidate_position) != nullptr) {
                    if (m_new_board.get_piece_on(candidate_position)->colour() == piece->colour()) { // can't generate this scenario
                        candidate_positions.pop();
                        continue;
                    } else if (m_new_board.get_piece_on(candidate_position)->type() == PieceType::King) {
                        original_move_king_unsafe = true;
                        break;
                    }
                }
                std::shared_ptr<Move> candidate_move = std::make_shared<Move>(piece->position(), candidate_position, m_new_board.get_piece_on(piece->position()), m_new_board.get_piece_on(candidate_position));
                candidate_moves.push_back(candidate_move);
                candidate_positions.pop();
            }
            if (original_move_king_unsafe) break;
            
            if (m_scenario_level == 1) {
                // single thread for base case
                for (auto& move : candidate_moves) {
                    Engine::run_scenario(move, 0);
                }
            } else {
                // multithreading
                std::thread threads[candidate_moves.size()];
                for (int i = 0; i < candidate_moves.size(); ++i) {
                    threads[i] = std::thread(&Engine::run_scenario, std::ref(candidate_moves[i]), m_scenario_level - 1);
                }
                for (std::thread& t : threads) {
                    t.join();
                }
            }

            for (auto& move : candidate_moves) {
                if (move->move_type() != MoveType::KingUnsafe) {
                    ++m_number_of_next_scenarios;
                    original_move_checkmate_candidate = false;
                    if (m_move_copy->move_to() == move->move_to()) {
                        ++opponent_attack;
                        if (unbalanced_trade(m_move_copy->moving_piece()->type(), move->moving_piece()->type())) {
                            ++critical_opponent_attack;
                        }
                    }
                    m_scenario_value -= move->value();
                }
            }
        } else {
            if (piece->position() == m_move_copy->moving_piece()->position()) { // TODO: defensive moves?
                continue;
            }
            std::queue<Position> candidate_positions = piece->candidate_positions();
            std::vector<std::shared_ptr<Move>> candidate_moves;
            std::shared_ptr<Move> candidate_move;
            while (!candidate_positions.empty()) {
                Position candidate_position = candidate_positions.front();
                if (candidate_position == m_move_copy->move_to()) {
                    std::shared_ptr<Move> candidate_move = std::make_shared<Move>(piece->position(), candidate_position, m_new_board.get_piece_on(piece->position()), m_new_board.get_piece_on(candidate_position));
                    candidate_moves.push_back(candidate_move);
                }
                candidate_positions.pop();
            }

            // single thread for base case
            for (auto& move : candidate_moves) {
                Engine::run_scenario(move, 0);
            }

            for (auto& move : candidate_moves) {
                if (move->move_type() != MoveType::KingUnsafe) {
                    ++support;
                }
            }
        }
    }
    if (original_move_checkmate_candidate) {
        m_original_move->move_type(MoveType::Checkmate);
    }
    if (original_move_king_unsafe) {
        m_original_move->move_type(MoveType::KingUnsafe);
        return;
    }

    // TODO: improve
    set_move_type(m_original_move);
    evaluate_move_type(m_original_move);
    if (support == 0) {
        if (opponent_attack == 0) { // OK
            if (m_original_move->move_type() != MoveType::Checkmate) {
                if (m_original_move->move_type() == MoveType::Capturing) {
                    m_original_move->move_type(MoveType::CapturingForFree);
                    evaluate_move_type(m_original_move);
                }
                if (m_original_move->move_type() == MoveType::Neutral) {
                    m_original_move->move_type(MoveType::SafeNeutral);
                    evaluate_move_type(m_original_move);
                }
            }
        } else { // Possibly not ok
            if (critical_opponent_attack == 0) {
                if (m_original_move->move_type() == MoveType::Capturing) {
                    evaluate_move_type(m_original_move);
                } else {
                    m_original_move->move_type(MoveType::Dangerous);
                    evaluate_move_type(m_original_move);
                }
            } else {
                m_original_move->move_type(MoveType::Dangerous);
                evaluate_move_type(m_original_move);
            }
            
        }
    } else {
        if (support > opponent_attack) {
            if (m_original_move->move_type() != MoveType::Checkmate) {
                if (critical_opponent_attack == 0) {
                    if (m_original_move->move_type() == MoveType::Capturing) {
                        m_original_move->move_type(MoveType::CapturingForFree);
                        evaluate_move_type(m_original_move);
                    } else if (m_original_move->move_type() == MoveType::Neutral) {
                        m_original_move->move_type(MoveType::SafeNeutral);
                        evaluate_move_type(m_original_move);
                    }
                } else {
                    m_original_move->move_type(MoveType::Dangerous);
                    evaluate_move_type(m_original_move);
                }
            }
        } else if (support < opponent_attack) { // BAD
            if (critical_opponent_attack == 0) {
                if (m_original_move->move_type() == MoveType::Capturing) {
                    evaluate_move_type(m_original_move);
                } else {
                    m_original_move->move_type(MoveType::Dangerous);
                    evaluate_move_type(m_original_move);
                }
            } else {
                m_original_move->move_type(MoveType::Dangerous);
                evaluate_move_type(m_original_move);
            }
        }
    }
 }

void Scenario::evaluate() {
    m_scenario_value = safe_division(m_scenario_value, m_number_of_next_scenarios);
    m_scenario_value += m_original_move->value();
}

int Scenario::value() const {
    return m_scenario_value;
}