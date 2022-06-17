//
// Created by JK on 13/06/2022.
//

#include "editLogic.h"

void editLogic::deleteCard(int currentlySelectedCard, int deck) {

    this->deckIndex=deck;
    std::string CardsID = std::to_string(currentlySelectedCard);
    std::string tempQry="DELETE FROM ";
    std::string tempDeckName=backendLogic::returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry2=" WHERE ID=";
    std::string tempQry3=";";

    tempQry=tempQry+tempDeckName+tempQry2+CardsID+tempQry3;

    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}

void editLogic::insertCard(const std::string& front, const std::string& back, int number) {

    this->deckIndex=number;
    std::string tempDeckName=backendLogic::returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry="INSERT INTO ";
    std::string tempQry2=" VALUE(";
    std::string quote="\"";
    std::string coma=", ";
    std::string tempQry3=");";
    std::string numberOfTimesBeingGuessed = "0";
    int CardID=backendLogic::returnNumberOfCardsInDeck(deckIndex);
    std::string cardID_butString = std::to_string(CardID);
    tempQry=tempQry+tempDeckName+tempQry2+quote+front+quote+coma+quote+back+quote+coma+numberOfTimesBeingGuessed+coma+cardID_butString+tempQry3;

    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}

void editLogic::clearBuffer() {
///nie interesuj sie kurwa, jak bede chcial, to zaimplementuje, a jak nie bedzie mi sie chcialo, to nie
}

void editLogic::setComment(const std::string& comment, int number) {

    deckIndex=number;
    std::string tempDeckName=backendLogic::returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry="ALTER TABLE ";
    std::string tempQry2=" COMMENT='";
    std::string tempQry3="';";
    tempQry=tempQry+tempDeckName+tempQry2+comment+tempQry3;
    std::cout<<tempQry<<"\n";
    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}

void editLogic::createDeck() {

    db.mysql_execute_querry("CREATE TABLE tempDeck (front varchar(100) NOT NULL, back varchar(100) NOT NULL, numberOfTimesBeingGuessed INT, ID int NOT NULL, PRIMARY KEY (ID));");
    deckIndex = backendLogic::returnNumberOfDecks()-1;
}

void editLogic::renameDeck(std::string name, int number) {

    deckIndex = number;
    std::string tempDeckName=backendLogic::returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry="ALTER TABLE ";
    std::string tempQry2=" RENAME TO ";
    std::string tempQry3=";";
    tempQry=tempQry+tempDeckName+tempQry2+name+tempQry3;

    const char * qry = tempQry.c_str();
    std::cout<<qry<<"\n";
    db.mysql_execute_querry(qry);

}

bool editLogic::isDeckEmpty(int deckNum) {
    std::string tempDeck = backendLogic::returnNameOfDeck(deckNum);
    std::cout<<"\n"<<deckNum<<"\n";
    std::string tempQry = "SELECT EXISTS (SELECT 1 FROM ";
    std::string tempQry2 = ");";
    tempQry=tempQry+tempDeck+tempQry2;
    std::cout<<"\n"<<tempQry<<"\n";
    const char* qry = tempQry.c_str();
    bool ans = db.mysql_execute_querry(qry);

    return ans;
}

void editLogic::changeCard(std::string front, std::string back, int numberOfDeck, int numberOfCard) {

}

bool editLogic::containsWhiteSpaces(const std::string& name) {
    for(auto x: name){
        if(isspace(x))
            return true;
        if(x=='\'' || x=='!' || x=='@')     //nie chce mi sie pisac wszystkich nielegalnych znakow, ale czaisz o co chodzi juz chyba czytaczu mojego kodu. Mogłbym tez zrobic to na odwrot i wpisac wszystkie legalne znaki, ale tego tez mi sie nie chce plus byloby wolniej
            return true;
    }
    return false;
}
