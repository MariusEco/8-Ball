#include <iostream>
#include <vector>
#include <random>
#include <conio.h>

class RandWord {
public:
    RandWord() = default;

    static std::string getRandomWord() {
        const std::string wordList[4] = {"apple", "banana", "kiwi", "mango"};
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> distribution(0, 3);
        int index = distribution(rng);
        return wordList[index];
    }
};

class Player {
private:
    std::string name;
    int score;
public:
    Player(const std::string &name, int score) : name(name), score(score) {}

    Player(const Player &other) = default;

    Player &operator=(const Player &other) = default;

    ~Player() = default;

    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << "name: " << player.name << " score: " << player.score;
        return os;
    }

//    const std::string &getName() const {
//        return name;
//    }
//
//    void increaseScore(int points) {
//        score += points;
//    }
//
//    int getScore() const {
//        return score;
//    }
};

class Scoreboard {
private:
    std::vector<Player> players;
public:
    explicit Scoreboard(const std::vector<Player> &players) : players(players) {}

    friend std::ostream &operator<<(std::ostream &os, const Scoreboard &scoreboard) {
        for (const auto &player: scoreboard.players) {
            os << player << " ";
        }
        return os;
    }
};

class UI {
private:
    std::string display;
public:
    explicit UI(const std::string &display) : display(display) {}

    friend std::ostream &operator<<(std::ostream &os, const UI &ui) {
        os << "display: " << ui.display;
        return os;
    }

    static void beginGame() {
        std::cout << "Welcome to the Hangman game!" << "\n";
        std::cout << "Press enter to continue..." << "\n";
        _getch();
    };

    static void displayWord(const std::string &word) {
        std::cout << "Word to guess: " << word << "\n";
    };

    static void displayMessage(const std::string &message) {
        std::cout << message << "\n";
    }

    static void displayTries(int tries) {
        std::cout << "Tries remaining: " << tries << "\n";
    }

    static void displayEnd(bool is_winner, const std::string &secret) {
        if (is_winner)
            std::cout << "Congratulations! You guessed the word: " << secret << "\n";
        else std::cout << "Sorry, you ran out of tries. The word was: " << secret << "\n";
    }
};

class HangmanGame {
private:
    Scoreboard scoreboard;
    UI ui;
    Player player;
    int incorrectGuesses;
    std::string guessedLetters;
    const int MAX_TRIES;
public:
    HangmanGame(const Scoreboard &scoreboard, const UI &ui, const Player &player,
                int incorrectGuesses = 0, const std::string &guessedLetters = "", const int maxTries = 6) : scoreboard(
            scoreboard),
                                                                                                            ui(ui),
                                                                                                            player(player),
                                                                                                            incorrectGuesses(
                                                                                                                    incorrectGuesses),
                                                                                                            guessedLetters(
                                                                                                                    guessedLetters),
                                                                                                            MAX_TRIES(
                                                                                                                    maxTries) {}

    static bool not_letter(const char& letter) {
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            return true;
        } else
            return false;
    }

    void game() {
        std::string secret = RandWord::getRandomWord();
        std::string word_to_guess(secret.length(), '*');
        UI::beginGame();
        while (incorrectGuesses < MAX_TRIES && word_to_guess != secret) {

            UI::displayWord(word_to_guess);

            char letter;
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            if (!not_letter(letter)) {
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
            bool search = false;
            for (int i = 0; i < int(secret.length()); ++i) {
                if (secret[i] == letter) {
                    word_to_guess[i] = letter;
                    search = true;
                }
            }

            if (!search) {
                incorrectGuesses++;
                UI::displayMessage("Unfortunately the letter " + std::string(1, letter) +
                                   " is not found in the word. Try another one!");
                UI::displayTries(MAX_TRIES - incorrectGuesses);
            }

        }
        if (word_to_guess == secret)
            UI::displayEnd(true, secret);
        else UI::displayEnd(false, secret);
    };

    friend std::ostream &operator<<(std::ostream &os, const HangmanGame &game) {
        os << "scoreboard: " << game.scoreboard << " ui: " << game.ui << " player: " << game.player
           << " incorrectGuesses: " << game.incorrectGuesses << " guessedLetters: " << game.guessedLetters
           << " MAX_TRIES: " << game.MAX_TRIES;
        return os;
    }
};

int main() {
    Player player1("David", 0);
    std::vector<Player> players = {
            Player("David", 100),
            Player("Rebecca", 150),
            Player("Marius", 200)
    };
    Scoreboard scoreboard(players);
    UI ui("Menu");
    HangmanGame game(scoreboard, ui, player1);
    game.game();
    return 0;
}