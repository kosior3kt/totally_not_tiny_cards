//
// Created by JK on 13/06/2022.
//

#ifndef PJC_NOWE_EDITLOGIC_H
#define PJC_NOWE_EDITLOGIC_H


#include "addLogic.h"

class editLogic: public addLogic{
    int deckIndex;
    dataBase db;
    backendLogic logic;
public:
    bool isDeckEmpty(int deckNum);
    void deleteCard(int currentlySelectedCard, int deck);
    void insertCard(std::string front, std::string back, int number);
    void changeCard(std::string front, std::string back, int numberOfDeck, int numberOfCard);
    void clearBuffer();
    bool containsWhiteSpaces(std::string nameAsWell);
    void setComment(std::string comment, int name);
    void createDeck();
    void renameDeck(std::string name, int number);

};


#endif //PJC_NOWE_EDITLOGIC_H
