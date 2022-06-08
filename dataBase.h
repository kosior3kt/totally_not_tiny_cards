//
// Created by JK on 29/05/2022.
//

#ifndef PJC_NOWE_DATABASE_H
#define PJC_NOWE_DATABASE_H

#include "/opt/homebrew/cellar/mysql/8.0.29/include/mysql/mysql.h"
#include "/opt/homebrew/Cellar/mysql-connector-c++/8.0.29/include/mysqlx/devapi/result.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>

#include "main.h"
#include "backendLogic.h"

class dataBaseParser{
public:
      struct connection_details{
        const char *server= "localhost", *name= "jk", *password="@1488#", *database="mysql_tuts";
    };

      dataBaseParser();
     MYSQL *mysql_connection_setup(connection_details mySqlDetails);
     MYSQL_RES* mysql_execute_querry(MYSQL *connection, const char *sql_query);


//     void OOP_jest_dla_debili();      //testowe
//     std::string selectPhraseTemp = "tblUsers;";
    connection_details createThisUselessStructure();
     void connect();
     void insertQuerry();       //testowe
     void fillStringsTEST(std::string deckName="dummyDeck");
     void fillStringForReturningNumberOfDecks();
     void fillStringForReturningNumberOfCards(std::string deckName="dummyDeck");
     int returnNumberOfDecks();
     int returnNumberOfCardsInDeck(int);
     std::string returnFrontOfCard(int, int);
     std::string returnBackOfCard(int, int);
     int returnNumberOfTimesBeingGuessed(int, int);
     std::string returnNameOfDeck(int number);
     const char * combineStrings();
     void makeItAllWork();
    std::string returnCommentToDeck(int number);
    void fillTheMap(int);

    ~dataBaseParser();




     const char * selectPhrase1 = "select * from ";
     const char* selectPhrase2;

     MYSQL * con;
     MYSQL_RES* res;
     MYSQL_ROW row;

};


#endif //PJC_NOWE_DATABASE_H
