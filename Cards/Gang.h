#ifndef GANG_H
#define GANG_H
#include "Card.h"
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include "../Players/Player.h"
#include "BattleCard.h"

class Gang : public Card
{
    std::vector<std::unique_ptr<BattleCard>> m_gangCards;
public:
    /*
     * C'tor of Card class
     *
     * @param cards - a vector that constains the name of all monsters that should be in the gang
     */
    Gang(std::vector<std::string> cards);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player& player) const override;

    

    /*
     * the function initialize map and creats all the neccery pairs
     */
    void initBattleDeckMap(std::map<std::string, std::unique_ptr<BattleCard>> &deck) const;
    //print all monstres in the gang
    void printCard() const override;
    Gang(const Gang &) = default;
    ~Gang() = default;
    Gang &operator=(const Gang &other) = default;
};

#endif