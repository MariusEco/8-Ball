#include "headers/HangmanGameWithTimer.h"
#include "headers/HangmanGameWithScores.h"
#include "headers/HangmanGame.h"
#include <iostream>
#include "headers/Exceptions.h"
#include "headers/GameStatistics.h"
#include "headers/HangmanContext.h"

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

        HangmanContext context;
        switch (choice) {
            case 1: {
                std::unique_ptr<HangmanStrategy> classicStrategy = std::make_unique<HangmanGame>(player);
                context.setStrategy(std::move(classicStrategy));
                gamesPlayed.incrementStat(1);
                break;
            }
            case 2: {
                std::unique_ptr<HangmanStrategy> scoresStrategy = std::make_unique<HangmanGameWithScores>(player,
                                                                                                          gamesPlayed);
                context.setStrategy(std::move(scoresStrategy));
                break;
            }
            case 3: {
                std::unique_ptr<HangmanStrategy> timerStrategy = std::make_unique<HangmanGameWithTimer>(player,
                                                                                                        gamesPlayed);
                context.setStrategy(std::move(timerStrategy));
                break;
            }
            default:
                std::cout << "Invalid choice! Exiting the program.\n";
                return 0;
        }

        context.executeGame();

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