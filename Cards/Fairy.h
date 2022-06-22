#ifndef Fairy_H
#define Fairy_H
#include "Card.h"
#include "../Players/Wizard.h"
#include "../Players/Player.h"


class Fairy:public Card {
public:
    /*
     * C'tor of Fairy class
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
     * Here we are explicitly telling the compiler to use the default methods
    */
    Fairy(const Fairy&) = default;
    ~Fairy() = default;
    Fairy& operator=(const Fairy& other) = default;
};

#endif 