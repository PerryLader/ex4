#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

const int DEFAULT_HP = 100;
const int DEFAULT_FORCE = 5;
const int DEFAULT_LVL = 1;
const int MAX_LVL = 10;

class Player
{
    char *m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_curHp;
    int m_coins;

public:
    // constractors
    Player()=delete ;
    Player(const char *playerName, const int maxHp = DEFAULT_HP, const int force = DEFAULT_FORCE);
    Player(const Player &player);

    // distractor
    ~Player();

    // oprators
    Player &operator=(const Player &player);

    // methods
    void printInfo();
    void levelUp();
    void heal(const int healSize);
    void damage(const int dmgSize);
    int getAttackStrength();
    int getLevel();
    void addCoins(const int coinsSize);
    void buff(const int buffSize);
    bool isKnockedOut();
    bool pay(const int coinsSize);
};

#endif