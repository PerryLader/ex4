#include "BattleCard.h"

BattleCard::BattleCard(const string name,const int force,const int loot,const int hp):
 Card(name),
 m_force(force),
 m_loot(loot),
 m_hp(hp)
{}

// void Card::applyEncounter(Player &player) const
// {
    
// }
