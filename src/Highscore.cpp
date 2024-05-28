#include "../headers/Highscore.h"

void Highscore::updateHighscore(const Player &player1, int score) {
    if (score > highscore) {
        highscore = score;
        std::cout << "Congratulations, " << player1.getName() << "! You have a new highscore: " << highscore << "\n";
    }
}

void Highscore::displayHighscore() const {
    std::cout << "Highscore : " << highscore << "\n";
}

Highscore::Highscore(const Player &player, int highscore) : player(player), highscore(highscore) {}

Highscore *Highscore::instance = nullptr;

Highscore *Highscore::getInstance(const Player &player, int highscore) {
    if (instance == nullptr) {
        instance = new Highscore(player, highscore);
    }
    return instance;
}