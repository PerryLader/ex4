#include "Treasure.h"
#include "../utilities.h"
using namespace std;

Treasure::Treasure() : Card()
{
}

void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(value);
    printTreasureMessage();
}
