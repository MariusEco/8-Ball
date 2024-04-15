#include "../headers/Exceptions.h"

FileOpenException::FileOpenException(const std::string& msg)
        : std::runtime_error(msg) {}

EmptyFileException::EmptyFileException(const std::string& msg)
        : std::runtime_error(msg) {}

InvalidWordsException::InvalidWordsException(const std::string& msg)
        : std::runtime_error(msg) {}