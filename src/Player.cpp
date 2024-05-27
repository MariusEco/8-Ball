#include "../headers/Player.h"

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

int Player::getScore() const {
    return score;
}

const std::string &Player::getName() const {
    return name;
}