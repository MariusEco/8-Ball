#include "../headers/Player.h"

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "name: " << player.name << " score: " << player.score;
    return os;
}

Player::Player(const std::string &name, int score) : name(name), score(score) {}

void Player::setName(const std::string &playerName) {
    name = playerName;
}

void Player::setScore(const int playerScore) {
    score = playerScore;
}

void Player::incrementScore() {
    score += 10;
}

[[nodiscard]] int Player::getScore() const {
    return score;
}