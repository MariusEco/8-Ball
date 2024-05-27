#include <fstream>
#include "../headers/RandWord.h"
#include "../headers/Exceptions.h"

std::pair<std::string, std::string> RandWord::getRandomWord() {
    try {
        /// \brief Vector that includes all the files
//        std::vector<std::string> fileNames = {"sports.txt", "animals.txt", "clothes.txt", "fruits.txt",
//                                              "home_objects.txt", "jobs.txt", "transport.txt"};
        std::vector<std::string> fileNames = {"testing.txt"};

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> fileDistribution(0, static_cast<int>(fileNames.size()) - 1);
        /// \brief The random file that has been chosen from the vector
        std::string chosenFileName = fileNames[fileDistribution(rng)];

        std::ifstream file(chosenFileName);
        if (!file.is_open()) {
            throw FileOpenException("Failed to open words file!");
        }

        /// \brief The vector which stores all the words from the chosen file
        std::vector<std::string> words;
        std::string word;
        while (file >> word) {
            bool validWord = true;
            /// \brief Checking for invalid words
            for (char c: word) {
                if (!std::isalpha(c) && c != '\'' && c != '-') {
                    validWord = false;
                    break;
                }
            }
            if (validWord)
                words.push_back(word);
            else throw InvalidWordsException("Invalid word found in file!");
        }

        if (words.empty()) {
            throw EmptyFileException("No words found in the file!");
        }

        std::uniform_int_distribution<int> wordDistribution(0, static_cast<int>(words.size()) - 1);
        int index = wordDistribution(rng);

        /// \brief Removing the file extension from the name
        auto dot = chosenFileName.find_last_of('.');
        if (dot != std::string::npos)
            chosenFileName = chosenFileName.substr(0, dot);

        return {words[index], chosenFileName};
    } catch (const std::exception &) {
        throw;
    }
}
