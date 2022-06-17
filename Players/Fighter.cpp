#include "Fighter.h"
using std::string;

Fighter::Fighter(const string playerName) : Player(playerName){}

int Fighter::getAttackStrength()
{
    int strength = m_level + m_force * 2;
    return strength;
}

void Fighter::printInfo(std::ostream& os) const
{
    printPlayerDetails(os, m_name, "Fighter", m_level, m_force, m_curHp, m_coins);
}