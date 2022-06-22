
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include "iostream"
#include <exception>
//a class that inherit from exeption.
//throw when the deck of cards file was not found
class DeckFileNotFound : public std::exception
{
public:
    const char *what() const throw() override
    {
        return "Deck File Error: File not found";
    }
};
//a class that inherit from exeption.
//throw when the deck of cards is not leagal
//unrecognized card
//Gang without EndGang
class DeckFileFormatError : public std::exception
{

public:
//conatain a massege that indicate the row in deck file that was illegal
    std::string m_msg;
    DeckFileFormatError(int lineNumber)
    {
        m_msg = "Deck File Error: File format error in line " + std::to_string(lineNumber);
    }
    
    const char *what() const throw() override
    {
        return m_msg.c_str();
    }
};
//a class that inherit from exeption.
//throw when the deck of cards contains less then 5 cards
class DeckFileInvalidSize : public std::exception
{

public:
    const char *what() const throw() override
    {
        return "Deck File Error: Deck size is invalid";
    }
};
#endif
