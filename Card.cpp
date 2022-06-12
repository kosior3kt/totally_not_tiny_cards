//
// Created by JK on 10/06/2022.
//

#include "Card.h"



Card::Card(std::string front_to_fill, std::string back_to_fill, int number) {
    this->front = std::move(front_to_fill);
    this->back = std::move(back_to_fill);
    this->numberOfTimesGuessed = number;
}
