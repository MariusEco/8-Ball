#include "../headers/Player.h"

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "name: " << player.name << " score: " << player.score;
    return os;
}

Player::Player(const std::string &name, int score) : name(name), score(score) {}