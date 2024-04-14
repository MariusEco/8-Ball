#ifndef OOP_HANGMANGAME_H
#define OOP_HANGMANGAME_H

#include <string>
#include <iostream>
#include "UI.h"
#include "Player.h"
#include "Highscore.h"

class HangmanGame {
private:
    Highscore highscore;
    Player player;
    /// \brief Number of incorrect guesses
    int incorrectGuesses;
    /// \brief The letters that have been guessed so far
    std::string guessedLetters;
    /// \brief The maximum number of tries
    const int MAX_TRIES;
public:

    HangmanGame(const Highscore &highscore, const Player &player, int incorrectGuesses=0,
                const std::string &guessedLetters="", int maxTries=6);

/// \brief Decides if a character is a letter
    /// \param letter constant reference to a character
    /// \return true if the character is a letter, false otherwise
    static bool not_letter(const char &letter);

    /// \brief Updates the word that we have to guess based on if the letter guessed is in the word or not
    /// \param secret the word that we have to guess
    /// \param letter the letter that has been guessed
    /// \param word_to_guess the terminal display of the word that we have to guess
    /// \return a bool variable which represents if the letter that has been guessed was in the word or not
    static int addLetters(const std::string &secret, const char &letter, std::string &word_to_guess);

    /// \brief Main game function that runs the proper game code
    void game();

    friend std::ostream &operator<<(std::ostream &os, const HangmanGame &game);

};

#endif