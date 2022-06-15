#include "Wizard.h"
using std::string;
using std::ostream;
Wizard::Wizard(const string playerName) : Player(playerName){};

void Wizard::heal(const int healSize) {
        if (healSize > 0)
    {
        m_curHp += healSize*2;
        if (m_curHp > m_maxHp)
        {
            m_curHp = m_maxHp;
        }
    }
}

void Wizard::printInfo(ostream& stream) const {
    printPlayerDetails(stream,m_name,"Wizard",m_level,m_force,m_curHp,m_coins);
}