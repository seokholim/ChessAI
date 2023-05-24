#include <iostream>
#include "chess_game.h"

using namespace std;

int main () {

    // human vs human, human vs basic computer

    ChessGame g;

    g.init();

    g.play();

    return 0;
}