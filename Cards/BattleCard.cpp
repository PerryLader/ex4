#include "BattleCard.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"

BattleCard::BattleCard(const std::string name) : Card(name)
{
}

void BattleCard::printCard() const
{
    printCardDetails(std::cout, m_name);
    if (m_name == DRAGON)
    {
        printMonsterDetails(std::cout, m_force, m_hp, m_loot, true);
    }
    else
    {
        printMonsterDetails(std::cout, m_force, m_hp, m_loot, false);
    }
    printEndOfCardDetails(std::cout);
}

bool BattleCard::applyGangEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.addCoins(m_loot);
        return false;
    }
    else
    {
        player.damage(m_hp);
        printLossBattle(player.getName(), m_name);
        return true;
    }
}