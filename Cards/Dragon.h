#ifndef Dragon_H
#define Dragon_H
#include "BattleCard.h"

class Dragon : public BattleCard
{
public:
    /*
     * C'tor of Dragon class
     */
    Dragon();

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;
    /*
     * Handling the player's applyLostEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     * player loses automaticly
     */
    void applyLostEncounter(Player &player) const override;
    /*
     * Handling the player's applyGangEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      bool
     * return true if player won all battles agains the monsters in the gang card
     * doesnt level up player who wins
     */
    bool applyGangEncounter(Player &player) const override;
    Dragon(const Dragon &) = default;
    ~Dragon() = default;
    Dragon &operator=(const Dragon &other) = default;
};

#endif