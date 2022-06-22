#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>
const int DEFAULT_HP = 100;
const int DEFAULT_FORCE = 5;
const int DEFAULT_LVL = 1;
const int MAX_LVL = 10;
const int DEFAULT_COINS = 10;
const int DEFAULT_HP_FAIRY = 10;
const int DEFAULT_DAMAGE_PITFALL = 10;
const int DEFAULT_DAMAGE_BARFIGHT = 10;

class Player
{
public:
    // constractors
    Player()=delete ;
    Player(const std::string playerName);
    Player(const Player &player) = default;

    // distractor
    virtual ~Player() = default;

    // oprators
    Player &operator=(const Player &player) = default;

    // methods
    virtual void printInfo(std::ostream& os) const = 0;
    virtual void heal(const int healSize);
    virtual int getAttackStrength() const;
    virtual void addCoins(const int coinsSize);

    void levelUp();
    void debuff(const int debuffSize);
    void damage(const int dmgSize);
    int getLevel() const;
    int getCurrHp() const;
    std::string getName() const;
    int getMoney() const;
    void buff(const int buffSize);
    bool isKnockedOut() const;
    bool isWinner() const;
    bool pay(const int coinsSize);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    protected:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_curHp;
    int m_coins;
};

#endif