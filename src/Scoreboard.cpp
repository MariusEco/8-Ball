#include "../headers/Scoreboard.h"

std::ostream &operator<<(std::ostream &os, const Scoreboard &scoreboard) {
    for (const auto &player: scoreboard.players) {
        os << player << " ";
    }
    return os;
}