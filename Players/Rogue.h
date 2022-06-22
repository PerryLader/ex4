#ifndef ROGUE_H
#define ROGUE_H

#include "Player.h"
#include "../utilities.h"

class Rogue: public Player{
    public:
    /*
     * C'tor of Rogue class
     * @param playerName - The name of the type of the player.
     */
    Rogue(const std::string playerName);
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Rogue() = default;
    Rogue(const Rogue&) = default;
    void addCoins(const int coinsSize) override;
    void printInfo(std::ostream& os) const override;
};

#endif