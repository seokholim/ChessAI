#include <iostream>
#include "chess_game.h"

using namespace std;

int main () {
    
    ChessGame g;

    g.initialize_players();

    g.initialize_pieces();

    g.start();

    return 0;
}