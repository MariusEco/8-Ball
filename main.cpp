#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class RandWord{
public:
    RandWord()=default;
    friend std::ostream &operator<<(std::ostream &os, const RandWord &) {
        return os;
    }
    // functie de alegere a unui cuvant random temporara nu foarte buna
    // implementare librarie random C++11
    // citire din fisierul tuturor cuvintelor din limba engleza
    static std::string getRandomWord() {
        const std::string wordList[4] = {"test1", "test2", "test3", "test4"};
        srand(static_cast<unsigned int>(time(nullptr)));
        std::string word = wordList[rand() % 4];
        return word;
    }
};
class Player{
private:
    std::string name;
    int score;
public:
    Player(const std::string& name, int score) : name(name), score(score) {}

    Player(const Player& other)= default;

    Player& operator=(const Player& other) {
        name = other.name;
        score = other.score;
        return *this;
    }

    ~Player()= default;

    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << "name: " << player.name << " score: " << player.score;
        return os;
    }

    std::string getName() const{
        return name;
    }

    void increaseScore(int points) {
        score += points;
    }

    int getScore() const {
        return score;
    }
};
class Scoreboard{
private:
    std::vector<Player> players;
public:
    explicit Scoreboard(const std::vector<Player> &players) : players(players) {}

    friend std::ostream &operator<<(std::ostream &os, const Scoreboard &scoreboard) {
        for (const auto& player : scoreboard.players) {
            os << player << " ";
        }
        return os;

    }
};
class UI{
private:
    std::string display;
public:
    explicit UI(const std::string &display) : display(display) {}

    friend std::ostream &operator<<(std::ostream &os, const UI &ui) {
        os << "display: " << ui.display;
        return os;
        // functii de afisare
    }

};
class HangmanGame{
private:
    Scoreboard scoreboard;
    UI ui;
    Player player;
    RandWord random;
    int incorrectGuesses;
    std::string guessedLetters;
    const int MAX_TRIES;
public:
    HangmanGame(const Scoreboard &scoreboard, const UI &ui, const Player &player, const RandWord &random,
                int incorrectGuesses=0, const std::string &guessedLetters="", const int maxTries=6) : scoreboard(scoreboard),
                                                                                                      ui(ui), player(player),
                                                                                                      random(random),
                                                                                                      incorrectGuesses(
                                                                                                              incorrectGuesses),
                                                                                                      guessedLetters(
                                                                                                              guessedLetters),
                                                                                                      MAX_TRIES(maxTries) {}

    friend std::ostream &operator<<(std::ostream &os, const HangmanGame &game) {
        os << "scoreboard: " << game.scoreboard << " ui: " << game.ui << " player: " << game.player
           << " incorrectGuesses: " << game.incorrectGuesses << " guessedLetters: " << game.guessedLetters
           << " MAX_TRIES: " << game.MAX_TRIES;
        return os;
    }
    static bool not_letter(const char letter) {
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            return true;
        } else
            return false;
    }

    void joc() const{
        //std::string secret= random.getRandomWord();
        //std::string word_to_guess(secret.length(),'_');

        int  tries = 0;
        while (tries < MAX_TRIES){
            //facem display la word_to_guess cu functie din UI
            //tastam litera pe care vrem sa o ghicim
            //daca e buna il punem in word_to_guess
            //daca nu ++tries sau daca nu este litera se afiseaza un mesaj
            //daca secret=word_to_guess castigam, else continuam
            //scoreboard si altele
        }
    };
};
int main()
{   RandWord word{};
    std::cout<<RandWord::getRandomWord()<<"\n";
    Player player1("David",0);
    Player player2 = player1;
    std::cout<<player1<<"\n";
    std::cout<<player2<<"\n";
    Player player3("Maria",250);
    player1=player3;
    std::cout<<player1<<"\n";
    player1.increaseScore(50);
    std::cout<<player1<<"\n";
    std::cout<<player1.getName()<<"\n";
    std::cout<<player1.getScore()<<"\n";
    UI ui("Meniu");
    std::cout<<ui<<"\n";
    std::vector<Player> players = {
            Player("David", 100),
            Player("Rebecca", 150),
            Player("Marius", 200)
    };
    Scoreboard scoreboard(players);
    std::cout<<scoreboard<<"\n";
    HangmanGame joc(scoreboard,ui,player1,word);
    std::cout<<joc<<"\n";
    std::cout<<HangmanGame::not_letter('9')<<"\n";
    return 0;
}