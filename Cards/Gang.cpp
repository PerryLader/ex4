#include "Gang.h"
#include "../utilities.h"
#include <iostream>
#include "Goblin.h"
#include "Dragon.h"
#include "Vampire.h"

Gang::Gang(std::vector<std::string> cards) : Card(GANG), m_gangCards()
{
    std::map<std::string, std::unique_ptr<BattleCard>> deck;
    for (int i = 0; (unsigned int) i < cards.size(); i++)
    {
        initBattleDeckMap(deck);
        m_gangCards.push_back(std::move(deck[cards[i]]));
    }
}

void Gang::printCard() const
{
    std::cout << "start Gang card" << std::endl;
    for (int i = 0;(unsigned int) i < m_gangCards.size(); i++)
    {
        std::cout << "Gang member number: " << i << std::endl;
        m_gangCards[i]->printCard();
    }
    std::cout << "end Gang card" << std::endl;
}
void Gang::applyEncounter(Player& player) const
{
    int counter = 0;
    bool didLose = false;
    while (!didLose && (unsigned int) counter < m_gangCards.size())
    {
        didLose = m_gangCards[counter]->applyGangEncounter(player);
        counter++;
    }
    if (didLose == false)
    {
        printWinBattle(player.getName(), GANG);
        player.levelUp();
    }
    while ((unsigned int) counter < m_gangCards.size())
    {
        m_gangCards[counter]->applyLostEncounter(player);
        counter++;
    }
}

void Gang::initBattleDeckMap(std::map<std::string, std::unique_ptr<BattleCard>> &deck) const
{
    deck[GOBLIN] = std::unique_ptr<BattleCard>(new Goblin());
    deck[DRAGON] = std::unique_ptr<BattleCard>(new Dragon());
    deck[VAMPIRE] = std::unique_ptr<BattleCard>(new Vampire());
}