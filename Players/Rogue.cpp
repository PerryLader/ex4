#include "Rogue.h"

Rogue::Rogue(const string playerName) :
Player(playerName) {};

void Rogue::addCoins(const int coinsSize){
        if (coinsSize > 0)
    {
        m_coins += coinsSize*2;
    }
}
void Rogue::printInfo(ostream& os) const {
    printPlayerDetails(os, m_name, "Rogue",m_level,m_force,m_curHp,m_coins);
}