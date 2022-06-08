
#ifndef BattleCard_H
#define BattleCard_H

#include "Card.h"
#include <iostream>
using namespace std;

class BattleCard:public Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    BattleCard(const string name,const int force,const int loot,const int hp);
    
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    BattleCard()=delete;  


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    BattleCard(const BattleCard&) = default;
    virtual ~BattleCard();
    BattleCard& operator=(const BattleCard& other) = default;


private:
    int m_force;
    int m_loot;
    int m_hp;
};

#endif 
