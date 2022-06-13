#include "Card.h"
#include "Barfight.h"
#include "Fairy.h"
#include "Merchant.h"
#include "Pitfall.h"
#include "Treasure.h"

Card::Card(const std::string name):m_name(name)
{}
 void Card::PrintCard(const Card& card) const
{
    printCardDetails(std::cout,m_name);
    printEndOfCardDetails(std::cout);
}

