//
// Created by JK on 14/06/2022.
//

#include "addLogic.h"

void addLogic::deleteDeck(int number) {
    dataBase db;
    backendLogic logic;
    std::string tempQry="DROP TABLE IF EXISTS ";
    std::string tempDeckName=logic.returnNameOfDeck(number);
    std::string tempQry2=";";
    tempQry=tempQry+tempDeckName+tempQry2;
    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}
