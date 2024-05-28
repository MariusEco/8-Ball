#ifndef OOP_HANGMANCONTEXT_H
#define OOP_HANGMANCONTEXT_H

#include "HangmanStrategy.h"
#include <memory>

class HangmanContext {
private:
    std::unique_ptr<HangmanStrategy> strategy_;
public:
    explicit HangmanContext(std::unique_ptr<HangmanStrategy> strategy = nullptr);

    /// \brief Sets the strategy for the Hangman game.
    /// \param strategy a unique pointer to a HangmanStrategy object.
    void setStrategy(std::unique_ptr<HangmanStrategy> strategy);

    /// \brief Executes the current strategy's game method.
    void executeGame() const;
};

#endif