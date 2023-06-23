#include "chess_engine.h"

ChessEngine::ChessEngine(Board* board) : board{board} {}

void ChessEngine::evaluate_move(Move* move, int level) {
    if (board == nullptr || move == nullptr) {
        return;
    }
    board->move_piece(move->get_move_from(), move->get_move_to());
    board->get_piece_on(move->get_move_to())->notify();
    board->get_piece_on(move->get_move_to())->calculate_moves();
    if (move != nullptr) {
        if (level == 0) {

            




        } else if (level == 1) {








        }
    }
    board->undo();
}

bool ChessEngine::king_checked(Move* move) {
    if (board == nullptr || move == nullptr) return false;
    board->move_piece(move->get_move_from(), move->get_move_to());
    board->get_piece_on(move->get_move_to())->notify();
    for (auto piece : board->get_pieces()) {
        if (move->get_moving_piece()->white() && piece->black()) {
            for (auto possible_move : piece->get_moves()) {
                
            }
        }
    }
}