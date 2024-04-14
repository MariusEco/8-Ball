#include "headers/HangmanGame.h"

int main() {
    Player player;
    Highscore highscore(player, 0);
    HangmanGame game(highscore, player);
    game.game();
    return 0;
}