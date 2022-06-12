#include "Dragon.h"


Dragon::Dragon():
 BattleCard()
{}

 void BattleCard::applyEncounter(Player &player) const 
 {
    if(player.getAttackStrength()>=DRAGON_FORCE)
    {
        player.addCoins(DRAGON_LOOT);
        player.levelUp();
    }
    else
    {
        player.damage(player.getCurrHp());
        player.damage(DRAGON_HP);
    }
}