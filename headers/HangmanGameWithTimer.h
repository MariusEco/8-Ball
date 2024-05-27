#ifndef OOP_HANGMANGAMEWITHTIMER_H
#define OOP_HANGMANGAMEWITHTIMER_H

#include <memory>
#include <chrono>
#include <ostream>
#include "AbstractHangman.h"
#include "GameStatistics.h"

class HangmanGameWithTimer : public AbstractHangman {
private:
    std::shared_ptr<AbstractHangman> ptr;
    GameStatistics<int> &gamesPlayed;

public:
    HangmanGameWithTimer(std::shared_ptr<AbstractHangman> ptr, const Player &player, GameStatistics<int> &gamesPlayed,
                         int incorrectGuesses = 0,
                         const std::string &guessedLetters = "", int maxTries = 6);

    void game() override;
};

#endif