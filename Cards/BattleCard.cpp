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
        printMonsterDetails(std::cout, DRAGON_FORCE, DRAGON_HP, DRAGON_LOOT, true);
    }
    if (m_name == GOBLIN)
    {
        printMonsterDetails(std::cout, GOBLIN_FORCE, GOBLIN_HP, GOBLIN_LOOT, false);
    }
    if (m_name == VAMPIRE)
    {
        printMonsterDetails(std::cout, VAMPIRE_FORCE, VAMPIRE_HP, VAMPIRE_LOOT, false);
    }

//     printEndOfCardDetails(std::cout);
// }