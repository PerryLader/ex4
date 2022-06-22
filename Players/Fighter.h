#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"
#include "../utilities.h"


class Fighter : public Player {
    public:
    /*
     * C'tor of Barfight class
     * @param playerName - The name of the type of the player.
     */
    Fighter(const std::string playerName);
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fighter() = default;
    Fighter(const Fighter&) = default;
    int getAttackStrength() const override;
    void printInfo(std::ostream& os) const override;
};

#endif