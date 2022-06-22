#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"
#include "../utilities.h"


class Fighter : public Player {
    public:
    Fighter(const std::string playerName);
    ~Fighter() = default;
    Fighter(const Fighter&) = default;
    int getAttackStrength() const override;
    void printInfo(std::ostream& os) const override;
};

#endif