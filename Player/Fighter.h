#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"

class Fighter : public Player {
    Fighter(const string playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE);
    ~Fighter() override;
    Fighter(const Fighter&) = default;
    int getAttackStrength() override;
};

#endif