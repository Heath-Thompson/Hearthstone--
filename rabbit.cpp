#include "rabbit.h"

string Rabbit::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|   Rabbit  |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Hedgehog::Rabbit(string name, int manaCost, int attack, int defense){ 
    name = "Rabbit";
    manaCost = 2;
    attack = 200;
    defense = 200;
}
