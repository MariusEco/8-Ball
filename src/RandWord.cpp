#include <stdexcept>
#include <fstream>
#include <iostream>
#include "../headers/RandWord.h"

std::string RandWord::getRandomWord() {
    try {
        std::vector<std::string> fileNames = {"fruits.txt", "animals.txt", "home_objects.txt", "jobs.txt", "sports.txt",
                                              "transport.txt", "clothes.txt"};
//        std::vector<std::string> fileNames = {"test.txt"};
        if (fileNames.empty()) {
            throw std::invalid_argument("The list of file names is empty");
        }

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> distribution(0, static_cast<int>(fileNames.size()) - 1);
        int fileIndex = distribution(rng);
        std::string fileName = fileNames[fileIndex];

        std::ifstream file(fileName);
        if (!file.is_open()) {
            throw std::runtime_error("Couldn't open file: " + fileName);
        }

        std::vector<std::string> words;
        std::string line;
        while (std::getline(file, line)) {
            words.push_back(line);
        }

        if (words.empty()) {
            throw std::runtime_error("The file is empty: " + fileName);
        }

        std::uniform_int_distribution<int> wordDistribution(0, static_cast<int>(words.size()) - 1);
        int wordIndex = wordDistribution(rng);
        return words[wordIndex];
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return "";
    }
}
