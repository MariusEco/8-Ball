#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int score;
public:
    Player() : score(0) {}

    /// \brief Updates the name of the player
    void setName(const std::string &playerName) {
        name = playerName;
    }

    /// \brief Updates the score of the player
    void setScore(const int playerScore) {
        score = playerScore;
    }

    /// \brief Increases the score of the player
    void incrementScore() {
        score += 10;
    }

    /// \return the score of the player
    [[nodiscard]] int getScore() const {
        return score;
    }

    /// \return the name of the player
    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

};

#endif