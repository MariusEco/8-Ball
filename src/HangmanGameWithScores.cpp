#include "../headers/HangmanGameWithScores.h"
#include "../headers/RandWord.h"
#include "../headers/UI.h"

HangmanGameWithScores::HangmanGameWithScores(const Player &player,
                                             GameStatistics<int> &gamesPlayed,
                                             int incorrectGuesses,
                                             const std::string &guessedLetters, int maxTries) : HangmanStrategy(player,
                                                                                                                incorrectGuesses,
                                                                                                                guessedLetters,
                                                                                                                maxTries),
                                                                                                gamesPlayed(
                                                                                                        gamesPlayed) {}

void HangmanGameWithScores::game() {
    UI::beginGame();
    UI::readPlayerName(player);
    Highscore *highscore = Highscore::getInstance(player, 0);
    bool play = true;
    while (play) {
        gamesPlayed.incrementStat(1);
        player.setScore(0);
        while (true) {
            guessedLetters = "";
            incorrectGuesses = 0;

            std::pair<std::string, std::string> secretAndCategory = RandWord::getRandomWord();
            /// \brief The word that we have to guess
            std::string secret = secretAndCategory.first;
            /// \brief The category which the word that we have to guess belongs to
            std::string category = secretAndCategory.second;
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
                if (!HangmanStrategy::not_letter(letter)) {
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
                bool search = HangmanStrategy::addLetters(secret, letter, word_to_guess);
                if (!search) {
                    incorrectGuesses++;
                    UI::displayMessage("Unfortunately the letter " + std::string(1, letter) +
                                       " is not found in the word. Try another one!");
                    UI::displayTries(MAX_TRIES - incorrectGuesses);

                    if (MAX_TRIES - incorrectGuesses == 4)
                        UI::displayMessage("Hint: The word is from the category: " + category);
                }

            }
            if (word_to_guess == secret) {
                UI::displayEnd(true, secret, player);
                player.incrementScore();
                std::cout << "Current score: " << player.getScore() << "\n";
                highscore->displayHighscore();
            } else {
                UI::displayEnd(false, secret, player);
                std::cout << "Final score: " << player.getScore() << "\n";
                highscore->displayHighscore();
                break;
            }
        }
        int score = player.getScore();
        highscore->updateHighscore(player, score);
        std::string answer;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> answer;
        if (answer == "y" || answer == "Y") {
            play = true;
        } else play = false;
    }
}