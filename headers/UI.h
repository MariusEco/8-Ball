#ifndef OOP_UI_H
#define OOP_UI_H

#include <string>
#include <iostream>
#include <limits>
#include "Player.h"

class UI {
public:
    UI() = default;

    /// \brief Displays a welcome message and starts the game
    static void beginGame();

    /// \brief Displays the word that you are guessing
    /// \param word constant reference to a string object that contains the word that you are guessing
    static void displayWord(const std::string &word);

    /// \brief Displays a typed message
    /// \param message constant reference to a string object that contains a typed message
    static void displayMessage(const std::string &message);

    /// \brief Displays the number of tries remaining
    /// \param tries integer variable that contains the number of tries remaining
    static void displayTries(int tries);

    /// \brief Displays if the player has won or lost
    /// \param is_winner bool variable that determines the win/lose state
    /// \param secret constant reference to a string object that contains the word that we need to guess
    static void displayEnd(bool is_winner, const std::string &secret, Player &player);

    /// \brief Reads the introduced player name and stores it
    /// \param player Player object that stores the name
    static void readPlayerName(Player &player);

    /// \brief Creates a simple terminal display of the word that we have to guess
    /// \param secret constant reference to a string object that contains the secret word read from a file
    /// \param word_to_guess reference to a string object that contains the display of the secret word
    static void createDisplayedWord(const std::string &secret, std::string &word_to_guess);
};


#endif