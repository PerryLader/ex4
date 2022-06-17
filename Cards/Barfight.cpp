#include "Barfight.h"
#include "../utilities.h"

Barfight::Barfight() : Card(BARFIGHT)
{
}

void Barfight::applyEncounter(Player &player) const
{
    const Fighter *fighter = dynamic_cast<const Fighter *>(&player);
    if (fighter != nullptr)
    {
        // player is a fighter
        printBarfightMessage(true);
    }
    else
    {
        player.damage(DEFAULT_DAMAGE_BARFIGHT);
        printBarfightMessage(false);
    }
}