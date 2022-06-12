#include "Dragon.h"
#include "../utilities.h"
using namespace std;


Dragon::Dragon():
 BattleCard()
{}

 void Dragon::applyEncounter(Player &player) const 
 {
    if(player.getAttackStrength()>=DRAGON_FORCE)
    {
        player.addCoins(DRAGON_LOOT);
        player.levelUp();
        printWinBattle(player.getName(),DRAGON);

    }
    else
    {
        player.damage(player.getCurrHp());
        player.damage(DRAGON_HP);
        printLossBattle(player.getName(),DRAGON);

    }
}