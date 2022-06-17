//
// Created by JK on 12/06/2022.
//

#ifndef PJC_NOWE_LESSONLOGIC_H
#define PJC_NOWE_LESSONLOGIC_H


#include "backendLogic.h"

class lessonLogic : public backendLogic{
int numberOfDeck;
///this method is responsible for sorting a card vector according to a number of times being guessed (less times, higher priority)
std::vector<Card> sortAccordingToNumberOfTimesBeingGuessed(int num);
///this method is responsible for trimming a local vector into no more than 10 cards
std::vector<Card> makeTrimmedVector();
struct localCard{
    std::string front;
    std::string back;
};
    bool passedSuccesfully=false;
std::vector<localCard> vectorForWork;
///this method is responsible for filling a locally used vector
void fillLocalVector();
public:
    ///(depreciated) this method is responsible for setting passed Succesfully flag to true
    void setPassedFlagToTrue();
    ///this method is responsible for returning size of a local vector
    int returnSizeOfVector();
    ///this method is responsible for taking actions when user guessed card right
    void guessedRight();
    ///this method is responsible for taking actions when user guessed card wrong
    void guessedWrong();
    ///this method is responsible for returning weather vector is already empty
    bool isEmpty();
    explicit lessonLogic(int num);
    std::string giveCard();
localCard current;
};
#endif //PJC_NOWE_LESSONLOGIC_H
