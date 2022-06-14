//
// Created by JK on 13/06/2022.
//

#ifndef PJC_NOWE_EDITLOGIC_H
#define PJC_NOWE_EDITLOGIC_H


#include "backendLogic.h"

class editLogic: backendLogic {
    int deckIndex;
    dataBase db;
    backendLogic logic;
public:
    void deleteCard(int currentlySelectedCard);
    void insertCard(std::string front, std::string back);
    void clearBuffer();
    void setComment(std::string comment);
    void createDeck();
    void renameDeck(std::string name);

};


#endif //PJC_NOWE_EDITLOGIC_H
