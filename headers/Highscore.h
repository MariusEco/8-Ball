#ifndef OOP_HIGHSCORE_H
#define OOP_HIGHSCORE_H

#include <ostream>
#include "Player.h"

class Highscore {
private:
    Player player;
    int highscore;
public:
    Highscore(const Player &player, int highscore);

    /// \brief Updates the current final score of the player, if said score is higher than the current highscore
    /// \param player Player object used to get the name of the player
    /// \param score integer that contains the current score
    void updateHighscore(const Player &player, int score);

    /// \brief Displays the current highscore
    void displayHighscore() const;

    friend std::ostream &operator<<(std::ostream &os, const Highscore &highscore);
};

#endif