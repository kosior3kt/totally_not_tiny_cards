//
// Created by JK on 11/06/2022->
//

#include "parser.h"

int parser::returnNumberOfDecks() {
    std::unique_ptr<dataBase> db = std::make_unique<dataBase>();
    const char * qry = "SELECT COUNT(*) from INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = 'mysql_tuts';";
    db->res = db->mysql_execute_querry(qry);
    while((db->row = mysql_fetch_row(db->res))){
        int temp = std::atoi(db->row[0]);
        mysql_free_result(db->res);
        mysql_close(db->con);
        return temp;
    }
    return 666;
}

int parser::returnNumberOfCardsInDeck(int number) {
    std::unique_ptr<dataBase> db = std::make_unique<dataBase>();
    std::string tempQry1 = returnNameOfDeck(number);
    tempQry1 = "SELECT COUNT(*) from "+tempQry1+";";
    const char * qry = tempQry1.c_str();

    db->res = db->mysql_execute_querry(qry);
    while((db->row = mysql_fetch_row(db->res))){
        int temp = std::atoi(db->row[0]);
        mysql_free_result(db->res);
        mysql_close(db->con);
        return temp;

    }
    return 666;
}

std::string parser::returnNameOfDeck(int number) {
    std::unique_ptr<dataBase> db = std::make_unique<dataBase>();
    const char * qry = "SELECT table_name FROM information_schema.tables WHERE table_schema = 'mysql_tuts';";
    db->res = db->mysql_execute_querry(qry);

    int i=0;
    while((db->row = mysql_fetch_row(db->res))){
        if(i==number) {
            std::string temp = db->row[0];
            mysql_free_result(db->res);
            mysql_close(db->con);
            return temp;
        }
        i++;
    }
    return "returnNameOfDeck doesnt work for some unknown reason…";
}

std::string parser::returnCommentToDeck(int number) {
    std::unique_ptr<dataBase> db = std::make_unique<dataBase>();
    std::string tempQry = "SELECT table_comment FROM INFORMATION_SCHEMA.TABLES WHERE table_name=\""+this->returnNameOfDeck(number)+"\";";
    const char * qry = tempQry.c_str();

    db->res = db->mysql_execute_querry(qry);
    db->row = mysql_fetch_row(db->res);
    std::string temp = db->row[0];
    mysql_free_result(db->res);
    mysql_close(db->con);
    return temp;
}
