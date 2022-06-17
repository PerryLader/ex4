#include "Pitfall.h"
#include "../utilities.h"

Pitfall::Pitfall() : Card(PITFALL)
{
}

void Pitfall::applyEncounter(Player &player) const
{
    const Rogue *rogue = dynamic_cast<const Rogue *>(&player);
    if (rogue != nullptr)
    {
        // player is a rogue
        printPitfallMessage(true);
    }
    else
    {
        player.damage(DEFAULT_DAMAGE_PITFALL);
        printPitfallMessage(false);
    }
}
