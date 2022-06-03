//
// Created by JK on 29/05/2022.
//

#include "dataBase.h"

MYSQL *dataBaseParser::mysql_connection_setup(dataBaseParser::connection_details mySqlDetails) {

    MYSQL *connection = mysql_init(NULL);
    if(!mysql_real_connect(connection, mySqlDetails.server, mySqlDetails.name, mySqlDetails.password, mySqlDetails.database, 0, NULL, 0)){
        std::cout<<"jebło";
        exit(1);
    }
    return connection;
}

MYSQL_RES *dataBaseParser::mysql_execute_querry(MYSQL *connection, const char *sql_query) {

    if(mysql_query(connection, sql_query)){
        std::cout<<"jebło 2 \n";
        exit(1);
    }
    return mysql_use_result(connection);
}

void dataBaseParser::connect() {
    this->con = mysql_connection_setup(this->createThisUselessStructure());
}

void dataBaseParser::insertQuerry() {

    this->fillStringsTEST("dummyDeck");

    res = dataBaseParser::mysql_execute_querry(this->con,  combineStrings());
    while((row = mysql_fetch_row(res))){
        for(int i=0; i<4; i++){
            std::cout<< row[i]<< " | ";
            if(i==3)
                std::cout<<"\n\n";
        }
    }

}

const char * dataBaseParser::combineStrings() {

    const char * wholePhrase = reinterpret_cast<const char *>(new const  char *[std::strlen(selectPhrase1) + strlen(selectPhrase2) + 1]);
    std::strcpy(const_cast<char *>(wholePhrase), selectPhrase1);
    std::strcat(const_cast<char *>(wholePhrase), selectPhrase2);
    return wholePhrase;
}

void dataBaseParser::makeItAllWork() {
    connect();
//    insertQuerry();
    returnNumberOfCardsInDeck();
//    std::cout<<"\n";
    returnNumberOfDecks();
//    std::cout<<returnNumberOfDecks();
    returnNameOfDeck(4);
//    std::cout<<returnCommentToDeck(0);
}

dataBaseParser::connection_details dataBaseParser::createThisUselessStructure() {
    connection_details *mysqlD = new connection_details;
    return *mysqlD;
}

int dataBaseParser::returnNumberOfDecks(){
    fillStringForReturningNumberOfDecks();
//    std::cout<<combineStrings();
    res = dataBaseParser::mysql_execute_querry(this->con,  combineStrings());
    int temp;
    while((row = mysql_fetch_row(res))){

//            std::cout<< row[0] << "\n\n";     //dziala juz tez xD
            temp = atoi(row[0]);
//            std::cout<<temp;
    }
    return temp;
}

void dataBaseParser::fillStringsTEST(std::string deckName) {
    this->selectPhrase2=deckName.c_str();
}

void dataBaseParser::fillStringForReturningNumberOfDecks() {
    this->selectPhrase1="SELECT COUNT(*) from INFORMATION_SCHEMA.TABLES ";
    this->selectPhrase2="WHERE TABLE_SCHEMA = 'mysql_tuts';";
}

void dataBaseParser::fillStringForReturningNumberOfCards(std::string deckName) {
    this->selectPhrase1="SELECT COUNT(*) from ";
    this->selectPhrase2=deckName.c_str();
}

int dataBaseParser::returnNumberOfCardsInDeck() {
    fillStringForReturningNumberOfCards();
//    std::cout<<combineStrings();
    res = dataBaseParser::mysql_execute_querry(this->con,  combineStrings());
    int temp;
    while((row = mysql_fetch_row(res))){
//        std::cout<< row[0]<< "\n\n";   //bo dziala juz xD
        temp = std::atoi(row[0]);
    }
    return temp;
}

std::string dataBaseParser::returnNameOfDeck(int number){
    const char * qry = "SELECT table_name FROM information_schema.tables WHERE table_schema = 'mysql_tuts';";
//    std::cout<<qry<<"\n\n";

    res = dataBaseParser::mysql_execute_querry(this->con, qry);

    std::string temp;
    int i=0;
    const char * done = "deck number is too large";
    while((row = mysql_fetch_row(res))){
        if(i==number) {
//            std::cout << row[0] << "\n\n";
            temp = row[0];
            done = temp.c_str();
        }
        i++;
    }


//    std::cout<<done;

    return done;
}

dataBaseParser::dataBaseParser() {
    this->connect();
}

std::string dataBaseParser::returnCommentToDeck(int number) {

    std::string temp1 = "SELECT table_comment FROM INFORMATION_SCHEMA.TABLES WHERE table_name=\'";
    std::string tempDeckName = this->returnNameOfDeck(number);
    std::string temp3 ="\';";
    std::string temp4 = temp1+tempDeckName+temp3;

    const char * qry = temp4.c_str();
    res = dataBaseParser::mysql_execute_querry(this->con,  qry);
    (row = mysql_fetch_row(res));
    std::string wholePhrase = row[0];

    return wholePhrase;
}

dataBaseParser::~dataBaseParser() {

    mysql_free_result(res);
    mysql_close(con);
}


