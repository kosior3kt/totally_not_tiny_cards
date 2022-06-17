//
// Created by JK on 10/06/2022.
//

#ifndef PJC_NOWE_CARD_H
#define PJC_NOWE_CARD_H

#include <cstdio>
#include <string>
#include <utility>

class Card {
public:
    std::string front;
    std::string back;
    int numberOfTimesGuessed;
    Card(std::string front_to_fill, std::string back_to_fill, int number);
private:

};
#endif //PJC_NOWE_CARD_H
