#include <iostream>
#include "chess_game.h"

using namespace std;

int main () {

    // human vs human, human vs basic computer

    ChessGame g;

    g.initialize_players();

    g.initialize_board();

    g.start();

    return 0;
}