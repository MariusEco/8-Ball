#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class FileOpenException : public std::runtime_error {
public:
    explicit FileOpenException(const std::string& msg);
};

class EmptyFileException : public std::runtime_error {
public:
    explicit EmptyFileException(const std::string& msg);
};

class InvalidWordsException : public std::runtime_error {
public:
    explicit InvalidWordsException(const std::string& msg);
};

#endif