#include <fstream>
#include "../headers/RandWord.h"

std::string RandWord::getRandomWord() {
    std::ifstream file("test.txt");

    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(words.size()) - 1);
    int index = distribution(rng);

    return words[index];
}

