#include "Barfight.h"
#include "../utilities.h"
#include "../Players/Fighter.h"

Barfight::Barfight() : Card()
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
