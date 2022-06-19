#include "Card.h"

Card::Card(const std::string name):m_name(name)
{}

 void Card::printCard() const
{
    printCardDetails(std::cout,m_name);
    printEndOfCardDetails(std::cout);
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    card.printCard();
    return std::cout;
}