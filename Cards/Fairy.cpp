#include "Fairy.h"
#include "../utilities.h"
#include "../Players/Wizard.h"

Fairy::Fairy() : Card(FAIRY)
{
}

void Fairy::applyEncounter(Player &player) const
{
    const Wizard *wiz = dynamic_cast<const Wizard *>(&player);
    if (wiz != nullptr)
    {
        // player is a wizard
        player.heal(DEFAULT_HP_FAIRY);
        printFairyMessage(true);
    }
    else
    {
        printFairyMessage(false);
    }
}
