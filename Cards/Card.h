//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef Card_H
#define Card_H

#include <string>
#include "Player.h"
#include "utilities.h"
#include <cstring>
using std::string;

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
    Card(const string name);
    
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const=0;

    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    Card()=delete  {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card();
    Card& operator=(const Card& other) = default;


private:
    string m_name;
};

#endif 
