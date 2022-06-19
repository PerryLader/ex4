#include "Gang.h"
#include "../utilities.h"

Gang::Gang() : Card(GANG), m_gangCards()
{}

void Gang::printCard() const
{
    std::cout << "start Gang card" << std::endl;
    for (int i = 0; i < m_gangCards.size(); i++)
    {
        std::cout << "Gang member number: " << i << std::endl;
        m_gangCards[i]->printCard();
    }
    std::cout << "end Gang card" << std::endl;
}

void Gang::applyEncounter(Player &player) const
{
    int counter = 0;
    bool didLose = false;
    while (!didLose && counter < m_gangCards.size())
    {
        didLose = m_gangCards[counter]->applyGangEncounter(player);
        counter++;
    }
    if (counter == m_gangCards.size())
    {
        player.levelUp();
    }
    while (counter < m_gangCards.size() && !player.isKnockedOut())
    {
        m_gangCards[counter]->applyLostEncounter(player);
    }
}