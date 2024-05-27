#ifndef OOP_GAMESTATISTICS_H
#define OOP_GAMESTATISTICS_H

#include <iostream>
#include <string>

template<typename T>
class GameStatistics {
private:
    /// \brief The name of the statistic
    std::string statName;
    /// \brief The value of the statistic
    T statValue;
public:
    GameStatistics(const std::string &name, const T &value) : statName(name), statValue(value) {}
    /// \brief Displays the statistic with it's current name and value
    void displayStatistic() const {
        std::cout << statName << " = " << statValue << "\n";
    }

    void incrementStat(const T &value) {
        statValue += value;
    }

};

#endif