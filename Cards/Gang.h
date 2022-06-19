#ifndef GANG_H
#define GANG_H
#include "Card.h"
#include "../Players/Player.h"
#include "BattleCard.h"


class Gang : public Card
{
    private:
    std::vector<std::unique_ptr<BattleCard>> m_gangCards;
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
     */
    Gang();

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
    void printCard() const override;
    Gang(const Gang &) = default;
    ~Gang() = default;
    Gang &operator=(const Gang &other) = default;
};

#endif