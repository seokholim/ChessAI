#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <queue>
#include "chess_piece.h"
#include "info.h"
#include "move.h"

class Player {
public:  
    Player(PlayerColour colour);

    void name(std::string name);
    std::string name() const;
    PlayerColour colour() const;

    void add_piece(std::shared_ptr<ChessPiece> chess_piece);
    void add_pieces(std::vector<std::shared_ptr<ChessPiece>> chess_pieces);
    std::vector<std::shared_ptr<ChessPiece>> get_pieces() const;
  
    void clear_moves();
    void generate_moves();
    void remove_best_move();
    std::shared_ptr<Move> get_best_move();

    void AI(bool AI);
    bool AI();
private:
    const PlayerColour colour_;
    std::string name_;
    std::vector<std::shared_ptr<ChessPiece>> pieces_;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_;

    bool AI_;
};

#endif