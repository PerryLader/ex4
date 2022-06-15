#include "iostream"
#include <exception>

class DeckFileNotFound : public std::exception
{
public:
    const char *what() const override
    {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError : public std::exception
{

public:
    int m_lineNumber;
    DeckFileFormatError(int lineNumber) : m_lineNumber(lineNumber) {}
    const char *what() const override
    {
        std::string temp = "Deck File Error: File format error in line " + std::to_string(m_lineNumber);
        return temp.c_str();
    }
};

class DeckFileInvalidSize : public std::exception
{

public:
    const char *what() const override
    {
        return "Deck File Error: Deck size is invalid";
    }
};
