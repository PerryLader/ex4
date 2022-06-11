#include "Mage.h"

Mage::Mage(const string playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE) : Player(playerName, maxHp, force){};

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
