#ifndef Fairy_H
#define Fairy_H
#include "Card.h"

class Fairy:public Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Fairy();
    
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
    Fairy(const Fairy&) = default;
    ~Fairy() override;
    Fairy& operator=(const Fairy& other) = default;
};

#endif 