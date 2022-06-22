#ifndef Merchant_H
#define Merchant_H
#include "Card.h"
#include "../Players/Player.h"

class Merchant:public Card {
public:
    /*
     * C'tor of Merchant class
    */
    Merchant();
    
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Merchant(const Merchant&) = default;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;
};

#endif 