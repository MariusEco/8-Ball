#ifndef OOP_HANGMANGAMEWITHSCORES_H
#define OOP_HANGMANGAMEWITHSCORES_H

#include <ostream>
#include "AbstractHangman.h"
#include "Highscore.h"
#include "GameStatistics.h"

class HangmanGameWithScores : public AbstractHangman {
private:
    Highscore highscore;
    GameStatistics<int> &gamesPlayed;
public:

    HangmanGameWithScores(const Highscore &highscore, const Player &player, GameStatistics<int> &gamesPlayed,
                          int incorrectGuesses = 0,
                          const std::string &guessedLetters = "", int maxTries = 6);

    void game() override;

    [[nodiscard]] Highscore* getHighscore() const;

};

#endif