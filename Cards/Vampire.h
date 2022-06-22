
#ifndef Vampire_H
#define Vampire_H
#include "BattleCard.h"


class Vampire:public BattleCard {
public:
    /*
     * C'tor of Vampire class
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
     * Handling the player's applyLostEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     * player loses automaticly
     */
    void applyLostEncounter(Player& player) const override;
    /*
     * Handling the player's applyGangEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      bool
     * return true if player won all battles agains the monsters in the gang card
     * doesnt level up player who wins
     */
    bool applyGangEncounter(Player & player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
};

#endif 
