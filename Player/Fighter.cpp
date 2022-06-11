#include "Fighter.h"

Fighter::Fighter(const string playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE) :
Player(playerName, maxHp, force) {};

int Fighter::getAttackStrength() {
    int strength = m_level + m_force*2;
    return strength;
}