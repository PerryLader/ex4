#ifndef Treasure_H
#define Treasure_H
#include "Card.h"
const int value=10;
class Treasure:public Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Treasure();
    
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
    Treasure()=delete; 


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Treasure(const Treasure&) = default;
    ~Treasure() override;
    Treasure& operator=(const Treasure& other) = default;
};

#endif 