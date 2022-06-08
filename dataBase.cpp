//
// Created by JK on 29/05/2022.
//

#include "dataBase.h"
#include "backendLogic.h"

backendLogic * temp = new backendLogic();

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
        exit(420);
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
    const char * qry = "SELECT table_name FROM information_schema.tables WHERE table_schema = 'mysql_tuts';";
    dataBaseParser::mysql_execute_querry(this->con,  qry);
//    insertQuerry();
//    returnNumberOfCardsInDeck(0);
//    std::cout<<"\n";
//    returnNumberOfDecks();
//    std::cout<<returnNumberOfDecks();
//    returnNameOfDeck(4);
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

int dataBaseParser::returnNumberOfCardsInDeck(int number=0) {

    fillStringForReturningNumberOfCards(returnNameOfDeck(number));
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
    row = mysql_fetch_row(res);
    std::string wholePhrase = row[0];

    return wholePhrase;
}

dataBaseParser::~dataBaseParser() {

    mysql_free_result(res);
    mysql_close(con);
}

void dataBaseParser::fillTheMap(int numberOfDeck) {

    this->connect();

//    std::cout<<"\ntutaj jeblo 0\n";
//    int tempNumberOfCards = this->returnNumberOfCardsInDeck(numberOfDeck);

    std::cout<<"\ntutaj jeblo 1\n";


//    for(int i=0; i<tempNumberOfCards; i++){
//    std::string tempFront = this->returnFrontOfCard(numberOfDeck,i);
//    std::string tempBack = this->returnBackOfCard(numberOfDeck,i);
//    int tempNumberOfTimesGuessed = this->returnNumberOfTimesBeingGuessed(numberOfDeck,i);
//        std::cout<<"\ntutaj jeblo 1\n";
//        temp->cards[tempFront]={tempFront, tempBack, tempNumberOfTimesGuessed};
//        std::cout<<"\ntutaj jeblo 2\n";
//        backendLogic::cardsInfo& chuj_wie = temp->cards[this->returnFrontOfCard(numberOfDeck,i)];
//
//        std::cout<<chuj_wie.frontOfTheCard<<"    <---- mama nadzieje, ze to zadzialaalo =3\n";
//    }

    const char * qry = "select * from mysql_tuts.dummydeck;";

    res = dataBaseParser::mysql_execute_querry(this->con,  qry);
    std::cout<<"jeblo znowu 2.5\n";
int i =0;
    while(this->row = mysql_fetch_row(res)){
//        std::string tempDupa = this->returnFrontOfCard(1,i);
        std::cout<<"tutej dziala nadal";
//            std::cout<< row[0] << "\n\n";     //dziala juz tez xD
        //std::cout<<row[0];
        //std::cout<<row[1];
        //std::cout<<row[2];
        temp->cards[row[0]] = { row[0], row[1], std::atoi(row[2])}; //z jakiegos powodu ten zapis nie dziala :<
        std::cout<<"dziala tutaj ejszcze \n";
        backendLogic::cardsInfo& chuj_wie = temp->cards[row[0]];
        std::cout<<"\ntutaj jeblo 3\n";

        std::cout<<chuj_wie.frontOfTheCard<<"    <---- mama nadzieje, ze to zadzialaalo =3\n";
//            std::cout<<temp;
i++;
    }



}

std::string dataBaseParser::returnFrontOfCard(int numberOfTheDeck, int numberOfTheCard) {

    std::string temp1 = "SELECT front FROM ";
    std::string tempDeckName = this->returnNameOfDeck(numberOfTheDeck);

    std::string temp3 =";";
    std::string temp4 = temp1+tempDeckName+temp3;

    const char * qry = temp4.c_str();

    std::cout<<qry;

    res = dataBaseParser::mysql_execute_querry(this->con,  qry);

int iterator=0;
    while((row = mysql_fetch_row(res))){
        if(iterator==numberOfTheCard){
            return row[0];
        }
        iterator++;
    }

    return "cos jak zawsze sie zjebalo ale we froncie tym razem";
}

std::string dataBaseParser::returnBackOfCard(int numberOfTheDeck, int numberOfTheCard) {
    std::string temp1 = "SELECT back FROM ";
    std::string tempDeckName = this->returnNameOfDeck(numberOfTheDeck);
    std::string temp3 =";";
    std::string temp4 = temp1+tempDeckName+temp3;

    const char * qry = temp4.c_str();

    res = dataBaseParser::mysql_execute_querry(this->con,  qry);

    int iterator=0;
    while((row = mysql_fetch_row(res))){
        if(iterator==numberOfTheCard){
            return row[0];
        }
        iterator++;
    }

    return "cos jak zawsze sie zjebalo ale we backu tym razem";
}

int dataBaseParser::returnNumberOfTimesBeingGuessed(int numberOfTheDeck, int numberOfTheCard) {
    std::string temp1 = "SELECT numberOfTimesGuessed FROM ";
    std::string tempDeckName = this->returnNameOfDeck(numberOfTheDeck);
    std::string temp3 =";";
    std::string temp4 = temp1+tempDeckName+temp3;

    const char * qry = temp4.c_str();

    res = dataBaseParser::mysql_execute_querry(this->con,  qry);

    int iterator=0;
    while((row = mysql_fetch_row(res))){
        if(iterator==numberOfTheCard){
            return std::atoi(row[0]);
        }
        iterator++;
    }

    return 69;
}


