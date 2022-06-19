#include "Dragon.h"
#include "../utilities.h"
using std::string;

Dragon::Dragon() : BattleCard(DRAGON)
{
    m_force = DRAGON_FORCE;
    m_hp = DRAGON_HP;
    m_loot = DRAGON_LOOT;
}

void Dragon::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= DRAGON_FORCE)
    {
        player.addCoins(DRAGON_LOOT);
        player.levelUp();
        printWinBattle(player.getName(), DRAGON);
    }
    else
    {
        player.damage(player.getCurrHp());
        printLossBattle(player.getName(), DRAGON);
    }
}

void Dragon::applyLostEncounter(Player &player) const
{
    player.damage(player.getCurrHp());
    printLossBattle(player.getName(), DRAGON);
}

bool Dragon::applyGangEncounter(Player &player) const
{
    if (player.getAttackStrength() >= DRAGON_FORCE)
    {
        player.addCoins(DRAGON_LOOT);
        printWinBattle(player.getName(), DRAGON);
        return false;
    }
    else
    {
        player.damage(player.getCurrHp());
        printLossBattle(player.getName(), DRAGON);
        return true;
    }
}