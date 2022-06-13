//
// Created by JK on 12/06/2022.
//

#ifndef PJC_NOWE_LESSONLOGIC_H
#define PJC_NOWE_LESSONLOGIC_H


#include "backendLogic.h"

class lessonLogic : public backendLogic{
int numberOfDeck;
std::vector<Card> sortAccordingToNumberOfTimesBeingGuessed(int num);
std::vector<Card> makeTrimmedVector();
struct localCard{
    std::string front;
    std::string back;
};
std::vector<localCard> vectorForWork;
void fillLocalVector();

public:
    void guessedRight();
    void guessedWrong();
    bool isEmpty();
explicit lessonLogic(int num);
std::string giveCard();
localCard current;


};


#endif //PJC_NOWE_LESSONLOGIC_H
