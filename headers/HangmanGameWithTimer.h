#ifndef OOP_HANGMANGAMEWITHTIMER_H
#define OOP_HANGMANGAMEWITHTIMER_H

#include <memory>
#include <chrono>
#include <ostream>
#include "HangmanStrategy.h"
#include "GameStatistics.h"
#include "Highscore.h"

class HangmanGameWithTimer : public HangmanStrategy {
private:

    GameStatistics<int> &gamesPlayed;

public:
    HangmanGameWithTimer(const Player &player, GameStatistics<int> &gamesPlayed,
                         int incorrectGuesses = 0,
                         const std::string &guessedLetters = "", int maxTries = 6);

    void game() override;
};

#endif