#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include <iostream>
#include"utilities.h"

const int DEFAULT_STARTING_HP = 100;
const int DEFAULT_STARTING_FORCE = 5;
const int DEFAULT_STARTING_LEVEL = 1;
const int DEFAULT_STARTING_COINS = 0;
const int MAX_LEVEL = 10;

class Player
{
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The maximum health points of the player.
     * @param force - The starting force of the player.
     * @return
     *      A new instance of Player.
    */
    Player(const char *name, int maxHP = 100, int force = 5);

    /*
     * copy C'tor of Player class
     *
     * @param other - the copied player.
     * @return
     *      A new instance of Card.
    */
    Player(const Player &other);

    /*
     * assignment operator of Player class
     *
     * @param other - the "copied" player.
     * @return
     *      Reference to the assigned player.
    */
    Player& operator=(const Player &other);

    /*
     * D'tor of Player class
    */
    ~Player();

    /*
     * Prints the player's infos in the form:
     * name:
     * level:
     * force:
     * hp:
     * coins:
     * 
     * @return
     *      void.
    */
    void printInfo() const;
    /*
     * 
     *
     * @param  - 
     * @param  - 
     * @param  - 
     * @param  - 
     * @return
     *      
    */
    void levelUp();
    int getLevel() const;
    void buff(int forceToAdd);
    void heal(int HpToAdd);
    void damage(int HpToRemove);
    bool isKnockedOut() const;
    void addCoins(int coinsToAdd);
    bool pay(int coinsToPay);
    int getAttackStrength() const;

private:
    char *m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};
#endif // EX2_PLAYER_H