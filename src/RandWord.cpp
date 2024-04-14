#include <fstream>
#include "../headers/RandWord.h"

std::string RandWord::getRandomWord() {
//        std::vector<std::string> fileNames = {"fruits.txt", "animals.txt", "home_objects.txt", "jobs.txt", "sports.txt",
//                                              "transport.txt", "clothes.txt"};
    std::vector<std::string> fileNames = {"test.txt"};

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(fileNames.size()) - 1);
    int fileIndex = distribution(rng);
    std::string fileName = fileNames[fileIndex];

    std::ifstream file(fileName);


    std::vector<std::string> words;
    std::string line;
    while (std::getline(file, line)) {
        words.push_back(line);
    }


    std::uniform_int_distribution<int> wordDistribution(0, static_cast<int>(words.size()) - 1);
    int wordIndex = wordDistribution(rng);
    return words[wordIndex];

}

