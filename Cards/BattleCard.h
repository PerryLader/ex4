
#ifndef BattleCard_H
#define BattleCard_H
#include "Card.h"
#include "../Players/Player.h"

const int GOBLIN_FORCE = 6;
const int GOBLIN_LOOT = 2;
const int GOBLIN_HP = 10;

const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_HP = -1;

const int VAMPIRE_FORCE = 10;
const int VAMPIRE_LOOT = 2;
const int VAMPIRE_HP = 10;
class BattleCard : public Card
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
    BattleCard(const std::string name);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     */
    virtual void applyEncounter(Player &player) const = 0;
    void printCard() const override;
    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
     */
    BattleCard() = delete;

    /*
     * Here we are explicitly telling the compiler to use the default methods
     */
    BattleCard(const BattleCard &) = default;
    virtual ~BattleCard() = default;
    BattleCard &operator=(const BattleCard &other) = default;
};

#endif
