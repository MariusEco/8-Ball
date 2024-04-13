#ifndef OOP_SCOREBOARD_H
#define OOP_SCOREBOARD_H


#include <vector>
#include "Player.h"

class [[maybe_unused]] Scoreboard {
private:
    std::vector<Player> players;
public:
    [[maybe_unused]] explicit Scoreboard(const std::vector<Player> &players) : players(players) {}

    friend std::ostream &operator<<(std::ostream &os, const Scoreboard &scoreboard);
};


#endif
