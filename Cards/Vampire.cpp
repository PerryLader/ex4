#include "Vampire.h"
#include "../utilities.h"
using std::string;

Vampire::Vampire() : BattleCard(VAMPIRE)
{
    m_force = VAMPIRE_FORCE;
    m_hp = VAMPIRE_HP;
    m_loot = VAMPIRE_LOOT;
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

void Vampire::applyLostEncounter(Player & player) const {
        player.debuff(1);
        player.damage(VAMPIRE_HP);
        printLossBattle(player.getName(),VAMPIRE);
}

bool Vampire::applyGangEncounter(Player &player) const
{
    if (player.getAttackStrength() >= VAMPIRE_FORCE)
    {
        player.addCoins(VAMPIRE_LOOT);
        printWinBattle(player.getName(),VAMPIRE);
        return false;
    }
    else
    {
        player.debuff(1);
        player.damage(VAMPIRE_HP);
        printLossBattle(player.getName(),VAMPIRE);
        return true;
    }
}