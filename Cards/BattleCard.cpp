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
    printMonsterDetails(std::cout, m_force, m_hp, m_loot, true);
    printEndOfCardDetails(std::cout);
}