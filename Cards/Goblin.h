
#ifndef Goblin_H
#define Goblin_H
#include "BattleCard.h"
#include "../Player.h"
#include <iostream>
using namespace std;

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
    Goblin(const string name);
    
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
    Goblin()=delete; 


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Goblin(const Goblin&) = default;
    ~Goblin();
    Goblin& operator=(const Goblin& other) = default;


private:
};

#endif 
