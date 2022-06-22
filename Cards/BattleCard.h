
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
     * @param name - The type/name of the card.
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
    /*
     * function that prints a battle card to cout
     */
    void printCard() const override;
    /*
     * function that prints a battle card to cout
     */
    BattleCard() = delete;
    /*
     * Handling the player's applyGangEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      bool
     * return true if player won all battles agains the monsters in the gang card
     * doesnt level up player who wins
     */
    virtual bool applyGangEncounter(Player &player) const;
    /*
     * Handling the player's applyLostEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     * player loses automaticly
     */
    virtual void applyLostEncounter(Player &player) const = 0;
    /*
     * Here we are explicitly telling the compiler to use the default methods
     */
    BattleCard(const BattleCard &) = default;
    virtual ~BattleCard() = default;
    BattleCard &operator=(const BattleCard &other) = default;
    protected: 
    int m_force;
    int m_hp;
    int m_loot;
};

#endif
