//
// Created by JK on 11/06/2022.
//

#ifndef PJC_NOWE_PARSER_H
#define PJC_NOWE_PARSER_H


#include "dataBase.h"
#include "Deck.h"
#include "Card.h"

class parser{
public:
    int returnNumberOfDecks();

    virtual int returnNumberOfCardsInDeck(int);

    virtual std::string returnNameOfDeck(int number);

    virtual std::string returnCommentToDeck(int number);

};


#endif //PJC_NOWE_PARSER_H
