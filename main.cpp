#include <iostream>
#include <vector>
#include <random>
#include <limits>

class RandWord {
public:
    RandWord() = default;
    /// \brief Selects a random word from a list
    /// \return a random word
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

    /// \brief Displays a welcome message and starts the game
    static void beginGame() {
        std::cout << "Welcome to the Hangman game!" << "\n";
        std::cout << "Press enter to continue..." << "\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    };

    /// \brief Displays the word that you are guessing
    /// \param word constant reference to a string object that contains the word that you are guessing
    static void displayWord(const std::string &word) {
        std::cout << "Word to guess: " << word << "\n";
    };

    /// \brief Displays a typed message
    /// \param message constant reference to a string object that contains a typed message
    static void displayMessage(const std::string &message) {
        std::cout << message << "\n";
    }

    /// \brief Displays the number of tries remaining
    /// \param tries integer variable that contains the number of tries remaining
    static void displayTries(int tries) {
        std::cout << "Tries remaining: " << tries << "\n";
    }

    /// \brief Displays if the player has won or lost
    /// \param is_winner bool variable that determines the win/lose state
    /// \param secret constant reference to a string object that contains the word that we need to guess
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
    /// \brief Number of incorrect guesses
    int incorrectGuesses;
    /// \brief The letters that have been guessed so far
    std::string guessedLetters;
    /// \brief The maximum number of tries
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

    /// \brief Decides if a character is a letter
    /// \param letter constant reference to a character
    /// \return true if the character is a letter, false otherwise
    static bool not_letter(const char& letter) {
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            return true;
        } else
            return false;
    }

    /// \brief Updates the word that we have to guess based on if the letter guessed is in the word or not
    /// \param secret the word that we have to guess
    /// \param letter the letter that has been guessed
    /// \param word_to_guess the terminal display of the word that we have to guess
    /// \return a bool variable which represents if the letter that has been guessed was in the word or not
    static int addLetters(const std::string& secret, const char& letter, std::string& word_to_guess){
        bool search = false;
        for (int i = 0; i < int(secret.length()); ++i) {
            if (secret[i] == letter) {
                word_to_guess[i] = letter;
                search = true;
            }
        }
        return search;
    }

    /// \brief Main game function that runs the proper game code
    void game() {
        /// \brief The word that we have to guess
        std::string secret = RandWord::getRandomWord();
        /// \brief A simple terminal display of the word we have to guess
        std::string word_to_guess(secret.length(), '*');
        UI::beginGame();
        /// \brief Condition for the game to continue
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
            bool search=addLetters(secret,letter,word_to_guess);
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