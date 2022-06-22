#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"


class Barfight : public Card
{
public:
    /*
     * C'tor of Barfight class
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

    
    Barfight(const Barfight &) = default;
    ~Barfight() = default;
    Barfight &operator=(const Barfight &other) = default;
};

#endif