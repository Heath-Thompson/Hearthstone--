#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "goblin.h"
#include "bear.h"
#include "frog.h"
#include "giraffe.h"
#include "hedgehog.h"
#include "rabbit.h"
#include "cow.h"
#include "dog.h"
#include "elephant.h"
#include "cat.h"
#include "pig.h"
#include "card.h"

using namespace std;

void getPlayerAction(Board&, Board&);
void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);

int main(int argc, char * argv[]){
    int turn, c;
    srand(time(0));

    // Set up Player board
    Board pb;
    // Create player deck and draw initial hand here:

    for (int i = 0; i < 20; i++){
        c = rand() % 11;
        Card* cards;
        switch(c){
            case 0: cards = new Goblin();
                break;
            case 1: cards = new Bear();
                break;
            case 2: cards = new Frog();
                break;
            case 3: cards = new Giraffe();
                break;
            case 4: cards = new Hedgehog();
                break;
            case 5: cards = new Rabbit();
                break;
            case 6: cards = new Elephant();
                break;
            case 7: cards = new Cat();
                break;
            case 8: cards = new Dog();
                break;
            case 9: cards = new Pig();
                break;
            case 10: cards = new Cow();
                break;
            default: cards = new Goblin();
                break;
        }
        pb.addToDeckList(cards);
    }

    pb.draw(5);
    pb.renderHand();
    pb.setMana(1);

    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
    for (int i = 0; i < 20; i++){
        c = rand() % 11;
        Card* cards;
        switch(c){
            case 0: cards = new Goblin();
                break;
            case 1: cards = new Bear();
                break;
            case 2: cards = new Frog();
                break;
            case 3: cards = new Giraffe();
                break;
            case 4: cards = new Hedgehog();
                break;
            case 5: cards = new Rabbit();
                break;
            case 6: cards = new Elephant();
                break;
            case 7: cards = new Cat();
                break;
            case 8: cards = new Dog();
                break;
            case 9: cards = new Pig();
                break;
            case 10: cards = new Cow();
                break;
            default: cards = new Goblin();
                break;
        }
        ob.addToDeckList(cards);
    }
    ob.draw(5);
    ob.setMana(1);
    renderBoard(pb, ob);

    while(pb.getHP() > 0 && ob.getHP() > 0){

        //coin flip to determine who goes first
        if(rand() % 2 == 0){
            while(pb.getHP() > 0 && ob.getHP() > 0){
                getPlayerAction(pb, ob);
                getOpponentAction(pb, ob);
                turn++;
            }
        }
        else{
            while(pb.getHP() > 0 && ob.getHP() > 0){
                getOpponentAction(pb, ob);
                getPlayerAction(pb, ob);
                turn++;
            }
        }
    }


    return 0;
}


void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderField();
    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();

    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;

    //clearScreen(1);
}

void getPlayerAction(Board & pb, Board & ob){
    int i;
    int j;
    while(pb.getHandSize() >= 0){
        if(i != 0){
            cout << "Enter a number for which card you would like to play, 0 to start the combat phase or 10 to end your turn: " << pb.showHand() << endl;
            cin >> i;
            //play the card corresponding to the number that user entered
            if(i != 0 && i != 10){
                if(pb.getCardInHand(i - 1)->getManaCost() <= pb.getMana()){
                    pb.playCardFromHand(i - 1);
                    renderBoard(pb, ob);
                }
                else{
                    cout << "You don't have enough mana to play that!";
                }
            }

        else if(i == 0){
            cout << "Which card would you like to attack with?";
            cin >> i;
            if(!pb.getCardOnField(i)->isExhausted())
            {
                cout << "What would you like to attack?";
                cin >> j;
                int targetIndex = j;
                if(pb.getCardOnField(i)->getAttack() > ob.getCardOnField(targetIndex)->getDefense()){
                	cout << "Your " << pb.getCardOnField(i)-> getName() << "destroyed your opponent's" << ob.getCardOnField(j)->getName() << "." << endl;
				}
            }
        }
        else if(i == 10){
            break;
        }
    }
}
}

void getOpponentAction(Board & pb, Board & ob){
    // Go through hand and play cards that the opponent can afford to play
    for(int i = 0; i < ob.getHandSize(); i++){
        if(ob.getCardInHand(i)->getManaCost() <= ob.getMana()){
            //ob.playCardFromHand(ob/*,i */);
            ob.playCardFromHand(i);
        }
        renderBoard(pb, ob);
    }

    // Attack with all creatures not exhausted
    for(int i = 0; i < ob.getFieldSize(); i++){
        if(!ob.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < pb.getFieldSize(); j++){
                if(ob.getCardOnField(i)->getAttack() > ob.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << ob.getCardOnField(i)->getName() << " destroyed your " << pb.getCardOnField(targetIndex)->getName() << "!" << endl;
                pb.discardCardFromField(targetIndex);
                renderBoard(pb, ob);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << ob.getCardOnField(i)->getName() << " attacks you directly for " << ob.getCardOnField(i)->getAttack() << " damage!" << endl;
                pb.setHP(pb.getHP() - ob.getCardOnField(i)->getAttack());
            }
        }

    }
}
