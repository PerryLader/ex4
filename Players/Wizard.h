#ifndef EX4_WIZARD
#define EX4_WIZARD

#include "Player.h"
#include "../utilities.h"
#include <iostream>

class Wizard : public Player
{
public:
    /*
     * C'tor of Wizard class
     * @param playerName - The name of the type of the player.
     */
    Wizard(const std::string playerName);
    /*
     * Here we are explicitly telling the compiler to use the default methods
     */
    ~Wizard() = default;
    Wizard(const Wizard &) = default;
    void heal(const int healSize) override;
    void printInfo(std::ostream &stream) const override;
};

#endif