#ifndef OOP_HANGMANGAME_H
#define OOP_HANGMANGAME_H

#include <string>
#include <iostream>
#include "UI.h"
#include "Player.h"
#include "AbstractHangman.h"

class HangmanGame : public AbstractHangman {
public:
    explicit HangmanGame(const Player &player, int incorrectGuesses = 0, const std::string &guessedLetters = "",
                         int maxTries = 6);

    void game() override;

};

#endif