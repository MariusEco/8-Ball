#ifndef OOP_HANGMANGAMEWITHSCORES_H
#define OOP_HANGMANGAMEWITHSCORES_H

#include <ostream>
#include "HangmanStrategy.h"
#include "Highscore.h"
#include "GameStatistics.h"

class HangmanGameWithScores : public HangmanStrategy {
private:

    GameStatistics<int> &gamesPlayed;
public:

    HangmanGameWithScores(const Player &player, GameStatistics<int> &gamesPlayed,
                          int incorrectGuesses = 0,
                          const std::string &guessedLetters = "", int maxTries = 6);

    void game() override;

};

#endif