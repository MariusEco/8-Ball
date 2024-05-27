#ifndef OOP_RANDWORD_H
#define OOP_RANDWORD_H

#include <string>
#include <random>

class RandWord {
public:
    RandWord() = default;

    /// \brief Selects a random word from a list
    /// \return a random word
    static std::pair<std::string, std::string> getRandomWord();
};

#endif