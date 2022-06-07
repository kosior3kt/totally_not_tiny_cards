//
// Created by JK on 03/06/2022.
//

#ifndef PJC_NOWE_BACKENDLOGIC_H
#define PJC_NOWE_BACKENDLOGIC_H


#include "main.h"
#include "dataBase.h"
#include <map>


class backendLogic {
public:
    static void zrupLogike();

    struct cardsInfo{
         std::string frontOfTheCard;
         std::string backOfTheCard;
         int numberOfTimesGuessed;
    };

    std::map<std::string, cardsInfo> cards;


private:


};


#endif //PJC_NOWE_BACKENDLOGIC_H
