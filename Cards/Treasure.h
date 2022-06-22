#ifndef Treasure_H
#define Treasure_H
#include "Card.h"
#include "../Players/Player.h"


const int value=10;
class Treasure:public Card {
public:
    /*
     * C'tor of Treasure class
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
     * Here we are explicitly telling the compiler to use the default methods
    */
    Treasure(const Treasure&) = default;
    ~Treasure() = default;
    Treasure& operator=(const Treasure& other) = default;
};

#endif 