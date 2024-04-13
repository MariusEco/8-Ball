#include "../headers/Highscore.h"

void Highscore::updateHighscore(const Player &player, int score) {
    if (score > highscore) {
        highscore = score;
        std::cout << "Congratulations, " << player.getName() << "! You have a new highscore: " << highscore << "\n";
    }
}

void Highscore::displayHighscore() const {
    std::cout << "Highscore : " << highscore << "\n";
}

Highscore::Highscore(const Player &player, int highscore) : player(player), highscore(highscore) {}

std::ostream &operator<<(std::ostream &os, const Highscore &highscore) {
    os << "player: " << highscore.player << " highscore: " << highscore.highscore;
    return os;
}
