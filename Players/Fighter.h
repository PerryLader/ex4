#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"

class Fighter : public Player {
    public:
    Fighter(const string playerName);
    ~Fighter() override;
    Fighter(const Fighter&) = default;
    int getAttackStrength() override;
    void printInfo(ostream& os) const override;
};

#endif