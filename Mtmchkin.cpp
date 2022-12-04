#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):m_player(playerName),
                                                                                    m_cards(new Card[numOfCards]),
                                                                                    m_numOfCards(numOfCards)
{
    for(int i = 0; i<numOfCards; i++){
        m_cards[i]=cardsArray[i];
    }
}

void Mtmchkin::playNextCard(){
    m_cards[m_actualCard].printInfo();
    m_cards[m_actualCard].applyEncounter(m_player);
    m_actualCard++;
    if(m_actualCard == m_numOfCards){
        m_actualCard = 0;
    }
}

bool Mtmchkin::isOver() const{
    return (getGameStatus()!= GameStatus::MidGame); 
}

GameStatus Mtmchkin::getGameStatus() const{
    if(m_player.isKnockedOut()){
        return GameStatus::Loss;
    }
    if(m_player.getLevel()==MAX_LEVEL){
        return GameStatus::Win;
    }
    return GameStatus::MidGame;
}