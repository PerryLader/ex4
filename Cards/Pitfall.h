#ifndef PITFALL_H
#define PITFALL_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Rogue.h"

class Pitfall:public Card {
public:
    /*
     * C'tor of Pitfall class
    */
    Pitfall();
    
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
    Pitfall(const Pitfall&) = default;
    ~Pitfall()= default;
    Pitfall& operator=(const Pitfall& other) = default;
};

#endif 