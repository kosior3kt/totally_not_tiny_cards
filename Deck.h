//
// Created by JK on 10/06/2022.
//

#include <cstdio>
#include <vector>
#include <string>

#ifndef PJC_NOWE_DECK_H
#define PJC_NOWE_DECK_H


class Deck{
public:
    Deck(int deckNumber1, int numberOfCards1, std::string commentTODeck1, std::string name1);

    int deckNumber;
    int numberOfCards;
    std::string commentToDeck;
    std::string name;
};


#endif //PJC_NOWE_DECK_H
