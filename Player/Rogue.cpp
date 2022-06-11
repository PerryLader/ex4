#include "Rogue.h"

Rogue::Rogue(const string playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE) :
Player(playerName, maxHp, force) {};

void Rogue::addCoins(const int coinsSize){
        if (coinsSize > 0)
    {
        m_coins += coinsSize*2;
    }
}