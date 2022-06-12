#include <iostream>
using namespace std;

#include "Player.h"
#include "utilities.h"


Player::Player(const string playerName, const int maxHp, const int force)
{
    m_name = playerName;
    m_level = DEFAULT_LVL;
    if (force <= 0)
    {
        this->m_force = DEFAULT_FORCE;
    }
    else
    {
        this->m_force = force;
    }

    if (maxHp <= 0)
    {
        this->m_maxHp = DEFAULT_HP;
        m_curHp = DEFAULT_HP;
    }
    else
    {
        this->m_maxHp = maxHp;
        m_curHp = maxHp;
    }
    m_coins = 0;
}
Player::Player(const Player &player) : m_level(player.m_level),
                                       m_force(player.m_force),
                                       m_maxHp(player.m_maxHp),
                                       m_curHp(player.m_curHp),
                                       m_coins(player.m_coins),
                                       m_name(player.m_name){}
// oprators
Player &Player::operator=(const Player &player)
{
    if (this == &player)
        return *this;
    this->m_name = player.m_name;
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHp = player.m_maxHp;
    this->m_curHp = this->m_maxHp;
    this->m_coins = player.m_coins;
    return *this;
}
// methods


ostream& operator<<(ostream& os, const Player& player){
    player.printInfo(os);
    return os;
}

void Player::levelUp()
{
    if (m_level <= 9)
    {
        m_level++;
    }
}
int Player::getLevel()
{
    return m_level;
}
int Player::getAttackStrength()
{
    int strength = m_level + m_force;
    return strength;
}
int Player::getCurrHp(){
    return m_curHp;
}
bool Player::isKnockedOut()
{

    return (m_curHp <= 0);
}
bool Player::pay(const int coinsSize)
{
    if (m_coins < coinsSize)
    {
        return false;
    }
    if (coinsSize > 0)
    {
        m_coins -= coinsSize;
    }
    return true;
}
void Player::heal(const int healSize)
{
    if (healSize > 0)
    {
        m_curHp += healSize;
        if (m_curHp > m_maxHp)
        {
            m_curHp = m_maxHp;
        }
    }
}
void Player::debuff(const int debuffSize){
    if(debuffSize > 0) {
        m_force -= debuffSize;
    }
}
void Player::damage(const int dmgSize)
{
    if (dmgSize > 0)
    {
        m_curHp = m_curHp - dmgSize;
    }
    if (m_curHp < 0)
    {
        m_curHp = 0;
    }
}
void Player::addCoins(const int coinsSize)
{
    if (coinsSize > 0)
    {
        m_coins += coinsSize;
    }
}
void Player::buff(const int buffSize)
{
    if (buffSize > 0)
    {
        m_force += buffSize;
    }
}
