#ifndef Exepetion_H_
#define Exepetion_H_
#include "iostream"
#include <exception>

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

class DeckFileNotFound : public std::exception
{
public:
    const char *what() const throw() override
    {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError : public std::exception
{

public:
    std::string m_msg;
    DeckFileFormatError(int lineNumber){
        m_msg = "Deck File Error: File format error in line " + std::to_string(lineNumber);
    }
    const char *what()  const throw () override

    {
        return m_msg.c_str();
    }
};

class DeckFileInvalidSize : public std::exception
{

public:
    const char *what() const throw() override
    {
        return "Deck File Error: Deck size is invalid";
    }
};
#endif

