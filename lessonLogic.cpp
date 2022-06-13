//
// Created by JK on 12/06/2022.
//

#include "lessonLogic.h"
#include <algorithm>
#include <random>


std::vector<Card> lessonLogic::sortAccordingToNumberOfTimesBeingGuessed(int number) {
    std::vector<Card> temp = fillTheVector(number);

    std::sort(temp.begin(), temp.end(), [](const Card& a, const Card& b){
        return a.numberOfTimesGuessed < b.numberOfTimesGuessed;});
    return temp;
}

std::vector<Card> lessonLogic::makeTrimmedVector() {
    int i=0;
    std::vector<Card> temp;
    for(const auto& x: this->sortAccordingToNumberOfTimesBeingGuessed(this->numberOfDeck)){
        if(i<10){
            temp.push_back(x);
            i++;
        }
        else{
            std::shuffle(temp.begin(), temp.end(), std::mt19937(std::random_device()()));
            return temp;
        }
    }
    std::shuffle(temp.begin(), temp.end(), std::mt19937(std::random_device()()));
    return temp;
}

lessonLogic::lessonLogic(int num) {
    this->numberOfDeck=num;
    this->fillLocalVector();
}

void lessonLogic::fillLocalVector() {
    for(const auto& x: makeTrimmedVector()){
        localCard tempCard = {x.front, x.back};
        this->vectorForWork.push_back(tempCard);
    }
}

std::string lessonLogic::giveCard() {
    this->current=vectorForWork.back();
    return vectorForWork.back().front;
}

void lessonLogic::guessedRight() {
    this->vectorForWork.pop_back();
}

void lessonLogic::guessedWrong() {
    std::shuffle(this->vectorForWork.begin(), this->vectorForWork.end(),std::mt19937(std::random_device()()));
}

bool lessonLogic::isEmpty() {
    return vectorForWork.empty();
}

int lessonLogic::returnSizeOfVector() {
    return this->vectorForWork.size();
}

void lessonLogic::setPassedFlagToTrue() {
    this->passedSuccesfully=true;
}











