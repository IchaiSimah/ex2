#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include <iostream>
#include "utilities.h"

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
    Player &operator=(const Player &other);

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
     * Add one to the player's level.
     *
     * @return
     *      void
     *
     */
    void levelUp();

    /*
     * getter of the player's level.
     *
     * @return
     *      the player's level.
     *
     */
    int getLevel() const;

    /*
     * Add force to the player.
     *
     * @param forceToAdd - the force to add to the player.
     * @return
     *      void
     *
     */
    void buff(int forceToAdd);

    /*
     * Add health Point to the player.
     *
     * @param HpToAdd - the health point to add to the player.
     * @return
     *      void
     *
     */
    void heal(int HpToAdd);

    /*
     * reduce health Point of the player.
     *
     * @param HpToRemove - the health point to remove from the player.
     * @return
     *      void
     *
     */
    void damage(int HpToRemove);

    /*
     * check if the player is knocked out.
     *
     * @return
     *      true - if the health point of the player is equal zero.
     *      false - if the health point of the player is bigger than zero
     *
     */
    bool isKnockedOut() const;

    /*
     * Add coins to the player.
     *
     * @param coinsToAdd - the coins to add to the player.
     * @return
     *      void
     *
     */
    void addCoins(int coinsToAdd);

    /*
     * check if the player can pay and make him pay.
     *
     * @param coinsToPay - the coins to pay.
     * @return
     *      true - if the coins he possess are sufficient to pay.
     *      false - if the coins he possesses are not enough.
     *
     */
    bool pay(int coinsToPay);

    /*
     * getter of player's strenght.
     *
     * @return
     *      'the player's strenght
     *
     */
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