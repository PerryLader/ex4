#include "Mage.h"

Mage::Mage(const string playerName) : Player(playerName){};

void Mage::heal(const int healSize) {
        if (healSize > 0)
    {
        m_curHp += healSize*2;
        if (m_curHp > m_maxHp)
        {
            m_curHp = m_maxHp;
        }
    }
}

void Mage::printInfo(ostream& stream) const {
    printPlayerDetails(stream,m_name,"Mage",m_level,m_force,m_curHp,m_coins);
}