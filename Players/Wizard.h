#ifndef EX4_WIZARD
#define EX4_WIZARD

#include "Player.h"
#include "../utilities.h"
#include <iostream>

class Wizard: public Player {
public:
Wizard(const std::string playerName);
// ~Wizard() override;
Wizard(const Wizard&) = default;
void heal(const int healSize) override;
void printInfo(std::ostream& stream) const override;

};

#endif