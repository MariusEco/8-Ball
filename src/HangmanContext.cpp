#include "../headers/HangmanContext.h"

HangmanContext::HangmanContext(std::unique_ptr<HangmanStrategy> strategy) : strategy_(std::move(strategy)) {}

void HangmanContext::setStrategy(std::unique_ptr<HangmanStrategy> strategy) {
    strategy_ = std::move(strategy);
}

void HangmanContext::executeGame() const {
    strategy_->game();
}