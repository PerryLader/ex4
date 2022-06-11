#ifndef ROGUE_H
#define ROGUE_H
#include "Player.h"

class Rogue: public Player{
    Rogue(const string playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE);
    ~Rogue() override;
    Rogue(const Rogue&) = default;
    void addCoins(const int coinsSize) override;
};

#endif