#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int score;
public:

    explicit Player(const std::string &name = "", int score = 0);

    /// \brief Updates the name of the player
    void setName(const std::string &playerName);

    /// \brief Updates the score of the player
    void setScore(int playerScore);

    /// \brief Increases the score of the player
    void incrementScore();

    /// \return the score of the player
    [[nodiscard]] int getScore() const;

    /// \return the name of the player
    [[nodiscard]] const std::string &getName() const;

};

#endif