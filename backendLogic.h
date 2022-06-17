//
// Created by JK on 03/06/2022.
//

#ifndef PJC_NOWE_BACKENDLOGIC_H
#define PJC_NOWE_BACKENDLOGIC_H


#include "parser.h"


class backendLogic: public parser {
public:
    backendLogic();
    ///this method is responsible for returning name of a deck of a given index but it does it by searching vector it secretly is plainly slower than just querying the thing but I wanted to proof to my teachers that i know how to handle overriding…
    std::string returnNameOfDeck(int deckNumber) override;
    ///this method is responsible for returning comment to a deck with a given index - override
    std::string returnCommentToDeck(int deckNumber) override;
    ///this method is responsible for returning a number of cards in a deck of a given index - override
    int returnNumberOfCardsInDeck(int deckNumber) override;
    ///this method is responsible for returning front of a card from a deck with given index, and with given index (of a card)
    std::string returnFrontOfCard(int, int);
    ///this method is responsible for returning back of a card from a deck with given index, and with given index (of a card)
    std::string returnBackOfCard(int, int);
    ///this method is responsible for returning number of times the card has been guessed from a deck with given index, and with given index (of a card)
    int returnNumberOfTimesBeingGuessed(int, int);

private:
    parser parser;
    std::vector<Deck> fillDeckVector();

protected:
    std::vector<Card> fillTheVector(int);
};


#endif //PJC_NOWE_BACKENDLOGIC_H
