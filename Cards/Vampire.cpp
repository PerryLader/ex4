#include "Vampire.h"
#include "../utilities.h"
using std::string;

Vampire::Vampire() : BattleCard()
{
}

void Vampire::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= VAMPIRE_FORCE)
    {
        player.addCoins(VAMPIRE_LOOT);
        player.levelUp();
        printWinBattle(player.getName(),VAMPIRE);
    }
    else
    {
        player.debuff(1);
        player.damage(VAMPIRE_HP);
        printLossBattle(player.getName(),VAMPIRE);
    }
}
