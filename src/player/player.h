#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <queue>
#include "../pieces/chess_piece.h"
#include "../utility/info.h"
#include "../engine/move.h"

class Player {
public:  
    Player(PlayerColour colour);

    void name(std::string name);
    std::string name() const;
    PlayerColour colour() const;

    void remove_piece(std::shared_ptr<ChessPiece> piece);
    void add_piece(std::shared_ptr<ChessPiece> piece);
    void add_pieces(std::vector<std::shared_ptr<ChessPiece>> piece);
    std::vector<std::shared_ptr<ChessPiece>> get_pieces() const;
  
    void clear_moves();
    void generate_moves();
    std::shared_ptr<Move> get_best_move() const;

    void AI(bool AI);
    bool AI() const;
private:
    std::string name_;
    const PlayerColour colour_;
    std::vector<std::shared_ptr<ChessPiece>> pieces_;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t1_;
    std::priority_queue<std::shared_ptr<Move>, std::vector<std::shared_ptr<Move>>, CompareMove> moves_t2_;

    bool AI_;
};

#endif