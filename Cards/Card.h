//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef Card_H
#define Card_H
#include "../Players/Player.h"
#include <iostream>
#include "../utilities.h"


const std::string GOBLIN="Goblin";
const std::string DRAGON="Dragon";
const std::string VAMPIRE="Vampire";
const std::string BARFIGHT="Barfight";
const std::string FAIRY="Fairy";
const std::string MERCHANT="Merchant";
const std::string PITFALL="Pitfall";
const std::string TREASURE="Treasure";
const std::string GANG="Gang";
const int DONT_BUY=0;
const int BUY_HEAL=1;
const int BUY_FORCE=2;
const int PRICE_HEAL=5;
const int PRICE_FORCE=10;
const int DEF_BUFF=1;
const int DEF_HEAL=1;
class Card {
public:

    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(const std::string name);
    const std::string getName()
    {
        return m_name;
    }

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    Card()=delete;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    friend std::ostream& operator << (std::ostream& os, const Card& card);
    Card(const Card&) = default;
    virtual ~Card() =default;
    Card& operator=(const Card& other) = default;

protected:
virtual void printCard() const;
const std::string m_name;
};

#endif 
