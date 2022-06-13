#include "Treasure.h"
#include "../utilities.h"
using std::string;

Treasure::Treasure() : Card(TREASURE)
{
}

void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(value);
    printTreasureMessage();
}
