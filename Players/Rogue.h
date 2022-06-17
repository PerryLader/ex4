#ifndef ROGUE_H
#define ROGUE_H

#include "Player.h"
#include "../utilities.h"

class Rogue: public Player{
    public:
    Rogue(const std::string playerName);
    ~Rogue() = default;
    Rogue(const Rogue&) = default;
    void addCoins(const int coinsSize) override;
    void printInfo(std::ostream& os) const override;
};

#endif