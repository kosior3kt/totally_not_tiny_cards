//
// Created by JK on 13/06/2022.
//

#ifndef PJC_NOWE_EDITLOGIC_H
#define PJC_NOWE_EDITLOGIC_H


#include "backendLogic.h"

class editLogic: backendLogic {

public:
    void deleteChosenDeck(int index);
    void createDeck(std::string name, std::string comment);

};


#endif //PJC_NOWE_EDITLOGIC_H
