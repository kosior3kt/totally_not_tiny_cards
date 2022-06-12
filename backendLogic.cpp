//
// Created by JK on 03/06/2022.
//

#include "backendLogic.h"



std::vector<Card> backendLogic::fillTheVector(int numberOfDeck) {
    dataBase db;
    std::cout<<"i'm filling the vector of cards";
    std::vector<Card> tempCardDeckVector;
    const char * qry = "select * from mysql_tuts.dummydeck;";
    db.res = db.mysql_execute_querry( qry);

    while((db.row = mysql_fetch_row(db.res))){
        Card *tempCard = new Card(db.row[0], db.row[1], std::atoi(db.row[2]));
        tempCardDeckVector.push_back(*tempCard);
    }

    return tempCardDeckVector;
}

std::string backendLogic::returnFrontOfCard(int numberOfTheDeck, int numberOfTheCard) {

    std::vector<Card> temp = fillTheVector(numberOfTheDeck);
    int i =0;
    for(const auto& x : temp){
        if(i==numberOfTheCard){
            std::cout<<"udalo sie =3"<<"\n"<<x.front;
            return x.front;
        }
        i++;
    }
return "nie dziala zwracanie przodu karty w backendlogic\n";
}

std::string backendLogic::returnBackOfCard(int numberOfTheDeck, int numberOfTheCard) {

    std::vector<Card> temp = fillTheVector(numberOfTheDeck);
    int i =0;
    for(const auto& x : temp){
        if(i==numberOfTheCard){
            std::cout<<"udalo sie =3"<<"\n"<<x.back;
            return x.back;
        }
        i++;
    }
    return "nie dziala zwracanie tylu karty w backendlogic\n";
}

int backendLogic::returnNumberOfTimesBeingGuessed(int numberOfTheDeck, int numberOfTheCard) {

    std::vector<Card> temp = fillTheVector(numberOfTheDeck);
    int i =0;
    for(auto x : temp){
        if(i==numberOfTheCard){
            std::cout<<"udalo sie =3"<<"\n"<<x.numberOfTimesGuessed;
            return x.numberOfTimesGuessed;
        }
        i++;
    }
    return 69;
}




std::vector<Deck> backendLogic::fillDeckVector() {
    std::vector<Deck> tempDeckVector;
    for(int i=0; i<parser.returnNumberOfDecks(); i++){
        Deck *tempDeck = new Deck(i, parser.returnNumberOfCardsInDeck(i), parser.returnCommentToDeck(i), parser.returnNameOfDeck(i));
//        std::cout<<i<<"    "<<parser.returnNumberOfCardsInDeck(i)<<"   "<<parser.returnNameOfDeck(i)<<"   "<<parser.returnCommentToDeck(i)<<"\n";
        tempDeckVector.push_back(*tempDeck);
    }
    return tempDeckVector;
}

std::string backendLogic::returnNameOfDeck(int deckNumber) {
    std::vector<Deck> temp = fillDeckVector();
    for( const auto& x: temp){
        if(x.deckNumber == deckNumber){
          return x.name;
        }
    }
return "returnNameOdDeck in backendLogic doesnt seem to be working \n";
}

std::string backendLogic::returnCommentToDeck(int deckNumber) {

    std::vector<Deck> temp = fillDeckVector();
    for( auto x: temp){
        if(x.deckNumber == deckNumber){
            return x.commentToDeck;
        }
    }
    return "returnCommentToDeck in backendLogic doesnt seem to be working \n";
}

int backendLogic::returnNumberOfCardsInDeck(int deckNumber) {
    std::vector<Deck> temp = fillDeckVector();
    for( const auto& x: temp){
        if(x.deckNumber == deckNumber){
            return x.numberOfCards;
        }
    }
}

backendLogic::backendLogic() {
    this->fillDeckVector();
}



///////////////////////////////////

