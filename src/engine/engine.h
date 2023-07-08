#ifndef ENGINE_H
#define ENGINE_H
#include "scenario.h"
#include "../board/board.h"
#include "../pieces/chess_piece.h"
#include "move.h"

class Engine {
public:
    Engine();
    Engine(Board* board, std::vector<std::shared_ptr<Piece>> pieces);
    ~Engine();

    void run_scenario(std::shared_ptr<Move>& move, int level);
    void evaluate_move(std::shared_ptr<Move>& move, int level);
    
    void generate_moves_for(std::shared_ptr<ChessPiece>& piece, bool use_engine);
    void generate_moves_for(std::vector<std::shared_ptr<ChessPiece>> pieces, bool use_engine);
private:
    Board* board_;
    std::vector<std::shared_ptr<Piece>> pieces_;
};

#endif