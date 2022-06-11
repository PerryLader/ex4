#ifndef EX4_MAGE
#define EX4_MAGE

#include "Player.h"
#include <iostream>
using namespace std;

class Mage: public Player {
public:
Mage(const string playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE);
~Mage() override;
Mage(const Mage&) = default;
void heal(const int healSize) override;

};

#endif