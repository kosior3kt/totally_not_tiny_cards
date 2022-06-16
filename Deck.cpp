//
// Created by JK on 10/06/2022.
//

#include "Deck.h"
#include <utility>

Deck::Deck(int deckNumber1, int numberOfCards1, std::string commentTODeck1, std::string name1) {
this->deckNumber=deckNumber1;
this->numberOfCards=numberOfCards1;
this->commentToDeck=std::move(commentTODeck1);
this->name = std::move(name1);
}
