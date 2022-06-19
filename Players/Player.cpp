
#include "Player.h"
#include "../utilities.h"
using std::ostream;
using std::string;

Player::Player(const string playerName) : m_name(playerName),
                                          m_level(DEFAULT_LVL),
                                          m_force(DEFAULT_FORCE),
                                          m_maxHp(DEFAULT_HP),
                                          m_curHp(DEFAULT_HP),
                                          m_coins(DEFAULT_COINS)
{
}

ostream &operator<<(ostream &os, const Player &player)
{
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
void Player::decLvl(const int dec)
{
    m_level = m_level - dec;
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
int Player::getCurrHp()
{
    return m_curHp;
}
string Player::getName()
{
    return m_name;
}
int Player::getMoney()
{
    return m_coins;
}
bool Player::isKnockedOut()
{

    return (m_curHp <= 0);
}

bool Player::isWinner()
{
    return (m_level == MAX_LVL);
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
void Player::debuff(const int debuffSize)
{
    if (debuffSize > 0)
    {
        m_force -= debuffSize;
    }
    if (m_force < 0)
    {
        m_force = 0;
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
