#include "../headers/UI.h"

void UI::beginGame() {
    std::cout << "Welcome to the Hangman game!" << "\n";
    std::cout << "Press enter to continue..." << "\n";
    std::string enter;
    std::getline(std::cin, enter);
}

void UI::displayWord(const std::string &word) {
    std::cout << "Word to guess: " << word << "\n";
}

void UI::displayMessage(const std::string &message) {
    std::cout << message << "\n";
}

void UI::displayTries(int tries) {
    std::cout << "Tries remaining: " << tries << "\n";
}

void UI::displayEnd(bool is_winner, const std::string &secret) {
    if (is_winner)
        std::cout << "Congratulations! You guessed the word: " << secret << "\n";
    else std::cout << "Sorry, you ran out of tries. The word was: " << secret << "\n";
}

void UI::readPlayerName(Player &player) {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;
    player.setName(playerName);
}

void UI::createDisplayedWord(const std::string &secret, std::string &word_to_guess) {
    for (char letter: secret) {
        if (letter == '-' || letter == ' ' || letter == '\'')
            word_to_guess += letter;
        else word_to_guess += '*';
    }
}