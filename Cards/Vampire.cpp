#include "Vampire.h"


Vampire::Vampire():
 BattleCard()
{}

 void BattleCard::applyEncounter(Player &player) const 
 {
    if(player.getAttackStrength()>=VAMPIRE_FORCE)
    {
        player.addCoins(VAMPIRE_LOOT);
        player.levelUp();
    }
    else
    {
        player.debuff(1);
        player.damage(VAMPIRE_HP);
    }
    
}
