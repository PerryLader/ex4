#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>
#include "../utilities.h"
using namespace std;

const int DEFAULT_HP = 100;
const int DEFAULT_FORCE = 5;
const int DEFAULT_LVL = 1;
const int MAX_LVL = 10;
const int DEFAULT_COINS = 10;

class Player
{
public:
    // constractors
    Player()=delete ;
    Player(const string playerName);
    Player(const Player &player);

    // distractor
    virtual ~Player();

    // oprators
    Player &operator=(const Player &player);

    // methods
    virtual void printInfo(ostream& os) const = 0;
    void levelUp();
    void debuff(const int debuffSize);
    virtual void heal(const int healSize);
    void damage(const int dmgSize);
    virtual int getAttackStrength();
    int getLevel();
    int getCurrHp();
    virtual void addCoins(const int coinsSize);
    void buff(const int buffSize);
    bool isKnockedOut();
    bool pay(const int coinsSize);
    friend ostream& operator<<(ostream& os, const Player& player);
    protected:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_curHp;
    int m_coins;
};

#endif