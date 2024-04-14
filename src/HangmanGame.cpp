#include "../headers/HangmanGame.h"
#include "../headers/RandWord.h"

HangmanGame::HangmanGame(const Highscore &highscore, const Player &player, int incorrectGuesses,
                         const std::string &guessedLetters, int maxTries) : highscore(highscore), player(player),
                                                                                  incorrectGuesses(incorrectGuesses),
                                                                                  guessedLetters(guessedLetters),
                                                                                  MAX_TRIES(maxTries) {}

std::ostream &operator<<(std::ostream &os, const HangmanGame &game) {
    os << "highscore: " << game.highscore << " player: " << game.player << " incorrectGuesses: "
       << game.incorrectGuesses << " guessedLetters: " << game.guessedLetters << " MAX_TRIES: " << game.MAX_TRIES;
    return os;
}

bool HangmanGame::not_letter(const char &letter) {
    if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
        return true;
    } else
        return false;
}

int HangmanGame::addLetters(const std::string &secret, const char &letter, std::string &word_to_guess) {
    bool search = false;
    for (int i = 0; i < int(secret.length()); ++i) {
        if (secret[i] == letter) {
            word_to_guess[i] = letter;
            search = true;
        }
    }
    return search;
}

void HangmanGame::game() {
    UI::beginGame();
    UI::readPlayerName(player);
    bool play = true;
    while (play) {
        player.setScore(0);
        while (true) {
            guessedLetters = "";
            incorrectGuesses = 0;
            /// \brief The word that we have to guess
            std::string secret = RandWord::getRandomWord();
            /// \brief A simple terminal display of the word we have to guess
            std::string word_to_guess;
            UI::createDisplayedWord(secret, word_to_guess);
            /// \brief Condition for the game to continue
            while (incorrectGuesses < MAX_TRIES && word_to_guess != secret) {

                UI::displayWord(word_to_guess);

                char letter;
                std::cout << "Guess a letter: ";
                /// \brief Restriction for only 1 character input
                while (!(std::cin >> letter) || std::cin.peek() != '\n') {
                    std::cout << "Invalid input. Please enter a single letter: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                if (!HangmanGame::not_letter(letter)) {
                    UI::displayMessage("Oops! That is not a valid letter. Try another one!");
                    incorrectGuesses++;
                    UI::displayTries(MAX_TRIES - incorrectGuesses);
                    continue;
                }
                if (guessedLetters.find(letter) != std::string::npos) {
                    UI::displayMessage("Oops! You already tried to guess that letter. Try another one!");
                    incorrectGuesses++;
                    UI::displayTries(MAX_TRIES - incorrectGuesses);
                    continue;
                }

                guessedLetters += letter;
                bool search = HangmanGame::addLetters(secret, letter, word_to_guess);
                if (!search) {
                    incorrectGuesses++;
                    UI::displayMessage("Unfortunately the letter " + std::string(1, letter) +
                                       " is not found in the word. Try another one!");
                    UI::displayTries(MAX_TRIES - incorrectGuesses);
                }

            }
            if (word_to_guess == secret) {
                UI::displayEnd(true, secret);
                player.incrementScore();
                std::cout << "Current Score: " << player.getScore() << "\n";
                highscore.displayHighscore();
            } else {
                UI::displayEnd(false, secret);
                std::cout << "Final score: " << player.getScore() << "\n";
                highscore.displayHighscore();
                break;
            }
        }
        int score = player.getScore();
        highscore.updateHighscore(player, score);
        std::string answer;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> answer;
        if (answer == "y" || answer == "Y") {
            play = true;
        } else play = false;
    }
}