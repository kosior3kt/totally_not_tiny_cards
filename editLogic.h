//
// Created by JK on 13/06/2022.
//

#ifndef PJC_NOWE_EDITLOGIC_H
#define PJC_NOWE_EDITLOGIC_H


#include "addLogic.h"

class editLogic: public addLogic{
    int deckIndex{};
    dataBase db;
public:
    ///this method is responsible for returning weather deck is empty or not
    bool isDeckEmpty(int deckNum);
    ///this method is responsible for deleting card with a given index, from a deck with given index
    void deleteCard(int currentlySelectedCard, int deck);
    ///this method is responsible for inserting new card with given front and back into deck with a given index
    void insertCard(const std::string& front, const std::string& back, int number);
    /// (depreciated) this method is responsible for changing a card to the new given front and new given back from a deck with a given index and card with given index
    void changeCard(std::string front, std::string back, int numberOfDeck, int numberOfCard);
    /// (depreciated) this method is responsible for clearing card adding buffer
    void clearBuffer();
    ///this method is responsible for checking werather given string contains any illegal characters
    bool containsWhiteSpaces(const std::string& nameAsWell);
    ///this method is responsible for setting a commetn to a deck with given index
    void setComment(const std::string& comment, int name);
    ///this method is responsible for creating a deck (it gets last index by default)
    void createDeck();
    ///this method is responsible for renaming a deck to a given name, with given (original) index
    void renameDeck(std::string name, int number);
};


#endif //PJC_NOWE_EDITLOGIC_H
