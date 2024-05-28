#ifndef OOP_HANGMANGAME_H
#define OOP_HANGMANGAME_H

#include <string>
#include <iostream>
#include "UI.h"
#include "Player.h"
#include "HangmanStrategy.h"

class HangmanGame : public HangmanStrategy {
public:

    explicit HangmanGame(const Player &player, int incorrectGuesses = 0, const std::string &guessedLetters = "",
                         int maxTries = 6);

    void game() override;

};

#endif