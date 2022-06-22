
#ifndef Goblin_H
#define Goblin_H
#include "BattleCard.h"

class Goblin:public BattleCard {
public:
    /*
     * C'tor of Goblin class
    */
    Goblin();
    
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
     /*
     * Handling the player's applyLostEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     * player loses automaticly
     */
    void applyLostEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Goblin(const Goblin&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;
};

#endif 
