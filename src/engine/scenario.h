#ifndef SCENARIO_H
#define SCENARIO_H
#include <memory>
#include <vector>
#include "../pieces/piece.h"
#include "../board/board.h"
#include "move.h"
#include "../pieces/rook.h"
#include "../pieces/knight.h"
#include "../pieces/bishop.h"
#include "../pieces/queen.h"
#include "../pieces/king.h"
#include "../pieces/pawn.h"
#include "../pieces/chess_piece.h"

class Scenario {
public:
    Scenario();
    Scenario(std::shared_ptr<Move> move, int level);
    ~Scenario();

    std::shared_ptr<Piece> copy_piece(std::shared_ptr<Piece> piece);

    void set_move_type(std::shared_ptr<Move> move);
    void evaluate_move_type(std::shared_ptr<Move> move);
    void move();

    void generate_next_scenarios();

    bool king_unsafe() const;

    void evaluate();
    int value() const;
private:
    std::shared_ptr<Move> m_original_move;
    int m_scenario_level;

    std::shared_ptr<Move> m_move_copy;
    Board m_new_board;
    std::vector<std::shared_ptr<Piece>> m_pieces_data_copy;
    PlayerColour m_scenario_colour;

    std::vector<std::shared_ptr<Scenario>> m_next_scenarios;
    int m_scenario_value;
};

#endif