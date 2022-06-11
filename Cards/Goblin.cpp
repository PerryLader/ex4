#include "Goblin.h"

Goblin::Goblin(const string name):
 BattleCard(name,6,2,10)
{}

 void BattleCard::applyEncounter(Player &player) const 
 {
    if(player.getAttackStrength()>=m_force)
    {
        player.addCoins(m_loot);
        player.levelUp();
    }
    else
    {
        player.damage(m_hp);
    }
}
