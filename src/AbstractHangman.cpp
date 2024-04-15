#include "../headers/AbstractHangman.h"

AbstractHangman::AbstractHangman(const Player &player, int incorrectGuesses,
                                 const std::string &guessedLetters, int maxTries) : player(player),
                                                                                    incorrectGuesses(incorrectGuesses),
                                                                                    guessedLetters(guessedLetters),
                                                                                    MAX_TRIES(maxTries) {}


bool AbstractHangman::not_letter(const char &letter) {
    if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
        return true;
    } else
        return false;
}

int AbstractHangman::addLetters(const std::string &secret, const char &letter, std::string &word_to_guess) {
    bool search = false;
    for (int i = 0; i < int(secret.length()); ++i) {
        if (secret[i] == letter) {
            word_to_guess[i] = letter;
            search = true;
        }
    }
    return search;
}