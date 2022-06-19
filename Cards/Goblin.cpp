#include "Goblin.h"
#include "../utilities.h"
using std::string;

Goblin::Goblin():
 BattleCard(GOBLIN)
{
    m_force = GOBLIN_FORCE;
    m_hp = GOBLIN_HP;
    m_loot = GOBLIN_LOOT;
}

 void Goblin::applyEncounter(Player &player) const 
 {
    if(player.getAttackStrength()>=GOBLIN_FORCE)
    {
        player.addCoins(GOBLIN_LOOT);
        player.levelUp();
        printWinBattle(player.getName(),GOBLIN);

    }
    else
    {
        player.damage(GOBLIN_HP);
        printLossBattle(player.getName(),GOBLIN);

    }
}
