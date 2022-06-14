//
// Created by JK on 13/06/2022.
//

#include "editLogic.h"

void editLogic::deleteCard(int currentlySelectedCard) {

    std::string CardsID = std::to_string(currentlySelectedCard);
    std::string tempQry="DELETE FROM ";
    std::string tempDeckName=logic.returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry2=" WHERE ID=";
    std::string tempQry3=";";

    tempQry=tempQry+tempDeckName+tempQry2+CardsID+tempQry3;

    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}

void editLogic::insertCard(std::string front, std::string back) {

    std::string tempDeckName=logic.returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry="INSERT INTO ";
    std::string tempQry2=" VALUE(";
    std::string quote="\"";
    std::string coma=", ";
    std::string tempQry3=");";
    std::string numberOfTimesBeingGuessed = "0";
    int CardID=logic.returnNumberOfCardsInDeck(deckIndex);
    std::string cardID_butString = std::to_string(CardID);
    tempQry=tempQry+tempDeckName+tempQry2+quote+front+quote+coma+quote+back+quote+coma+numberOfTimesBeingGuessed+coma+cardID_butString+tempQry3;

    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}

void editLogic::clearBuffer() {
///nie interesuj sie kurwa, jak bede chcial, to zaimplementuje, a jak nie bedzie mi sie chcialo, to nie
}

void editLogic::setComment(std::string comment) {

    std::string tempDeckName=logic.returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry="ALTER TABLE ";
    std::string tempQry2=" COMMENT='";
    std::string tempQry3="';";
    tempQry=tempQry+tempDeckName+tempQry2+comment+tempQry3;

    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}

void editLogic::createDeck() {

    db.mysql_execute_querry("CREATE TABLE tempDeck (front varchar(100) NOT NULL, back varchar(100) NOT NULL, numberOfTimesBeingGuessed INT, ID int NOT NULL, PRIMARY KEY (ID));");
    deckIndex = logic.returnNumberOfDecks()-1;
}

void editLogic::renameDeck(std::string name) {

    std::string tempDeckName=logic.returnNameOfDeck(deckIndex);   //albo tak, albo trzeba tu zrobic -1, ale to w sumie wyjdzie w debuggu =3
    std::string tempQry="ALTER TABLE ";
    std::string tempQry2=" RENAME TO ";
    std::string tempQry3=";";
    tempQry=tempQry+tempDeckName+tempQry2+name+tempQry3;

    const char * qry = tempQry.c_str();
    db.mysql_execute_querry(qry);
}
