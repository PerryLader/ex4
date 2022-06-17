
#ifndef Vampire_H
#define Vampire_H
#include "BattleCard.h"


class Vampire:public BattleCard {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Vampire();
    
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @returns
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
};

#endif 
