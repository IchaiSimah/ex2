#include "Player.h"
#include <string.h>
/**
 *  char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
 *
 */
Player::Player(const char *name, int maxHP, int force) : m_name(new char[strlen(name) + 1]),
                                                   m_level(DEFAULT_STARTING_LEVEL),
                                                   m_force(force),
                                                   m_maxHP(maxHP),
                                                   m_HP(maxHP),
                                                   m_coins(DEFAULT_STARTING_COINS)
{
    strcpy(m_name, name);
    if (m_force < 0)
    {
        m_force = DEFAULT_STARTING_FORCE;
    }
    if (m_HP < 0)
    {
        m_HP = DEFAULT_STARTING_HP;
        m_maxHP = DEFAULT_STARTING_HP;
    }
}

Player::Player(const Player &other):m_name(new char[strlen(other.m_name)+1]),
                                    m_level(other.m_level),
                                    m_force(other.m_force),
                                    m_maxHP(other.m_maxHP),
                                    m_HP(other.m_HP),
                                    m_coins(other.m_coins)
{
    strcpy(m_name, other.m_name);
}
Player &Player::operator=(const Player& other){
    if(this == &other){
        return *this;
    }
    delete[] m_name;
    m_name = new char[strlen(other.m_name)+1];
    strcpy(m_name, other.m_name);
    m_level = other.m_level;
    m_force = other.m_force;
    m_maxHP = other.m_maxHP;
    m_HP = other.m_HP;
    m_coins = other.m_coins;
    return *this;
}
Player::~Player(){
    delete[] m_name;
}
void Player::printInfo() const{
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if(m_level < MAX_LEVEL){
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int forceToAdd)
{
    if (forceToAdd > 0)
    {
        m_force += forceToAdd;
    }
}
void Player::heal(int HpToAdd){
    if(HpToAdd > 0)
    {
        m_HP += HpToAdd;
        if(m_HP > m_maxHP){
            m_HP = m_maxHP;
        }
    }
}

void Player::damage(int HpToRemove){
        if(HpToRemove > 0)
    {
        m_HP -= HpToRemove;
        if(m_HP < 0){
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const{
    return(!(bool)m_HP);
}

void Player::addCoins(int coinsToAdd){
    if(coinsToAdd > 0){
        m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay){
    if(coinsToPay < 0){ //TO CHECK
        return true;
    }
    if(m_coins >= coinsToPay){
        m_coins -= coinsToPay;
        return true;
    }
    return false;
}
int Player::getAttackStrength() const{
    return m_force + m_level;
}
