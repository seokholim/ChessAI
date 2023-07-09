#ifndef ENGINE_H
#define ENGINE_H
#include <thread>
#include "scenario.h"
#include "../board/board.h"
#include "../pieces/chess_piece.h"
#include "move.h"


class Engine {
public:
    Engine();
    ~Engine();

    static void run_scenario(std::shared_ptr<Move>& move, int level);
    static void evaluate_move(std::shared_ptr<Move>& move, int level);
    
    static void generate_moves_for_piece(std::shared_ptr<ChessPiece>& piece, bool use_engine);
    void generate_moves_for_pieces(std::vector<std::shared_ptr<ChessPiece>> pieces, bool use_engine);
private:

};

#endif