#include "headers/HangmanGameWithTimer.h"
#include "headers/HangmanGameWithScores.h"
#include "headers/HangmanGame.h"
#include <iostream>
#include "headers/Exceptions.h"
#include "headers/GameStatistics.h"

int main() {
    GameStatistics<int> gamesPlayed("Games Played", 0);
    GameStatistics<double> totalTimePlayed("Total Time Played", 0.0);

    try {
        std::cout << "Choose the game type (1/2/3):\n"
                  << "1. Hangman Game Classic\n"
                  << "2. Hangman Game With Scores\n"
                  << "3. Hangman Game With Timer\n"
                  << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        Player player;

        auto start = std::chrono::steady_clock::now();

        switch (choice) {
            case 1: {
                HangmanGame game(player);
                game.game();
                gamesPlayed.incrementStat(1);
                break;
            }
            case 2: {
                Highscore highscore(player, 0);
                HangmanGameWithScores gameWithScores(highscore, player, gamesPlayed);
                gameWithScores.game();
                break;
            }
            case 3: {
                Highscore highscore(player, 0);
                std::shared_ptr<AbstractHangman> ptr = std::make_shared<HangmanGameWithScores>(highscore, player,
                                                                                               gamesPlayed);
                HangmanGameWithTimer gameWithTimer(ptr, player, gamesPlayed);
                gameWithTimer.game();
                break;
            }
            default:
                std::cout << "Invalid choice! Exiting the program.\n";
                return 0;
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        totalTimePlayed.incrementStat(elapsed.count());

        std::cout << "Statistics:\n";
        gamesPlayed.displayStatistic();
        totalTimePlayed.displayStatistic();
        std::cout << "Thanks for playing!\n";

    } catch (const std::exception &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
