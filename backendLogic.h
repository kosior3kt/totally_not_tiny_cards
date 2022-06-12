//
// Created by JK on 03/06/2022.
//



#ifndef PJC_NOWE_BACKENDLOGIC_H
#define PJC_NOWE_BACKENDLOGIC_H


#include "parser.h"
#include <map>


class backendLogic: public parser {
public:

    backendLogic();
    std::string returnNameOfDeck(int deckNumber);
    std::string returnCommentToDeck(int deckNumber);
    int returnNumberOfCardsInDeck(int deckNumber);


    std::string returnFrontOfCard(int, int);
    std::string returnBackOfCard(int, int);
    int returnNumberOfTimesBeingGuessed(int, int);
    parser parser;


private:
    std::vector<Card> fillTheVector(int);
    std::vector<Deck> fillDeckVector();


};


#endif //PJC_NOWE_BACKENDLOGIC_H
