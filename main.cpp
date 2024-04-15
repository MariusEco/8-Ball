#include "headers/HangmanGameWithTimer.h"
#include "headers/HangmanGameWithScores.h"
#include "headers/HangmanGame.h"
#include <iostream>
#include "headers/Exceptions.h"

int main() {
    try {
        std::cout << "Choose the game type (1/2/3):\n"
                  << "1. Hangman Game Classic\n"
                  << "2. Hangman Game With Scores\n"
                  << "3. Hangman Game With Timer\n"
                  << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        Player player;
        switch (choice) {
            case 1: {
                HangmanGame game(player);
                game.game();
                break;
            }
            case 2: {
                Highscore highscore(player, 0);
                HangmanGameWithScores gameWithScores(highscore, player);
                gameWithScores.game();
                break;
            }
            case 3: {
                Highscore highscore(player, 0);
                std::shared_ptr<AbstractHangman> ptr = std::make_shared<HangmanGameWithScores>(highscore, player);
                HangmanGameWithTimer gameWithTimer(ptr, player);
                gameWithTimer.game();
                break;
            }
            default:
                std::cout << "Invalid choice! Exiting the program.\n";
                return 0;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
