#ifndef ROGUE_H
#define ROGUE_H
#include "Player.h"

class Rogue: public Player{
    public:
    Rogue(const string playerName);
    ~Rogue() override;
    Rogue(const Rogue&) = default;
    void addCoins(const int coinsSize) override;
    void printInfo(ostream& os) const override;
};

#endif