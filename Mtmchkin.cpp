#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):m_player(playerName),
                                                                                    m_cards(new Card[numOfCards]),
                                                                                    m_numOfCards(numOfCards),
                                                                                    m_actualCard(FIRST_CARD)
{
    for(int i = 0; i<numOfCards; i++){
        m_cards[i]=cardsArray[i];
    }
}

Mtmchkin::Mtmchkin(const Mtmchkin &mtmchkin) : m_player(mtmchkin.m_player),
                                               m_cards(new Card[mtmchkin.m_numOfCards]),
                                               m_numOfCards(mtmchkin.m_numOfCards),
                                               m_actualCard(mtmchkin.m_actualCard) {
    for (int i = 0; i < m_numOfCards; ++i) {
        m_cards[i] = mtmchkin.m_cards[i];
    }
}

Mtmchkin &Mtmchkin::operator=(const Mtmchkin &mtmchkin)
        {

    if (this == &mtmchkin) {
        return *this;
    }
    m_player = mtmchkin.m_player;
    m_numOfCards = mtmchkin.m_numOfCards;
    m_actualCard = mtmchkin.m_actualCard;
    delete[] m_cards;
    m_cards = new Card[mtmchkin.m_numOfCards];
    for (int i = 0; i < m_numOfCards; ++i) {
        m_cards[i] = mtmchkin.m_cards[i];
    }
    return *this;

}

Mtmchkin::~Mtmchkin(){
    delete[] m_cards;
}

void Mtmchkin::playNextCard(){
    
    if(isOver()){
        return;
    }
    m_cards[m_actualCard].printInfo();
    m_cards[m_actualCard].applyEncounter(m_player);
    m_actualCard++;
    if(m_actualCard == m_numOfCards){
        m_actualCard = 0;
    }
    m_player.printInfo();

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
