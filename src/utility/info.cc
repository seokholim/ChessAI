#include "info.h"

bool valid_piece_type(PieceType piece_type) {
    if (piece_type == PieceType::Pawn || piece_type == PieceType::Rook || piece_type == PieceType::Knight ||
        piece_type == PieceType::Bishop || piece_type == PieceType::Queen || piece_type == PieceType::King) {
            return true;
    }
    return false;
}

bool unbalanced_trade(PieceType trading, PieceType with) {
    if (trading == PieceType::Pawn) {
        return false;
    } else if (trading == PieceType::Bishop || trading == PieceType::Knight || trading == PieceType::Rook) {
        if (with != PieceType::Pawn) {
            return false;
        }
        return true;
    } else if (trading == PieceType::Queen) {
        if (with == PieceType::Queen) {
            return false;
        }
        return true;
    } else if (trading == PieceType::King) { // logically impossible
        return false;
    }
    return true;
}

std::string convert_to_char(PlayerColour player_colour, PieceType piece_type) {
    if (player_colour == PlayerColour::White) {
        switch(piece_type) {
            case PieceType::King:
                return "♔";
            case PieceType::Queen:
                return "♕";
            case PieceType::Bishop:
                return "♗";
            case PieceType::Knight:
                return "♘";
            case PieceType::Rook:
                return "♖";
            case PieceType::Pawn:
                return "♙";
            default:
                return "W";
        }
    } else if (player_colour == PlayerColour::Black) {
        switch(piece_type) {
            case PieceType::King:
                return "♚";
            case PieceType::Queen:
                return "♛";
            case PieceType::Bishop:
                return "♝";
            case PieceType::Knight:
                return "♞";
            case PieceType::Rook:
                return "♜";
            case PieceType::Pawn:
                return "♟︎";
            default:
                return "B";
        }
    }
    return " ";
}

Position::Position() {}

Position::Position(char column, int row) : column{column}, row{row} {}

bool Position::operator==(const Position& other_pos) const {
    return (this->column == other_pos.column && this->row == other_pos.row);
}

bool valid_position(Position position) {
    if ((1 <= position.row && position.row <= 8) 
    && ('a' <= position.column && position.column <= 'h')) return true;
    return false;
}

bool increasing_column(Position pos1, Position pos2) {
    return pos1.column < pos2.column;
}

bool valid_player_colour(PlayerColour player_colour) {
    if (player_colour == PlayerColour::White || player_colour == PlayerColour::Black) return true;
    return false;
}

bool valid_direction(Direction direction) {
    if (direction == Direction::Forward || direction == Direction::Backward ||
        direction == Direction::Right || direction == Direction::Left ||
        direction == Direction::ForwardRight || direction == Direction::ForwardLeft ||
        direction == Direction::BackwardRight || direction == Direction::BackwardLeft) {
        return true;
    }
    return false;
}

bool valid_chess_move_type(MoveType move_type) {
    if (move_type == MoveType::Capturing || move_type == MoveType::Evading || move_type == MoveType::Neutral
    ||  move_type == MoveType::Castling || move_type == MoveType::EnPassant || move_type == MoveType::Upgrade
    ||  move_type == MoveType::Dangerous || move_type == MoveType::CapturingForFree || move_type == MoveType::SafeNeutral) {
        return true;
    }
    return false;
}

bool is_move_t1(MoveType move_type) {
    if (move_type == MoveType::Castling) {
        return true;
    }
    return false;
}

int safe_division(int num, int den) { // where den > 0
    if (den <= 0) {
        return 0;
    }
    int absolute_num = 1;
    if (num < 0) {
        absolute_num = -num;
    } else {
        absolute_num = num;
    }
    if (absolute_num < den) {
        return 0;
    } else if (num < 0) {
        return -(absolute_num / den);
    }
    return num / den;
}