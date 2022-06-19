#ifndef Dragon_H
#define Dragon_H
#include "BattleCard.h"

class Dragon:public BattleCard {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Dragon();
    
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
    void applyLostEncounter(Player &player) const override;
    bool applyGangEncounter(Player &player) const override;
    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;
};

#endif 