#include "Gang.h"
#include "../utilities.h"

Gang::Gang(const std::vector<std::unique_ptr<BattleCard>> gangCards) : Card(GANG), m_gangCards()
{
    for (int i = 0; i < gangCards.size(); i++)
    {
        m_gangCards.push_back(std::move(gangCards[i]));
    }
}

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
    int hp = player.getCurrHp();
    int counter = 0;
    int totalForce = 0;
    while (hp == player.getCurrHp() && counter < m_gangCards.size())
    {
        hp = player.getCurrHp();
        m_gangCards[counter]->applyEncounter(player);
        counter++;
    }
    if (counter == m_gangCards.size())
    {
        player.decLvl(counter - 1);
    }
    while (counter < m_gangCards.size())
    {
        if (m_name == DRAGON)
        {
            totalForce += player.getCurrHp();
        }
        if (m_name == GOBLIN)
        {
            totalForce += GOBLIN_HP;
        }
        if (m_name == VAMPIRE)
        {
            totalForce += VAMPIRE_HP;
        }
    }
    player.damage(totalForce);
}