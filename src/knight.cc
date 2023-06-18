#include "knight.h"

Knight::Knight(PlayerColour player_colour) : Piece{PieceType::Knight, player_colour} {}

void Knight::evaluate_move(Position new_pos) {
    
}

void Knight::calculate_moves() {
    this->moves.clear();

    if (white()) {
        // Forward Forward Right (FFR)
        Position considered_pos = position;
        considered_pos.row += 2;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // FRR
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column += 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BRR
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column += 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BBR
        considered_pos = position;
        considered_pos.row -= 2;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BBL
        considered_pos = position;
        considered_pos.row -= 2;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BLL
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column -= 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // FLL
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column -= 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // FFl
        considered_pos = position;
        considered_pos.row += 2;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->black()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

    } else {
        // Forward Forward Right (FFR)
        Position considered_pos = position;
        considered_pos.row -= 2;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // FRR
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column -= 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BRR
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column -= 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BBR
        considered_pos = position;
        considered_pos.row += 2;
        considered_pos.column -= 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BBL
        considered_pos = position;
        considered_pos.row += 2;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // BLL
        considered_pos = position;
        considered_pos.row += 1;
        considered_pos.column += 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // FLL
        considered_pos = position;
        considered_pos.row -= 1;
        considered_pos.column += 2;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }

        // FFl
        considered_pos = position;
        considered_pos.row -= 2;
        considered_pos.column += 1;
        if (valid_position(considered_pos)) {
            if (board->empty_on(considered_pos) 
             || board->get_piece_on(considered_pos)->white()) {
                Move* new_move = new Move{this->position, considered_pos, this};
                this->moves.push_back(new_move);
            }
        }
    }

}

void Knight::update() {
    calculate_moves();
}