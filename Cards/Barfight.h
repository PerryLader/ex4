#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"


class Barfight : public Card
{
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
     */
    Barfight();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
     */

    /*
     * Here we are explicitly telling the compiler to use the default methods
     */
    Barfight(const Barfight &) = default;
    ~Barfight() = default;
    Barfight &operator=(const Barfight &other) = default;
};

#endif