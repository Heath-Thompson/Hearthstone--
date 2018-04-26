#include <iostream>
#include <vector>
#include <cstdlib>
#include "board.h"

using namespace std;

Board::Board(){
    hp = 2000;
    mana = 0;
    maxMana = 0;
}

void Board::addToDeckList(Card* c){
    if(deck.size() < 21){
        deck.push_back(c);
    }
}
int Board::getDeck(){
    return deck.size();
}

Card* Board::showHand(){
    for (int i = 0; i < hand.size(); i++){
        cout << i << ": " << hand[i]->getName() << "(" << hand[i]->getManaCost() << ")" << endl;
    }
}

Card* Board::showField() {
    cout << endl;
    for (int i = 0; i < getFieldSize(); i++){
        cout << i + 1 << ": " << field[i]->getName() << endl;
    }
}

void Board::draw(int num){
    int j = deck.size() - 1;
    for(int i = 0; i < num; i++){
        hand.push_back(deck[j]);
        j--;
    }
}

void Board::playCardFromHand(int indx){
    Card* temp = hand[indx];
    field.push_back(hand[indx]);
    hand.erase(hand.begin() + indx);
    mana -= temp->getManaCost();
}

Card* Board::getCardOnField(int indx){
    return field[indx];
}

Card* Board::getCardInHand(int indx){
    return hand[indx];
}

int Board::getHP(){
    return hp;
}

void Board::setHP(int n){
    hp = n;
}

int Board::getHandSize(){
    return hand.size();
}

int Board::getFieldSize(){
    return field.size();
}

void Board::setMaxMana(int m) {
    maxMana = m;
}

int Board::getMana(){
    return mana;
}

void Board::incMana(){
    mana++;
}

void Board::discardCardFromField(int indx){
    Card* temp = field[indx];
    discard.push_back(temp);
    field.erase(field.begin() + indx);  //SHOULD ERASE CARD AT INDEX... DOUBLE CHECK
}

void Board::unExhaustField(){
    for (int i = 0; i < field.size(); i++){
        field[i]->unExhaust();
    }
}

void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}

void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana)
            cout << "@ ";
        else
            cout << "O ";
    }

    cout << endl;
}

void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}
