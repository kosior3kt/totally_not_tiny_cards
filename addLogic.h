//
// Created by JK on 14/06/2022.
//

#ifndef PJC_NOWE_ADDLOGIC_H
#define PJC_NOWE_ADDLOGIC_H


#include "backendLogic.h"

class addLogic: public backendLogic {
public:
    ///this method is responsible for deleting a deck with a chosen index
    static void deleteDeck(int number);

};


#endif //PJC_NOWE_ADDLOGIC_H
