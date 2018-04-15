#include "bear.h"

string Bear::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|   Bear    |";
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

Hedgehog::Bear(string name, int manaCost, int attack, int defense){ 
    name = "Bear";
    manaCost = 6;
    attack = 500;
    defense = 600;
}
