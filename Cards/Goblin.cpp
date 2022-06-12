#include "Goblin.h"


Goblin::Goblin():
 BattleCard()
{}

 void BattleCard::applyEncounter(Player &player) const 
 {
    if(player.getAttackStrength()>=GOBLIN_FORCE)
    {
        player.addCoins(GOBLIN_LOOT);
        player.levelUp();
    }
    else
    {
        player.damage(GOBLIN_HP);
    }
}
