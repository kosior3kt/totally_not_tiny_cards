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
    ///this method is responsible for returning number of decks(tables) in currently used database
    int returnNumberOfDecks();
    ///this method is responsible for returning number of cards in deck of given index
    virtual int returnNumberOfCardsInDeck(int);
    ///this method is responsible for returning name of a deck of given index
    virtual std::string returnNameOfDeck(int number);
    ///this method is responsible for returning the comment assigned to a deck of a given index
    virtual std::string returnCommentToDeck(int number);
};


#endif //PJC_NOWE_PARSER_H
