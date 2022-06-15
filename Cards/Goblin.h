
#ifndef Goblin_H
#define Goblin_H
#include "BattleCard.h"

class Goblin:public BattleCard {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
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
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Goblin(const Goblin&) = default;
    ~Goblin() override;
    Goblin& operator=(const Goblin& other) = default;
};

#endif 
